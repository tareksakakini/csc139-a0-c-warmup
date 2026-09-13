/*
 * CSC 139 - A0 C Warm-Up - Exercise 02: reading compiler errors
 *
 * CONCEPT: The compiler tells you exactly what is wrong. Learn to read it.
 *
 * This file does not compile. There are three bugs. Run `make test-02` and
 * read what gcc says.
 *
 * Two habits that will save you hours this semester:
 *
 *   1. Always fix the FIRST error first, then recompile. One real mistake often
 *      produces a cascade of fake ones underneath it.
 *   2. The line number gcc reports is where it NOTICED the problem, which is
 *      often one line AFTER the line that caused it. A missing semicolon is
 *      reported on the following line.
 *
 * TODO: make it compile and print the line below. Do not change what it computes.
 *
 * Your program must print EXACTLY this:
 *
 *     2 + 2 = 4
 *
 * Check yourself with:  make test-02        (or: make run-02 to just see it)
 */

#include <stdio.h>

int main(void)
{
    int total = 2 + 2;

    printf("2 + 2 = %d\n", total);

    return 0;
}
