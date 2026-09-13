/*
 * CSC 139 - A0 C Warm-Up - Exercise 13: let the sanitizer find it
 *
 * CONCEPT: When you cannot see the bug, make the machine point at it.
 *
 * `reverse` is wrong, and this time it is not obvious by eye. Do not squint at
 * it. Run it:
 *
 *     make run-13
 *
 * AddressSanitizer will stop the program and print a report. It looks like a
 * wall of text; you only need three things from it:
 *
 *   - the first line:  what kind of error (heap/stack-buffer-overflow, and
 *     whether it was a READ or a WRITE)
 *   - the first frame of the stack trace that names one of YOUR files:
 *     that is the line to look at
 *   - the line that says where the object was allocated
 *
 * Read those three, go to the line, and the bug is usually obvious. Getting
 * fluent at this is worth more to you this semester than any syntax you will
 * learn today.
 *
 * TODO: fix reverse().
 *
 * Your program must print EXACTLY this:
 *
 *     5 4 3 2 1
 *     done
 *
 * Check yourself with:  make test-13        (or: make run-13 to just see it)
 */

#include <stdio.h>

static void reverse(int *a, int n)
{
    for (int i = 0; i < n / 2; i++) {
        int tmp  = a[i];
        a[i]     = a[n - i];
        a[n - i] = tmp;
    }
}

int main(void)
{
    int a[5] = { 1, 2, 3, 4, 5 };

    reverse(a, 5);

    for (int i = 0; i < 5; i++)
        printf("%d%s", a[i], i == 4 ? "\n" : " ");

    printf("done\n");

    return 0;
}
