#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 12
#define STATE_COUNT 30
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 46
#define ALIAS_COUNT 0
#define TOKEN_COUNT 39
#define EXTERNAL_TOKEN_COUNT 1
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 5

enum {
  sym__whiteSpace = 1,
  sym__upper = 2,
  aux_sym__lower_token1 = 3,
  aux_sym__lower_token2 = 4,
  aux_sym__lower_token3 = 5,
  sym__digit = 6,
  sym__paren = 7,
  sym__delim = 8,
  sym__opchar = 9,
  sym__printableChar = 10,
  anon_sym_BSLASH = 11,
  anon_sym_u = 12,
  sym__hexDigit = 13,
  aux_sym__charEscapeSeq_token1 = 14,
  anon_sym_BQUOTE = 15,
  aux_sym__id_token1 = 16,
  anon_sym__ = 17,
  aux_sym__integerLiteral_token1 = 18,
  anon_sym_0 = 19,
  aux_sym__hexNumeral_token1 = 20,
  aux_sym__exponentPart_token1 = 21,
  aux_sym__exponentPart_token2 = 22,
  sym__floatType = 23,
  anon_sym_true = 24,
  anon_sym_false = 25,
  anon_sym_SQUOTE = 26,
  anon_sym_DQUOTE = 27,
  aux_sym__stringElement_token1 = 28,
  sym__decimalPoint = 29,
  sym__charMinusQuoteDollar = 30,
  anon_sym_DOLLAR = 31,
  anon_sym_SLASH_STAR = 32,
  anon_sym_STAR_SLASH = 33,
  anon_sym_SLASH_SLASH = 34,
  aux_sym__comment_token1 = 35,
  anon_sym_SEMI = 36,
  anon_sym_DASH = 37,
  sym__multi_comment = 38,
  sym_compilation_unit = 39,
  sym__floatingPointLiteral = 40,
  sym__exponentPart = 41,
  sym__booleanLiteral = 42,
  sym__comment = 43,
  aux_sym_compilation_unit_repeat1 = 44,
  aux_sym__floatingPointLiteral_repeat1 = 45,
};

static const char *ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym__whiteSpace] = "_whiteSpace",
  [sym__upper] = "_upper",
  [aux_sym__lower_token1] = "_lower_token1",
  [aux_sym__lower_token2] = "_lower_token2",
  [aux_sym__lower_token3] = "_lower_token3",
  [sym__digit] = "_digit",
  [sym__paren] = "_paren",
  [sym__delim] = "_delim",
  [sym__opchar] = "_opchar",
  [sym__printableChar] = "_printableChar",
  [anon_sym_BSLASH] = "\\",
  [anon_sym_u] = "u",
  [sym__hexDigit] = "_hexDigit",
  [aux_sym__charEscapeSeq_token1] = "_charEscapeSeq_token1",
  [anon_sym_BQUOTE] = "`",
  [aux_sym__id_token1] = "_id_token1",
  [anon_sym__] = "_",
  [aux_sym__integerLiteral_token1] = "_integerLiteral_token1",
  [anon_sym_0] = "0",
  [aux_sym__hexNumeral_token1] = "_hexNumeral_token1",
  [aux_sym__exponentPart_token1] = "_exponentPart_token1",
  [aux_sym__exponentPart_token2] = "_exponentPart_token2",
  [sym__floatType] = "_floatType",
  [anon_sym_true] = "true",
  [anon_sym_false] = "false",
  [anon_sym_SQUOTE] = "'",
  [anon_sym_DQUOTE] = "\"",
  [aux_sym__stringElement_token1] = "_stringElement_token1",
  [sym__decimalPoint] = "_decimalPoint",
  [sym__charMinusQuoteDollar] = "_charMinusQuoteDollar",
  [anon_sym_DOLLAR] = "$",
  [anon_sym_SLASH_STAR] = "/*",
  [anon_sym_STAR_SLASH] = "*/",
  [anon_sym_SLASH_SLASH] = "//",
  [aux_sym__comment_token1] = "_comment_token1",
  [anon_sym_SEMI] = ";",
  [anon_sym_DASH] = "-",
  [sym__multi_comment] = "_multi_comment",
  [sym_compilation_unit] = "compilation_unit",
  [sym__floatingPointLiteral] = "_floatingPointLiteral",
  [sym__exponentPart] = "_exponentPart",
  [sym__booleanLiteral] = "_booleanLiteral",
  [sym__comment] = "_comment",
  [aux_sym_compilation_unit_repeat1] = "compilation_unit_repeat1",
  [aux_sym__floatingPointLiteral_repeat1] = "_floatingPointLiteral_repeat1",
};

static TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym__whiteSpace] = sym__whiteSpace,
  [sym__upper] = sym__upper,
  [aux_sym__lower_token1] = aux_sym__lower_token1,
  [aux_sym__lower_token2] = aux_sym__lower_token2,
  [aux_sym__lower_token3] = aux_sym__lower_token3,
  [sym__digit] = sym__digit,
  [sym__paren] = sym__paren,
  [sym__delim] = sym__delim,
  [sym__opchar] = sym__opchar,
  [sym__printableChar] = sym__printableChar,
  [anon_sym_BSLASH] = anon_sym_BSLASH,
  [anon_sym_u] = anon_sym_u,
  [sym__hexDigit] = sym__hexDigit,
  [aux_sym__charEscapeSeq_token1] = aux_sym__charEscapeSeq_token1,
  [anon_sym_BQUOTE] = anon_sym_BQUOTE,
  [aux_sym__id_token1] = aux_sym__id_token1,
  [anon_sym__] = anon_sym__,
  [aux_sym__integerLiteral_token1] = aux_sym__integerLiteral_token1,
  [anon_sym_0] = anon_sym_0,
  [aux_sym__hexNumeral_token1] = aux_sym__hexNumeral_token1,
  [aux_sym__exponentPart_token1] = aux_sym__exponentPart_token1,
  [aux_sym__exponentPart_token2] = aux_sym__exponentPart_token2,
  [sym__floatType] = sym__floatType,
  [anon_sym_true] = anon_sym_true,
  [anon_sym_false] = anon_sym_false,
  [anon_sym_SQUOTE] = anon_sym_SQUOTE,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [aux_sym__stringElement_token1] = aux_sym__stringElement_token1,
  [sym__decimalPoint] = sym__decimalPoint,
  [sym__charMinusQuoteDollar] = sym__charMinusQuoteDollar,
  [anon_sym_DOLLAR] = anon_sym_DOLLAR,
  [anon_sym_SLASH_STAR] = anon_sym_SLASH_STAR,
  [anon_sym_STAR_SLASH] = anon_sym_STAR_SLASH,
  [anon_sym_SLASH_SLASH] = anon_sym_SLASH_SLASH,
  [aux_sym__comment_token1] = aux_sym__comment_token1,
  [anon_sym_SEMI] = anon_sym_SEMI,
  [anon_sym_DASH] = anon_sym_DASH,
  [sym__multi_comment] = sym__multi_comment,
  [sym_compilation_unit] = sym_compilation_unit,
  [sym__floatingPointLiteral] = sym__floatingPointLiteral,
  [sym__exponentPart] = sym__exponentPart,
  [sym__booleanLiteral] = sym__booleanLiteral,
  [sym__comment] = sym__comment,
  [aux_sym_compilation_unit_repeat1] = aux_sym_compilation_unit_repeat1,
  [aux_sym__floatingPointLiteral_repeat1] = aux_sym__floatingPointLiteral_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym__whiteSpace] = {
    .visible = false,
    .named = true,
  },
  [sym__upper] = {
    .visible = false,
    .named = true,
  },
  [aux_sym__lower_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__lower_token2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__lower_token3] = {
    .visible = false,
    .named = false,
  },
  [sym__digit] = {
    .visible = false,
    .named = true,
  },
  [sym__paren] = {
    .visible = false,
    .named = true,
  },
  [sym__delim] = {
    .visible = false,
    .named = true,
  },
  [sym__opchar] = {
    .visible = false,
    .named = true,
  },
  [sym__printableChar] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_BSLASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_u] = {
    .visible = true,
    .named = false,
  },
  [sym__hexDigit] = {
    .visible = false,
    .named = true,
  },
  [aux_sym__charEscapeSeq_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_BQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym__id_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym__] = {
    .visible = true,
    .named = false,
  },
  [aux_sym__integerLiteral_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_0] = {
    .visible = true,
    .named = false,
  },
  [aux_sym__hexNumeral_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__exponentPart_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__exponentPart_token2] = {
    .visible = false,
    .named = false,
  },
  [sym__floatType] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_true] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_false] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SQUOTE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym__stringElement_token1] = {
    .visible = false,
    .named = false,
  },
  [sym__decimalPoint] = {
    .visible = false,
    .named = true,
  },
  [sym__charMinusQuoteDollar] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_DOLLAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SLASH_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR_SLASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SLASH_SLASH] = {
    .visible = true,
    .named = false,
  },
  [aux_sym__comment_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_SEMI] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH] = {
    .visible = true,
    .named = false,
  },
  [sym__multi_comment] = {
    .visible = false,
    .named = true,
  },
  [sym_compilation_unit] = {
    .visible = true,
    .named = true,
  },
  [sym__floatingPointLiteral] = {
    .visible = false,
    .named = true,
  },
  [sym__exponentPart] = {
    .visible = false,
    .named = true,
  },
  [sym__booleanLiteral] = {
    .visible = false,
    .named = true,
  },
  [sym__comment] = {
    .visible = false,
    .named = true,
  },
  [aux_sym_compilation_unit_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__floatingPointLiteral_repeat1] = {
    .visible = false,
    .named = false,
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
      if (eof) ADVANCE(10);
      if (lookahead == ' ') ADVANCE(11);
      if (lookahead == '"') ADVANCE(33);
      if (lookahead == '$') ADVANCE(35);
      if (lookahead == '\'') ADVANCE(32);
      if (lookahead == '+') ADVANCE(18);
      if (lookahead == ',') ADVANCE(17);
      if (lookahead == '-') ADVANCE(45);
      if (lookahead == '.') ADVANCE(34);
      if (lookahead == '/') ADVANCE(19);
      if (lookahead == '0') ADVANCE(25);
      if (lookahead == ';') ADVANCE(44);
      if (lookahead == 'E') ADVANCE(13);
      if (lookahead == 'L') ADVANCE(13);
      if (lookahead == 'X') ADVANCE(13);
      if (lookahead == '\\') ADVANCE(21);
      if (lookahead == '_') ADVANCE(24);
      if (lookahead == '`') ADVANCE(23);
      if (lookahead == 'b') ADVANCE(14);
      if (lookahead == 'd') ADVANCE(14);
      if (lookahead == 'e') ADVANCE(14);
      if (lookahead == 'f') ADVANCE(14);
      if (lookahead == 'l') ADVANCE(14);
      if (lookahead == 'u') ADVANCE(22);
      if (lookahead == 'x') ADVANCE(14);
      if (lookahead == 127) ADVANCE(20);
      if (('D' <= lookahead && lookahead <= 'F')) ADVANCE(13);
      if (('a' <= lookahead && lookahead <= 'c')) ADVANCE(14);
      if (lookahead == 'n' ||
          lookahead == 'r' ||
          lookahead == 't') ADVANCE(14);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r') ADVANCE(11);
      if (('A' <= lookahead && lookahead <= 'C')) ADVANCE(13);
      if (lookahead == '(' ||
          lookahead == ')' ||
          ('[' <= lookahead && lookahead <= ']') ||
          lookahead == '{' ||
          lookahead == '}') ADVANCE(16);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(15);
      if (lookahead == 11388 ||
          lookahead == 11389 ||
          lookahead == 42652 ||
          lookahead == 42653 ||
          lookahead == 42864 ||
          lookahead == 43000 ||
          lookahead == 43001 ||
          (43868 <= lookahead && lookahead <= 43871)) ADVANCE(13);
      if (('!' <= lookahead && lookahead <= '@') ||
          lookahead == '^' ||
          ('|' <= lookahead && lookahead <= '~')) ADVANCE(18);
      if (('g' <= lookahead && lookahead <= 'z')) ADVANCE(14);
      if (lookahead == 170 ||
          (688 <= lookahead && lookahead <= 696) ||
          lookahead == 704 ||
          lookahead == 705 ||
          (736 <= lookahead && lookahead <= 740)) ADVANCE(13);
      if (('G' <= lookahead && lookahead <= 'Z')) ADVANCE(13);
      if (lookahead == 890 ||
          lookahead == 7544 ||
          (7579 <= lookahead && lookahead <= 7615) ||
          lookahead == 8305 ||
          lookahead == 8319 ||
          (8336 <= lookahead && lookahead <= 8348)) ADVANCE(13);
      if (lookahead == 181 ||
          lookahead == 187 ||
          (223 <= lookahead && lookahead <= 246) ||
          (248 <= lookahead && lookahead <= 255) ||
          lookahead == 257 ||
          lookahead == 259 ||
          lookahead == 261 ||
          lookahead == 263 ||
          lookahead == 265 ||
          lookahead == 267 ||
          lookahead == 269 ||
          lookahead == 271 ||
          lookahead == 273 ||
          lookahead == 275 ||
          lookahead == 277 ||
          lookahead == 279 ||
          lookahead == 281 ||
          lookahead == 283 ||
          lookahead == 285 ||
          lookahead == 287 ||
          lookahead == 289 ||
          lookahead == 291 ||
          lookahead == 293 ||
          lookahead == 295 ||
          lookahead == 297 ||
          lookahead == 299 ||
          lookahead == 301 ||
          lookahead == 303 ||
          lookahead == 305 ||
          lookahead == 307 ||
          lookahead == 309 ||
          lookahead == 311 ||
          lookahead == 312 ||
          lookahead == 314 ||
          lookahead == 316 ||
          lookahead == 318 ||
          lookahead == 320 ||
          lookahead == 322 ||
          lookahead == 324 ||
          lookahead == 326 ||
          lookahead == 328 ||
          lookahead == 329 ||
          lookahead == 331 ||
          lookahead == 333 ||
          lookahead == 335 ||
          lookahead == 337 ||
          lookahead == 339 ||
          lookahead == 341 ||
          lookahead == 343 ||
          lookahead == 345 ||
          lookahead == 347 ||
          lookahead == 349 ||
          lookahead == 351 ||
          lookahead == 353 ||
          lookahead == 355 ||
          lookahead == 357 ||
          lookahead == 359 ||
          lookahead == 361 ||
          lookahead == 363 ||
          lookahead == 365 ||
          lookahead == 367 ||
          lookahead == 369 ||
          lookahead == 371 ||
          lookahead == 373 ||
          lookahead == 375 ||
          lookahead == 378 ||
          lookahead == 380 ||
          (382 <= lookahead && lookahead <= 384) ||
          lookahead == 387 ||
          lookahead == 389 ||
          lookahead == 392 ||
          lookahead == 396 ||
          lookahead == 397 ||
          lookahead == 402 ||
          lookahead == 405 ||
          (409 <= lookahead && lookahead <= 411) ||
          lookahead == 414 ||
          lookahead == 417 ||
          lookahead == 419 ||
          lookahead == 421 ||
          lookahead == 424 ||
          lookahead == 426 ||
          lookahead == 427 ||
          lookahead == 429 ||
          lookahead == 432 ||
          lookahead == 436 ||
          lookahead == 438 ||
          lookahead == 441 ||
          lookahead == 442 ||
          (445 <= lookahead && lookahead <= 447) ||
          lookahead == 454 ||
          lookahead == 457 ||
          lookahead == 460 ||
          lookahead == 462 ||
          lookahead == 464 ||
          lookahead == 466 ||
          lookahead == 468 ||
          lookahead == 470 ||
          lookahead == 472 ||
          lookahead == 474 ||
          lookahead == 476 ||
          lookahead == 477 ||
          lookahead == 479 ||
          lookahead == 481 ||
          lookahead == 483 ||
          lookahead == 485 ||
          lookahead == 487 ||
          lookahead == 489 ||
          lookahead == 491 ||
          lookahead == 493 ||
          lookahead == 495 ||
          lookahead == 496 ||
          lookahead == 499 ||
          lookahead == 501 ||
          lookahead == 505 ||
          lookahead == 507 ||
          lookahead == 509 ||
          lookahead == 511 ||
          lookahead == 513 ||
          lookahead == 515 ||
          lookahead == 517 ||
          lookahead == 519 ||
          lookahead == 521 ||
          lookahead == 523 ||
          lookahead == 525 ||
          lookahead == 527 ||
          lookahead == 529 ||
          lookahead == 531 ||
          lookahead == 533 ||
          lookahead == 535 ||
          lookahead == 537 ||
          lookahead == 539 ||
          lookahead == 541 ||
          lookahead == 543 ||
          lookahead == 545 ||
          lookahead == 547 ||
          lookahead == 549 ||
          lookahead == 551 ||
          lookahead == 553 ||
          lookahead == 555 ||
          lookahead == 557 ||
          lookahead == 559 ||
          lookahead == 561 ||
          (563 <= lookahead && lookahead <= 569) ||
          lookahead == 572 ||
          lookahead == 575 ||
          lookahead == 576 ||
          lookahead == 578 ||
          lookahead == 583 ||
          lookahead == 585 ||
          lookahead == 587 ||
          lookahead == 589 ||
          (591 <= lookahead && lookahead <= 659) ||
          (661 <= lookahead && lookahead <= 687) ||
          lookahead == 881 ||
          lookahead == 883 ||
          lookahead == 887 ||
          (891 <= lookahead && lookahead <= 893) ||
          lookahead == 912 ||
          (940 <= lookahead && lookahead <= 974) ||
          lookahead == 976 ||
          lookahead == 977 ||
          (981 <= lookahead && lookahead <= 983) ||
          lookahead == 985 ||
          lookahead == 987 ||
          lookahead == 989 ||
          lookahead == 991 ||
          lookahead == 993 ||
          lookahead == 995 ||
          lookahead == 997 ||
          lookahead == 999 ||
          lookahead == 1001 ||
          lookahead == 1003 ||
          lookahead == 1005 ||
          (1007 <= lookahead && lookahead <= 1011) ||
          lookahead == 1013 ||
          lookahead == 1016 ||
          lookahead == 1019 ||
          lookahead == 1020 ||
          (1072 <= lookahead && lookahead <= 1119) ||
          lookahead == 1121 ||
          lookahead == 1123 ||
          lookahead == 1125 ||
          lookahead == 1127 ||
          lookahead == 1129 ||
          lookahead == 1131 ||
          lookahead == 1133 ||
          lookahead == 1135 ||
          lookahead == 1137 ||
          lookahead == 1139 ||
          lookahead == 1141 ||
          lookahead == 1143 ||
          lookahead == 1145 ||
          lookahead == 1147 ||
          lookahead == 1149 ||
          lookahead == 1151 ||
          lookahead == 1153 ||
          lookahead == 1163 ||
          lookahead == 1165 ||
          lookahead == 1167 ||
          lookahead == 1169 ||
          lookahead == 1171 ||
          lookahead == 1173 ||
          lookahead == 1175 ||
          lookahead == 1177 ||
          lookahead == 1179 ||
          lookahead == 1181 ||
          lookahead == 1183 ||
          lookahead == 1185 ||
          lookahead == 1187 ||
          lookahead == 1189 ||
          lookahead == 1191 ||
          lookahead == 1193 ||
          lookahead == 1195 ||
          lookahead == 1197 ||
          lookahead == 1199 ||
          lookahead == 1201 ||
          lookahead == 1203 ||
          lookahead == 1205 ||
          lookahead == 1207 ||
          lookahead == 1209 ||
          lookahead == 1211 ||
          lookahead == 1213 ||
          lookahead == 1215 ||
          lookahead == 1218 ||
          lookahead == 1220 ||
          lookahead == 1222 ||
          lookahead == 1224 ||
          lookahead == 1226 ||
          lookahead == 1228 ||
          lookahead == 1230 ||
          lookahead == 1231 ||
          lookahead == 1233 ||
          lookahead == 1235 ||
          lookahead == 1237 ||
          lookahead == 1239 ||
          lookahead == 1241 ||
          lookahead == 1243 ||
          lookahead == 1245 ||
          lookahead == 1247 ||
          lookahead == 1249 ||
          lookahead == 1251 ||
          lookahead == 1253 ||
          lookahead == 1255 ||
          lookahead == 1257 ||
          lookahead == 1259 ||
          lookahead == 1261 ||
          lookahead == 1263 ||
          lookahead == 1265 ||
          lookahead == 1267 ||
          lookahead == 1269 ||
          lookahead == 1271 ||
          lookahead == 1273 ||
          lookahead == 1275 ||
          lookahead == 1277 ||
          lookahead == 1279 ||
          lookahead == 1281 ||
          lookahead == 1283 ||
          lookahead == 1285 ||
          lookahead == 1287 ||
          lookahead == 1289 ||
          lookahead == 1291 ||
          lookahead == 1293 ||
          lookahead == 1295 ||
          lookahead == 1297 ||
          lookahead == 1299 ||
          lookahead == 1301 ||
          lookahead == 1303 ||
          lookahead == 1305 ||
          lookahead == 1307 ||
          lookahead == 1309 ||
          lookahead == 1311 ||
          lookahead == 1313 ||
          lookahead == 1315 ||
          lookahead == 1317 ||
          lookahead == 1319 ||
          lookahead == 1321 ||
          lookahead == 1323 ||
          lookahead == 1325 ||
          lookahead == 1327 ||
          (1376 <= lookahead && lookahead <= 1416) ||
          (4304 <= lookahead && lookahead <= 4346) ||
          (4349 <= lookahead && lookahead <= 4351) ||
          (5112 <= lookahead && lookahead <= 5117) ||
          (7296 <= lookahead && lookahead <= 7304) ||
          (7424 <= lookahead && lookahead <= 7467) ||
          (7531 <= lookahead && lookahead <= 7578) ||
          lookahead == 7681 ||
          lookahead == 7683 ||
          lookahead == 7685 ||
          lookahead == 7687 ||
          lookahead == 7689 ||
          lookahead == 7691 ||
          lookahead == 7693 ||
          lookahead == 7695 ||
          lookahead == 7697 ||
          lookahead == 7699 ||
          lookahead == 7701 ||
          lookahead == 7703 ||
          lookahead == 7705 ||
          lookahead == 7707 ||
          lookahead == 7709 ||
          lookahead == 7711 ||
          lookahead == 7713 ||
          lookahead == 7715 ||
          lookahead == 7717 ||
          lookahead == 7719 ||
          lookahead == 7721 ||
          lookahead == 7723 ||
          lookahead == 7725 ||
          lookahead == 7727 ||
          lookahead == 7729 ||
          lookahead == 7731 ||
          lookahead == 7733 ||
          lookahead == 7735 ||
          lookahead == 7737 ||
          lookahead == 7739 ||
          lookahead == 7741 ||
          lookahead == 7743 ||
          lookahead == 7745 ||
          lookahead == 7747 ||
          lookahead == 7749 ||
          lookahead == 7751 ||
          lookahead == 7753 ||
          lookahead == 7755 ||
          lookahead == 7757 ||
          lookahead == 7759 ||
          lookahead == 7761 ||
          lookahead == 7763 ||
          lookahead == 7765 ||
          lookahead == 7767 ||
          lookahead == 7769 ||
          lookahead == 7771 ||
          lookahead == 7773 ||
          lookahead == 7775 ||
          lookahead == 7777 ||
          lookahead == 7779 ||
          lookahead == 7781 ||
          lookahead == 7783 ||
          lookahead == 7785 ||
          lookahead == 7787 ||
          lookahead == 7789 ||
          lookahead == 7791 ||
          lookahead == 7793 ||
          lookahead == 7795 ||
          lookahead == 7797 ||
          lookahead == 7799 ||
          lookahead == 7801 ||
          lookahead == 7803 ||
          lookahead == 7805 ||
          lookahead == 7807 ||
          lookahead == 7809 ||
          lookahead == 7811 ||
          lookahead == 7813 ||
          lookahead == 7815 ||
          lookahead == 7817 ||
          lookahead == 7819 ||
          lookahead == 7821 ||
          lookahead == 7823 ||
          lookahead == 7825 ||
          lookahead == 7827 ||
          (7829 <= lookahead && lookahead <= 7837) ||
          lookahead == 7839 ||
          lookahead == 7841 ||
          lookahead == 7843 ||
          lookahead == 7845 ||
          lookahead == 7847 ||
          lookahead == 7849 ||
          lookahead == 7851 ||
          lookahead == 7853 ||
          lookahead == 7855 ||
          lookahead == 7857 ||
          lookahead == 7859 ||
          lookahead == 7861 ||
          lookahead == 7863 ||
          lookahead == 7865 ||
          lookahead == 7867 ||
          lookahead == 7869 ||
          lookahead == 7871 ||
          lookahead == 7873 ||
          lookahead == 7875 ||
          lookahead == 7877 ||
          lookahead == 7879 ||
          lookahead == 7881 ||
          lookahead == 7883 ||
          lookahead == 7885 ||
          lookahead == 7887 ||
          lookahead == 7889 ||
          lookahead == 7891 ||
          lookahead == 7893 ||
          lookahead == 7895 ||
          lookahead == 7897 ||
          lookahead == 7899 ||
          lookahead == 7901 ||
          lookahead == 7903 ||
          lookahead == 7905 ||
          lookahead == 7907 ||
          lookahead == 7909 ||
          lookahead == 7911 ||
          lookahead == 7913 ||
          lookahead == 7915 ||
          lookahead == 7917 ||
          lookahead == 7919 ||
          lookahead == 7921 ||
          lookahead == 7923 ||
          lookahead == 7925 ||
          lookahead == 7927 ||
          lookahead == 7929 ||
          lookahead == 7931 ||
          lookahead == 7933 ||
          (7935 <= lookahead && lookahead <= 7943) ||
          (7952 <= lookahead && lookahead <= 7957) ||
          (7968 <= lookahead && lookahead <= 7975) ||
          (7984 <= lookahead && lookahead <= 7991) ||
          (8000 <= lookahead && lookahead <= 8005) ||
          (8016 <= lookahead && lookahead <= 8023) ||
          (8032 <= lookahead && lookahead <= 8039) ||
          (8048 <= lookahead && lookahead <= 8061) ||
          (8064 <= lookahead && lookahead <= 8071) ||
          (8080 <= lookahead && lookahead <= 8087) ||
          (8096 <= lookahead && lookahead <= 8103) ||
          (8112 <= lookahead && lookahead <= 8116) ||
          lookahead == 8118 ||
          lookahead == 8119 ||
          lookahead == 8126 ||
          (8130 <= lookahead && lookahead <= 8132) ||
          lookahead == 8134 ||
          lookahead == 8135 ||
          (8144 <= lookahead && lookahead <= 8147) ||
          lookahead == 8150 ||
          lookahead == 8151 ||
          (8160 <= lookahead && lookahead <= 8167) ||
          (8178 <= lookahead && lookahead <= 8180) ||
          lookahead == 8182 ||
          lookahead == 8183 ||
          lookahead == 8458 ||
          lookahead == 8462 ||
          lookahead == 8463 ||
          lookahead == 8467 ||
          lookahead == 8495 ||
          lookahead == 8500 ||
          lookahead == 8505 ||
          lookahead == 8508 ||
          lookahead == 8509 ||
          (8518 <= lookahead && lookahead <= 8521) ||
          lookahead == 8526 ||
          lookahead == 8580 ||
          (11312 <= lookahead && lookahead <= 11358) ||
          lookahead == 11361 ||
          lookahead == 11365 ||
          lookahead == 11366 ||
          lookahead == 11368 ||
          lookahead == 11370 ||
          lookahead == 11372 ||
          lookahead == 11377 ||
          lookahead == 11379 ||
          lookahead == 11380 ||
          (11382 <= lookahead && lookahead <= 11387) ||
          lookahead == 11393 ||
          lookahead == 11395 ||
          lookahead == 11397 ||
          lookahead == 11399 ||
          lookahead == 11401 ||
          lookahead == 11403 ||
          lookahead == 11405 ||
          lookahead == 11407 ||
          lookahead == 11409 ||
          lookahead == 11411 ||
          lookahead == 11413 ||
          lookahead == 11415 ||
          lookahead == 11417 ||
          lookahead == 11419 ||
          lookahead == 11421 ||
          lookahead == 11423 ||
          lookahead == 11425 ||
          lookahead == 11427 ||
          lookahead == 11429 ||
          lookahead == 11431 ||
          lookahead == 11433 ||
          lookahead == 11435 ||
          lookahead == 11437 ||
          lookahead == 11439 ||
          lookahead == 11441 ||
          lookahead == 11443 ||
          lookahead == 11445 ||
          lookahead == 11447 ||
          lookahead == 11449 ||
          lookahead == 11451 ||
          lookahead == 11453 ||
          lookahead == 11455 ||
          lookahead == 11457 ||
          lookahead == 11459 ||
          lookahead == 11461 ||
          lookahead == 11463 ||
          lookahead == 11465 ||
          lookahead == 11467 ||
          lookahead == 11469 ||
          lookahead == 11471 ||
          lookahead == 11473 ||
          lookahead == 11475 ||
          lookahead == 11477 ||
          lookahead == 11479 ||
          lookahead == 11481 ||
          lookahead == 11483 ||
          lookahead == 11485 ||
          lookahead == 11487 ||
          lookahead == 11489 ||
          lookahead == 11491 ||
          lookahead == 11492 ||
          lookahead == 11500 ||
          lookahead == 11502 ||
          lookahead == 11507 ||
          (11520 <= lookahead && lookahead <= 11557) ||
          lookahead == 11559 ||
          lookahead == 11565 ||
          lookahead == 42561 ||
          lookahead == 42563 ||
          lookahead == 42565 ||
          lookahead == 42567 ||
          lookahead == 42569 ||
          lookahead == 42571 ||
          lookahead == 42573 ||
          lookahead == 42575 ||
          lookahead == 42577 ||
          lookahead == 42579 ||
          lookahead == 42581 ||
          lookahead == 42583 ||
          lookahead == 42585 ||
          lookahead == 42587 ||
          lookahead == 42589 ||
          lookahead == 42591 ||
          lookahead == 42593 ||
          lookahead == 42595 ||
          lookahead == 42597 ||
          lookahead == 42599 ||
          lookahead == 42601 ||
          lookahead == 42603 ||
          lookahead == 42605 ||
          lookahead == 42625 ||
          lookahead == 42627 ||
          lookahead == 42629 ||
          lookahead == 42631 ||
          lookahead == 42633 ||
          lookahead == 42635 ||
          lookahead == 42637 ||
          lookahead == 42639 ||
          lookahead == 42641 ||
          lookahead == 42643 ||
          lookahead == 42645 ||
          lookahead == 42647 ||
          lookahead == 42649 ||
          lookahead == 42651 ||
          lookahead == 42787 ||
          lookahead == 42789 ||
          lookahead == 42791 ||
          lookahead == 42793 ||
          lookahead == 42795 ||
          lookahead == 42797 ||
          (42799 <= lookahead && lookahead <= 42801) ||
          lookahead == 42803 ||
          lookahead == 42805 ||
          lookahead == 42807 ||
          lookahead == 42809 ||
          lookahead == 42811 ||
          lookahead == 42813 ||
          lookahead == 42815 ||
          lookahead == 42817 ||
          lookahead == 42819 ||
          lookahead == 42821 ||
          lookahead == 42823 ||
          lookahead == 42825 ||
          lookahead == 42827 ||
          lookahead == 42829 ||
          lookahead == 42831 ||
          lookahead == 42833 ||
          lookahead == 42835 ||
          lookahead == 42837 ||
          lookahead == 42839 ||
          lookahead == 42841 ||
          lookahead == 42843 ||
          lookahead == 42845 ||
          lookahead == 42847 ||
          lookahead == 42849 ||
          lookahead == 42851 ||
          lookahead == 42853 ||
          lookahead == 42855 ||
          lookahead == 42857 ||
          lookahead == 42859 ||
          lookahead == 42861 ||
          (42863 <= lookahead && lookahead <= 42872) ||
          lookahead == 42874 ||
          lookahead == 42876 ||
          lookahead == 42879 ||
          lookahead == 42881 ||
          lookahead == 42883 ||
          lookahead == 42885 ||
          lookahead == 42887 ||
          lookahead == 42892 ||
          lookahead == 42894 ||
          lookahead == 42897 ||
          (42899 <= lookahead && lookahead <= 42901) ||
          lookahead == 42903 ||
          lookahead == 42905 ||
          lookahead == 42907 ||
          lookahead == 42909 ||
          lookahead == 42911 ||
          lookahead == 42913 ||
          lookahead == 42915 ||
          lookahead == 42917 ||
          lookahead == 42919 ||
          lookahead == 42921 ||
          lookahead == 42927 ||
          lookahead == 42933 ||
          lookahead == 42935 ||
          lookahead == 42937 ||
          lookahead == 42939 ||
          lookahead == 42941 ||
          lookahead == 42943 ||
          lookahead == 42947 ||
          lookahead == 42952 ||
          lookahead == 42954 ||
          lookahead == 42998 ||
          lookahead == 43002 ||
          (43824 <= lookahead && lookahead <= 43866) ||
          (43872 <= lookahead && lookahead <= 43880) ||
          (43888 <= lookahead && lookahead <= 43967) ||
          (64256 <= lookahead && lookahead <= 64262) ||
          (64275 <= lookahead && lookahead <= 64279) ||
          (65345 <= lookahead && lookahead <= 65370) ||
          (66600 <= lookahead && lookahead <= 66639) ||
          (66776 <= lookahead && lookahead <= 66811)) ADVANCE(14);
      if (lookahead == 186 ||
          (192 <= lookahead && lookahead <= 214) ||
          (216 <= lookahead && lookahead <= 222) ||
          (256 <= lookahead && lookahead <= 703) ||
          (710 <= lookahead && lookahead <= 721) ||
          lookahead == 748 ||
          lookahead == 750 ||
          (880 <= lookahead && lookahead <= 884) ||
          lookahead == 886 ||
          lookahead == 895 ||
          lookahead == 902 ||
          (904 <= lookahead && lookahead <= 906) ||
          lookahead == 908 ||
          (910 <= lookahead && lookahead <= 929) ||
          (931 <= lookahead && lookahead <= 1012) ||
          (1015 <= lookahead && lookahead <= 1152) ||
          (1162 <= lookahead && lookahead <= 1326) ||
          (1329 <= lookahead && lookahead <= 1366) ||
          lookahead == 1369 ||
          (1488 <= lookahead && lookahead <= 1514) ||
          (1519 <= lookahead && lookahead <= 1522) ||
          (1568 <= lookahead && lookahead <= 1610) ||
          lookahead == 1646 ||
          lookahead == 1647 ||
          (1649 <= lookahead && lookahead <= 1747) ||
          lookahead == 1749 ||
          lookahead == 1765 ||
          lookahead == 1766 ||
          lookahead == 1774 ||
          lookahead == 1775 ||
          (1786 <= lookahead && lookahead <= 1788) ||
          lookahead == 1791 ||
          lookahead == 1808 ||
          (1810 <= lookahead && lookahead <= 1839) ||
          (1869 <= lookahead && lookahead <= 1957) ||
          lookahead == 1969 ||
          (1994 <= lookahead && lookahead <= 2026) ||
          lookahead == 2036 ||
          lookahead == 2037 ||
          lookahead == 2042 ||
          (2048 <= lookahead && lookahead <= 2069) ||
          lookahead == 2074 ||
          lookahead == 2084 ||
          lookahead == 2088 ||
          (2112 <= lookahead && lookahead <= 2136) ||
          (2144 <= lookahead && lookahead <= 2154) ||
          (2208 <= lookahead && lookahead <= 2228) ||
          (2230 <= lookahead && lookahead <= 2247) ||
          (2308 <= lookahead && lookahead <= 2361) ||
          lookahead == 2365 ||
          lookahead == 2384 ||
          (2392 <= lookahead && lookahead <= 2401) ||
          (2417 <= lookahead && lookahead <= 2432) ||
          (2437 <= lookahead && lookahead <= 2444) ||
          lookahead == 2447 ||
          lookahead == 2448 ||
          (2451 <= lookahead && lookahead <= 2472) ||
          (2474 <= lookahead && lookahead <= 2480) ||
          lookahead == 2482 ||
          (2486 <= lookahead && lookahead <= 2489) ||
          lookahead == 2493 ||
          lookahead == 2510 ||
          lookahead == 2524 ||
          lookahead == 2525 ||
          (2527 <= lookahead && lookahead <= 2529) ||
          lookahead == 2544 ||
          lookahead == 2545 ||
          lookahead == 2556 ||
          (2565 <= lookahead && lookahead <= 2570) ||
          lookahead == 2575 ||
          lookahead == 2576 ||
          (2579 <= lookahead && lookahead <= 2600) ||
          (2602 <= lookahead && lookahead <= 2608) ||
          lookahead == 2610 ||
          lookahead == 2611 ||
          lookahead == 2613 ||
          lookahead == 2614 ||
          lookahead == 2616 ||
          lookahead == 2617 ||
          (2649 <= lookahead && lookahead <= 2652) ||
          lookahead == 2654 ||
          (2674 <= lookahead && lookahead <= 2676) ||
          (2693 <= lookahead && lookahead <= 2701) ||
          (2703 <= lookahead && lookahead <= 2705) ||
          (2707 <= lookahead && lookahead <= 2728) ||
          (2730 <= lookahead && lookahead <= 2736) ||
          lookahead == 2738 ||
          lookahead == 2739 ||
          (2741 <= lookahead && lookahead <= 2745) ||
          lookahead == 2749 ||
          lookahead == 2768 ||
          lookahead == 2784 ||
          lookahead == 2785 ||
          lookahead == 2809 ||
          (2821 <= lookahead && lookahead <= 2828) ||
          lookahead == 2831 ||
          lookahead == 2832 ||
          (2835 <= lookahead && lookahead <= 2856) ||
          (2858 <= lookahead && lookahead <= 2864) ||
          lookahead == 2866 ||
          lookahead == 2867 ||
          (2869 <= lookahead && lookahead <= 2873) ||
          lookahead == 2877 ||
          lookahead == 2908 ||
          lookahead == 2909 ||
          (2911 <= lookahead && lookahead <= 2913) ||
          lookahead == 2929 ||
          lookahead == 2947 ||
          (2949 <= lookahead && lookahead <= 2954) ||
          (2958 <= lookahead && lookahead <= 2960) ||
          (2962 <= lookahead && lookahead <= 2965) ||
          lookahead == 2969 ||
          lookahead == 2970 ||
          lookahead == 2972 ||
          lookahead == 2974 ||
          lookahead == 2975 ||
          lookahead == 2979 ||
          lookahead == 2980 ||
          (2984 <= lookahead && lookahead <= 2986) ||
          (2990 <= lookahead && lookahead <= 3001) ||
          lookahead == 3024 ||
          (3077 <= lookahead && lookahead <= 3084) ||
          (3086 <= lookahead && lookahead <= 3088) ||
          (3090 <= lookahead && lookahead <= 3112) ||
          (3114 <= lookahead && lookahead <= 3129) ||
          lookahead == 3133 ||
          (3160 <= lookahead && lookahead <= 3162) ||
          lookahead == 3168 ||
          lookahead == 3169 ||
          lookahead == 3200 ||
          (3205 <= lookahead && lookahead <= 3212) ||
          (3214 <= lookahead && lookahead <= 3216) ||
          (3218 <= lookahead && lookahead <= 3240) ||
          (3242 <= lookahead && lookahead <= 3251) ||
          (3253 <= lookahead && lookahead <= 3257) ||
          lookahead == 3261 ||
          lookahead == 3294 ||
          lookahead == 3296 ||
          lookahead == 3297 ||
          lookahead == 3313 ||
          lookahead == 3314 ||
          (3332 <= lookahead && lookahead <= 3340) ||
          (3342 <= lookahead && lookahead <= 3344) ||
          (3346 <= lookahead && lookahead <= 3386) ||
          lookahead == 3389 ||
          lookahead == 3406 ||
          (3412 <= lookahead && lookahead <= 3414) ||
          (3423 <= lookahead && lookahead <= 3425) ||
          (3450 <= lookahead && lookahead <= 3455) ||
          (3461 <= lookahead && lookahead <= 3478) ||
          (3482 <= lookahead && lookahead <= 3505) ||
          (3507 <= lookahead && lookahead <= 3515) ||
          lookahead == 3517 ||
          (3520 <= lookahead && lookahead <= 3526) ||
          (3585 <= lookahead && lookahead <= 3632) ||
          lookahead == 3634 ||
          lookahead == 3635 ||
          (3648 <= lookahead && lookahead <= 3654) ||
          lookahead == 3713 ||
          lookahead == 3714 ||
          lookahead == 3716 ||
          (3718 <= lookahead && lookahead <= 3722) ||
          (3724 <= lookahead && lookahead <= 3747) ||
          lookahead == 3749 ||
          (3751 <= lookahead && lookahead <= 3760) ||
          lookahead == 3762 ||
          lookahead == 3763 ||
          lookahead == 3773 ||
          (3776 <= lookahead && lookahead <= 3780) ||
          lookahead == 3782 ||
          (3804 <= lookahead && lookahead <= 3807) ||
          lookahead == 3840 ||
          (3904 <= lookahead && lookahead <= 3911) ||
          (3913 <= lookahead && lookahead <= 3948) ||
          (3976 <= lookahead && lookahead <= 3980) ||
          (4096 <= lookahead && lookahead <= 4138) ||
          lookahead == 4159 ||
          (4176 <= lookahead && lookahead <= 4181) ||
          (4186 <= lookahead && lookahead <= 4189) ||
          lookahead == 4193 ||
          lookahead == 4197 ||
          lookahead == 4198 ||
          (4206 <= lookahead && lookahead <= 4208) ||
          (4213 <= lookahead && lookahead <= 4225) ||
          lookahead == 4238 ||
          (4256 <= lookahead && lookahead <= 4293) ||
          lookahead == 4295 ||
          lookahead == 4301 ||
          (4348 <= lookahead && lookahead <= 4680) ||
          (4682 <= lookahead && lookahead <= 4685) ||
          (4688 <= lookahead && lookahead <= 4694) ||
          lookahead == 4696 ||
          (4698 <= lookahead && lookahead <= 4701) ||
          (4704 <= lookahead && lookahead <= 4744) ||
          (4746 <= lookahead && lookahead <= 4749) ||
          (4752 <= lookahead && lookahead <= 4784) ||
          (4786 <= lookahead && lookahead <= 4789) ||
          (4792 <= lookahead && lookahead <= 4798) ||
          lookahead == 4800 ||
          (4802 <= lookahead && lookahead <= 4805) ||
          (4808 <= lookahead && lookahead <= 4822) ||
          (4824 <= lookahead && lookahead <= 4880) ||
          (4882 <= lookahead && lookahead <= 4885) ||
          (4888 <= lookahead && lookahead <= 4954) ||
          (4992 <= lookahead && lookahead <= 5007) ||
          (5024 <= lookahead && lookahead <= 5109) ||
          (5121 <= lookahead && lookahead <= 5740) ||
          (5743 <= lookahead && lookahead <= 5759) ||
          (5761 <= lookahead && lookahead <= 5786) ||
          (5792 <= lookahead && lookahead <= 5866) ||
          (5870 <= lookahead && lookahead <= 5880) ||
          (5888 <= lookahead && lookahead <= 5900) ||
          (5902 <= lookahead && lookahead <= 5905) ||
          (5920 <= lookahead && lookahead <= 5937) ||
          (5952 <= lookahead && lookahead <= 5969) ||
          (5984 <= lookahead && lookahead <= 5996) ||
          (5998 <= lookahead && lookahead <= 6000) ||
          (6016 <= lookahead && lookahead <= 6067) ||
          lookahead == 6103 ||
          lookahead == 6108 ||
          (6176 <= lookahead && lookahead <= 6264) ||
          (6272 <= lookahead && lookahead <= 6276) ||
          (6279 <= lookahead && lookahead <= 6312) ||
          lookahead == 6314 ||
          (6320 <= lookahead && lookahead <= 6389) ||
          (6400 <= lookahead && lookahead <= 6430) ||
          (6480 <= lookahead && lookahead <= 6509) ||
          (6512 <= lookahead && lookahead <= 6516) ||
          (6528 <= lookahead && lookahead <= 6571) ||
          (6576 <= lookahead && lookahead <= 6601) ||
          (6656 <= lookahead && lookahead <= 6678) ||
          (6688 <= lookahead && lookahead <= 6740) ||
          lookahead == 6823 ||
          (6917 <= lookahead && lookahead <= 6963) ||
          (6981 <= lookahead && lookahead <= 6987) ||
          (7043 <= lookahead && lookahead <= 7072) ||
          lookahead == 7086 ||
          lookahead == 7087 ||
          (7098 <= lookahead && lookahead <= 7141) ||
          (7168 <= lookahead && lookahead <= 7203) ||
          (7245 <= lookahead && lookahead <= 7247) ||
          (7258 <= lookahead && lookahead <= 7293) ||
          (7312 <= lookahead && lookahead <= 7354) ||
          (7357 <= lookahead && lookahead <= 7359) ||
          (7401 <= lookahead && lookahead <= 7404) ||
          (7406 <= lookahead && lookahead <= 7411) ||
          lookahead == 7413 ||
          lookahead == 7414 ||
          lookahead == 7418 ||
          (7468 <= lookahead && lookahead <= 7530) ||
          (7680 <= lookahead && lookahead <= 7951) ||
          (7960 <= lookahead && lookahead <= 7965) ||
          (7976 <= lookahead && lookahead <= 7999) ||
          (8008 <= lookahead && lookahead <= 8013) ||
          lookahead == 8025 ||
          lookahead == 8027 ||
          lookahead == 8029 ||
          (8031 <= lookahead && lookahead <= 8047) ||
          (8072 <= lookahead && lookahead <= 8111) ||
          (8120 <= lookahead && lookahead <= 8124) ||
          (8136 <= lookahead && lookahead <= 8140) ||
          (8152 <= lookahead && lookahead <= 8155) ||
          (8168 <= lookahead && lookahead <= 8172) ||
          (8184 <= lookahead && lookahead <= 8188) ||
          lookahead == 8450 ||
          lookahead == 8455 ||
          (8459 <= lookahead && lookahead <= 8466) ||
          lookahead == 8469 ||
          (8473 <= lookahead && lookahead <= 8477) ||
          lookahead == 8484 ||
          lookahead == 8486 ||
          lookahead == 8488 ||
          (8490 <= lookahead && lookahead <= 8493) ||
          (8496 <= lookahead && lookahead <= 8504) ||
          lookahead == 8510 ||
          lookahead == 8511 ||
          lookahead == 8517 ||
          (8544 <= lookahead && lookahead <= 8584) ||
          (11264 <= lookahead && lookahead <= 11310) ||
          (11360 <= lookahead && lookahead <= 11490) ||
          (11499 <= lookahead && lookahead <= 11501) ||
          lookahead == 11506 ||
          (11568 <= lookahead && lookahead <= 11623) ||
          lookahead == 11631 ||
          (11648 <= lookahead && lookahead <= 11670) ||
          (11680 <= lookahead && lookahead <= 11686) ||
          (11688 <= lookahead && lookahead <= 11694) ||
          (11696 <= lookahead && lookahead <= 11702) ||
          (11704 <= lookahead && lookahead <= 11710) ||
          (11712 <= lookahead && lookahead <= 11718) ||
          (11720 <= lookahead && lookahead <= 11726) ||
          (11728 <= lookahead && lookahead <= 11734) ||
          (11736 <= lookahead && lookahead <= 11742) ||
          lookahead == 11823 ||
          (12293 <= lookahead && lookahead <= 12295) ||
          (12321 <= lookahead && lookahead <= 12329) ||
          (12337 <= lookahead && lookahead <= 12341) ||
          (12344 <= lookahead && lookahead <= 12348) ||
          (12353 <= lookahead && lookahead <= 12438) ||
          (12445 <= lookahead && lookahead <= 12447) ||
          (12449 <= lookahead && lookahead <= 12538) ||
          (12540 <= lookahead && lookahead <= 12543) ||
          (12549 <= lookahead && lookahead <= 12591) ||
          (12593 <= lookahead && lookahead <= 12686) ||
          (12704 <= lookahead && lookahead <= 12735) ||
          (12784 <= lookahead && lookahead <= 12799) ||
          lookahead == 13312 ||
          lookahead == 19903 ||
          lookahead == 19968 ||
          lookahead == 40956 ||
          (40960 <= lookahead && lookahead <= 42124) ||
          (42192 <= lookahead && lookahead <= 42237) ||
          (42240 <= lookahead && lookahead <= 42508) ||
          (42512 <= lookahead && lookahead <= 42527) ||
          lookahead == 42538 ||
          lookahead == 42539 ||
          (42560 <= lookahead && lookahead <= 42606) ||
          (42623 <= lookahead && lookahead <= 42650) ||
          (42656 <= lookahead && lookahead <= 42735) ||
          (42775 <= lookahead && lookahead <= 42783) ||
          (42786 <= lookahead && lookahead <= 42888) ||
          (42891 <= lookahead && lookahead <= 42942) ||
          (42946 <= lookahead && lookahead <= 42953) ||
          (42997 <= lookahead && lookahead <= 43009) ||
          (43011 <= lookahead && lookahead <= 43013) ||
          (43015 <= lookahead && lookahead <= 43018) ||
          (43020 <= lookahead && lookahead <= 43042) ||
          (43072 <= lookahead && lookahead <= 43123) ||
          (43138 <= lookahead && lookahead <= 43187) ||
          (43250 <= lookahead && lookahead <= 43255) ||
          lookahead == 43259 ||
          lookahead == 43261 ||
          lookahead == 43262 ||
          (43274 <= lookahead && lookahead <= 43301) ||
          (43312 <= lookahead && lookahead <= 43334) ||
          (43360 <= lookahead && lookahead <= 43388) ||
          (43396 <= lookahead && lookahead <= 43442) ||
          lookahead == 43471 ||
          (43488 <= lookahead && lookahead <= 43492) ||
          (43494 <= lookahead && lookahead <= 43503) ||
          (43514 <= lookahead && lookahead <= 43518) ||
          (43520 <= lookahead && lookahead <= 43560) ||
          (43584 <= lookahead && lookahead <= 43586) ||
          (43588 <= lookahead && lookahead <= 43595) ||
          (43616 <= lookahead && lookahead <= 43638) ||
          lookahead == 43642 ||
          (43646 <= lookahead && lookahead <= 43695) ||
          lookahead == 43697 ||
          lookahead == 43701 ||
          lookahead == 43702 ||
          (43705 <= lookahead && lookahead <= 43709) ||
          lookahead == 43712 ||
          lookahead == 43714 ||
          (43739 <= lookahead && lookahead <= 43741) ||
          (43744 <= lookahead && lookahead <= 43754) ||
          (43762 <= lookahead && lookahead <= 43764) ||
          (43777 <= lookahead && lookahead <= 43782) ||
          (43785 <= lookahead && lookahead <= 43790) ||
          (43793 <= lookahead && lookahead <= 43798) ||
          (43808 <= lookahead && lookahead <= 43814) ||
          (43816 <= lookahead && lookahead <= 43822) ||
          lookahead == 43881 ||
          (43968 <= lookahead && lookahead <= 44002) ||
          lookahead == 44032 ||
          lookahead == 55203 ||
          (55216 <= lookahead && lookahead <= 55238) ||
          (55243 <= lookahead && lookahead <= 55291) ||
          (63744 <= lookahead && lookahead <= 64109) ||
          (64112 <= lookahead && lookahead <= 64217) ||
          lookahead == 64285 ||
          (64287 <= lookahead && lookahead <= 64296) ||
          (64298 <= lookahead && lookahead <= 64310) ||
          (64312 <= lookahead && lookahead <= 64316) ||
          lookahead == 64318 ||
          lookahead == 64320 ||
          lookahead == 64321 ||
          lookahead == 64323 ||
          lookahead == 64324 ||
          (64326 <= lookahead && lookahead <= 64433) ||
          (64467 <= lookahead && lookahead <= 64829) ||
          (64848 <= lookahead && lookahead <= 64911) ||
          (64914 <= lookahead && lookahead <= 64967) ||
          (65008 <= lookahead && lookahead <= 65019) ||
          (65136 <= lookahead && lookahead <= 65140) ||
          (65142 <= lookahead && lookahead <= 65276) ||
          (65313 <= lookahead && lookahead <= 65338) ||
          (65382 <= lookahead && lookahead <= 65470) ||
          (65474 <= lookahead && lookahead <= 65479) ||
          (65482 <= lookahead && lookahead <= 65487) ||
          (65490 <= lookahead && lookahead <= 65495) ||
          (65498 <= lookahead && lookahead <= 65500) ||
          (65536 <= lookahead && lookahead <= 65547) ||
          (65549 <= lookahead && lookahead <= 65574) ||
          (65576 <= lookahead && lookahead <= 65594) ||
          lookahead == 65596 ||
          lookahead == 65597 ||
          (65599 <= lookahead && lookahead <= 65613) ||
          (65616 <= lookahead && lookahead <= 65629) ||
          (65664 <= lookahead && lookahead <= 65786) ||
          (65856 <= lookahead && lookahead <= 65908) ||
          (66176 <= lookahead && lookahead <= 66204) ||
          (66208 <= lookahead && lookahead <= 66256) ||
          (66304 <= lookahead && lookahead <= 66335) ||
          (66349 <= lookahead && lookahead <= 66378) ||
          (66384 <= lookahead && lookahead <= 66421) ||
          (66432 <= lookahead && lookahead <= 66461) ||
          (66464 <= lookahead && lookahead <= 66499) ||
          (66504 <= lookahead && lookahead <= 66511) ||
          (66513 <= lookahead && lookahead <= 66517) ||
          (66560 <= lookahead && lookahead <= 66717) ||
          (66736 <= lookahead && lookahead <= 66771) ||
          (66816 <= lookahead && lookahead <= 66855) ||
          (66864 <= lookahead && lookahead <= 66915) ||
          (67072 <= lookahead && lookahead <= 67382) ||
          (67392 <= lookahead && lookahead <= 67413) ||
          (67424 <= lookahead && lookahead <= 67431) ||
          (67584 <= lookahead && lookahead <= 67589) ||
          lookahead == 67592 ||
          (67594 <= lookahead && lookahead <= 67637) ||
          lookahead == 67639 ||
          lookahead == 67640 ||
          lookahead == 67644 ||
          (67647 <= lookahead && lookahead <= 67669) ||
          (67680 <= lookahead && lookahead <= 67702) ||
          (67712 <= lookahead && lookahead <= 67742) ||
          (67808 <= lookahead && lookahead <= 67826) ||
          lookahead == 67828 ||
          lookahead == 67829 ||
          (67840 <= lookahead && lookahead <= 67861) ||
          (67872 <= lookahead && lookahead <= 67897) ||
          (67968 <= lookahead && lookahead <= 68023) ||
          lookahead == 68030 ||
          lookahead == 68031 ||
          lookahead == 68096 ||
          (68112 <= lookahead && lookahead <= 68115) ||
          (68117 <= lookahead && lookahead <= 68119) ||
          (68121 <= lookahead && lookahead <= 68149) ||
          (68192 <= lookahead && lookahead <= 68220) ||
          (68224 <= lookahead && lookahead <= 68252) ||
          (68288 <= lookahead && lookahead <= 68295) ||
          (68297 <= lookahead && lookahead <= 68309)) ADVANCE(13);
      END_STATE();
    case 1:
      if (lookahead == '*') ADVANCE(36);
      if (lookahead == '/') ADVANCE(39);
      END_STATE();
    case 2:
      if (lookahead == '/') ADVANCE(38);
      END_STATE();
    case 3:
      if (lookahead == 'e') ADVANCE(30);
      END_STATE();
    case 4:
      if (lookahead == 'e') ADVANCE(31);
      END_STATE();
    case 5:
      if (lookahead == 'l') ADVANCE(7);
      END_STATE();
    case 6:
      if (lookahead == 'r') ADVANCE(8);
      END_STATE();
    case 7:
      if (lookahead == 's') ADVANCE(4);
      END_STATE();
    case 8:
      if (lookahead == 'u') ADVANCE(3);
      END_STATE();
    case 9:
      if (eof) ADVANCE(10);
      if (lookahead == '*') ADVANCE(2);
      if (lookahead == '.') ADVANCE(34);
      if (lookahead == '/') ADVANCE(1);
      if (lookahead == 'f') ADVANCE(29);
      if (lookahead == 't') ADVANCE(6);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(27);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(26);
      if (('D' <= lookahead && lookahead <= 'F') ||
          lookahead == 'd') ADVANCE(28);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(11);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(15);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(sym__whiteSpace);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(sym__whiteSpace);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(43);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(sym__upper);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(aux_sym__lower_token1);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(sym__digit);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(sym__paren);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(sym__delim);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(sym__opchar);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(sym__opchar);
      if (lookahead == '*') ADVANCE(36);
      if (lookahead == '/') ADVANCE(39);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(sym__printableChar);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(anon_sym_BSLASH);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(anon_sym_u);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_BQUOTE);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym__);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(anon_sym_0);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(aux_sym__exponentPart_token1);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(aux_sym__exponentPart_token2);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(sym__floatType);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(sym__floatType);
      if (lookahead == 'a') ADVANCE(5);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(sym__decimalPoint);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(anon_sym_DOLLAR);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(anon_sym_SLASH_STAR);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_SLASH_STAR);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(43);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_STAR_SLASH);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_SLASH_SLASH);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(anon_sym_SLASH_SLASH);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(43);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(aux_sym__comment_token1);
      if (lookahead == '\n') ADVANCE(11);
      if (lookahead == '/') ADVANCE(42);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(12);
      if (lookahead != 0) ADVANCE(43);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(aux_sym__comment_token1);
      if (lookahead == '*') ADVANCE(37);
      if (lookahead == '/') ADVANCE(40);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(43);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(aux_sym__comment_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(43);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    default:
      return false;
  }
}

static TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 9},
  [2] = {.lex_state = 9},
  [3] = {.lex_state = 9},
  [4] = {.lex_state = 9},
  [5] = {.lex_state = 9},
  [6] = {.lex_state = 9},
  [7] = {.lex_state = 9},
  [8] = {.lex_state = 9},
  [9] = {.lex_state = 9},
  [10] = {.lex_state = 9},
  [11] = {.lex_state = 9},
  [12] = {.lex_state = 9},
  [13] = {.lex_state = 9},
  [14] = {.lex_state = 9},
  [15] = {.lex_state = 9},
  [16] = {.lex_state = 9},
  [17] = {.lex_state = 9},
  [18] = {.lex_state = 9},
  [19] = {.lex_state = 9},
  [20] = {.lex_state = 9},
  [21] = {.lex_state = 9},
  [22] = {.lex_state = 9},
  [23] = {.lex_state = 9},
  [24] = {.lex_state = 9, .external_lex_state = 1},
  [25] = {.lex_state = 9},
  [26] = {.lex_state = 9},
  [27] = {.lex_state = 41},
  [28] = {(TSStateId)(-1)},
  [29] = {(TSStateId)(-1)},
};

enum {
  ts_external_token__multi_comment = 0,
};

static TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token__multi_comment] = sym__multi_comment,
};

