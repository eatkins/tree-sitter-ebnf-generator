.PHONY: all test
all: test

test.ebnf: test-grammar.js ../tree-sitter-to-ebnf.js
	../tree-sitter-to-ebnf.js $< > $@
	cat test.ebnf

grammar.js: test.ebnf ../../lua/parse_grammar.lua
	../../lua/parse_grammar.lua -o $@ -s $<

src/grammar.json: grammar.js src/scanner.c
	tree-sitter generate

test: src/grammar.json $(wildcard corpus/*.txt)
	tree-sitter test $(TEST_FLAG) $(TEST_FILTER)
