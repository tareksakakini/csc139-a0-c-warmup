/*
 * CSC 139 - A0 C Warm-Up - Exercise 07: the for loop
 *
 * CONCEPT: C's for loop is three expressions: set up, test, advance.
 *
 *     for (int i = 1; i <= 5; i++)
 *
 *   - `int i = 1` runs once, before the loop
 *   - `i <= 5` is checked before every pass; the loop stops when it is false
 *   - `i++` runs after every pass
 *
 * There is no `for x in ...`. If you want to walk a collection, you count.
 * Declaring the counter inside the parentheses (`for (int i = ...`) keeps it
 * local to the loop; that needs C99 or later, which is what we compile with.
 *
 * TODO: print each number from 1 to 5 and its square.
 *
 * Your program must print EXACTLY this:
 *
 *     1 squared is 1
 *     2 squared is 4
 *     3 squared is 9
 *     4 squared is 16
 *     5 squared is 25
 *
 * Check yourself with:  make test-07        (or: make run-07 to just see it)
 */

#include <stdio.h>

int main(void)
{
    /* TODO: loop from 1 to 5 and print each line. */

    return 0;
}
