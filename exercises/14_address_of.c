/*
 * CSC 139 - A0 C Warm-Up - Exercise 14: variables have addresses
 *
 * CONCEPT: Every variable sits somewhere in memory, and `&` tells you where.
 *
 * This is the idea the rest of C is built on, so go slowly.
 *
 * A variable is a named box of bytes at some numbered location in memory. `&x`
 * is that location - the address of x. An address is just a number, and on this
 * machine it takes 8 bytes to hold one.
 *
 * We do not print addresses in these exercises, because the actual number is
 * different every run. We print facts ABOUT them instead.
 *
 * TODO: fill in the three expressions.
 *
 * Your program must print EXACTLY this:
 *
 *     x holds 42
 *     an address takes 8 bytes
 *     &x and &y are different: yes
 *
 * Check yourself with:  make test-14        (or: make run-14 to just see it)
 */

#include <stdio.h>

int main(void)
{
    int x = 42;
    int y = 42;

    printf("x holds %d\n", x);

    /* TODO: how many bytes does the address of x take?
             Hint: sizeof works on any expression, including &x. */
    printf("an address takes %zu bytes\n", (size_t)0);

    /* TODO: are the two addresses different? x and y hold the same VALUE,
             but they are two separate boxes, so they cannot share a location. */
    printf("&x and &y are different: %s\n", 0 ? "yes" : "no");

    return 0;
}
