module.exports = grammar({
  name: 'scala',
  extras: $ => [/\s/],
  externals: $ => [ $._automatic_semicolon, 'else' ],
  conflits: $ => [ [ $.foo, $.bar] ],
  rules: {
    top1: $ => choice($.foo, $.blah, $.bar, $.buzz, $.ok, $.low),
    foo: $ => 'hello',
    blah: $ => repeat1(choice('blah', 'barz', seq($.foo, "x"))),
    bar: $ => seq("bar", field("blah", seq($.foo, $.foo))),
    buzz: $ => seq("car", alias(seq($.foo, $.foo), $.car)),
    ok: $ => token(seq("ok", "go")),
    low: $ => token.immediate(seq(/[a-z]+/, "ok")),
    zz: $ => commaSep1(/[a-z]+/),
    _zz: $ => "zzzzzaaa",
    ww: $ => seq("zzz", field("top", $.zz), "kk"),
    anno: $ => prec.right(seq('@', field("name", $._zz), field("arguments", repeat($.ok)))),
    function_definition: $ => seq('foo', choice(
      seq('=', field('body', $._zz)),
      field('body', $.zz)
    )),
    pc: $ => prec(-1, seq("kk", $._zz)),
  }
})

function commaSep(rule) {
  return optional(commaSep1(rule))
}

function commaSep1(rule) {
  return seq(rule, repeat(seq(',', rule)))
}
