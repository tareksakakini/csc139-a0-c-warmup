/*
 * CSC 139 - A0 C Warm-Up - Exercise 04: types have sizes
 *
 * CONCEPT: Every C type occupies a fixed, knowable number of bytes.
 *
 * In most languages an integer is just an integer. In C it is a specific number
 * of bytes in memory, and you can ask how many with `sizeof`.
 *
 * `sizeof` gives a value of type `size_t` - an unsigned integer type big enough
 * to measure any object. printf prints a size_t with %zu, not %d. Using the
 * wrong specifier here is undefined behaviour, not a rounding error.
 *
 * You will meet size_t constantly in this course: it is the type of the third
 * argument to read() and write().
 *
 * TODO: fill in the four sizeof expressions.
 *
 * Your program must print EXACTLY this:
 *
 *     char   is 1 bytes
 *     int    is 4 bytes
 *     long   is 8 bytes
 *     double is 8 bytes
 *
 * Check yourself with:  make test-04        (or: make run-04 to just see it)
 */

#include <stdio.h>

int main(void)
{
    printf("char   is %zu bytes\n", sizeof(char));
    printf("int    is %zu bytes\n", sizeof(int));
    printf("long   is %zu bytes\n", sizeof(long));
    printf("double is %zu bytes\n", sizeof(double));

    return 0;
}
