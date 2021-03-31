.PHONY: all test
all: test

grammar.js: scala.ebnf ../../src/lua/parse_grammar.lua
	../../src/lua/parse_grammar.lua -o grammar.js scala.ebnf

src/grammar.json: grammar.js
	tree-sitter generate
	#node-gyp build

test: src/grammar.json $(wildcard *.ebnf)
	tree-sitter test $(DEBUG) $(TEST_FLAG) $(TEST_FILTER)
	if [ -z "$(TEST_FLAG)" ]; then tree-sitter parse examples/**.scala --quiet --time; fi
