/*
 * CSC 139 - A0 C Warm-Up - Exercise 17: pointer arithmetic counts elements
 *
 * CONCEPT: `p + 1` does not add 1 byte. It adds one whole element.
 *
 * If p is an `int *`, then `p + 1` is the address four bytes further along,
 * because that is where the next int starts. The compiler scales the arithmetic
 * by sizeof(*p) for you. If p were a `char *`, `p + 1` really would be one byte
 * along, because a char is one byte.
 *
 * The name of an array, used in an expression, gives you the address of its
 * first element. So `int *p = a;` is legal with no `&` in sight.
 *
 * To see the raw byte distance, cast both sides to `char *` first - that forces
 * the arithmetic to count in single bytes.
 *
 * TODO: fill in the four expressions.
 *
 * Your program must print EXACTLY this:
 *
 *     *p is 10
 *     *(p + 1) is 20
 *     *(p + 3) is 40
 *     p + 1 is 4 bytes further along than p
 *
 * Check yourself with:  make test-17        (or: make run-17 to just see it)
 */

#include <stdio.h>

int main(void)
{
    int  a[4] = { 10, 20, 30, 40 };
    int *p    = a;

    printf("*p is %d\n", *p);

    printf("*(p + 1) is %d\n", *(p + 1));

    printf("*(p + 3) is %d\n", *(p + 3));

    printf("p + 1 is %ld bytes further along than p\n",
           (long)((char *)(p + 1) - (char *)p));

    return 0;
}
