/*
 * CSC 139 - A0 C Warm-Up - Exercise 36: arguments arrive as strings
 *
 * CONCEPT: main can take the command line: a count and an array of strings.
 *
 *     int main(int argc, char *argv[])
 *
 * argv is an array of `char *`, one per word on the command line. argv[0] is the
 * name the program was invoked as, so the first real argument is argv[1] and
 * argc is always at least 1. argv[argc] is NULL.
 *
 * They are always strings, even when they look like numbers. Converting one is a
 * separate step - strtol, which reports failure properly, rather than atoi,
 * which cannot tell "0" from "banana".
 *
 * This exercise is run as:   ./36_argv alpha beta
 *
 * TODO: print argc and each real argument. Do not print argv[0]'s value - it
 * changes depending on how the program was started.
 *
 * Your program must print EXACTLY this:
 *
 *     argc is 3
 *     argv[1] is alpha
 *     argv[2] is beta
 *
 * Check yourself with:  make test-36        (or: make run-36 to just see it)
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
    /* TODO: print  argc is N */

    /* TODO: loop from 1 to argc - 1 and print  argv[i] is <the string> */
    (void)argv;

    return 0;
}
