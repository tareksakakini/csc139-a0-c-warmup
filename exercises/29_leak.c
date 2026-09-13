/*
 * CSC 139 - A0 C Warm-Up - Exercise 29: what you allocate, you free
 *
 * CONCEPT: Memory you never free is never reused. Nothing reclaims it for you.
 *
 * There is no garbage collector. Every malloc needs a matching free on every
 * path out of the function - including the error paths, which is where leaks
 * actually hide.
 *
 * A leak in a program that runs for a second is invisible. A leak in a program
 * that runs for a month is an outage. Operating system kernels, which is what
 * this course is about, are in the second category.
 *
 * LeakSanitizer is bundled with the sanitizer you have been using. When the
 * program exits it reports every block still allocated and the stack trace of
 * the malloc that created it, so finding a leak is mechanical: run it, read the
 * trace, add the missing free.
 *
 * Note the early return in the middle of make_row. That path leaks. Run it and
 * read the report before you fix anything.
 *
 * TODO: make the program leak-free without changing what it prints.
 *
 * Your program must print EXACTLY this:
 *
 *     row 3: 0 1 2
 *     row 0: (empty)
 *
 * Check yourself with:  make test-29        (or: make run-29 to just see it)
 */

#include <stdio.h>
#include <stdlib.h>

static void make_row(size_t n)
{
    int *row = malloc((n ? n : 1) * sizeof *row);
    if (row == NULL)
        return;

    if (n == 0) {
        printf("row 0: (empty)\n");
        return;
    }

    for (size_t i = 0; i < n; i++)
        row[i] = (int)i;

    printf("row %zu:", n);
    for (size_t i = 0; i < n; i++)
        printf(" %d", row[i]);
    printf("\n");
}

int main(void)
{
    make_row(3);
    make_row(0);

    return 0;
}
