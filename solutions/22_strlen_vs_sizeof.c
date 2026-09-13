/*
 * CSC 139 - A0 C Warm-Up - Exercise 22: length is not capacity
 *
 * CONCEPT: sizeof measures the box. strlen counts what is currently in it.
 *
 *     char buf[32] = "hello";
 *
 *     sizeof(buf)   32 - the storage you reserved, known at compile time, free
 *     strlen(buf)    5 - characters before the terminator, counted at run time
 *                        by walking the bytes one at a time
 *
 * Two different questions with two different answers, and mixing them up is how
 * buffers overflow.
 *
 * Also notice what "counted at run time" costs you: strlen is a loop. Calling it
 * inside a loop condition turns an O(n) pass into an O(n^2) one. Compute it once.
 *
 * strlen is declared in <string.h> and returns a size_t.
 *
 * TODO: fill in the four blanks.
 *
 * Your program must print EXACTLY this:
 *
 *     sizeof(buf) is 32 bytes of storage
 *     strlen(buf) is 5 characters
 *     after overwriting:
 *     sizeof(buf) is 32 bytes of storage
 *     strlen(buf) is 12 characters
 *
 * Check yourself with:  make test-22        (or: make run-22 to just see it)
 */

#include <stdio.h>
#include <string.h>

int main(void)
{
    char buf[32] = "hello";

    printf("sizeof(buf) is %zu bytes of storage\n", sizeof(buf));
    printf("strlen(buf) is %zu characters\n", strlen(buf));

    strcpy(buf, "hello, world");

    printf("after overwriting:\n");
    printf("sizeof(buf) is %zu bytes of storage\n", sizeof(buf));
    printf("strlen(buf) is %zu characters\n", strlen(buf));

    return 0;
}
