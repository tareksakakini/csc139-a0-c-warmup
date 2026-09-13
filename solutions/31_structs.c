/*
 * CSC 139 - A0 C Warm-Up - Exercise 31: grouping values together
 *
 * CONCEPT: A struct is several values of different types stored as one object.
 *
 *     struct point {
 *         int x;
 *         int y;
 *     };
 *
 *     struct point p = { 3, 4 };
 *     p.x = 10;
 *
 * No methods, no inheritance, no privacy - just named fields laid out in memory
 * in the order you wrote them. The type's full name is `struct point`, with the
 * keyword, everywhere you use it.
 *
 * Unlike arrays, structs ARE copied when you assign them or pass them to a
 * function. `struct point q = p;` makes a genuine copy - which is why changing
 * b below leaves a untouched. That is convenient for small structs and expensive
 * for big ones, which is why real code usually passes a pointer instead: the
 * next exercise.
 *
 * TODO: define the struct and make b a copy of a.
 *
 * Your program must print EXACTLY this:
 *
 *     a is at (3, 4)
 *     b is at (3, 4)
 *     after moving b, a is at (3, 4)
 *     b is at (10, 4)
 *
 * Check yourself with:  make test-31        (or: make run-31 to just see it)
 */

#include <stdio.h>

struct point {
    int x;
    int y;
};

static void print_point(const char *label, struct point p)
{
    printf("%s is at (%d, %d)\n", label, p.x, p.y);
}

int main(void)
{
    struct point a = { 3, 4 };

    struct point b = a;

    print_point("a", a);
    print_point("b", b);

    b.x = 10;

    printf("after moving b, ");
    print_point("a", a);
    print_point("b", b);

    return 0;
}
