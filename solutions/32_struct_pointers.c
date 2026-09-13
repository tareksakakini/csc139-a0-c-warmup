/*
 * CSC 139 - A0 C Warm-Up - Exercise 32: the arrow operator
 *
 * CONCEPT: p->field is shorthand for (*p).field.
 *
 * When you have a POINTER to a struct, reaching a field means dereferencing
 * first. The parentheses are required, because `.` binds tighter than `*`:
 *
 *     (*p).x        correct, and nobody writes it
 *     p->x          the same thing, and what everybody writes
 *
 * Passing `struct point *` instead of `struct point` means the function can
 * modify the caller's struct, and means only 8 bytes cross the call instead of
 * the whole object. This is the normal way to pass anything bigger than a couple
 * of ints.
 *
 * `const struct point *p` says "I will read through this pointer but not write
 * through it" - the compiler enforces it, and it documents your intent to the
 * next reader. Use it on parameters you do not modify.
 *
 * TODO: write move_by() so it modifies the caller's struct through the pointer.
 *
 * Your program must print EXACTLY this:
 *
 *     start: (3, 4)
 *     after move: (8, 1)
 *
 * Check yourself with:  make test-32        (or: make run-32 to just see it)
 */

#include <stdio.h>

struct point {
    int x;
    int y;
};

static void print_point(const char *label, const struct point *p)
{
    printf("%s: (%d, %d)\n", label, p->x, p->y);
}

static void move_by(struct point *p, int dx, int dy)
{
    p->x += dx;
    p->y += dy;
}

int main(void)
{
    struct point a = { 3, 4 };

    print_point("start", &a);

    move_by(&a, 5, -3);

    print_point("after move", &a);

    return 0;
}
