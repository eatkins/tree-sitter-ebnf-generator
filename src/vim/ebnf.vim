" Vim syntax file
" Language: ebnf
" Maintainer: Ethan Atkins
"
" This is a crude syntax that makes it clear what are constants
" and what are rule definitions.

if exists("b:current_syntax")
  finish
endif

setlocal iskeyword+=:
setlocal iskeyword+==
syn keyword assign ::=
"syn match const_assign /.\+ :=.*/
syn match dollar_expansion /[$]\(([a-zA-Z_0-9]\+)\|[a-zA-Z_0-9]\+\)/
syn match constant_assign / [:][=] /
syn match any contained /[a-zA-Z]/
syn match comment /^[ ]*;.\+\n\|; [^'"]\+\n/
"syn match all_chars contained /.*/
"syn region CONST_RHS start='/ [:][=] /' end=/.\+^[a-zA-Z0-9]\+[ ]\+[:]/ contains=any
syn region CONST_RHS start='/ [:][=] /' end=/\n/ contains=any
hi def link dollar_expansion Keyword
hi def link constant_assign Keyword
"hi def link assign StorageClass
hi def link any StorageClass
hi def link comment Comment
