Tree-sitter-ebnf-generator provides a script that can convert files defined in
an EBNF grammar into equivalent
[tree-sitter](https://tree-sitter.github.io/tree-sitter/) grammar.js dsl files.
The syntax is both more compact and readable than the tree-sitter js syntax and
far more similar to published EBNF grammars for languages such as scala and lua
which should make writing grammars more straightforward and less error prone.

The examples directory shows how the ebnf format can be used to generate
tree-sitter grammars for a language. The lua language context free grammar can
be found [here](examples/lua/lua.ebnf) along with its generated tree-sitter
[grammar](examples/lua/grammar.js). Similarly, scala language context free
grammar can be found [here](examples/scala/scala.ebnf) along with its generated
tree-sitter [grammar](examples/scala/grammar.js). All syntactical elements in
the lua and scala grammars can be converted to the tree-sitter. It is not yet
possible to create a parser from the grammars because of issues with precedence
rules and tree-sitter's requirement that syntactic rules may not match the empty
string. Future work is to modify the grammars so that they do not rely on rules
that can match the empty string.

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
parenthesis grouping to specify precedence and associativity.

Rules:
```
  id ::= expression
    defines a rule with name id and . Any identifiers defined as the left
    hand side of a rule can be referenced in an expression without any
    wrapping, e.g.

    foo ::= "bar"
    bar ::= foo "baz"

    defines two rules with identifiers foo and bar. The identifier foo
    will match the string "bar" while the identifer bar will match the
    string "barbaz" (space separate expressions are interpreted as
    concatenation)

  constant_id := value
    defines a constant that can be inlined on the right hand side of a
    rule. For example,

    foo := "bar"
    bar ::= "$(foo)buzz"
    baz ::= $foo "buzz"

    defines two rules bar and baz that are each semantically identical
    although the right hand side of bar will be expanded to a single
    string literal ("barbuzz") while the right hand side of baz will
    be expanded to the concatenation "bar" "buzz"

    Constants can be useful to define inline gramattical elements that
    are reused but don't need to be a part of the language grammar.
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
    the first expression matches "foobar" while the second matches
    "$(baz)buzz" where $(baz) is the value assigned on the right hand
    side of the definition of baz

  "foo"?, bar? (foo | bar)?
    matches the expression immediately to the left of the ? or nothing

  "foo"*, bar*, (foo | bar)*
    matches zero or more occurrences of the expression immediately to
    the right of the *

  "foo"+, bar+, (foo | bar)+
    matches one or more occurrences of the expression immediately to
    the right of the +

  "foo" | "bar", "foo" "bar" | "baz" "buzz"
    matches either the expression to the left of the | or the expression
    to the right. Concatenation has higher precedence than alternation
    so (A B) | (C | D) is equivalent to A B | C D.

  <("foo" bar)
    defines an expression concatenating "foo" and bar while assigning
    left associative precedence to the expression

  >("foo")
    defines an expression concatenating "foo" and bar while assigning
    right associative precedence to the expression

  5("foo")
    defines an expression with precedence value 5. Matches with higher
    precedence are preferred when there is a conflict.

  <6(foo), >7(bar)
    defines expressions that have both a specified associativity (left if
    the leading character is < and right for >) and a precedence value.
```

