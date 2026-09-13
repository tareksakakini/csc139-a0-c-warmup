/*
 * CSC 139 - A0 C Warm-Up - Exercise 05: integer division
 *
 * CONCEPT: Dividing two ints gives an int. The remainder is thrown away, not rounded.
 *
 * 7 / 2 is 3 in C. Not 3.5, and not 4 - the fractional part is discarded, always
 * toward zero. This bites people who learned division in a language with one
 * numeric type.
 *
 * To get a real quotient, at least one operand must be a floating-point value.
 * Print an int with %d and a double with %f (%.1f for one decimal place).
 *
 * `%` is the remainder operator. To print a literal percent sign with printf you
 * write two of them: %%
 *
 * TODO: fill in the three expressions.
 *
 * Your program must print EXACTLY this:
 *
 *     7 / 2 = 3
 *     7 % 2 = 1
 *     7.0 / 2 = 3.5
 *
 * Check yourself with:  make test-05        (or: make run-05 to just see it)
 */

#include <stdio.h>

int main(void)
{
    int a = 7;
    int b = 2;

    printf("7 / 2 = %d\n", a / b);

    printf("7 %% 2 = %d\n", a % b);

    printf("7.0 / 2 = %.1f\n", (double)a / b);

    return 0;
}
