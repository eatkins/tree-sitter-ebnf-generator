#include <tree_sitter/parser.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

enum TokenType {
  MULTI_COMMENT,
  AUTOMATIC_SEMICOLON,
  VAL,
  VAR,
  DEF,
  INTERP_START,
  OPEN_COMMENT,
  EMPTY,
  TRAILING_COMMA,
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

#define NEWLINE 0x0A
#define TAB     0x09
#define CR      0x13
#define SPACE   0x20

static inline bool is_wspace(int character) {
  switch(character) {
    // fallthrough enabled
    case NEWLINE:
    case TAB:
    case CR:
    case SPACE: return true;
    default: return false;
  }
}

static inline bool is_letter_or_digit(int character) {
  return
    character >= 48 && character < 58 ||
    character >= 65 && character < 91 ||
    character >= 97 && character < 123;
}

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

#define NONE                     0
#define IN_PARENS                1
#define IN_BRACES                2
#define IN_QUOTES                3
#define STATE_STACK_SIZE       256
#define LEFT_PAREN             '('
#define RIGHT_PAREN            ')'
#define LEFT_BRACE             '{'
#define RIGHT_BRACE            '}'
#define QUOTE                  '"'
#define SINGLE_QUOTE           '\''
#define EQUALS                 '='
#define FORWARD_SLASH          '/'

static bool scan_def(TSLexer *lexer) {
  lexer->result_symbol = DEF;
  int state_stack[STATE_STACK_SIZE];
  state_stack[0] = NONE;
  int head = 0;
  char current = lexer->lookahead;
  char prev_char = 0;
rec:
  while(current) {
    switch(state_stack[head]) {
      case NONE:
        while(current) {
          switch(current) {
            case LEFT_PAREN:
left_paren:
              if (head >= STATE_STACK_SIZE - 1) return false;
              state_stack[++head] = IN_PARENS;
              lexer->advance(lexer, false);
              current = lexer->lookahead;
              goto rec;
            case QUOTE:
quote:
              if (head >= STATE_STACK_SIZE - 1) return false;
              state_stack[++head] = IN_QUOTES;
              lexer->advance(lexer, false);
              current = lexer->lookahead;
              goto rec;
            case LEFT_BRACE:
              return false;
            case FORWARD_SLASH:
forward_slash:
              lexer->advance(lexer, false);
              // TODO properly support comments
              return lexer->lookahead == '/';
            case NEWLINE:
              return true;
            case EQUALS:
              return false;
          }
          prev_char = current;
          lexer->advance(lexer, false);
          current = lexer->lookahead;
        }
        return true;
      case IN_PARENS:
        while(current) {
          switch(current) {
            case LEFT_BRACE:
left_brace:
              if (head >= STATE_STACK_SIZE - 1) return false;
              state_stack[++head] = IN_BRACES;
              lexer->advance(lexer, false);
              current = lexer->lookahead;
              goto rec;
            case RIGHT_PAREN:
              head--;
              goto rec;
            case LEFT_PAREN:
              goto left_paren;
            case QUOTE:
              goto quote;
          }
          prev_char = current;
          lexer->advance(lexer, false);
          current = lexer->lookahead;
        }
      case IN_BRACES:
        while(current) {
          switch(current) {
            case RIGHT_BRACE:
              head--;
              goto rec;
            case LEFT_PAREN:
              goto left_paren;
            case LEFT_BRACE:
              goto left_brace;
            case QUOTE:
              goto quote;
          }
          prev_char = current;
          lexer->advance(lexer, false);
          current = lexer->lookahead;
        }
      case IN_QUOTES:
        while(current) {
          switch(current) {
            case QUOTE:
              if (prev_char != '\\') {
                head--;
                prev_char = current;
                lexer->advance(lexer, false);
                current = lexer->lookahead;
                goto rec;
              }
              break;
            case LEFT_PAREN:
              goto left_paren;
            case LEFT_BRACE:
              goto left_brace;
          }
          prev_char = prev_char == '\\' && current == '\\' ? 0 : current;
          lexer->advance(lexer, false);
          current = lexer->lookahead;
        }
    }
  }
  return true;
}

#undef NONE
#undef IN_PARENS
#undef IN_BRACES
#undef IN_QUOTES
#undef IN_SINGLE_QUOTES
#undef STATE_STACK_SIZE
#undef LEFT_PAREN
#undef RIGHT_PAREN
#undef LEFT_BRAACE
#undef RIGHT_BRACE
#undef QOUTE
#undef SINGLE_QUOTE

static bool maybe_add_automatic_newline(TSLexer *lexer, int nl_disabled, int new_line_count) {
  lexer->advance(lexer, false);
  while(lexer->lookahead && is_wspace(lexer->lookahead)) {
    if (lexer->lookahead == NEWLINE) new_line_count++;
    lexer->advance(lexer, false);
    char c = lexer->lookahead;
    if (!c) return false;
    if (c == '.') {
      lexer->result_symbol = AUTOMATIC_SEMICOLON;
      lexer->mark_end(lexer);
      lexer->advance(lexer, false);
      c = lexer->lookahead;
      return c > 47 && c < 58;
    }
  }
  if (new_line_count > 0) {
    lexer->result_symbol = AUTOMATIC_SEMICOLON;
    lexer->mark_end(lexer);
    if (new_line_count > 1) return true;
    else if (nl_disabled) return false;

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
            if (is_wspace(next_char)) return false; // a word that cannot start a statement was found
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
        if (!is_wspace(lexer->lookahead)) { next_char = lexer->lookahead; }
      }
    }
    return true;
  }
  return false;
}

