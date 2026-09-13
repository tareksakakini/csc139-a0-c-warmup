/*
 * CSC 139 - A0 C Warm-Up - Exercise 15: following a pointer
 *
 * CONCEPT: A pointer variable holds an address. `*` goes to that address.
 *
 *     int  x = 10;
 *     int *p = &x;     p holds the address of x
 *     *p               the int living at that address - that IS x
 *
 * `*` in a declaration and `*` in an expression are different things wearing the
 * same costume:
 *
 *     int *p;      declaration: "p is a pointer to int"
 *     *p = 99;     expression:  "store 99 where p points"
 *
 * After `p = &x`, the names `x` and `*p` are two doors into the same box. Write
 * through one and you see it through the other. That is the whole mechanism
 * behind how a C function returns data to its caller, and behind how read() puts
 * bytes into a buffer you own.
 *
 * TODO: print *p, then assign through p, then print x.
 *
 * Your program must print EXACTLY this:
 *
 *     *p is 10
 *     after *p = 99, x is 99
 *
 * Check yourself with:  make test-15        (or: make run-15 to just see it)
 */

#include <stdio.h>

int main(void)
{
    int  x = 10;
    int *p = &x;

    printf("*p is %d\n", *p);

    *p = 99;

    printf("after *p = 99, x is %d\n", x);

    return 0;
}
