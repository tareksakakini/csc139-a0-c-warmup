/*
 * CSC 139 - A0 C Warm-Up - Exercise 27: asking for memory at run time
 *
 * CONCEPT: malloc reserves a block of bytes on the heap and gives you its address.
 *
 * Everything so far had a size fixed when you compiled. `int a[5]` is five ints,
 * always. When the size is not known until the program runs, you ask the
 * allocator:
 *
 *     int *a = malloc(n * sizeof *a);
 *
 * Three things to get right, every time:
 *
 *   - malloc counts BYTES, not elements. Forgetting to multiply by the element
 *     size is the bug in the code below, and it is a very common one.
 *   - `sizeof *a` reads as "the size of the thing a points at". Prefer it to
 *     `sizeof(int)`: if you later change a's type, this expression follows along
 *     and `sizeof(int)` does not.
 *   - malloc can fail and return NULL. Check it.
 *
 * And when you are finished, free(a). Not freeing is exercise 29.
 *
 * TODO: fix the allocation size, check for NULL, and free the block.
 *
 * Your program must print EXACTLY this:
 *
 *     allocated room for 6 ints
 *     0 2 4 6 8 10
 *
 * Check yourself with:  make test-27        (or: make run-27 to just see it)
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    size_t n = 6;

    /* TODO: this reserves n BYTES, not n ints. Fix it.
             Then check the result for NULL before using it. */
    int *a = malloc(n);

    printf("allocated room for %zu ints\n", n);

    for (size_t i = 0; i < n; i++)
        a[i] = (int)i * 2;

    for (size_t i = 0; i < n; i++)
        printf("%d%s", a[i], i == n - 1 ? "\n" : " ");

    /* TODO: give the memory back. */

    return 0;
}
