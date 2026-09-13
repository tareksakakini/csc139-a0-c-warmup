/*
 * CSC 139 - A0 C Warm-Up - Exercise 12: nobody checks your indexes
 *
 * CONCEPT: Reading past the end of an array is not an error. It is just wrong.
 *
 * In the language you already know, `a[5]` on a 5-element list raises. In C it
 * reads whatever bytes happen to sit after the array and carries on, cheerfully,
 * with a garbage value. Sometimes it crashes. Sometimes it works for a year and
 * then crashes on a customer's machine.
 *
 * The loop below runs one step too far. Find it by reading the code.
 *
 * From this exercise on, everything is compiled with -fsanitize=address, a
 * debugging mode that puts guard bytes around your arrays and stops the program
 * the moment you touch one. That is why this crashes instead of silently
 * printing junk. It is not on by default - it is a tool you switch on, and from
 * now on you switch it on.
 *
 * TODO: fix the loop.
 *
 * Your program must print EXACTLY this:
 *
 *     1
 *     1
 *     2
 *     3
 *     5
 *     done
 *
 * Check yourself with:  make test-12        (or: make run-12 to just see it)
 */

#include <stdio.h>

int main(void)
{
    int fib[5] = { 1, 1, 2, 3, 5 };
    int n = 5;

    for (int i = 0; i <= n; i++)
        printf("%d\n", fib[i]);

    printf("done\n");

    return 0;
}