static bool ts_external_scanner_states[2][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token__multi_comment] = true,
  },
};

static uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [sym__comment] = STATE(0),
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym__whiteSpace] = ACTIONS(3),
    [sym__upper] = ACTIONS(1),
    [aux_sym__lower_token1] = ACTIONS(1),
    [aux_sym__lower_token2] = ACTIONS(1),
    [aux_sym__lower_token3] = ACTIONS(1),
    [sym__digit] = ACTIONS(1),
    [sym__paren] = ACTIONS(1),
    [sym__delim] = ACTIONS(1),
    [sym__opchar] = ACTIONS(1),
    [sym__printableChar] = ACTIONS(1),
    [anon_sym_BSLASH] = ACTIONS(1),
    [anon_sym_u] = ACTIONS(1),
    [sym__hexDigit] = ACTIONS(1),
    [aux_sym__charEscapeSeq_token1] = ACTIONS(1),
    [anon_sym_BQUOTE] = ACTIONS(1),
    [aux_sym__id_token1] = ACTIONS(1),
    [anon_sym__] = ACTIONS(1),
    [aux_sym__integerLiteral_token1] = ACTIONS(1),
    [anon_sym_0] = ACTIONS(1),
    [aux_sym__hexNumeral_token1] = ACTIONS(1),
    [aux_sym__exponentPart_token1] = ACTIONS(1),
    [aux_sym__exponentPart_token2] = ACTIONS(1),
    [sym__floatType] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [aux_sym__stringElement_token1] = ACTIONS(1),
    [sym__decimalPoint] = ACTIONS(1),
    [sym__charMinusQuoteDollar] = ACTIONS(1),
    [anon_sym_DOLLAR] = ACTIONS(1),
    [anon_sym_SLASH_STAR] = ACTIONS(5),
    [anon_sym_SLASH_SLASH] = ACTIONS(7),
    [anon_sym_SEMI] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [sym__multi_comment] = ACTIONS(1),
  },
  [1] = {
    [sym_compilation_unit] = STATE(26),
    [sym__floatingPointLiteral] = STATE(16),
    [sym__booleanLiteral] = STATE(16),
    [sym__comment] = STATE(1),
    [aux_sym_compilation_unit_repeat1] = STATE(4),
    [aux_sym__floatingPointLiteral_repeat1] = STATE(12),
    [sym__whiteSpace] = ACTIONS(3),
    [sym__digit] = ACTIONS(9),
    [anon_sym_true] = ACTIONS(11),
    [anon_sym_false] = ACTIONS(11),
    [sym__decimalPoint] = ACTIONS(13),
    [anon_sym_SLASH_STAR] = ACTIONS(5),
    [anon_sym_SLASH_SLASH] = ACTIONS(7),
  },
};

