function! ConvertEbnf()
  for lineno in range(a:firstline, a:lastline)
    let line = getline(lineno)
    let fixedQuotesLine = substitute(line, '[’‘]', "'", 'ge')
		let fixedOptionalLine = substitute(fixedQuotesLine, '\([^' . "'" . '"]\)[\[]\([^\]]\+\)[\]]', '\1(\2)?', 'ge')
		let fixedRepeat1Line = substitute(fixedOptionalLine, '\(.+\) {[ ]*\1[ ]*}', '(\1)+', 'ge')
		let fixedRepeatLine = substitute(fixedRepeat1Line, '\([^' . "'" . '"]\)[{]\([^}]\+\)}', '\1(\2)*', 'ge')
		let fixedSpacesLine = substitute(fixedRepeatLine, '([ ]\+\(.\+\)[ ]\+)', '\1', 'ge')
		let fixedParensLine = substitute(fixedSpacesLine, '(\([^ ()]\+\))', '\1', 'ge')
		call setline(lineno, fixedParensLine)
  endfor
endfunction

command -range CE <line1>,<line2>call ConvertEbnf()
