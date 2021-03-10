#include <tree_sitter/parser.h>
#include <wctype.h>
#include <stdio.h>
#include <assert.h>

enum TokenType {
  MULTI_COMMENT
};

void *tree_sitter_scala_external_scanner_create() { return NULL; }
void tree_sitter_scala_external_scanner_destroy(void *p) {}
void tree_sitter_scala_external_scanner_reset(void *p) {}
unsigned tree_sitter_scala_external_scanner_serialize(void *p, char *buffer) { return 0; }
void tree_sitter_scala_external_scanner_deserialize(void *p, const char *b, unsigned n) {}

static bool recursive_scan_comment(TSLexer *lexer) {
  lexer->result_symbol = MULTI_COMMENT;
  int comment_count = 0;
  int prev_char = 0;
  while(lexer->lookahead != 0) {
    if (prev_char == '/' && lexer->lookahead == '*') {
      comment_count += 1;
      prev_char = 0;
    } else if (prev_char == '*' && lexer->lookahead == '/') {
      if (comment_count == 0) return true;
      comment_count -= 1;
      prev_char = 0;
    } else {
      prev_char = lexer->lookahead;
    }
    lexer->mark_end(lexer);
    lexer->advance(lexer, false);
  }
  return false;
}

bool tree_sitter_scala_external_scanner_scan(void *payload, TSLexer *lexer,
                                             const bool *valid_symbols) {
  if (valid_symbols[MULTI_COMMENT] && recursive_scan_comment(lexer)) return true;
  return false;
}
