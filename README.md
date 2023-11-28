Tree-sitter-ebnf-generator provides scripts that can convert files defined in
an EBNF grammar into equivalent
[tree-sitter](https://tree-sitter.github.io/tree-sitter/) grammar.js dsl format
and vice versa. The EBNF syntax is both more compact and readable than the
tree-sitter js syntax and far more similar to published EBNF grammars for
languages such as scala and lua which should make writing grammars more
straightforward and less error prone. The extended EBNF format defined in this
project supports all of the features in the tree-sitter js DSL.

The examples directory shows how the ebnf format can be used to generate
tree-sitter grammars for a language. The lua language context free grammar can
be found [here](examples/lua/lua.ebnf) along with its generated tree-sitter
[grammar](examples/lua/grammar.js). Similarly, scala language context free
grammar can be found [here](examples/scala/scala.ebnf) along with its generated
tree-sitter [grammar](examples/scala/grammar.js). All syntactical elements in
the lua and scala grammars can be converted to the tree-sitter grammar.

Note this project is under active development so it is possible that some of the
syntax may change.

### EBNF -> tree-sitter
The script for converting from the EBNF format is called
[parse_grammar.lua](src/lua/parse_grammar.lua). It should work with any lua
version >= 5.1, including luajit.

Usage: invoke this script with optional arguments leading grammar file as the first
       command argument along with optional tail argument, e.g.:
       `./parse_grammar.lua foo.ebnf -o grammar.js -v`

Options:
```
  -o|--output-file  specifies the optional output file for the tree-sitter dsl
                    (default nil)
  -v|--verbose      prints the out (default true if output_file == nil, otherwise false)
  -h|--help         prints this message
```

Syntax: the syntax used is very similar to the [w3c EBNF
syntax](https://www.w3.org/TR/xml/#sec-notation). Unicode code points are
represented with \uXXXX. Line comments are started with a `;` character
and extend to the end of the line. Character classes can be negated with `^`
but there is no `-` operator like in the w3c syntax because tree-sitter does
not support intersections. Unlike most EBNF notations, there is syntax using
parenthesis grouping to specify precedence and associativity. All of the
concepts defined below map directly to equivalent concepts for creating
tree-sitter
[parsers](https://tree-sitter.github.io/tree-sitter/creating-parsers).

The EBNF syntax is presented below along with equivalent tree-sitter dsl code.

Rules:
```
  id ::= expression
    defines a rule with name id and . Any identifiers defined as the left
    hand side of a rule can be referenced in an expression without any
    wrapping, e.g.

    foo ::= "bar" (tree-sitter `foo: $ => "bar"`)
    bar ::= foo "baz" (tree-sitter `bar $ => seq($.foo, "baz")`)

    defines two rules with identifiers foo and bar. The identifier foo
    will match the string "bar" while the identifer bar will match the
    string "barbaz" (space separated expressions are interpreted as
    concatenation)

  constant_id := value
    defines a constant that can be inlined on the right hand side of a
    rule. For example,

    foo := "bar"
    bar ::= "$(foo)buzz" (tree-sitter `bar: $ => "barbuzz"`)
    baz ::= $foo "buzz" (tree-sitter `baz: $ => seq("bar", "buzz")

    defines two rules bar and baz that are each semantically identical
    although the right hand side of bar will be expanded to a single
    string literal ("barbuzz") while the right hand side of baz will
    be expanded to the concatenation "bar" "buzz"

    Constants can be useful to define inline gramattical elements that
    are reused but don't need to be a part of the language grammar. This is
    a bit more powerful than adding a rule to the tree-sitter `inline` fields
    because it allows for rules that can match the empty string.
```


Terminals:
```
  "foo", 'bar'
    matches string literals beginning with double or single quotes

  [a-zA-Z0-9], [\u0020-\u0x007f],
    matches any characters in the ranges specified

  [abc]
    matches any characters in the enumerated set

  [abcg-z]
    matches any enumerated characters as well as characters in ranges

  [^abc], [^D-F]
    matches any character not in the enumerated set or range

  /.*/, /[a-z]?1/
    matches any set of characters that match the regular expression in
    javascript regex notation (the above character classes are syntactic
    sugar for regular expression)
```

Expressions:
```
  "foo" "bar", baz "buzz"
    tree-sitter: seq("foo", "bar"), seq($.baz, "buzz")

    the first expression matches "foobar" while the second matches
    "$(baz)buzz" where $(baz) is the value assigned on the right hand
    side of the definition of baz

  "foo"?, bar? (foo | bar)?
    tree-sitter: optional("foo"), optional($.bar), optional(choice($.foo, $.bar))

    matches the expression immediately to the left of the ? or nothing.

  "foo"*, bar*, (foo | bar)*
  tree-sitter: repeat("foo"), repeat($.bar), repeat(choice($.foo, $.bar))

    matches zero or more occurrences of the expression immediately to
    the right of the *.

  "foo"+, bar+, (foo | bar)+
  tree-sitter: repeat1("foo"), repeat1($.bar), repeat1(choice($.foo, $.bar))

    matches one or more occurrences of the expression immediately to
    the right of the +.

  "foo" | "bar", "foo" "bar" | "baz" "buzz"
  tree-sitter: choice("foo", "bar"), choice(seq("foo", "bar"), seq("baz", "buzz"))

    matches either the expression to the left of the | or the expression
    to the right. Concatenation has higher precedence than alternation
    so (A B) | (C D) is equivalent to A B | C D.

  <("foo" bar)
  tree-sitter: prec.left("foo", $.bar)

    defines an expression concatenating "foo" and bar while assigning
    left associative precedence to the expression.

  >("foo")
  tree-sitter: prec.right("foo")

    defines an expression concatenating "foo" and bar while assigning
    right associative precedence to the expression.

  5("foo")
  tree-sitter: prec(5, "foo")

    defines an expression with precedence value 5. Matches with higher
    precedence are preferred when there is a conflict.

  <6(foo), >7(bar)
  tree-sitter: prec.left(6, $.foo), prec.right(7, $.bar)

    defines expressions that have both a specified associativity (left if
    the leading character is < and right for >) and a precedence value.

  ~2(foo | bar)
  tree-sitter: prec.dynamic(2, choice($.foo, $.bar))

    defines an expression that has dynamic precedence that is used to resolve
    conflicts at runtime

  !("foo" "bar")
  tree-sitter: token.immediate(seq("foo", "bar")

    defines an expression for which no extra elements will be valid in between the
    concatenated elements. For example, this will match "foobar" but _not_ "foo bar"

  @("foo" bar "baz")
  tree-sitter: token(seq("foo", $.bar, "baz")

    defines a single token that is defined in terms of other tokens to simplify
    the tree generated by tree-sitter

  bar -> foo, "baz"+ -> "buzz"
  tree-sitter: alias($.bar, $.foo), alias(repeat1("baz"), "buzz")

    aliases a rule. If the right hand side is a string literal, then the
    tree-sitter node will be anonymous. Otherwise it will be a named node. Note
    that `->` has the highest precedence so that "foo" "bar" -> $.baz is
    equivalent to seq("foo", alias("foo", $.baz). Use explicit grouping if
    necessary, i.e. `("foo" "bar") -> baz` to generate
    `alias(seq("foo", "bar"), $.baz)`

  bar: foo, "baz"?: "buzz"
  tree-sitter: field("foo", $.bar), field("buzz", optional("baz"))

    defines a field name . Quotation marks are optional because the field name
    must be a string literal. Quotations marks are however necessary if the
    field name has spaces in it. Note that `:` has the highest precedence so that
    "foo" "bar": baz is equivalent to seq("foo", field("baz", "bar"). Use
    explicit grouping if necessary, i.e. `("foo" "bar"): baz` to generate
    `field("baz", seq("foo", "bar"))`
```

### tree-sitter to EBNF

There is also a node.js script that converts a tree-sitter grammar.js file into
the EBNF format. It is found at
[tree-sitter-to-ebnf.js](src/js/tree-sitter-to-ebnf.js). To run the script, it
may be necessary to run `npm install` in the src/js directory. The input to the
script is just the name of a tree-sitter grammar.js file, e.g
`./src/js/tree-sitter-to-ebnf.js examples/handwritten-scala/scala.ebnf`. The
output can be redirected to a file.
