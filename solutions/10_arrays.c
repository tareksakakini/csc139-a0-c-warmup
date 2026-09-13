/*
 * CSC 139 - A0 C Warm-Up - Exercise 10: arrays
 *
 * CONCEPT: An array is a fixed number of same-typed values, laid out back to back in memory.
 *
 *     int scores[5] = { 90, 75, 88, 100, 62 };
 *
 * That reserves room for exactly five ints, side by side. Indexing is 0-based,
 * so the valid indexes are 0 through 4.
 *
 * The size must be known when the array is created, and it never changes. There
 * is no append. There is no slicing. Growing a collection means allocating a new,
 * bigger one and copying - which you will do by hand in exercise 30.
 *
 * TODO: print each score, then the total.
 *
 * Your program must print EXACTLY this:
 *
 *     scores[0] = 90
 *     scores[1] = 75
 *     scores[2] = 88
 *     scores[3] = 100
 *     scores[4] = 62
 *     total = 415
 *
 * Check yourself with:  make test-10        (or: make run-10 to just see it)
 */

#include <stdio.h>

int main(void)
{
    int scores[5] = { 90, 75, 88, 100, 62 };
    int total = 0;

    for (int i = 0; i < 5; i++) {
        printf("scores[%d] = %d\n", i, scores[i]);
        total += scores[i];
    }

    printf("total = %d\n", total);

    return 0;
}
