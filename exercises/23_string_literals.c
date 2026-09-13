/*
 * CSC 139 - A0 C Warm-Up - Exercise 23: literals are read-only
 *
 * CONCEPT: "hello" in your source is not a variable. It lives in memory you may not write to.
 *
 *     char *p = "hello";     p points into read-only memory
 *     char  a[] = "hello";   a is YOUR array, initialised by copying the literal
 *
 * The two lines look almost identical and behave completely differently. The
 * first gives you a pointer to a constant the compiler put in a read-only page;
 * writing through it is undefined behaviour, and on Linux it segfaults. The
 * second reserves six writable bytes of your own and copies the letters in.
 *
 * Rule of thumb: if you intend to modify it, it must be an array you own.
 *
 * TODO: this program crashes. Work out which line writes to read-only memory,
 * and make the capitalisation happen on the writable copy instead. Do not change
 * what gets printed.
 *
 * Your program must print EXACTLY this:
 *
 *     the literal still says hello
 *     the copy now says Hello
 *
 * Check yourself with:  make test-23        (or: make run-23 to just see it)
 */

#include <stdio.h>

int main(void)
{
    char *literal = "hello";
    char  copy[]  = "hello";

    literal[0] = 'H';

    printf("the literal still says %s\n", literal);
    printf("the copy now says %s\n", copy);

    return 0;
}
