/*
 * CSC 139 - A0 C Warm-Up - Exercise 03: warnings are bugs
 *
 * CONCEPT: A warning is a bug the compiler already found for you.
 *
 * This file compiles. It is still wrong.
 *
 * `doubled` never returns anything, so the value `main` prints is garbage - it
 * is whatever happened to be lying around in the CPU register the caller reads.
 * The compiler noticed. It said `warning: control reaches end of non-void
 * function`, and then compiled it anyway, because that is what C does.
 *
 * This exercise is built with -Werror, which turns every warning into an error.
 * Get in the habit now: a clean build means zero warnings, not zero errors.
 *
 * TODO: fix everything gcc complains about.
 *
 * Your program must print EXACTLY this:
 *
 *     doubled(21) = 42
 *
 * Check yourself with:  make test-03        (or: make run-03 to just see it)
 */

#include <stdio.h>

static int doubled(int n)
{
    int unused = 5;

    n * 2;
}

int main(void)
{
    printf("doubled(21) = %d\n", doubled(21));

    return 0;
}
