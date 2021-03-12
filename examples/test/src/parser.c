#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 12
#define STATE_COUNT 13
#define LARGE_STATE_COUNT 3
#define SYMBOL_COUNT 9
#define ALIAS_COUNT 0
#define TOKEN_COUNT 5
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 6

enum {
  aux_sym__id_token1 = 1,
  anon_sym_val = 2,
  anon_sym_COLON = 3,
  anon_sym_EQ = 4,
  sym_Foo = 5,
  aux_sym__id = 6,
  sym_ValDcl = 7,
  sym_ValDef = 8,
};

static const char *ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [aux_sym__id_token1] = "_id_token1",
  [anon_sym_val] = "val",
  [anon_sym_COLON] = ":",
  [anon_sym_EQ] = "=",
  [sym_Foo] = "Foo",
  [aux_sym__id] = "_id",
  [sym_ValDcl] = "ValDcl",
  [sym_ValDef] = "ValDef",
};

static TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [aux_sym__id_token1] = aux_sym__id_token1,
  [anon_sym_val] = anon_sym_val,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_EQ] = anon_sym_EQ,
  [sym_Foo] = sym_Foo,
  [aux_sym__id] = aux_sym__id,
  [sym_ValDcl] = sym_ValDcl,
  [sym_ValDef] = sym_ValDef,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [aux_sym__id_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_val] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [sym_Foo] = {
    .visible = true,
    .named = true,
  },
  [aux_sym__id] = {
    .visible = false,
    .named = false,
  },
  [sym_ValDcl] = {
    .visible = true,
    .named = true,
  },
  [sym_ValDef] = {
    .visible = true,
    .named = true,
  },
};

static TSSymbol ts_alias_sequences[1][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(4);
      if (lookahead == ':') ADVANCE(7);
      if (lookahead == '=') ADVANCE(8);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(5);
      END_STATE();
    case 1:
      if (lookahead == 'a') ADVANCE(2);
      END_STATE();
    case 2:
      if (lookahead == 'l') ADVANCE(6);
      END_STATE();
    case 3:
      if (lookahead == 'v') ADVANCE(1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(3)
      END_STATE();
    case 4:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 5:
      ACCEPT_TOKEN(aux_sym__id_token1);
      END_STATE();
    case 6:
      ACCEPT_TOKEN(anon_sym_val);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    default:
      return false;
  }
}

static TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 3},
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
};

static uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [aux_sym__id_token1] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
  },
  [1] = {
    [sym_Foo] = STATE(11),
    [sym_ValDcl] = STATE(12),
    [sym_ValDef] = STATE(12),
    [anon_sym_val] = ACTIONS(3),
  },
  [2] = {
    [aux_sym__id] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(5),
    [aux_sym__id_token1] = ACTIONS(7),
    [anon_sym_COLON] = ACTIONS(5),
    [anon_sym_EQ] = ACTIONS(5),
  },
};

static uint16_t ts_small_parse_table[] = {
  [0] = 4,
    ACTIONS(10), 1,
      aux_sym__id_token1,
    ACTIONS(12), 1,
      anon_sym_COLON,
    ACTIONS(14), 1,
      anon_sym_EQ,
    STATE(2), 1,
      aux_sym__id,
  [13] = 4,
    ACTIONS(10), 1,
      aux_sym__id_token1,
    ACTIONS(16), 1,
      ts_builtin_sym_end,
    ACTIONS(18), 1,
      anon_sym_EQ,
    STATE(2), 1,
      aux_sym__id,
  [26] = 3,
    ACTIONS(10), 1,
      aux_sym__id_token1,
    ACTIONS(20), 1,
      ts_builtin_sym_end,
    STATE(2), 1,
      aux_sym__id,
  [36] = 3,
    ACTIONS(10), 1,
      aux_sym__id_token1,
    ACTIONS(22), 1,
      ts_builtin_sym_end,
    STATE(2), 1,
      aux_sym__id,
  [46] = 2,
    ACTIONS(24), 1,
      aux_sym__id_token1,
    STATE(3), 1,
      aux_sym__id,
  [53] = 2,
    ACTIONS(26), 1,
      aux_sym__id_token1,
    STATE(4), 1,
      aux_sym__id,
  [60] = 2,
    ACTIONS(28), 1,
      aux_sym__id_token1,
    STATE(5), 1,
      aux_sym__id,
  [67] = 2,
    ACTIONS(30), 1,
      aux_sym__id_token1,
    STATE(6), 1,
      aux_sym__id,
  [74] = 1,
    ACTIONS(32), 1,
      ts_builtin_sym_end,
  [78] = 1,
    ACTIONS(34), 1,
      ts_builtin_sym_end,
};

static uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(3)] = 0,
  [SMALL_STATE(4)] = 13,
  [SMALL_STATE(5)] = 26,
  [SMALL_STATE(6)] = 36,
  [SMALL_STATE(7)] = 46,
  [SMALL_STATE(8)] = 53,
  [SMALL_STATE(9)] = 60,
  [SMALL_STATE(10)] = 67,
  [SMALL_STATE(11)] = 74,
  [SMALL_STATE(12)] = 78,
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__id, 2),
  [7] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__id, 2), SHIFT_REPEAT(2),
  [10] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [12] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [14] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [16] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ValDcl, 4),
  [18] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [20] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ValDef, 4),
  [22] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ValDef, 6),
  [24] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [26] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [28] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [30] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [32] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [34] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Foo, 1),
};

#ifdef __cplusplus
extern "C" {
#endif
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
    .field_count = FIELD_COUNT,
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
