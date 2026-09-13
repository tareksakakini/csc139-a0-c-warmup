/*
 * CSC 139 - A0 C Warm-Up - Exercise 18: arrays decay into pointers
 *
 * CONCEPT: Pass an array to a function and the function receives only an address.
 *
 * The array itself never gets copied. What crosses the call boundary is one
 * pointer to the first element - and a pointer has no idea how many elements
 * follow it.
 *
 * So inside `sum`, `sizeof(arr)` is 8: the size of a pointer, not of the array.
 * The length is simply gone. That is why the version below returns the wrong
 * answer, and why essentially every array-taking function in C - including
 * read() and write() - also takes a count.
 *
 * This is the most common way a working program quietly becomes a broken one, so
 * it is worth saying plainly: the moment an array is passed to a function, its
 * length must be passed with it or it is lost.
 *
 * TODO: give sum() a length parameter and use it. Fix the call in main too.
 *
 * Your program must print EXACTLY this:
 *
 *     in main, sizeof(a) is 24 bytes, so 6 items
 *     inside sum, sizeof(arr) is 8 bytes - a pointer, not an array
 *     sum is 21
 *
 * Check yourself with:  make test-18        (or: make run-18 to just see it)
 */

#include <stdio.h>

static int sum(int *arr, size_t n)
{
    printf("inside sum, sizeof(arr) is %zu bytes - a pointer, not an array\n",
           sizeof(arr));

    int total = 0;
    for (size_t i = 0; i < n; i++)
        total += arr[i];

    return total;
}

int main(void)
{
    int a[] = { 1, 2, 3, 4, 5, 6 };

    printf("in main, sizeof(a) is %zu bytes, so %zu items\n",
           sizeof(a), sizeof(a) / sizeof(a[0]));

    printf("sum is %d\n", sum(a, sizeof(a) / sizeof(a[0])));

    return 0;
}
