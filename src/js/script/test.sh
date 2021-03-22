#!/usr/bin/env bash --noprofile

set -eE

PARAMS=""
WATCH=

while (( "$#" )); do
  case "$1" in
    -w|--watch)
			WATCH="true"
			shift
      ;;
    *) # preserve positional arguments
      PARAMS="$PARAMS $1"
      shift
      ;;
  esac
done
COMMAND="make -C test"
echo $(pwd)
SOURCES="test/Makefile tree-sitter-to-ebnf.js test/test-grammar.js ../lua/parse_grammar.lua test/corpus/** test/src/scanner.c"

if [ -n "$WATCH" ]; then
	trap "exec $0 $PARAMS -w $DEBUG $TEST_FLAG $TEST_FILTER" ERR
	ls $SOURCES | entr -c -d $COMMAND
fi

$COMMAND
