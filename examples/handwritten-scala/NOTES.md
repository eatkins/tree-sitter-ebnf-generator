~~
1) 'new' does not work correctly (2021-24-3 11:18 PDT) (currently at 79% in sbt)
	* `instance_expression ::= 3('new' _expression) `
	* `'new' (ClassTemplate | TemplateBody)`
  * problems:
    * _expression is completely wrong
    * there is no distinction between TemplateBody and Block
    * ClassTemplate builds on TemplateBody
~~

1) 'new' now works but the parsing stats dropped from 85% to 75% (2021-24-3 04:30 PDT)



