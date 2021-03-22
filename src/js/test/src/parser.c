#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 12
#define STATE_COUNT 15
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 22
#define ALIAS_COUNT 1
#define TOKEN_COUNT 17
#define EXTERNAL_TOKEN_COUNT 2
#define FIELD_COUNT 1
#define MAX_ALIAS_SEQUENCE_LENGTH 3

enum {
  sym_foo = 1,
  anon_sym_blah = 2,
  anon_sym_barz = 3,
  anon_sym_x = 4,
  anon_sym_bar = 5,
  anon_sym_car = 6,
  sym_ok = 7,
  sym_low = 8,
  anon_sym_COMMA = 9,
  anon_sym_zzz = 10,
  anon_sym_kk = 11,
  anon_sym_AT = 12,
  anon_sym_foo = 13,
  anon_sym_EQ = 14,
  anon_sym_else = 15,
  sym__automatic_semicolon = 16,
  sym_top1 = 17,
  sym_blah = 18,
  sym_bar = 19,
  sym_buzz = 20,
  aux_sym_blah_repeat1 = 21,
  alias_sym_car = 22,
};

static const char *ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_foo] = "foo",
  [anon_sym_blah] = "blah",
  [anon_sym_barz] = "barz",
  [anon_sym_x] = "x",
  [anon_sym_bar] = "bar",
  [anon_sym_car] = "car",
  [sym_ok] = "ok",
  [sym_low] = "low",
  [anon_sym_COMMA] = ",",
  [anon_sym_zzz] = "zzz",
  [anon_sym_kk] = "kk",
  [anon_sym_AT] = "@",
  [anon_sym_foo] = "foo",
  [anon_sym_EQ] = "=",
  [anon_sym_else] = "else",
  [sym__automatic_semicolon] = "_automatic_semicolon",
  [sym_top1] = "top1",
  [sym_blah] = "blah",
  [sym_bar] = "bar",
  [sym_buzz] = "buzz",
  [aux_sym_blah_repeat1] = "blah_repeat1",
  [alias_sym_car] = "car",
};

static TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_foo] = sym_foo,
  [anon_sym_blah] = anon_sym_blah,
  [anon_sym_barz] = anon_sym_barz,
  [anon_sym_x] = anon_sym_x,
  [anon_sym_bar] = anon_sym_bar,
  [anon_sym_car] = anon_sym_car,
  [sym_ok] = sym_ok,
  [sym_low] = sym_low,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_zzz] = anon_sym_zzz,
  [anon_sym_kk] = anon_sym_kk,
  [anon_sym_AT] = anon_sym_AT,
  [anon_sym_foo] = anon_sym_foo,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_else] = anon_sym_else,
  [sym__automatic_semicolon] = sym__automatic_semicolon,
  [sym_top1] = sym_top1,
  [sym_blah] = sym_blah,
  [sym_bar] = sym_bar,
  [sym_buzz] = sym_buzz,
  [aux_sym_blah_repeat1] = aux_sym_blah_repeat1,
  [alias_sym_car] = alias_sym_car,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_foo] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_blah] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_barz] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_x] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_bar] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_car] = {
    .visible = true,
    .named = false,
  },
  [sym_ok] = {
    .visible = true,
    .named = true,
  },
  [sym_low] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_zzz] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_kk] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_foo] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_else] = {
    .visible = true,
    .named = false,
  },
  [sym__automatic_semicolon] = {
    .visible = false,
    .named = true,
  },
  [sym_top1] = {
    .visible = true,
    .named = true,
  },
  [sym_blah] = {
    .visible = true,
    .named = true,
  },
  [sym_bar] = {
    .visible = true,
    .named = true,
  },
  [sym_buzz] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_blah_repeat1] = {
    .visible = false,
    .named = false,
  },
  [alias_sym_car] = {
    .visible = true,
    .named = true,
  },
};

enum {
  field_blah = 1,
};

static const char *ts_field_names[] = {
  [0] = NULL,
  [field_blah] = "blah",
};

static const TSFieldMapSlice ts_field_map_slices[3] = {
  [1] = {.index = 0, .length = 2},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_blah, 1},
    {field_blah, 2},
};

static TSSymbol ts_alias_sequences[3][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
  [2] = {
    [1] = alias_sym_car,
    [2] = alias_sym_car,
  },
};

static uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(39);
      if (lookahead == ',') ADVANCE(54);
      if (lookahead == '=') ADVANCE(59);
      if (lookahead == '@') ADVANCE(57);
      if (lookahead == 'b') ADVANCE(1);
      if (lookahead == 'c') ADVANCE(5);
      if (lookahead == 'e') ADVANCE(20);
      if (lookahead == 'f') ADVANCE(30);
      if (lookahead == 'h') ADVANCE(11);
      if (lookahead == 'k') ADVANCE(16);
      if (lookahead == 'o') ADVANCE(17);
      if (lookahead == 'x') ADVANCE(46);
      if (lookahead == 'z') ADVANCE(38);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      END_STATE();
    case 1:
      if (lookahead == 'a') ADVANCE(34);
      if (lookahead == 'l') ADVANCE(2);
      END_STATE();
    case 2:
      if (lookahead == 'a') ADVANCE(14);
      END_STATE();
    case 3:
      if (lookahead == 'a') ADVANCE(31);
      if (lookahead == 'l') ADVANCE(4);
      if (lookahead == 'o') ADVANCE(19);
      if (('b' <= lookahead && lookahead <= 'z')) ADVANCE(33);
      END_STATE();
    case 4:
      if (lookahead == 'a') ADVANCE(15);
      if (lookahead == 'o') ADVANCE(19);
      if (('b' <= lookahead && lookahead <= 'z')) ADVANCE(33);
      END_STATE();
    case 5:
      if (lookahead == 'a') ADVANCE(35);
      END_STATE();
    case 6:
      if (lookahead == 'a') ADVANCE(32);
      if (lookahead == 'o') ADVANCE(19);
      if (('b' <= lookahead && lookahead <= 'z')) ADVANCE(33);
      END_STATE();
    case 7:
      if (lookahead == 'b') ADVANCE(1);
      if (lookahead == 'c') ADVANCE(5);
      if (lookahead == 'h') ADVANCE(11);
      if (lookahead == 'o') ADVANCE(17);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(7)
      END_STATE();
    case 8:
      if (lookahead == 'b') ADVANCE(3);
      if (lookahead == 'c') ADVANCE(6);
      if (lookahead == 'h') ADVANCE(10);
      if (lookahead == 'o') ADVANCE(18);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(7)
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(33);
      END_STATE();
    case 9:
      if (lookahead == 'e') ADVANCE(60);
      END_STATE();
    case 10:
      if (lookahead == 'e') ADVANCE(21);
      if (lookahead == 'o') ADVANCE(19);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(33);
      END_STATE();
    case 11:
      if (lookahead == 'e') ADVANCE(22);
      END_STATE();
    case 12:
      if (lookahead == 'g') ADVANCE(28);
      if (lookahead == 'o') ADVANCE(19);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(33);
      END_STATE();
    case 13:
      if (lookahead == 'g') ADVANCE(26);
      END_STATE();
    case 14:
      if (lookahead == 'h') ADVANCE(42);
      END_STATE();
    case 15:
      if (lookahead == 'h') ADVANCE(43);
      if (lookahead == 'o') ADVANCE(19);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(33);
      END_STATE();
    case 16:
      if (lookahead == 'k') ADVANCE(56);
      END_STATE();
    case 17:
      if (lookahead == 'k') ADVANCE(13);
      END_STATE();
    case 18:
      if (lookahead == 'k') ADVANCE(12);
      if (lookahead == 'o') ADVANCE(19);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(33);
      END_STATE();
    case 19:
      if (lookahead == 'k') ADVANCE(53);
      if (lookahead == 'o') ADVANCE(19);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(33);
      END_STATE();
    case 20:
      if (lookahead == 'l') ADVANCE(36);
      END_STATE();
    case 21:
      if (lookahead == 'l') ADVANCE(23);
      if (lookahead == 'o') ADVANCE(19);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(33);
      END_STATE();
    case 22:
      if (lookahead == 'l') ADVANCE(24);
      END_STATE();
    case 23:
      if (lookahead == 'l') ADVANCE(29);
      if (lookahead == 'o') ADVANCE(19);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(33);
      END_STATE();
    case 24:
      if (lookahead == 'l') ADVANCE(27);
      END_STATE();
    case 25:
      if (lookahead == 'o') ADVANCE(58);
      END_STATE();
    case 26:
      if (lookahead == 'o') ADVANCE(51);
      END_STATE();
    case 27:
      if (lookahead == 'o') ADVANCE(40);
      END_STATE();
    case 28:
      if (lookahead == 'o') ADVANCE(52);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(33);
      END_STATE();
    case 29:
      if (lookahead == 'o') ADVANCE(41);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(33);
      END_STATE();
    case 30:
      if (lookahead == 'o') ADVANCE(25);
      END_STATE();
    case 31:
      if (lookahead == 'o') ADVANCE(19);
      if (lookahead == 'r') ADVANCE(47);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(33);
      END_STATE();
    case 32:
      if (lookahead == 'o') ADVANCE(19);
      if (lookahead == 'r') ADVANCE(50);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(33);
      END_STATE();
    case 33:
      if (lookahead == 'o') ADVANCE(19);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(33);
      END_STATE();
    case 34:
      if (lookahead == 'r') ADVANCE(48);
      END_STATE();
    case 35:
      if (lookahead == 'r') ADVANCE(49);
      END_STATE();
    case 36:
      if (lookahead == 's') ADVANCE(9);
      END_STATE();
    case 37:
      if (lookahead == 'z') ADVANCE(55);
      END_STATE();
    case 38:
      if (lookahead == 'z') ADVANCE(37);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(sym_foo);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(sym_foo);
      if (lookahead == 'k') ADVANCE(53);
      if (lookahead == 'o') ADVANCE(19);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(33);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(anon_sym_blah);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(anon_sym_blah);
      if (lookahead == 'o') ADVANCE(19);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(33);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(anon_sym_barz);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(anon_sym_barz);
      if (lookahead == 'o') ADVANCE(19);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(33);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(anon_sym_x);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(anon_sym_bar);
      if (lookahead == 'o') ADVANCE(19);
      if (lookahead == 'z') ADVANCE(45);
      if (('a' <= lookahead && lookahead <= 'y')) ADVANCE(33);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(anon_sym_bar);
      if (lookahead == 'z') ADVANCE(44);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(anon_sym_car);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(anon_sym_car);
      if (lookahead == 'o') ADVANCE(19);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(33);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(sym_ok);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(sym_ok);
      if (lookahead == 'k') ADVANCE(53);
      if (lookahead == 'o') ADVANCE(19);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(33);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(sym_low);
      if (lookahead == 'o') ADVANCE(19);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(33);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(anon_sym_zzz);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(anon_sym_kk);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(anon_sym_AT);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(anon_sym_foo);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(anon_sym_else);
      END_STATE();
    default:
      return false;
  }
}

static TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 8},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
};

enum {
  ts_external_token__automatic_semicolon = 0,
  ts_external_token_else = 1,
};

static TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token__automatic_semicolon] = sym__automatic_semicolon,
  [ts_external_token_else] = anon_sym_else,
};

static bool ts_external_scanner_states[2][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token__automatic_semicolon] = true,
    [ts_external_token_else] = true,
  },
};

static uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_foo] = ACTIONS(1),
    [anon_sym_blah] = ACTIONS(1),
    [anon_sym_barz] = ACTIONS(1),
    [anon_sym_x] = ACTIONS(1),
    [anon_sym_bar] = ACTIONS(1),
    [anon_sym_car] = ACTIONS(1),
    [sym_ok] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_zzz] = ACTIONS(1),
    [anon_sym_kk] = ACTIONS(1),
    [anon_sym_AT] = ACTIONS(1),
    [anon_sym_foo] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_else] = ACTIONS(1),
    [sym__automatic_semicolon] = ACTIONS(1),
  },
  [1] = {
    [sym_top1] = STATE(9),
    [sym_blah] = STATE(8),
    [sym_bar] = STATE(8),
    [sym_buzz] = STATE(8),
    [aux_sym_blah_repeat1] = STATE(2),
    [sym_foo] = ACTIONS(3),
    [anon_sym_blah] = ACTIONS(5),
    [anon_sym_barz] = ACTIONS(5),
    [anon_sym_bar] = ACTIONS(7),
    [anon_sym_car] = ACTIONS(9),
    [sym_ok] = ACTIONS(11),
    [sym_low] = ACTIONS(13),
  },
};

