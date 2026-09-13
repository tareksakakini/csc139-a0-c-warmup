#!/usr/bin/env bash
# CSC 139 - A0 warm-up test harness.
#
#   bash tests/run_tests.sh              # test every exercise
#   bash tests/run_tests.sh 07           # test just exercise 07
#   bash tests/run_tests.sh --quiet      # one line per exercise (used by 'make progress')
#   bash tests/run_tests.sh --solutions  # run the reference solutions instead (instructor)
#
# An exercise passes when it COMPILES with no errors, EXITS 0, and prints
# exactly what tests/expected/NN.txt says it should.

set -uo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
MANIFEST="$ROOT/tests/manifest.txt"
EXPECTED_DIR="$ROOT/tests/expected"
SRCDIR="$ROOT/exercises"
BUILD="$ROOT/.build"
BASE_CFLAGS="-std=c17 -Wall -Wextra -g"
QUIET=0
ONLY=""

while [ $# -gt 0 ]; do
  case "$1" in
    --solutions) SRCDIR="$ROOT/solutions" ;;
    --quiet)     QUIET=1 ;;
    -h|--help)   sed -n '2,12p' "$0"; exit 0 ;;
    *)           ONLY="$ONLY $(printf '%02d' "$((10#$1))" 2>/dev/null || echo "$1")" ;;
  esac
  shift
done

mkdir -p "$BUILD"
pass=0; fail=0; todo=0; failed_list=""

if [ -t 1 ] && [ "${NO_COLOR:-}" = "" ]; then
  G=$'\033[32m'; R=$'\033[31m'; Y=$'\033[33m'; D=$'\033[2m'; N=$'\033[0m'
else
  G=""; R=""; Y=""; D=""; N=""
fi

while IFS='|' read -r num slug title mode cflags args stdin_file <&3; do
  case "$num" in ''|\#*) continue ;; esac

  if [ -n "$ONLY" ]; then
    case " $ONLY " in *" $num "*) ;; *) continue ;; esac
  fi

  src="$SRCDIR/${num}_${slug}.c"
  bin="$BUILD/${num}_${slug}"
  exp="$EXPECTED_DIR/${num}.txt"
  log="$BUILD/${num}.log"

  if [ ! -f "$src" ]; then
    fail=$((fail+1)); failed_list="$failed_list $num"
    printf '%s[ MISSING ]%s %s  %s (no such file: %s)\n' "$R" "$N" "$num" "$title" "${src#$ROOT/}"
    continue
  fi

  [ "$cflags" = "-" ] && cflags=""
  [ "$args" = "-" ] && args=""

  # --- compile -----------------------------------------------------------
  if ! gcc $BASE_CFLAGS -I"$ROOT/include" $cflags -o "$bin" "$src" > "$log" 2>&1; then
    fail=$((fail+1)); failed_list="$failed_list $num"
    printf '%s[  FAIL  ]%s %s  %s %s(does not compile)%s\n' "$R" "$N" "$num" "$title" "$D" "$N"
    [ $QUIET -eq 1 ] || sed 's/^/            /' "$log" | head -12
    continue
  fi

  # --- run ---------------------------------------------------------------
  out="$BUILD/${num}.out"
  err="$BUILD/${num}.err"
  if [ "$stdin_file" != "-" ]; then
    ( cd "$ROOT" && timeout 10 "$bin" $args < "$ROOT/$stdin_file" ) > "$out" 2> "$err"
  else
    ( cd "$ROOT" && timeout 10 "$bin" $args < /dev/null ) > "$out" 2> "$err"
  fi
  rc=$?

  if [ $rc -ne 0 ]; then
    fail=$((fail+1)); failed_list="$failed_list $num"
    reason="exited with status $rc"
    [ $rc -eq 124 ] && reason="timed out - infinite loop?"
    [ $rc -ge 128 ] && reason="killed by signal $((rc-128)) - this is usually a segfault"
    grep -qi 'sanitizer' "$err" && reason="a sanitizer caught a memory error"
    printf '%s[  FAIL  ]%s %s  %s %s(%s)%s\n' "$R" "$N" "$num" "$title" "$D" "$reason" "$N"
    if [ $QUIET -eq 0 ] && [ -s "$err" ]; then
      head -20 "$err" | sed 's/^/            /'
    fi
    continue
  fi

  # --- compare -----------------------------------------------------------
  if [ ! -f "$exp" ]; then
    todo=$((todo+1))
    printf '%s[  ????  ]%s %s  %s (no expected output on file)\n' "$Y" "$N" "$num" "$title"
    continue
  fi

  if diff -q "$exp" "$out" > /dev/null 2>&1; then
    pass=$((pass+1))
    printf '%s[  PASS  ]%s %s  %s\n' "$G" "$N" "$num" "$title"
  else
    fail=$((fail+1)); failed_list="$failed_list $num"
    printf '%s[  FAIL  ]%s %s  %s %s(wrong output)%s\n' "$R" "$N" "$num" "$title" "$D" "$N"
    if [ $QUIET -eq 0 ]; then
      printf '            %s--- expected ---------------- your output ---%s\n' "$D" "$N"
      diff --side-by-side --width=100 "$exp" "$out" 2>/dev/null | head -20 | sed 's/^/            /'
    fi
  fi
done 3< "$MANIFEST"

echo
printf '%s%d passed%s' "$G" "$pass" "$N"
[ $fail -gt 0 ] && printf ', %s%d failed%s' "$R" "$fail" "$N"
[ $todo -gt 0 ] && printf ', %s%d with no expected output%s' "$Y" "$todo" "$N"
echo
if [ $fail -gt 0 ]; then
  echo "Still to do:$failed_list"
  echo "Work on the lowest number first - each one builds on the last."
  exit 1
fi
echo "Nothing left. Go open Assignment 1."
