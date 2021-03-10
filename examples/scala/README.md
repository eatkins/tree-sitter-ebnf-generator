Defines a [tree-sitter](https://tree-sitter.github.io/tree-sitter/) grammar for
the [scala](https://www.scala-lang.org) programming language. The tree-sitter
grammar is automatically generated from [scala.ebnf](scala.ebnf) using the lua
[parse_grammar script](../../src/lua/parse_grammar.lua). The grammar is adapted
from https://www.scala-lang.org/files/archive/spec/2.13/13-syntax-summary.html.
There is an included [vim script](script/vim/convert_ebnf.vim) for converting
the grammar defined in the scala EBNF format to the format recognized by
`parse_grammar.lua`. To use it, source the file in vim and then it should be
possible to convert lines by selecting them in visual mode and typing `:`
followed by CE (convert ebnf).
