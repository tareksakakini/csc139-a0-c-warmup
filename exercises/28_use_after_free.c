/*
 * CSC 139 - A0 C Warm-Up - Exercise 28: freed memory is not yours
 *
 * CONCEPT: After free(p), the block belongs to the allocator again. Reading it is a bug even when it appears to work.
 *
 * free() does not erase anything and does not change your pointer. p still holds
 * the same address; that address just no longer belongs to you. The next malloc
 * anywhere in the program may hand the same bytes to somebody else.
 *
 * Read through a freed pointer and you will often see your old data sitting
 * there, intact, and conclude the code is fine. It is not fine. It is a bug that
 * surfaces later, somewhere else, under load.
 *
 * Two habits that cost nothing:
 *   - free exactly once, at the point where the block's life clearly ends
 *   - set the pointer to NULL right after, so a later mistake crashes loudly
 *     instead of reading a stranger's data
 *
 * TODO: the code below frees too early. Move the free so every read happens
 * while the block is still alive, and NULL the pointer afterwards.
 *
 * Your program must print EXACTLY this:
 *
 *     first: 10
 *     second: 20
 *     sum: 30
 *
 * Check yourself with:  make test-28        (or: make run-28 to just see it)
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *a = malloc(2 * sizeof *a);
    if (a == NULL)
        return 1;

    a[0] = 10;
    a[1] = 20;

    printf("first: %d\n", a[0]);

    free(a);

    printf("second: %d\n", a[1]);
    printf("sum: %d\n", a[0] + a[1]);

    return 0;
}
