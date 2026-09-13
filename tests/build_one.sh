#!/usr/bin/env bash
# Build and run one exercise, using the same flags the checker uses.
#   bash tests/build_one.sh exercises 7
set -uo pipefail
ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
DIR="$1"
NUM="$(printf '%02d' "$((10#$2))")"
BASE_CFLAGS="-std=c17 -Wall -Wextra -g"

line="$(grep "^$NUM|" "$ROOT/tests/manifest.txt")" || { echo "No exercise $NUM."; exit 1; }
IFS='|' read -r num slug title mode cflags args stdin_file <<< "$line"
[ "$cflags" = "-" ] && cflags=""
[ "$args" = "-" ] && args=""

src="$ROOT/$DIR/${num}_${slug}.c"
[ -f "$src" ] || { echo "No such file: ${src#$ROOT/}"; exit 1; }
mkdir -p "$ROOT/.build"
bin="$ROOT/.build/${num}_${slug}"

echo "--- $num  $title"
echo "gcc $BASE_CFLAGS $cflags -o ${bin#$ROOT/} ${src#$ROOT/}"
gcc $BASE_CFLAGS -I"$ROOT/include" $cflags -o "$bin" "$src" || exit 1
echo "--- output:"
cd "$ROOT"
if [ "$stdin_file" != "-" ]; then "$bin" $args < "$ROOT/$stdin_file"; else "$bin" $args; fi
rc=$?
echo "--- exited with status $rc"
exit 0
