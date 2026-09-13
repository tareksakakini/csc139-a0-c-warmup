/*
 * CSC 139 - A0 C Warm-Up - Exercise 09: integers wrap around
 *
 * CONCEPT: A C integer has a fixed width. Past the top, it wraps to the bottom.
 *
 * There are no arbitrary-precision integers in C. An `unsigned char` holds
 * 0..255. Add 10 to 250 and you get 4, because the arithmetic is done modulo 256.
 * An `unsigned int` holds 0..4294967295 and wraps the same way.
 *
 * This is well defined for *unsigned* types, and it is how counters, hashes and
 * checksums are expected to behave. For *signed* types overflow is undefined
 * behaviour - the compiler is allowed to assume it never happens, and will
 * optimise on that assumption. Do not rely on signed overflow, ever.
 *
 * UINT_MAX lives in <limits.h>. Print an unsigned int with %u.
 *
 * TODO: do the two additions and print the results.
 *
 * Your program must print EXACTLY this:
 *
 *     250 + 10 in an unsigned char is 4
 *     4294967295 + 1 in an unsigned int is 0
 *
 * Check yourself with:  make test-09        (or: make run-09 to just see it)
 */

#include <stdio.h>
#include <limits.h>

int main(void)
{
    unsigned char small = 250;
    unsigned int  big   = UINT_MAX;

    small = (unsigned char)(small + 10);
    printf("250 + 10 in an unsigned char is %u\n", small);

    big = big + 1u;
    printf("4294967295 + 1 in an unsigned int is %u\n", big);

    return 0;
}
