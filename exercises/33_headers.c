/*
 * CSC 139 - A0 C Warm-Up - Exercise 33: what #include actually does
 *
 * CONCEPT: A header is a list of promises. #include pastes it into your file.
 *
 * Open include/stats.h and read it - it is short. It declares two functions and
 * contains no code at all.
 *
 * #include is a literal text substitution performed before compilation: the
 * preprocessor replaces the line with the entire contents of that file. That is
 * the whole trick. <stdio.h> is not special; it is a file full of prototypes
 * like the ones you wrote in exercise 08, and printf works because that file
 * declares it.
 *
 *     #include <stdio.h>     look in the system include directories
 *     #include "stats.h"     look next to this source file first
 *
 * This exercise is compiled with -Iinclude, which adds our include/ directory to
 * the search path.
 *
 * Your job is to supply the implementations the header promises. The header
 * tells you the exact signatures; match them or the compiler will object.
 *
 * TODO: implement stats_max and stats_sum. Do not edit stats.h.
 *
 * Your program must print EXACTLY this:
 *
 *     max is 30
 *     sum is 73
 *     max of one item is 7
 *
 * Check yourself with:  make test-33        (or: make run-33 to just see it)
 */

#include <stdio.h>
#include "stats.h"

/* TODO: implement the two functions stats.h promises. Read the header for
   the exact signatures and what each one must do. */

int main(void)
{
    int a[] = { 12, 7, 30, 5, 19 };
    int one[] = { 7 };

    printf("max is %d\n", stats_max(a, 5));
    printf("sum is %d\n", stats_sum(a, 5));
    printf("max of one item is %d\n", stats_max(one, 1));

    return 0;
}