static const char* keywords[] = { "def", "var", "val" };
static const int tokens[] = { DEF, VAR, VAL };

static bool scan_interp(TSLexer *lexer, const bool *valid_symbols, int flags) {
  lexer->mark_end(lexer);
  int i = 0;
  char buf[3];
  char current_char = lexer->lookahead;
  bool interp = is_letter_or_digit(current_char) && valid_symbols[INTERP_START];
  bool empty = valid_symbols[EMPTY];
  bool init_empty = empty;
  bool all_ws = valid_symbols[AUTOMATIC_SEMICOLON];
  int new_line_count = 0;
  bool open_comment = valid_symbols[OPEN_COMMENT];
  while (current_char && i < 3 && (interp || all_ws || open_comment)) {
    buf[i] = current_char;
    if (i == 0) open_comment = current_char == '/';
    else if (i == 1 && open_comment) {
      if (current_char == '*') {
        lexer->mark_end(lexer);
        lexer->result_symbol = OPEN_COMMENT;
        return true;
      }
    }
    i += 1;
    if (is_wspace(current_char)) {
      interp = false;
      if (current_char == NEWLINE && !empty) new_line_count++;
      break;
    } else {
      if (i > 1 && interp && current_char == '"') {
        lexer->result_symbol = INTERP_START;
        return true;
      }
      if (empty && current_char == '}') {
        lexer->mark_end(lexer);
        lexer->result_symbol = EMPTY;
        return true;
      }
      empty = false;
      all_ws = false;
      interp = interp && is_letter_or_digit(current_char);
    }
    lexer->advance(lexer, false);
    current_char = lexer->lookahead;
  }
  if (i == 3 && current_char && is_wspace(current_char) && !all_ws && !empty) {
    interp = false;
    for (int i = 0; i < 3; ++i) {
      if (strncmp(buf, keywords[i], 3) == 0) {
        lexer->mark_end(lexer);
        lexer->result_symbol = tokens[i];
        int token = tokens[i];
        if (token == DEF) return scan_def(lexer);

        while (current_char && current_char != '=' && current_char != ':' && current_char != ';' && current_char != '\n') {
          lexer->advance(lexer, false);
          current_char = lexer->lookahead;
        }
        if (lexer->lookahead == ':') {
          while (lexer->lookahead && lexer->lookahead != ';' && lexer->lookahead != '\n') {
            if (lexer->lookahead == '=') return false;
            lexer->advance(lexer, false);
          }
          return true;
        }
        return false;
      }
    }
  } else if (empty && i > 0 && !is_wspace(lexer->lookahead)) {
    lexer->mark_end(lexer);
    lexer->result_symbol = EMPTY;
    return true;
  } else if (all_ws) {
    return maybe_add_automatic_newline(lexer, false, new_line_count);
  }
  if (interp && i > 1) {
    lexer->result_symbol = INTERP_START;
    while (lexer->lookahead && !is_wspace(lexer->lookahead) && is_letter_or_digit(lexer->lookahead)) {
      if (lexer->lookahead == '"') {
        return true;
      }
      lexer->advance(lexer, false);
    }
  }
  return false;
}

bool tree_sitter_scala_external_scanner_scan(void *payload, TSLexer *lexer,
                                             const bool *valid_symbols) {
  char buf[1024];
  int bytes_read = 0;

  int flags = *(int *)payload;
  if (valid_symbols[TRAILING_COMMA] && lexer->lookahead == ',') {
    lexer->result_symbol = TRAILING_COMMA;
    do {
      lexer->advance(lexer, false);
    } while (lexer->lookahead && lexer->lookahead != NEWLINE);
    if (lexer->lookahead == NEWLINE) {
      lexer->mark_end(lexer);
      do {
        lexer->advance(lexer, false);
        if (lexer->lookahead == ')') return true;
      } while (is_wspace(lexer->lookahead));
      return false;
    }
    return false;
  }
  if (valid_symbols[MULTI_COMMENT] && recursive_scan_comment(lexer)) return true;
  if (valid_symbols[INTERP_START] || valid_symbols[VAL] || valid_symbols[DEF] || valid_symbols[VAL] || valid_symbols[AUTOMATIC_SEMICOLON] || valid_symbols[OPEN_COMMENT] || valid_symbols[EMPTY]) {
    if (scan_interp(lexer, valid_symbols, flags)) return true;
  }
  return false;
}

#undef TAB
#undef NEWLINE
#undef CR
#undef SPACE
#undef KEYWORD
