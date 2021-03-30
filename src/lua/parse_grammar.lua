#!/usr/bin/env lua

local msg = [[
Converts a language grammar specified in an EBNF format into the tree-sitter
grammar.js dsl.
]]
local usage = [[
Usage: invoke this script with optional arguments leading grammar file as the first
       command argument along with optional tail argument, e.g.:
       e.g. `./parse_grammar.lua foo.ebnf -o grammar.js -v`

Options:
  -o|--output-file  specifies the optional output file for the tree-sitter dsl
                      default: nil
  -v|--verbose      prints the parsed tree to stdout
                      default: true if output_file == nil, otherwise false
  -q|--quiet        disables printing the parsed tree to stdout
                      default: false
  --hide-lower-case hides nodes that begin with a lower case letter unless
                    first character is bracketed, e.g. [f]oo ::= "foo"
  --camel-to-snake  converts camel case references to snake case
  -h|--help         prints this message
]]

local syntax = [[
Syntax: the syntax used is very similar to the w3c EBNF syntax found at
https://www.w3.org/TR/xml/#sec-notation. Unicode code points are
represented with \uXXXX. Line comments are started with a ';' character
and extend to the end of the line. Character classes can be negated with `^`
but there is no `-` operator like in the w3c syntax because tree-sitter does
not support intersections. Unlike most EBNF notations, there is syntax using
parenthesis grouping to specify precedence and associativity.

Rules:
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

Terminals:
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

Expressions:
  "foo" "bar", baz "buzz"
    tree-sitter: seq("foo", "bar"), seq($.baz, "buzz")

    the first expression matches "foobar" while the second matches
    "$(baz)buzz" where $(baz) is the value assigned on the right hand
    side of the definition of baz

  "foo"?, bar? (foo | bar)?
    tree-sitter: optional("foo"), optional($.bar), optional(choice($.foo, $.bar))

    matches the expression immediately to the left of the ? or nothing.
    Tree-sitter equivalent:


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
    so (A B) | (C | D) is equivalent to A B | C D.

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
    that -> has the highest precedence so that "foo" "bar" -> $.baz is
    equivalent to seq("foo", alias("foo", $.baz). Use explicit grouping if
    necessary, i.e. `("foo" "bar") -> baz` to generate
    `alias(seq("foo", "bar"), $.baz)`

  bar: foo, "baz"?: "buzz"
  tree-sitter: field("foo", $.bar), field("buzz", optional("baz"))

    defines a field name . Quotation marks are optional because the field name
    must be a string literal. Quotations marks are however necessary if the
    field name has spaces in it. Note that:has the highest precedence so that
    "foo" "bar": baz is equivalent to seq("foo", field("baz", "bar"). Use
    explicit grouping if necessary, i.e. `("foo" "bar"): baz` to generate
    `field("baz", seq("foo", "bar"))`
]]
local function print_help()
  print(msg)
  print(usage)
  print(syntax)
  os.exit(0)
end
local verbose = false
local quiet = false
local output_file = nil
local file = nil

local unpack = unpack or table.unpack
local tokens = {}
local tokenmap = {}
local values = {}
local hidden = nil
local camel_to_snake = nil

local function parse_args()
  local args = arg
  local arg = table.remove(args, 1)
  while arg do
    if arg == "-v" or arg == "--verbose" then
      verbose = true
    elseif arg == "-q" or arg == "--quiet" then
      quiet = true
    elseif arg == "--hide-lower-case" then
      hidden = true
    elseif arg == "--camel-to-snake" then
      camel_to_snake = true
    elseif arg == "-o" or arg == "--output-file" then
      output_file = table.remove(args, 1)
      assert(output_file, "usage: must provide an output file with " .. arg)
    elseif arg == "-h" or arg == "--help" then
      print_help()
    else
      if #args ~= 0 then
        print("error: unused trailing arguments (" .. table.concat(args, ", ") .. ")")
        os.exit(1)
      end
      file = arg
    end
    arg = #args > 0 and table.remove(args, 1)
  end
  if not file then
    print("error: no input file specified!")
    print(usage)
    os.exit(1)
  end
  if not output_file then verbose = true end
end
parse_args()

local function print_table(t)
  print("{" .. table.concat(t, ", ") .. "}")
end

local function format_reference(s)
  if camel_to_snake then
    local pattern = "([A-Z][a-z0-9]*)"
    local prefix_start, prefix_end, match = s:find(pattern)
    if prefix_start then
      local res = {}
      while (prefix_start) do
        if #res == 0 and prefix_start > 1 then table.insert(res, s:sub(1, prefix_start - 1)) end
        if #res > 0 then table.insert(res, "_") end
        table.insert(res, match:lower())
        prefix_start, prefix_end, match = s:find(pattern, prefix_end + 1)
      end
      return table.concat(res)
    else
      return s
    end
  else
    return s
  end
end

local function replace_dollars(token, debug)
  if token:find("%$") then
    return token:gsub("%$([(]?)([%w._]+)([)]?)", function(lp, w, rp)
      local value = values[w] or values[format_reference(w)]
      if not value then
        error("no constant defined for " .. w .. " in " .. token)
      end
      if not value.replaced then value.replaced = replace_dollars(value.raw) end
      return value.replaced .. (#lp == 0 and rp or "")
    end)
  else
    return token
  end
end
local function is_lower_byte(s, i)
  local b = s:byte(i, i)
  return b > 96 and b < 123
end
local function scan_file()
  local id = nil
  local body = nil
  local def = nil
  local line_num = nil
  local count = 0
  local is_value = nil
  local rules = nil
  local function savetoken(clear)
    if id and body and is_value then
      values[id] = { raw = table.concat(body, " ") }
    elseif id and body and def then
      local full_body = table.concat(body, " ")
      local start, _, literal = id:find("%[([a-z])]")
      if literal then
        id = format_reference(literal .. id:sub(4))
      else
        if hidden and rules and is_lower_byte(id, 1) then
          id = "_" .. format_reference(id)
        else
          id = format_reference(id)
        end
      end
      table.insert(tokens, { id, full_body , rules })
      tokenmap[id] = { def, line_num, math.max(count - 1, line_num) }
    end
    id = nil
    body = nil
    def = nil
    line_num = nil
    is_value = nil
  end
  for line in io.lines(file) do
    count = count + 1
    local is_comment = line:find("%s*;") == 1
    if line == "rules:" then
      rules = true
    elseif #line == 0 then
      savetoken(true)
    elseif is_comment then
      if def then table.insert(def, line) end
    else
      local leading = "[%w_%[%]]"
      local prefix = leading .. leading .. "?" .. leading .. "?"
      local s, _, i, a, b = line:find("(" .. prefix .. "[%w_.]*)%s*(:?:=)%s*(.*)")
      local is_beginning = not rules and s == 1
      if not is_beginning then
        local ss, e = line:find("  " .. leading)
        is_beginning = ss == 1 and e == s
      end
      if is_beginning then
        savetoken()
        is_value = a == ":="
        line_num = count
        id = i
        body = { b }
        def = { line }
      else
        assert(def, line .. tostring(is_beginning))
        table.insert(def, line)
        local rest = line:match("%s+(.*)")
        if rest then
          if body then
            if #rest > 0 then
              table.insert(body, rest .. "\n")
            else
              savetoken()
            end
          else
            error("Error: declarations must be aligned in the left-most column")
          end
        end
      end
    end
  end
  savetoken()
end
scan_file()

local contextFree = {}

local char = string.char
local SPACE = 0x20
local DOUBLE_QUOTE = 0x22
local SINGLE_QUOTE = 0x27
local LEFT_ANGLE = 0x3c
local RIGHT_ANGLE = 0x3e
local LEFT_PARENS = 0x28
local RIGHT_PARENS = 0x29
local LEFT_BRACKET = 0x5b
local RIGHT_BRACKET= 0x5d
local FORWARD_SLASH = 0x2f
local BACK_SLASH = 0x5c
local PIPE = 0x7c
local QUESTION_MARK = 0x3f
local PLUS = 0x2b
local TIMES = 0x2a
local NEWLINE = 0x0a
local SEMI = 0x3b
local LEFT_CURLY_BRACKET = 0x7b
local RIGHT_CURLY_BRACKET = 0x7d
local COLON = 0x3a

local NONE = 0
local IN_GROUP = NONE + 1
local IN_CHOICE = IN_GROUP + 1
local IN_ARRAY = IN_CHOICE + 1
local IN_ALIAS = IN_ARRAY + 1
local IN_FIELD = IN_ALIAS + 1
local _IN_CHAR_GROUPING = IN_FIELD + 1
local IN_DOUBLE_QUOTE = _IN_CHAR_GROUPING +  1
local IN_SINGLE_QUOTE = IN_DOUBLE_QUOTE + 1
local IN_COMMENT = IN_SINGLE_QUOTE + 1
local _ANY_REGEX = IN_COMMENT + 1
local IN_REGEX = _ANY_REGEX + 1
local IN_MINI_REGEX = IN_REGEX + 1
local function stateToString(state)
    return ((state == NONE and "NONE") or
    (state == IN_GROUP and "IN_GROUP") or
    (state == IN_CHOICE and "IN_CHOICE") or
    (state == IN_ARRAY and "IN_ARRAY") or
    (state == IN_ALIAS and "IN_ALIAS") or
    (state == IN_FIELD and "IN_FIELD") or
    (state == IN_DOUBLE_QUOTE and "IN_DOUBLE_QUOTE") or
    (state == IN_SINGLE_QUOTE and "IN_SINGLE_QUOTE") or
    (state == IN_COMMENT and "IN_COMMENT") or
    (state == IN_REGEX and "IN_REGEX") or
    (state == IN_MINI_REGEX and "IN_MINI_REGEX") or "UNKNOWN")
    .. "(" .. state .. ")"
end

local NO_PRECEDENCE = 0
local LEFT_ASSOCIATIVE = "<"
local RIGHT_ASSOCIATIVE = ">"
local DYNAMIC = "~"

local ROOT = "root"
local CHOICE = "choice"
local ALIAS = "alias"
local SEQUENCE = "sequence"
local ARRAY = "array"
local LITERAL = "literal"
local REFERENCE = "reference"
local REPEAT_AT_LEAST_ONCE = "repeat1"
local REPEAT = "repeat"
local OPTIONAL = "optional"
local MULTI_CHOICE = "multi_choice"
local PRECEDENCE = "precedence"
local IMMEDIATE = "immediate"
local TOKEN = "token"
local FIELD = "field"

local function new_sequence(precedence)
  return { sequence = {}, precedence = precedence or 0, kind = SEQUENCE }
end
local function new_node(kind)
  return { kind = kind, children = {} }
end
local function add_literal(node, current_word)
  table.insert(node.children, { children = { table.concat(current_word) }, kind = LITERAL })
end
local function add_reference(node, reference)
  table.insert(node.children, { children = { reference }, kind = REFERENCE })
end
local function repeat_last(node, kind)
  local to_repeat = table.remove(node.children)
  table.insert(node.children, { children = { to_repeat }, kind = kind })
end

local function print_node(n, offset, max_width)
  max_width = max_width or 80
  local function impl(n, offset)
    local output = {}
    local function write(s) table.insert(output, s) end
    local function write_function_with_delims(left, right, handle_children)
      write(left)
      local parts, multi_line = handle_children(left, 2 + offset)
      if type(parts) ~= "table" then parts = { parts } end
      if not multi_line then
        local total_len = -2 -- account for no trailing ', '
        for _, p in ipairs(parts) do total_len = total_len + #p + 2 end
        multi_line = total_len > max_width
      end
      local sep = multi_line and ",\n" or ", "
      local offset_str = multi_line and "  "
      if multi_line then write("\n") end
      for i, part in ipairs(parts) do
        if multi_line then
          local lines = {}
          for line in part:gmatch("([^\n]+)") do table.insert(lines, line) end
          for j, line in ipairs(lines) do
            write("  " .. line)
            if j < #lines then write("\n") end
          end
        else
          write(part)
        end
        if i < #parts then write(sep) end
      end
      if multi_line then write("\n") end
      write(right)
      return table.concat(output), multi_line
    end
    local function write_function(name, handle_children)
      return write_function_with_delims(name .. "(", ")", handle_children)
    end
    local function handle_children(node)
      return function(outer, new_offset)
        if outer == "seq(" or outer == "choice(" or outer == "["
            or outer:find("token") or outer == "alias(" or outer == "field(" then
          local parts = {}
          local multi_line = false
          for _, n in ipairs(node.children) do
            if type(n) == "table" then
              value, ml = impl(n, new_offset)
            else
              ml = #value > new_offset
            end
            multi_line = multi_line or ml
            table.insert(parts, value)
          end
          return parts, multi_line
        else
          local result, multi_line = impl(node, new_offset)
          return { result }, multi_line
        end
      end
    end
    local function write_function_with_args(name, node)
      return write_function(name, handle_children(node))
    end
    local function write_repeat(kind, node)
      return write_function(kind, function(outer, new_offset)
        return impl(n.children[1], new_offset)
      end)
    end
    local function write_precedence(name, precedence, next_node)
      return write_function(name, function(outer, new_offset)
        local parts, multi_line = handle_children(next_node)(outer, new_offset)
        if precedence then
          table.insert(parts, 1, tostring(precedence))
        end
        return parts, multi_line
      end)
    end
    offset = offset or 0
    local max_width = max_width - offset

    if n.kind == SEQUENCE or n.kind == ROOT then
      local len = #n.children
      if len == 0 then error("empty sequence") end
      return write_function_with_args("seq", n)
    elseif n.kind == LITERAL then
      return n.children[1], #n.children[1] > max_width
    elseif n.kind == REFERENCE then
      local result = "$." .. n.children[1]
      return result, #result > max_width
    elseif n.kind == REPEAT_AT_LEAST_ONCE then
      write_repeat(REPEAT_AT_LEAST_ONCE)
    elseif n.kind == REPEAT then
      write_repeat(REPEAT)
    elseif n.kind == OPTIONAL then
      write_repeat(OPTIONAL)
    elseif n.kind == CHOICE then
      return write_function_with_args(CHOICE, { kind = SEQUENCE, children = n.children })
    elseif n.kind == IMMEDIATE then
      return write_function_with_args("token.immediate", { kind = SEQUENCE, children = n.children })
    elseif n.kind == TOKEN then
      return write_function_with_args("token", { kind = SEQUENCE, children = n.children })
    elseif n.kind == PRECEDENCE then
      local modifier, next_node = unpack(n.children)
      local prec = tonumber(modifier:match("([-0-9]+)"))
      local assoc = modifier:match("([<>~])")
      local immediate = modifier:match("([%!])")
      local func =
        (assoc == LEFT_ASSOCIATIVE and "prec.left") or
        (assoc == RIGHT_ASSOCIATIVE and "prec.right") or
        (assoc == DYNAMIC and "prec.dynamic") or
        "prec"
      write_precedence(func, prec, next_node)
    elseif n.kind == ARRAY then
      write_function_with_delims("[", "]", handle_children(n.children[1]))
    elseif n.kind == ALIAS then
      return write_function_with_args("alias", { kind = ALIAS, children = n.children })
    elseif n.kind == FIELD then
      return write_function_with_args("field", { kind = FIELD, children = n.children })
    else
      error("unknown kind: " .. (n.kind or "nil"))
    end
    return table.concat(output)
  end
  local res = impl(n, offset) -- drop multi_line flag
  return res
end

local function flatten(n, string)
  local function impl(n, result)
    local function flatten_repeat(n, result, kind)
      local opt_node = new_node(kind)
      table.insert(opt_node.children, impl(n.children[1], opt_node))
      table.insert(result.children, opt_node)
    end
    if n.kind == SEQUENCE or n.kind == ROOT then
      local seq = result
      local len = #n.children
      if len == 0 then error("empty sequence in " .. tostring(string)) end
      if len > 1 then
        if n.kind == SEQUENCE then
          seq = new_node(SEQUENCE)
          table.insert(result.children, seq)
        end
        for i, v in ipairs(n.children) do
          impl(v, seq)
        end
      else
        impl(n.children[1], seq)
      end
    elseif n.kind == LITERAL then
      table.insert(result.children, { children = { n.children[1] }, kind = LITERAL })
    elseif n.kind == REFERENCE then
      add_reference(result, n.children[1])
    elseif n.kind == REPEAT_AT_LEAST_ONCE then
      flatten_repeat(n, result, REPEAT_AT_LEAST_ONCE)
    elseif n.kind == REPEAT then
      flatten_repeat(n, result, REPEAT)
    elseif n.kind == OPTIONAL then
      flatten_repeat(n, result, OPTIONAL)
    elseif n.kind == CHOICE then
      local node = new_node(CHOICE)
      local children = {}
      for _, v in ipairs(n.children) do table.insert(children, flatten(v, string)) end
      for _, v in ipairs(children) do
        if v.kind == CHOICE then
          for _, cn in ipairs(v.children) do table.insert(node.children, cn) end
        else
          table.insert(node.children, v)
        end
      end
      table.insert(result.children, node)
    elseif n.kind == PRECEDENCE then
      local p, next_node = unpack(n.children)
      local node = new_node(PRECEDENCE)
      table.insert(node.children, p)
      table.insert(node.children, flatten(next_node, string))
      table.insert(result.children, node)
    elseif n.kind == ARRAY then
      table.insert(result.children, n)
    elseif n.kind == IMMEDIATE then
      local immediate = new_node(IMMEDIATE)
      for _, c in ipairs(n.children) do
        table.insert(immediate.children, flatten(c))
      end
      table.insert(result.children, immediate)
    elseif n.kind == TOKEN then
      local token = new_node(TOKEN)
      for _, c in ipairs(n.children) do
        table.insert(token.children, flatten(c))
      end
      table.insert(result.children, token)
    elseif n.kind == ALIAS then
      local alias = new_node(ALIAS)
      for _, c in ipairs(n.children) do table.insert(alias.children, flatten(c)) end
      table.insert(result.children, alias)
    elseif n.kind == FIELD then
      local field = new_node(FIELD)
      for _, c in ipairs(n.children) do table.insert(field.children, flatten(c)) end
      table.insert(result.children, field)
    else
      error("unknown kind: " .. (n.kind or "nil"))
    end
    return n.kind
  end
  local result = new_node(ROOT)
  impl(n, result, ROOT)
  return #result.children == 1 and result.children[1] or result
end

local function source_error(comment, source_info)
  local msg = comment .. " in"
  .. " rule '" .. source_info.lhs .. "' defined at line " .. source_info.start_line
  .. "\n" .. source_info.rhs
  print(msg)
  error("")
end
local function maybe_add_reference_impl(node, current_word, externals, source_info, alias)
  local id = format_reference(table.concat(current_word))
  local init_id = id
  id = tokenmap[id] and id or (tokenmap["_" .. id] and "_" .. id)
  if alias then
    add_reference(node, init_id)
  elseif id then
    add_reference(node, id)
  elseif externals then
    local ref_id = format_reference(table.concat(current_word))
    tokenmap[ref_id] = true
    add_reference(node, ref_id)
  else
    source_error("no reference exists for " .. table.concat(current_word), source_info)
  end
end

local function parse_body(id, string)
  local externals = id == "externals"
  local bytes = { string:byte(1, -1) }
  local node_stack = { new_node(ROOT) }
  local last_byte = nil
  local current_word = {}
  local state_stack = { NONE }
  local _, start_line, end_line = unpack(tokenmap[id])
  local source_info = {
    lhs = id,
    rhs = string,
    start_line = start_line
  }
  local function maybe_add_alias_or_field(state)
    state = state or state_stack[#state_stack]
    if state == IN_ALIAS or state == IN_FIELD then
      local alias_node = table.remove(node_stack)
      local top_node = node_stack[#node_stack]
      local children = top_node.children
      local index = (state == IN_FIELD and 1) or 2
      table.insert(top_node.children[#top_node.children].children, index, alias_node)
      table.remove(state_stack)
    end
  end
  for _, b in ipairs(bytes) do
    local state = state_stack[#state_stack]
    local node = node_stack[#node_stack]
    local function handle_alias_or_field()
      if current_word then
        local state = state_stack[#state_stack]
        local alias = state == IN_ALIAS
        if current_word and alias then
          maybe_add_reference_impl(node_stack[#node_stack], current_word, externals, source_info, alias)
        elseif current_word and state == IN_FIELD then
          table.insert(current_word, 1, "'")
          table.insert(current_word, "'")
          add_literal(node_stack[#node_stack], current_word)
        end
        maybe_add_alias_or_field(state)
        current_word = nil
      end
    end
    local function maybe_add_reference(state)
      local alias = state == IN_ALIAS
      if current_word then
        maybe_add_reference_impl(node, current_word, externals, source_info, alias)
      elseif state == IN_FIELD then
        add_literal(node, current_word)
      end
      current_word = nil
    end
    if (b == SPACE or b == NEWLINE) and state < _IN_CHAR_GROUPING then
      local word = current_word and table.concat(current_word)
      local kind = (word == "->" and ALIAS) or (word == ":" and FIELD)
      if kind then
        local to_alias = table.remove(node.children)
        table.insert(node.children, { children = { to_alias }, kind = kind })
        table.insert(state_stack, kind == ALIAS and IN_ALIAS or IN_FIELD)
        table.insert(node_stack, new_node(SEQUENCE))
        current_word = nil
      else
        if state == IN_FIELD or state == IN_ALIAS then
          handle_alias_or_field()
        elseif word then
          maybe_add_reference(state)
          maybe_add_alias_or_field(state)
        end
      end
    elseif b == DOUBLE_QUOTE and state ~= IN_SINGLE_QUOTE and state < _ANY_REGEX then
      if state == IN_DOUBLE_QUOTE then
        table.insert(current_word, '"')
        add_literal(node, current_word)
        current_word = nil
        table.remove(state_stack)
        maybe_add_alias_or_field()
      else
        table.insert(state_stack, IN_DOUBLE_QUOTE)
        current_word = { '"' }
      end
    elseif b == SINGLE_QUOTE and state ~= IN_DOUBLE_QUOTE and state < _ANY_REGEX then
      if state == IN_SINGLE_QUOTE then
        table.insert(current_word, "'")
        add_literal(node, current_word)
        current_word = nil
        table.remove(state_stack)
        maybe_add_alias_or_field()
      else
        table.insert(state_stack, IN_SINGLE_QUOTE)
        current_word = { "'" }
      end
    elseif b == FORWARD_SLASH and state < _IN_CHAR_GROUPING then
      table.insert(state_stack, IN_REGEX)
      current_word = { "/" }
    elseif b == FORWARD_SLASH and state == IN_REGEX and state ~= IN_MINI_REGEX and last_byte ~= BACK_SLASH then
      table.insert(current_word, "/")
      add_literal(node, current_word)
      current_word = nil
      table.remove(state_stack)
    elseif b == LEFT_CURLY_BRACKET and state < _IN_CHAR_GROUPING  then
      current_word = nil
      local array = new_node(ARRAY)
      local next_node = new_node(SEQUENCE)
      table.insert(array.children, next_node)
      table.insert(node.children, array)
      table.insert(node_stack, next_node)
      table.insert(state_stack, IN_ARRAY)
    elseif b == RIGHT_CURLY_BRACKET and state == IN_ARRAY then
      maybe_add_reference()
      table.remove(node_stack)
      local prev_state = table.remove(state_stack)
      while prev_state == IN_CHOICE do
        prev_state = table.remove(state_stack)
        table.remove(node_stack)
      end
    elseif b == LEFT_BRACKET and (state < _IN_CHAR_GROUPING or state == IN_REGEX)  then
      table.insert(state_stack, IN_MINI_REGEX)
      if state ~= IN_REGEX then
        current_word = { "/[" }
      elseif current_word then
        table.insert(current_word, "[")
      end
    elseif b == RIGHT_BRACKET and state == IN_MINI_REGEX then
      local len = current_word and #current_word or 0
      local last = current_word and current_word[len]
      local tail = len > 1 and table.concat({ current_word[len - 1], current_word[len] })
      table.insert(current_word, "]")
      if last ~= "\\" or tail == "\\\\" then
        table.remove(state_stack)
        if state_stack[#state_stack] ~= IN_REGEX then
          table.insert(current_word, "/")
          add_literal(node, current_word)
          current_word = nil
        end
      end
    elseif b == LEFT_PARENS and state < _IN_CHAR_GROUPING then
      local modifier = current_word and table.concat(current_word) or ""
      current_word = nil
      local next_node = new_node(SEQUENCE)
      local prec = nil
      local is_immediate = false
      local immediate = nil
      local token = nil
      local is_token = false
      modifier = modifier:gsub("!", function(i) is_immediate = true; return "" end)
      modifier = modifier:gsub("[%@]", function(i) is_token = true; return "" end)
      if #modifier > 0 then
        prec = new_node(PRECEDENCE)
        table.insert(prec.children, modifier)
        table.insert(prec.children, next_node)
      end
      if is_immediate then
        immediate = new_node(IMMEDIATE)
        table.insert(immediate.children, prec or next_node)
      end
      if is_token then
        token = new_node(TOKEN)
        table.insert(token.children, immediate or prec or next_node)
      end
      local nn = prec or immediate or token or next_node
      table.insert(node.children, prec or immediate or token or next_node)
      table.insert(node_stack, next_node)
      table.insert(state_stack, IN_GROUP)
    elseif b == RIGHT_PARENS and state == NONE then
      source_error("unmatched right parens", source_info)
    elseif b == RIGHT_PARENS and (state == IN_GROUP or state == IN_CHOICE) then
      maybe_add_reference()
      table.remove(node_stack)
      local prev_state = table.remove(state_stack)
      while prev_state == IN_CHOICE do
        prev_state = table.remove(state_stack)
        table.remove(node_stack)
      end
    elseif b == RIGHT_PARENS and (state == IN_ALIAS or state == IN_FIELD) then
      handle_alias_or_field()
      table.remove(node_stack)
      local prev_state = table.remove(state_stack)
      while prev_state == IN_CHOICE do
        prev_state = table.remove(state_stack)
        table.remove(node_stack)
      end
    elseif b == PIPE and (state == NONE or state == IN_GROUP or state == IN_CHOICE) then
      local seq = node.children
      if #seq == 0 then
        source_error("must have element to left of choice", source_info)
      end
      local choice_node = new_node(SEQUENCE)
      table.insert(state_stack, IN_CHOICE)
      table.insert(node_stack, choice_node)
      local left, right = new_node(SEQUENCE), new_node(SEQUENCE)
      left.children = seq
      right.children = { choice_node }

      node.children = { { kind = CHOICE, children = { left, right } } }
    elseif state < _IN_CHAR_GROUPING and (b == PLUS or b == TIMES or b == QUESTION_MARK) then
      maybe_add_reference()
      assert(#node.children >= 1, "no modifiers allowed for empty sequence")
      local kind =
        (b == PLUS and REPEAT_AT_LEAST_ONCE)
        or (b == TIMES and REPEAT)
        or (b == QUESTION_MARK and OPTIONAL)
      repeat_last(node, kind)
    elseif b == COLON and state < _IN_CHAR_GROUPING then
      maybe_add_reference()
      local field = table.remove(node.children)
      table.insert(node.children, { children = { field }, kind = FIELD })
      table.insert(state_stack, IN_FIELD)
      table.insert(node_stack, new_node(SEQUENCE))
      current_word = nil
    elseif b == SEMI and state < _IN_CHAR_GROUPING then
      table.insert(state_stack, IN_COMMENT)
    elseif b == NEWLINE and state == IN_COMMENT then
      table.remove(state_stack)
    elseif state == IN_COMMENT then
    else
      if not current_word then
        current_word = { char(b) }
      else
        table.insert(current_word, char(b))
      end
    end
    last_byte = b
  end
  if current_word then
    local state = state_stack[#state_stack]
    local alias = state == IN_ALIAS
    if current_word and state ~= IN_FIELD then
      maybe_add_reference_impl(node_stack[#node_stack], current_word, externals, source_info, alias)
    elseif current_word and state == IN_FIELD then
      table.insert(current_word, 1, "'")
      table.insert(current_word, "'")
      add_literal(node_stack[#node_stack], current_word)
    end
    maybe_add_alias_or_field(state)
    current_word = nil
  end
  while #state_stack > 1 do
    local removed = table.remove(state_stack)
    assert(removed == IN_CHOICE or removed == IN_COMMENT,
      "unexpected state for " .. string .. ": " .. stateToString(removed))
    if removed == IN_CHOICE then table.remove(node_stack) end
  end
  assert(#node_stack == 1, "unbalanced node stack for (" .. string .. ")")
  return print_node(flatten(table.remove(node_stack), string))

end

local rule_defs = {}

for _, v in ipairs(tokens) do
  local id, body, in_rules = unpack(v)
  local replaced = replace_dollars(body)
  local tree_sitter_body = {}
  local parsed = parse_body(id, replaced)
  local base_indent = in_rules and "    " or "  "
  local def = { base_indent .. id .. ": $ => " }
  for line in parsed:gmatch("([^\n]*)") do table.insert(tree_sitter_body, line) end
  if #tree_sitter_body == 1 then
    table.insert(def, table.remove(tree_sitter_body))
  else
    local indent = def[1]:gsub(".", " ")
    for i, line in ipairs(tree_sitter_body) do
      local new_indent = i > 1 and indent or ""
      table.insert(def, new_indent .. line)
      if i < #tree_sitter_body then table.insert(def, "\n") end
    end
  end
  local full_body, start_line, end_line = unpack(tokenmap[id])
  local line_num = start_line .. ((start_line == end_line and "") or ("-" .. end_line))
  local index = file .. ":" .. line_num
  local prefix = { base_indent .. "/*", base_indent .. " * " .. index }
  for i, b in ipairs(full_body) do
    local start, space_end = b:find("%s+")
    if start == 1 then b = b:sub(start + 2) end
    table.insert(prefix, base_indent .. " * " .. b:gsub("*/", "*∕")) -- this adds a unicode division sign
  end
  prefix = table.concat(prefix, "\n") .. "\n" .. base_indent .. " */\n"
  table.insert(def, 1, prefix)

  table.insert(in_rules and rule_defs or contextFree, table.concat(def))
end

table.insert(contextFree, "  rules: {\n" .. table.concat(rule_defs, ",\n") .. "\n  }\n")
local name = file:gsub(".ebnf", "")
local slash_index = name:find("/")
while slash_index do
  name = name:sub(slash_index + 1)
  slash_index = name:find("/")
end
local constants = {}
for k, v in pairs(values) do
  table.insert(constants, { k, v })
end
table.sort(constants, function(a, b) return a[1] < b[1] end)
local max_key_len = 0
for _, c in ipairs(constants) do max_key_len = math.max(max_key_len, #c[1]) end
local key_padding = max_key_len + 2
local constants_comment = { "/*", " * inline constants: " }
for _, c in ipairs(constants) do
  local key, value = unpack(c)
  local padding = ""
  for i = #key, key_padding do padding = padding .. " " end
  local base = key .. padding .. ":= " .. value.raw:gsub("*/", "*∕")
  table.insert(constants_comment, " * " .. base)
  if not value.replaced then error(key .. " is unused") end
  if value.replaced ~= value.raw then
    table.insert(constants_comment, " *     (" .. value.replaced:gsub("*/", "*∕") .. ")")
  end
end
table.insert(constants_comment, " */")

local content = [[
// This file was autogenerated by parse_grammar.lua from ]] .. file .. [[.

]] .. table.concat(constants_comment, "\n") .. [[


module.exports = grammar({
  name: ']] .. name .. [[',

]] .. table.concat(contextFree, ",\n") .. [[
});
]]
if output_file then
  print("writing to " .. output_file)
  io.open(output_file, "w"):write(content)
end
if not quiet and verbose then print(content) end
