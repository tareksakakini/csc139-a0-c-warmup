/*
 * CSC 139 - A0 C Warm-Up - Exercise 11: arrays do not know their length
 *
 * CONCEPT: There is no arr.length. You compute it, or you carry it alongside.
 *
 * An array in C is raw storage. Nothing is stored next to it saying how long it
 * is. What you CAN do, while you are in the scope where the array was declared,
 * is ask the compiler:
 *
 *     sizeof(arr) / sizeof(arr[0])
 *
 *     total bytes in the array / bytes in one element  =  number of elements
 *
 * Read that formula until it is obvious. Then note the catch, because it is the
 * subject of exercise 18: this only works where the real array is visible. Pass
 * the array to a function and `sizeof` silently starts measuring something else.
 *
 * That is exactly why nearly every C function that takes an array also takes a
 * length - and why read() and write() take a byte count.
 *
 * TODO: compute n with the sizeof formula. Do not write 6.
 *
 * Your program must print EXACTLY this:
 *
 *     sizeof(items) = 24 bytes
 *     one element   = 4 bytes
 *     so n          = 6
 *     sum           = 36
 *
 * Check yourself with:  make test-11        (or: make run-11 to just see it)
 */

#include <stdio.h>

int main(void)
{
    int items[] = { 1, 2, 4, 8, 13, 8 };

    size_t n = sizeof(items) / sizeof(items[0]);

    printf("sizeof(items) = %zu bytes\n", sizeof(items));
    printf("one element   = %zu bytes\n", sizeof(items[0]));
    printf("so n          = %zu\n", n);

    int sum = 0;
    for (size_t i = 0; i < n; i++)
        sum += items[i];

    printf("sum           = %d\n", sum);

    return 0;
}