static uint16_t ts_small_parse_table[] = {
  [0] = 4,
    ACTIONS(15), 1,
      ts_builtin_sym_end,
    ACTIONS(17), 1,
      sym_foo,
    STATE(3), 1,
      aux_sym_blah_repeat1,
    ACTIONS(19), 2,
      anon_sym_blah,
      anon_sym_barz,
  [14] = 4,
    ACTIONS(21), 1,
      ts_builtin_sym_end,
    ACTIONS(23), 1,
      sym_foo,
    STATE(3), 1,
      aux_sym_blah_repeat1,
    ACTIONS(26), 2,
      anon_sym_blah,
      anon_sym_barz,
  [28] = 1,
    ACTIONS(21), 4,
      ts_builtin_sym_end,
      sym_foo,
      anon_sym_blah,
      anon_sym_barz,
  [35] = 2,
    ACTIONS(29), 1,
      ts_builtin_sym_end,
    ACTIONS(31), 1,
      anon_sym_x,
  [42] = 1,
    ACTIONS(33), 1,
      sym_foo,
  [46] = 1,
    ACTIONS(35), 1,
      sym_foo,
  [50] = 1,
    ACTIONS(29), 1,
      ts_builtin_sym_end,
  [54] = 1,
    ACTIONS(37), 1,
      ts_builtin_sym_end,
  [58] = 1,
    ACTIONS(39), 1,
      sym_foo,
  [62] = 1,
    ACTIONS(41), 1,
      sym_foo,
  [66] = 1,
    ACTIONS(31), 1,
      anon_sym_x,
  [70] = 1,
    ACTIONS(43), 1,
      ts_builtin_sym_end,
  [74] = 1,
    ACTIONS(45), 1,
      ts_builtin_sym_end,
};

static uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 14,
  [SMALL_STATE(4)] = 28,
  [SMALL_STATE(5)] = 35,
  [SMALL_STATE(6)] = 42,
  [SMALL_STATE(7)] = 46,
  [SMALL_STATE(8)] = 50,
  [SMALL_STATE(9)] = 54,
  [SMALL_STATE(10)] = 58,
  [SMALL_STATE(11)] = 62,
  [SMALL_STATE(12)] = 66,
  [SMALL_STATE(13)] = 70,
  [SMALL_STATE(14)] = 74,
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [15] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_blah, 1),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [21] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_blah_repeat1, 2),
  [23] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_blah_repeat1, 2), SHIFT_REPEAT(12),
  [26] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_blah_repeat1, 2), SHIFT_REPEAT(3),
  [29] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_top1, 1),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [37] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [43] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bar, 3, .production_id = 1),
  [45] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_buzz, 3, .production_id = 2),
};

#ifdef __cplusplus
extern "C" {
#endif
void *tree_sitter_test_external_scanner_create(void);
void tree_sitter_test_external_scanner_destroy(void *);
bool tree_sitter_test_external_scanner_scan(void *, TSLexer *, const bool *);
unsigned tree_sitter_test_external_scanner_serialize(void *, char *);
void tree_sitter_test_external_scanner_deserialize(void *, const char *, unsigned);

#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_test(void) {
  static TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .parse_table = (const uint16_t *)ts_parse_table,
    .parse_actions = ts_parse_actions,
    .lex_modes = ts_lex_modes,
    .alias_sequences = (const TSSymbol *)ts_alias_sequences,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .lex_fn = ts_lex,
    .external_scanner = {
      (const bool *)ts_external_scanner_states,
      ts_external_scanner_symbol_map,
      tree_sitter_test_external_scanner_create,
      tree_sitter_test_external_scanner_destroy,
      tree_sitter_test_external_scanner_scan,
      tree_sitter_test_external_scanner_serialize,
      tree_sitter_test_external_scanner_deserialize,
    },
    .field_count = FIELD_COUNT,
    .field_map_slices = (const TSFieldMapSlice *)ts_field_map_slices,
    .field_map_entries = (const TSFieldMapEntry *)ts_field_map_entries,
    .field_names = ts_field_names,
    .large_state_count = LARGE_STATE_COUNT,
    .small_parse_table = (const uint16_t *)ts_small_parse_table,
    .small_parse_table_map = (const uint32_t *)ts_small_parse_table_map,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .state_count = STATE_COUNT,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
