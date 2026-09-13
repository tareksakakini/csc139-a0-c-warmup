/*
 * CSC 139 - A0 C Warm-Up - Exercise 19: indexing IS pointer arithmetic
 *
 * CONCEPT: a[i] is defined as *(a + i). Not similar to it - defined as it.
 *
 * The square brackets are pure syntax sugar. The standard says:
 *
 *     a[i]   means   *(a + i)
 *
 * Everything follows from that. `a[0]` is `*(a + 0)` is `*a`. And since addition
 * is commutative, `*(a + 2)` is also `*(2 + a)`, which means `2[a]` is legal C
 * and gives you the same element. Nobody writes that, but the fact that it
 * compiles tells you there is no separate "array indexing" operation in the
 * language at all - just addition and dereference.
 *
 * Once this clicks, the write loop in Assignment 1 stops looking strange:
 * `buf + written` is simply "the part of the buffer you have not sent yet".
 *
 * TODO: fill in the four expressions. Use a different form for each of the
 * first three.
 *
 * Your program must print EXACTLY this:
 *
 *     a[2] is 30
 *     *(a + 2) is 30
 *     2[a] is 30
 *     all three are the same element: yes
 *
 * Check yourself with:  make test-19        (or: make run-19 to just see it)
 */

#include <stdio.h>

int main(void)
{
    int a[4] = { 10, 20, 30, 40 };

    printf("a[2] is %d\n", a[2]);

    printf("*(a + 2) is %d\n", *(a + 2));

    printf("2[a] is %d\n", 2[a]);

    printf("all three are the same element: %s\n",
           (a[2] == *(a + 2) && *(a + 2) == 2[a]) ? "yes" : "no");

    return 0;
}
