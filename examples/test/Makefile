
.PHONY: all test
all: test

grammar.js: test.ebnf ../../src/lua/parse_grammar.lua
	../../src/lua/parse_grammar.lua -o grammar.js $(VERBOSE) test.ebnf

src/grammar.json: grammar.js
	tree-sitter generate

test: src/grammar.json $(wildcard *.ebnf)
	tree-sitter test $(DEBUG) $(TEST_FLAG) $(TEST_FILTER)
