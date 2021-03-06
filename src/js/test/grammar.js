// This file was autogenerated by parse_grammar.lua from test.ebnf.

/*
 * inline constants: 
 */

module.exports = grammar({
  name: 'test',

  /*
   * test.ebnf:1 
   * extras  ::=  { /\s/ }
   */
  extras: $ => [/\s/],
  /*
   * test.ebnf:3 
   * externals  ::=  { _automatic_semicolon 'else' }
   */
  externals: $ => [$._automatic_semicolon, 'else'],
  /*
   * test.ebnf:5 
   * conflits  ::=  { { foo bar } }
   */
  conflits: $ => [[$.foo, $.bar]],
  rules: {
    /*
     * test.ebnf:8 
     * top1  ::=  foo | blah | bar | buzz | ok | low
     */
    top1: $ => choice($.foo, $.blah, $.bar, $.buzz, $.ok, $.low),
    /*
     * test.ebnf:9 
     * foo  ::=  'hello'
     */
    foo: $ => 'hello',
    /*
     * test.ebnf:10 
     * blah  ::=  ('blah' | 'barz' | (foo 'x'))+
     */
    blah: $ => repeat1(choice('blah', 'barz', seq($.foo, 'x'))),
    /*
     * test.ebnf:11 
     * bar  ::=  'bar' ((foo foo): blah)
     */
    bar: $ => seq('bar', field('blah', seq($.foo, $.foo))),
    /*
     * test.ebnf:12 
     * buzz  ::=  'car' ((foo foo) -> car)
     */
    buzz: $ => seq('car', alias(seq($.foo, $.foo), $.car)),
    /*
     * test.ebnf:13 
     * ok  ::=  @('ok' 'go')
     */
    ok: $ => token(seq('ok', 'go')),
    /*
     * test.ebnf:14 
     * low  ::=  !(/[a-z]+/ 'ok')
     */
    low: $ => token.immediate(seq(/[a-z]+/, 'ok')),
    /*
     * test.ebnf:15 
     * zz  ::=  /[a-z]+/ (',' /[a-z]+/)*
     */
    zz: $ => seq(/[a-z]+/, repeat(seq(',', /[a-z]+/))),
    /*
     * test.ebnf:16 
     * _zz  ::=  'zzzzzaaa'
     */
    _zz: $ => 'zzzzzaaa',
    /*
     * test.ebnf:17 
     * ww  ::=  'zzz' (zz: top) 'kk'
     */
    ww: $ => seq('zzz', field('top', $.zz), 'kk'),
    /*
     * test.ebnf:18 
     * anno  ::=  >('@' (_zz: name) (ok*: arguments))
     */
    anno: $ => prec.right(seq('@', field('name', $._zz), field('arguments', repeat($.ok)))),
    /*
     * test.ebnf:19 
     * function_definition  ::=  'foo' (('=' (_zz: body)) | (zz: body))
     */
    function_definition: $ => seq('foo', choice(seq('=', field('body', $._zz)), field('body', $.zz))),
    /*
     * test.ebnf:20 
     * pc  ::=  -1('kk' _zz)
     */
    pc: $ => prec(-1, seq('kk', $._zz))
  }
});
