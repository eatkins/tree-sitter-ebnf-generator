#include <tree_sitter/parser.h>
#include <wctype.h>
#include <stdio.h>

enum TokenType {
  AUTOMATIC_SEMICOLON,
  SIMPLE_STRING,
  SIMPLE_MULTILINE_STRING,
  INTERPOLATED_STRING_MIDDLE,
  INTERPOLATED_STRING_END,
  INTERPOLATED_MULTILINE_STRING_MIDDLE,
  INTERPOLATED_MULTILINE_STRING_END,
};

typedef struct keyword {
  int len;
  const char *word;
} keyword;
#define MAKE_KEYWORD(a, b) static keyword a = { sizeof(b) - 1, b }

MAKE_KEYWORD(ELSE, "else");
MAKE_KEYWORD(CATCH, "catch");
MAKE_KEYWORD(EXTENDS, "extends");
MAKE_KEYWORD(FINALLY, "finally");
MAKE_KEYWORD(FORSOME, "forSome");
MAKE_KEYWORD(MATCH, "match");
MAKE_KEYWORD(WITH, "with");
MAKE_KEYWORD(YIELD, "yield");
MAKE_KEYWORD(COMMA, ";");
MAKE_KEYWORD(PERIOD, ".");
MAKE_KEYWORD(SEMICOLON, ";");
MAKE_KEYWORD(COLON, ":");
MAKE_KEYWORD(EQUALS, "=");
MAKE_KEYWORD(RIGHT_ARROW, "=>");
MAKE_KEYWORD(LEFT_ARROW, "<-");
MAKE_KEYWORD(COVARIANT_TYPE_BOUND, "<:");
MAKE_KEYWORD(VIEW_BOUND, "<%");
MAKE_KEYWORD(CONTRAVARIANT_TYPE_BOUND, ">:");
MAKE_KEYWORD(POUND, "#");
MAKE_KEYWORD(LEFT_BRACKET, "[");
MAKE_KEYWORD(RIGHT_PARENS, ")");
MAKE_KEYWORD(RIGHT_BRACKET, "]");
MAKE_KEYWORD(RIGHT_CURLY, "}");

static keyword* invalid_begin_strings[] = {
  &ELSE,
  &CATCH,
  &EXTENDS,
  &FINALLY,
  &FORSOME,
  &MATCH,
  &WITH,
  &YIELD,
  &COMMA,
  &PERIOD,
  &SEMICOLON,
  &COLON,
  &EQUALS,
  &RIGHT_ARROW,
  &LEFT_ARROW,
  &COVARIANT_TYPE_BOUND,
  &VIEW_BOUND,
  &CONTRAVARIANT_TYPE_BOUND,
  &POUND,
  &LEFT_BRACKET,
  &RIGHT_PARENS,
  &RIGHT_BRACKET,
  &RIGHT_CURLY
};

void *tree_sitter_scala_external_scanner_create() { return NULL; }
void tree_sitter_scala_external_scanner_destroy(void *p) {}
void tree_sitter_scala_external_scanner_reset(void *p) {}
unsigned tree_sitter_scala_external_scanner_serialize(void *p, char *buffer) { return 0; }
void tree_sitter_scala_external_scanner_deserialize(void *p, const char *b, unsigned n) {}

static void advance(TSLexer *lexer) { lexer->advance(lexer, false); }

static bool scan_string_content(TSLexer *lexer, bool is_multiline, bool has_interpolation) {
  unsigned closing_quote_count = 0;
  for (;;) {
    if (lexer->lookahead == '"') {
      advance(lexer);
      closing_quote_count++;
      if (!is_multiline) {
        lexer->result_symbol = has_interpolation ? INTERPOLATED_STRING_END : SIMPLE_STRING;
        return true;
      }
      if (closing_quote_count == 3) {
        lexer->result_symbol = has_interpolation ? INTERPOLATED_MULTILINE_STRING_END : SIMPLE_MULTILINE_STRING;
        return true;
      }
    } else if (lexer->lookahead == '$') {
      if (is_multiline && has_interpolation) {
        lexer->result_symbol =  INTERPOLATED_MULTILINE_STRING_MIDDLE;
        return true;
      } else if (has_interpolation){
        lexer->result_symbol = INTERPOLATED_STRING_MIDDLE;
        return true;
      } else {
        advance(lexer);
      }
    } else {
      closing_quote_count = 0;
      if (lexer->lookahead == '\\') {
        advance(lexer);
        if (lexer->lookahead != 0) advance(lexer);
      } else if (lexer->lookahead == '\n') {
        if (is_multiline) {
          advance(lexer);
        } else {
          return false;
        }
      } else if (lexer->lookahead == 0) {
        return false;
      } else {
        advance(lexer);
      }
    }
  }
}

bool tree_sitter_scala_external_scanner_scan(void *payload, TSLexer *lexer,
                                             const bool *valid_symbols) {
  unsigned newline_count = 0;
  while (iswspace(lexer->lookahead)) {
    if (lexer->lookahead == '\n') newline_count++;
    lexer->advance(lexer, true);
  }

  if (valid_symbols[AUTOMATIC_SEMICOLON] && newline_count > 0) {
    lexer->mark_end(lexer);
    lexer->result_symbol = AUTOMATIC_SEMICOLON;

    if (newline_count > 1) return true;

    int active_count = sizeof(invalid_begin_strings) / sizeof(keyword*);
    int active_automata[active_count];
    for (int i = 0; i < active_count; ++i) active_automata[i] = i;
    int chars_read = 0;
    int next_char = lexer->lookahead;
    while (chars_read < 8 && next_char) {
      int current_char = next_char;
      int char_index = chars_read++;
      next_char = 0;
      int active_index = 0;
      int new_active_count = 0;
      for (int i = 0; i < active_count; ++i) {
        int invalid_index = active_automata[i];
        keyword *word = invalid_begin_strings[invalid_index];
        if (word->word[char_index] == current_char) {
          if (chars_read == word->len) {
            if (next_char == 0) {
              lexer->advance(lexer, false);
              next_char = lexer->lookahead;
            }
            if (iswspace(next_char)) return false; // a word that cannot start a statement was found
            else if (chars_read == 1 && current_char == '.') {
              // could be a floating point literal
              lexer->advance(lexer, false);
              return lexer->lookahead >= '0' && lexer->lookahead <= '9';
            }
          } else {
            active_automata[active_index++] = active_automata[invalid_index];
            new_active_count++;
          }
        }
      }
      active_count = new_active_count;
      if (next_char == 0) {
        lexer->advance(lexer, false);
        if (!iswspace(lexer->lookahead)) { next_char = lexer->lookahead; }
      }
    }
    return true;
  }

  while (iswspace(lexer->lookahead)) {
    if (lexer->lookahead == '\n') newline_count++;
    lexer->advance(lexer, true);
  }

  if (valid_symbols[SIMPLE_STRING] && lexer->lookahead == '"') {
    advance(lexer);

    bool is_multiline = false;
    if (lexer->lookahead == '"') {
      advance(lexer);
      if (lexer->lookahead == '"') {
        advance(lexer);
        is_multiline = true;
      } else {
        lexer->result_symbol = SIMPLE_STRING;
        return true;
      }
    }

    return scan_string_content(lexer, is_multiline, false);
  }

  if (valid_symbols[INTERPOLATED_STRING_MIDDLE]) {
    return scan_string_content(lexer, false, true);
  }

  if (valid_symbols[INTERPOLATED_MULTILINE_STRING_MIDDLE]) {
    return scan_string_content(lexer, true, true);
  }

  return false;
}