static uint16_t ts_small_parse_table[] = {
  [0] = 10,
    ACTIONS(3), 1,
      sym__whiteSpace,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(7), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(15), 1,
      ts_builtin_sym_end,
    ACTIONS(17), 1,
      sym__digit,
    ACTIONS(23), 1,
      sym__decimalPoint,
    STATE(12), 1,
      aux_sym__floatingPointLiteral_repeat1,
    ACTIONS(20), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(2), 2,
      sym__comment,
      aux_sym_compilation_unit_repeat1,
    STATE(16), 2,
      sym__floatingPointLiteral,
      sym__booleanLiteral,
  [34] = 10,
    ACTIONS(3), 1,
      sym__whiteSpace,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(7), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(9), 1,
      sym__digit,
    ACTIONS(28), 1,
      aux_sym__exponentPart_token1,
    ACTIONS(30), 1,
      sym__floatType,
    STATE(3), 1,
      sym__comment,
    STATE(6), 1,
      aux_sym__floatingPointLiteral_repeat1,
    STATE(10), 1,
      sym__exponentPart,
    ACTIONS(26), 4,
      ts_builtin_sym_end,
      anon_sym_true,
      anon_sym_false,
      sym__decimalPoint,
  [68] = 11,
    ACTIONS(3), 1,
      sym__whiteSpace,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(7), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(9), 1,
      sym__digit,
    ACTIONS(13), 1,
      sym__decimalPoint,
    ACTIONS(32), 1,
      ts_builtin_sym_end,
    STATE(2), 1,
      aux_sym_compilation_unit_repeat1,
    STATE(4), 1,
      sym__comment,
    STATE(12), 1,
      aux_sym__floatingPointLiteral_repeat1,
    ACTIONS(11), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(16), 2,
      sym__floatingPointLiteral,
      sym__booleanLiteral,
  [104] = 10,
    ACTIONS(3), 1,
      sym__whiteSpace,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(7), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(9), 1,
      sym__digit,
    ACTIONS(28), 1,
      aux_sym__exponentPart_token1,
    ACTIONS(36), 1,
      sym__floatType,
    STATE(5), 1,
      sym__comment,
    STATE(6), 1,
      aux_sym__floatingPointLiteral_repeat1,
    STATE(11), 1,
      sym__exponentPart,
    ACTIONS(34), 4,
      ts_builtin_sym_end,
      anon_sym_true,
      anon_sym_false,
      sym__decimalPoint,
  [138] = 7,
    ACTIONS(3), 1,
      sym__whiteSpace,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(7), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(40), 1,
      sym__digit,
    ACTIONS(43), 1,
      sym__floatType,
    STATE(6), 2,
      sym__comment,
      aux_sym__floatingPointLiteral_repeat1,
    ACTIONS(38), 5,
      ts_builtin_sym_end,
      aux_sym__exponentPart_token1,
      anon_sym_true,
      anon_sym_false,
      sym__decimalPoint,
  [165] = 8,
    ACTIONS(3), 1,
      sym__whiteSpace,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(7), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(9), 1,
      sym__digit,
    ACTIONS(47), 1,
      sym__floatType,
    STATE(6), 1,
      aux_sym__floatingPointLiteral_repeat1,
    STATE(7), 1,
      sym__comment,
    ACTIONS(45), 4,
      ts_builtin_sym_end,
      anon_sym_true,
      anon_sym_false,
      sym__decimalPoint,
  [193] = 6,
    ACTIONS(3), 1,
      sym__whiteSpace,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(7), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(51), 1,
      sym__floatType,
    STATE(8), 1,
      sym__comment,
    ACTIONS(49), 6,
      ts_builtin_sym_end,
      sym__digit,
      aux_sym__exponentPart_token1,
      anon_sym_true,
      anon_sym_false,
      sym__decimalPoint,
  [217] = 8,
    ACTIONS(3), 1,
      sym__whiteSpace,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(7), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(9), 1,
      sym__digit,
    ACTIONS(55), 1,
      sym__floatType,
    STATE(6), 1,
      aux_sym__floatingPointLiteral_repeat1,
    STATE(9), 1,
      sym__comment,
    ACTIONS(53), 4,
      ts_builtin_sym_end,
      anon_sym_true,
      anon_sym_false,
      sym__decimalPoint,
  [245] = 6,
    ACTIONS(3), 1,
      sym__whiteSpace,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(7), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(59), 1,
      sym__floatType,
    STATE(10), 1,
      sym__comment,
    ACTIONS(57), 5,
      ts_builtin_sym_end,
      sym__digit,
      anon_sym_true,
      anon_sym_false,
      sym__decimalPoint,
  [268] = 6,
    ACTIONS(3), 1,
      sym__whiteSpace,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(7), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(30), 1,
      sym__floatType,
    STATE(11), 1,
      sym__comment,
    ACTIONS(26), 5,
      ts_builtin_sym_end,
      sym__digit,
      anon_sym_true,
      anon_sym_false,
      sym__decimalPoint,
  [291] = 10,
    ACTIONS(3), 1,
      sym__whiteSpace,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(7), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(9), 1,
      sym__digit,
    ACTIONS(28), 1,
      aux_sym__exponentPart_token1,
    ACTIONS(61), 1,
      sym__floatType,
    ACTIONS(63), 1,
      sym__decimalPoint,
    STATE(6), 1,
      aux_sym__floatingPointLiteral_repeat1,
    STATE(12), 1,
      sym__comment,
    STATE(13), 1,
      sym__exponentPart,
  [322] = 6,
    ACTIONS(3), 1,
      sym__whiteSpace,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(7), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(36), 1,
      sym__floatType,
    STATE(13), 1,
      sym__comment,
    ACTIONS(34), 5,
      ts_builtin_sym_end,
      sym__digit,
      anon_sym_true,
      anon_sym_false,
      sym__decimalPoint,
  [345] = 5,
    ACTIONS(3), 1,
      sym__whiteSpace,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(7), 1,
      anon_sym_SLASH_SLASH,
    STATE(14), 1,
      sym__comment,
    ACTIONS(26), 5,
      ts_builtin_sym_end,
      sym__digit,
      anon_sym_true,
      anon_sym_false,
      sym__decimalPoint,
  [365] = 5,
    ACTIONS(3), 1,
      sym__whiteSpace,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(7), 1,
      anon_sym_SLASH_SLASH,
    STATE(15), 1,
      sym__comment,
    ACTIONS(34), 5,
      ts_builtin_sym_end,
      sym__digit,
      anon_sym_true,
      anon_sym_false,
      sym__decimalPoint,
  [385] = 5,
    ACTIONS(3), 1,
      sym__whiteSpace,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(7), 1,
      anon_sym_SLASH_SLASH,
    STATE(16), 1,
      sym__comment,
    ACTIONS(65), 5,
      ts_builtin_sym_end,
      sym__digit,
      anon_sym_true,
      anon_sym_false,
      sym__decimalPoint,
  [405] = 5,
    ACTIONS(3), 1,
      sym__whiteSpace,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(7), 1,
      anon_sym_SLASH_SLASH,
    STATE(17), 1,
      sym__comment,
    ACTIONS(57), 5,
      ts_builtin_sym_end,
      sym__digit,
      anon_sym_true,
      anon_sym_false,
      sym__decimalPoint,
  [425] = 5,
    ACTIONS(3), 1,
      sym__whiteSpace,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(7), 1,
      anon_sym_SLASH_SLASH,
    STATE(18), 1,
      sym__comment,
    ACTIONS(67), 5,
      ts_builtin_sym_end,
      sym__digit,
      anon_sym_true,
      anon_sym_false,
      sym__decimalPoint,
  [445] = 5,
    ACTIONS(3), 1,
      sym__whiteSpace,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(7), 1,
      anon_sym_SLASH_SLASH,
    STATE(19), 1,
      sym__comment,
    ACTIONS(69), 5,
      ts_builtin_sym_end,
      sym__digit,
      anon_sym_true,
      anon_sym_false,
      sym__decimalPoint,
  [465] = 7,
    ACTIONS(3), 1,
      sym__whiteSpace,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(7), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(9), 1,
      sym__digit,
    ACTIONS(71), 1,
      aux_sym__exponentPart_token2,
    STATE(9), 1,
      aux_sym__floatingPointLiteral_repeat1,
    STATE(20), 1,
      sym__comment,
  [487] = 6,
    ACTIONS(3), 1,
      sym__whiteSpace,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(7), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(9), 1,
      sym__digit,
    STATE(3), 1,
      aux_sym__floatingPointLiteral_repeat1,
    STATE(21), 1,
      sym__comment,
  [506] = 6,
    ACTIONS(3), 1,
      sym__whiteSpace,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(7), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(9), 1,
      sym__digit,
    STATE(7), 1,
      aux_sym__floatingPointLiteral_repeat1,
    STATE(22), 1,
      sym__comment,
  [525] = 6,
    ACTIONS(3), 1,
      sym__whiteSpace,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(7), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(9), 1,
      sym__digit,
    STATE(5), 1,
      aux_sym__floatingPointLiteral_repeat1,
    STATE(23), 1,
      sym__comment,
  [544] = 5,
    ACTIONS(3), 1,
      sym__whiteSpace,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(7), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(73), 1,
      sym__multi_comment,
    STATE(24), 1,
      sym__comment,
  [560] = 5,
    ACTIONS(3), 1,
      sym__whiteSpace,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(7), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(75), 1,
      anon_sym_STAR_SLASH,
    STATE(25), 1,
      sym__comment,
  [576] = 5,
    ACTIONS(3), 1,
      sym__whiteSpace,
    ACTIONS(5), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(7), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(77), 1,
      ts_builtin_sym_end,
    STATE(26), 1,
      sym__comment,
  [592] = 5,
    ACTIONS(79), 1,
      sym__whiteSpace,
    ACTIONS(81), 1,
      anon_sym_SLASH_STAR,
    ACTIONS(83), 1,
      anon_sym_SLASH_SLASH,
    ACTIONS(85), 1,
      aux_sym__comment_token1,
    STATE(27), 1,
      sym__comment,
  [608] = 1,
    ACTIONS(87), 1,
      ts_builtin_sym_end,
  [612] = 1,
    ACTIONS(89), 1,
      ts_builtin_sym_end,
};

static uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 34,
  [SMALL_STATE(4)] = 68,
  [SMALL_STATE(5)] = 104,
  [SMALL_STATE(6)] = 138,
  [SMALL_STATE(7)] = 165,
  [SMALL_STATE(8)] = 193,
  [SMALL_STATE(9)] = 217,
  [SMALL_STATE(10)] = 245,
  [SMALL_STATE(11)] = 268,
  [SMALL_STATE(12)] = 291,
  [SMALL_STATE(13)] = 322,
  [SMALL_STATE(14)] = 345,
  [SMALL_STATE(15)] = 365,
  [SMALL_STATE(16)] = 385,
  [SMALL_STATE(17)] = 405,
  [SMALL_STATE(18)] = 425,
  [SMALL_STATE(19)] = 445,
  [SMALL_STATE(20)] = 465,
  [SMALL_STATE(21)] = 487,
  [SMALL_STATE(22)] = 506,
  [SMALL_STATE(23)] = 525,
  [SMALL_STATE(24)] = 544,
  [SMALL_STATE(25)] = 560,
  [SMALL_STATE(26)] = 576,
  [SMALL_STATE(27)] = 592,
  [SMALL_STATE(28)] = 608,
  [SMALL_STATE(29)] = 612,
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [15] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_compilation_unit_repeat1, 2),
  [17] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_compilation_unit_repeat1, 2), SHIFT_REPEAT(8),
  [20] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_compilation_unit_repeat1, 2), SHIFT_REPEAT(18),
  [23] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_compilation_unit_repeat1, 2), SHIFT_REPEAT(23),
  [26] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__floatingPointLiteral, 3),
  [28] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [30] = {.entry = {.count = 1, .reusable = false}}, SHIFT(17),
  [32] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_compilation_unit, 1),
  [34] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__floatingPointLiteral, 2),
  [36] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [38] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__floatingPointLiteral_repeat1, 2),
  [40] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__floatingPointLiteral_repeat1, 2), SHIFT_REPEAT(8),
  [43] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__floatingPointLiteral_repeat1, 2),
  [45] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__exponentPart, 3),
  [47] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__exponentPart, 3),
  [49] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__floatingPointLiteral_repeat1, 1),
  [51] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__floatingPointLiteral_repeat1, 1),
  [53] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__exponentPart, 2),
  [55] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__exponentPart, 2),
  [57] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__floatingPointLiteral, 4),
  [59] = {.entry = {.count = 1, .reusable = false}}, SHIFT(19),
  [61] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [63] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [65] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_compilation_unit_repeat1, 1),
  [67] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__booleanLiteral, 1),
  [69] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__floatingPointLiteral, 5),
  [71] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [73] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [75] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [77] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [79] = {.entry = {.count = 1, .reusable = false}}, SHIFT_EXTRA(),
  [81] = {.entry = {.count = 1, .reusable = false}}, SHIFT(24),
  [83] = {.entry = {.count = 1, .reusable = false}}, SHIFT(27),
  [85] = {.entry = {.count = 1, .reusable = false}}, SHIFT(28),
  [87] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__comment, 2),
  [89] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__comment, 3),
};

#ifdef __cplusplus
extern "C" {
#endif
void *tree_sitter_scala_external_scanner_create(void);
void tree_sitter_scala_external_scanner_destroy(void *);
bool tree_sitter_scala_external_scanner_scan(void *, TSLexer *, const bool *);
unsigned tree_sitter_scala_external_scanner_serialize(void *, char *);
void tree_sitter_scala_external_scanner_deserialize(void *, const char *, unsigned);

#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_scala(void) {
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
      tree_sitter_scala_external_scanner_create,
      tree_sitter_scala_external_scanner_destroy,
      tree_sitter_scala_external_scanner_scan,
      tree_sitter_scala_external_scanner_serialize,
      tree_sitter_scala_external_scanner_deserialize,
    },
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
