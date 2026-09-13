/*
 * CSC 139 - A0 C Warm-Up - Exercise 30: growing a block
 *
 * CONCEPT: realloc resizes an allocation, moving it somewhere bigger if it has to.
 *
 * This is how you build the growable list your old language gave you for free.
 *
 *     int *bigger = realloc(a, new_count * sizeof *a);
 *
 * realloc copies your existing contents into the new block and frees the old one
 * for you. It may also return a DIFFERENT address, which is why you must not
 * write it like this:
 *
 *     a = realloc(a, new_count * sizeof *a);        <-- WRONG
 *
 * If realloc fails it returns NULL, and that line has just overwritten your only
 * pointer to the old block - which is still allocated. You have leaked it and
 * lost the data. Always land the result in a temporary, check it, then assign.
 *
 * Doubling the capacity when it fills, rather than growing by one, is what keeps
 * the total copying cost proportional to the number of items rather than to its
 * square.
 *
 * TODO: implement the growth step in push().
 *
 * Your program must print EXACTLY this:
 *
 *     pushed 5 items, capacity ended at 8
 *     0 10 20 30 40
 *
 * Check yourself with:  make test-30        (or: make run-30 to just see it)
 */

#include <stdio.h>
#include <stdlib.h>

static int    *items = NULL;
static size_t  count = 0;
static size_t  cap   = 0;

static int push(int value)
{
    if (count == cap) {
        size_t new_cap = (cap == 0) ? 2 : cap * 2;

        int *bigger = realloc(items, new_cap * sizeof *items);
        if (bigger == NULL)
            return -1;

        items = bigger;
        cap   = new_cap;
    }

    items[count++] = value;
    return 0;
}

int main(void)
{
    for (int i = 0; i < 5; i++)
        if (push(i * 10) != 0) {
            fprintf(stderr, "out of memory\n");
            free(items);
            return 1;
        }

    printf("pushed %zu items, capacity ended at %zu\n", count, cap);

    for (size_t i = 0; i < count; i++)
        printf("%d%s", items[i], i == count - 1 ? "\n" : " ");

    free(items);

    return 0;
}
