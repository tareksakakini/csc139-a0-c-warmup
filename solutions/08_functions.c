/*
 * CSC 139 - A0 C Warm-Up - Exercise 08: declare before you use
 *
 * CONCEPT: The compiler reads your file top to bottom, once. It cannot call forward.
 *
 * When gcc reaches a call to `max_of`, it must already know what `max_of` takes
 * and returns. You give it that knowledge in one of two ways:
 *
 *   - define the whole function above the caller, or
 *   - write a *prototype* above the caller and define it anywhere:
 *         int max_of(int a, int b);      <- note the semicolon, no body
 *
 * Header files like <stdio.h> are nothing more magical than a pile of these
 * prototypes. That is the entire reason you #include them.
 *
 * If you define a function but never declare it before its first use, or declare
 * it but never define it, you get a linker error - `undefined reference to
 * max_of` - which comes from a different program than the compiler and looks
 * nothing like a compiler error. Expect it, and recognise it.
 *
 * TODO: write the prototype and the definition of max_of.
 *
 * Your program must print EXACTLY this:
 *
 *     max_of(3, 9) = 9
 *     max_of(9, 3) = 9
 *     max_of(4, 4) = 4
 *
 * Check yourself with:  make test-08        (or: make run-08 to just see it)
 */

#include <stdio.h>

int max_of(int a, int b);

int main(void)
{
    printf("max_of(3, 9) = %d\n", max_of(3, 9));
    printf("max_of(9, 3) = %d\n", max_of(9, 3));
    printf("max_of(4, 4) = %d\n", max_of(4, 4));

    return 0;
}

int max_of(int a, int b)
{
    if (a > b)
        return a;
    return b;
}
