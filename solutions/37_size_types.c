/*
 * CSC 139 - A0 C Warm-Up - Exercise 37: size_t is unsigned
 *
 * CONCEPT: Mixing signed and unsigned integers silently converts one of them. Usually the wrong one.
 *
 * size_t is the unsigned type C uses for sizes and counts. It cannot hold a
 * negative number - and that is not a harmless restriction, because C converts
 * rather than complains:
 *
 *     size_t n = 5;
 *     for (int i = 0; i < n; i++)      i is converted to size_t
 *
 * That is what -Wsign-compare is warning about below, and this exercise is
 * compiled with -Werror so you cannot skip past it. The fix is to use the same
 * type on both sides: make the loop counter a size_t.
 *
 * The version of this that actually bites: when n is 0, `n - 1` is not -1. It is
 * the largest value a size_t can hold, and `for (size_t i = 0; i <= n - 1; i++)`
 * becomes an 18-quintillion-iteration loop. Never subtract from an unsigned
 * value you have not first proved is non-zero.
 *
 * In Assignment 1, read() and write() take a size_t count and return a SIGNED
 * ssize_t, precisely so that -1 can mean failure. Getting these two mixed up is
 * a real source of bugs there.
 *
 * TODO: fix the sign-compare warning without changing the output.
 *
 * Your program must print EXACTLY this:
 *
 *     sum is 73
 *     (size_t)0 - 1 is 18446744073709551615
 *
 * Check yourself with:  make test-37        (or: make run-37 to just see it)
 */

#include <stdio.h>

int main(void)
{
    int    a[] = { 12, 7, 30, 5, 19 };
    size_t n   = sizeof(a) / sizeof(a[0]);
    int    sum = 0;

    for (size_t i = 0; i < n; i++)
        sum += a[i];

    printf("sum is %d\n", sum);

    size_t zero = 0;
    printf("(size_t)0 - 1 is %zu\n", zero - 1);

    return 0;
}
