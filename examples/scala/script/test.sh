#!/usr/bin/env bash --noprofile

set -e

PARAMS=""
WATCH=
VERBOSE=
DEBUG=

while (( "$#" )); do
  case "$1" in
    -w|--watch)
			echo "watch"
			WATCH="true"
			shift
      ;;
		-d|--debug)
			echo "debug"
			VERBOSE="-v"
			DEBUG="-d"
			PARAMS="$PARAMS $1"
			shift
			;;
    *) # preserve positional arguments
      PARAMS="$PARAMS $1"
      shift
      ;;
  esac
done

if [ -n "$WATCH" ]; then
	echo `pwd`
	ls ../../src/lua/parse_grammar.lua
	ls **.ebnf **/*.txt ../../src/lua/parse_grammar.lua src/*.c | entr -c $0 $PARAMS
fi

../../src/lua/parse_grammar.lua -o grammar.js scala.ebnf $VERBOSE
tree-sitter generate
tree-sitter test $DEBUG
