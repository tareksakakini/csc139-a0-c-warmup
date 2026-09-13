/*
 * CSC 139 - A0 C Warm-Up - Exercise 16: pass by value, always
 *
 * CONCEPT: C copies every argument. To let a function change your variable, hand it an address.
 *
 * `swap` below takes two ints. It gets COPIES of them. It swaps the copies, the
 * copies die when the function returns, and a and b in main never move. C has no
 * pass-by-reference - not for ints, not for structs, not for anything.
 *
 * The fix is not a language feature, it is a habit: pass the address instead.
 * The function takes `int *`, and writes through the pointers.
 *
 * This is why so many C functions take pointers as arguments. They are not
 * "returning" through them in any special sense - you handed over the address of
 * your own variable and gave the function permission to write there.
 *
 * TODO: make swap actually swap. You will need to change its parameters, its
 * body, and how main calls it.
 *
 * Your program must print EXACTLY this:
 *
 *     before: a = 3, b = 7
 *     after:  a = 7, b = 3
 *
 * Check yourself with:  make test-16        (or: make run-16 to just see it)
 */

#include <stdio.h>

static void swap(int x, int y)
{
    int tmp = x;
    x = y;
    y = tmp;
}

int main(void)
{
    int a = 3;
    int b = 7;

    printf("before: a = %d, b = %d\n", a, b);

    swap(a, b);

    printf("after:  a = %d, b = %d\n", a, b);

    return 0;
}
