
.PHONY: all test
all: test

grammar.js: scala.ebnf ../../src/lua/parse_grammar.lua
	../../src/lua/parse_grammar.lua -o grammar.js $(VERBOSE) scala.ebnf

src/grammar.json: grammar.js
	tree-sitter generate

.corpus_files: $(wildcard *.ebnf)
	touch .corpus_files

test: src/grammar.json .corpus_files
	tree-sitter test $(DEBUG) $(TEST_FLAG) $(TEST_FILTER)
