.PHONY: all test
all: test

grammar.js: scala.ebnf ../../src/lua/parse_grammar.lua Makefile
	../../src/lua/parse_grammar.lua -o grammar.js --hide-lower-case scala.ebnf

src/grammar.json: grammar.js
	tree-sitter generate

test: src/grammar.json $(wildcard *.ebnf)
	tree-sitter test $(DEBUG) $(TEST_FLAG) $(TEST_FILTER)
