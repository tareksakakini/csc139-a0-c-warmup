# CSC 139 - Assignment 0: C warm-up
#
#   make check-env     prove your environment works (run this first)
#   make run-07        build and run exercise 07
#   make test-07       check exercise 07
#   make test          check everything
#   make progress      the scoreboard
#   make report        write progress.txt for Canvas
#   make solution-07   build and run the reference solution for 07
#   make clean

CC      = gcc
CFLAGS  = -std=c17 -Wall -Wextra -g
BUILD   = .build

.PHONY: all test progress report check-env clean help

help:
	@sed -n '3,10p' Makefile | sed 's/^# \{0,1\}//'

all: test

$(BUILD):
	@mkdir -p $(BUILD)

# ---------------------------------------------------------------------------
# run-NN / solution-NN - build one exercise and run it, so you can see what it
# actually prints. Extra flags for that exercise (sanitizers, -Werror) come
# from tests/manifest.txt, the same way the checker builds it.
# ---------------------------------------------------------------------------
run-%: | $(BUILD)
	@bash tests/build_one.sh exercises $*

solution-%: | $(BUILD)
	@bash tests/build_one.sh solutions $*

test-%:
	@bash tests/run_tests.sh $*

test:
	@bash tests/run_tests.sh

progress:
	@bash tests/run_tests.sh --quiet

# What you upload to Canvas.
report:
	@NO_COLOR=1 bash tests/run_tests.sh --quiet > progress.txt 2>&1 || true
	@echo "Wrote progress.txt - upload that to Canvas."
	@tail -3 progress.txt

check-env: | $(BUILD)
	@echo "CSC 139 A0 environment check"
	@echo "----------------------------"
	@printf 'kernel      : '; uname -sr
	@printf 'gcc         : '; if command -v gcc >/dev/null 2>&1; then gcc --version | head -1; else echo '(not installed)'; fi
	@printf 'make        : '; if command -v make >/dev/null 2>&1; then make --version | head -1; else echo '(not installed)'; fi
	@printf 'gdb         : '; if command -v gdb >/dev/null 2>&1; then gdb --version | head -1; else echo '(not installed)'; fi
	@echo "----------------------------"
	@printf 'sanitizers  : '
	@printf 'int main(void){int *p=0;return *p;}\n' > $(BUILD)/.sancheck.c
	@if $(CC) -fsanitize=address,undefined -o $(BUILD)/.sancheck $(BUILD)/.sancheck.c >/dev/null 2>&1; then \
		echo 'PASS - the memory-error detector works here'; \
	else \
		echo 'FAIL - post on Canvas with a screenshot before you start'; exit 1; \
	fi
	@printf 'man 2 open  : '; if man 2 open >/dev/null 2>&1; then echo 'PASS'; else echo '(missing - use man7.org instead)'; fi
	@echo "----------------------------"
	@echo "Good to go. Start with:  make run-01"

clean:
	@rm -rf $(BUILD)
