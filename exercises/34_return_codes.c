/*
 * CSC 139 - A0 C Warm-Up - Exercise 34: errors come back as values
 *
 * CONCEPT: C has no exceptions. A function reports failure by returning a value you must check.
 *
 * Nothing is thrown, nothing unwinds. The convention across almost all of C and
 * all of POSIX is:
 *
 *     0 or a valid result   it worked
 *     -1 or NULL            it failed
 *
 * and the caller is responsible for looking. If you do not look, the program
 * carries on with a meaningless value, which is how a small failure becomes a
 * confusing crash three functions later.
 *
 * The pattern for "I need to return both a result and a status" is to return the
 * status and write the result through a pointer - exercise 16, put to work:
 *
 *     int safe_div(int a, int b, int *out);
 *
 * TODO: make safe_div refuse to divide by zero, returning -1 instead. main
 * already checks the return value; look at how.
 *
 * Your program must print EXACTLY this:
 *
 *     10 / 2 = 5
 *     10 / 0 failed, as it should
 *
 * Check yourself with:  make test-34        (or: make run-34 to just see it)
 */

#include <stdio.h>

/* Divide a by b, storing the result in *out.
   Return 0 on success, -1 if the division cannot be done. */
static int safe_div(int a, int b, int *out)
{
    /* TODO: b might be zero. Dividing by it is undefined behaviour - the
             program will be stopped by the sanitizer. Detect it and return
             -1 without touching *out. */
    *out = a / b;
    return 0;
}

static void try_div(int a, int b)
{
    int result;

    if (safe_div(a, b, &result) != 0) {
        printf("%d / %d failed, as it should\n", a, b);
        return;
    }

    printf("%d / %d = %d\n", a, b, result);
}

int main(void)
{
    try_div(10, 2);
    try_div(10, 0);

    return 0;
}
