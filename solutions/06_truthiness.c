/*
 * CSC 139 - A0 C Warm-Up - Exercise 06: there is no boolean
 *
 * CONCEPT: In a condition, 0 is false and every other value is true.
 *
 * C has no native true/false type in the sense you are used to. `if (n)` is
 * legal for any integer n, and it means "if n is not zero".
 *
 * Two consequences worth internalising now:
 *
 *   - `if (x = 5)` compiles. It assigns 5 to x, and 5 is true, so the branch
 *     always runs. This is the single most famous C bug. gcc warns about it.
 *   - Functions signal failure by returning 0 or -1, and you test that value
 *     directly. You will do this for every system call you make this semester.
 *
 * TODO: write `describe` so it prints  <n> is true  or  <n> is false.
 *
 * Your program must print EXACTLY this:
 *
 *     0 is false
 *     1 is true
 *     -1 is true
 *     42 is true
 *
 * Check yourself with:  make test-06        (or: make run-06 to just see it)
 */

#include <stdio.h>

static void describe(int n)
{
    if (n)
        printf("%d is true\n", n);
    else
        printf("%d is false\n", n);
}

int main(void)
{
    describe(0);
    describe(1);
    describe(-1);
    describe(42);

    return 0;
}
