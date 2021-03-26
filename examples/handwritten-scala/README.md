tree-sitter-scala
=================

[![Test the grammar](https://github.com/tree-sitter/tree-sitter-scala/actions/workflows/ci.yml/badge.svg)](https://github.com/tree-sitter/tree-sitter-scala/actions/workflows/ci.yml)

This is a fork of the
Scala grammar for [tree-sitter](https://github.com/tree-sitter/tree-sitter). It
uses the EBNF syntax in
[tree-sitter-ebnf-grammar](https://github.com/eatkins/tree-sitter-ebnf-generator)
rather than the built in grammar.js.

References

* [The Scala Language Specification](https://www.scala-lang.org/files/archive/spec/2.13/)
* [Scala Syntax Summary](https://www.scala-lang.org/files/archive/spec/2.13/13-syntax-summary.html)

Development
-----------

First, install the project's dependencies:

```sh
npm install
```


Add a test case to `./corpus`, make the required changes to `grammar.js`,
regenerate and recompile the parser, and run the tests:

```sh
./script/test.sh
```

The [test script](script/test.sh) has an optional flag `-w` that will put it
into a continuous mode in which it waits for change to the source files, which
include [scala.ebnf](scala.ebnf), [src/scanner.c](src/scanner.c) and the
[parse_grammer.lua](../../src/lua/parse_grammar.lua) script that converts the
scala.ebnf file into a grammar.js file. The test script also supports filtering
tests with the usual -f flag in the `tree-sitter test` runner. This allows for
rapid incremental development of the grammar.
