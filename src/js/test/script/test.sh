#!/usr/bin/env bash --noprofile

set -eE

PARAMS=""
WATCH=
VERBOSE=
DEBUG=
TEST_FILTER=
TEST_FLAG=

while (( "$#" )); do
  case "$1" in
    -w|--watch)
			WATCH="true"
			shift
      ;;
		-d|--debug)
			VERBOSE="-v"
			DEBUG="-d"
			shift
			;;
		-f)
			TEST_FLAG="-f"
			shift
			TEST_FILTER="$1"
			shift
			;;
    *) # preserve positional arguments
      PARAMS="$PARAMS $1"
      shift
      ;;
  esac
done
COMMAND="make VERBOSE=$VERBOSE DEBUG=$DEBUG TEST_FLAG=$TEST_FLAG TEST_FILTER=$TEST_FILTER"

if [ -n "$WATCH" ]; then
	trap "exec $0 $PARAMS -w $DEBUG $TEST_FLAG $TEST_FILTER" ERR
	ls ../../src/lua/parse_grammar.lua
	ls Makefile *.ebnf corpus/*.txt ../../src/lua/parse_grammar.lua src/scanner.c |
		entr -d -c $COMMAND
fi

$COMMAND
