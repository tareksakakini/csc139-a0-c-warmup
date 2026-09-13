/*
 * CSC 139 - A0 C Warm-Up - Exercise 20: NULL and the check you must write
 *
 * CONCEPT: A pointer to nothing is spelled NULL, and going through it kills the program.
 *
 * A function that looks something up has to be able to say "not there". C's
 * answer is to return NULL - a pointer value guaranteed not to be the address of
 * any object.
 *
 * Nothing forces you to check. Dereference NULL and the hardware stops you: your
 * process gets SIGSEGV and dies with no message worth reading. Under the
 * sanitizer you at least get told which line.
 *
 * The pattern below is one you will write hundreds of times this semester:
 *
 *     T *p = something_that_might_fail();
 *     if (p == NULL) {
 *         ...handle it...
 *     }
 *
 * TODO: check the result of find() before using it.
 *
 * Your program must print EXACTLY this:
 *
 *     found 30
 *     not found
 *
 * Check yourself with:  make test-20        (or: make run-20 to just see it)
 */

#include <stdio.h>
#include <stddef.h>

/* Return a pointer to the first element equal to target, or NULL. */
static int *find(int *a, size_t n, int target)
{
    for (size_t i = 0; i < n; i++)
        if (a[i] == target)
            return &a[i];

    return NULL;
}

static void report(int *a, size_t n, int target)
{
    int *hit = find(a, n, target);

    /* TODO: if hit is NULL, print  not found  instead of crashing. */
    printf("found %d\n", *hit);
}

int main(void)
{
    int a[4] = { 10, 20, 30, 40 };

    report(a, 4, 30);
    report(a, 4, 99);

    return 0;
}
