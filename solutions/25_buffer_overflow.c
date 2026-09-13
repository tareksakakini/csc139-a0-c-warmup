/*
 * CSC 139 - A0 C Warm-Up - Exercise 25: the classic buffer overflow
 *
 * CONCEPT: strcpy writes as many bytes as the source has, regardless of what the destination can hold.
 *
 *     char small[8];
 *     strcpy(small, "this is far too long");
 *
 * strcpy takes no size. It copies until it finds the terminator in the SOURCE,
 * so it writes 21 bytes into 8 bytes of space and stomps over whatever came
 * next. This one bug pattern is responsible for a large share of the security
 * vulnerabilities of the last thirty years.
 *
 * The fix is to use a function you can bound. snprintf is the easiest to reason
 * about:
 *
 *     snprintf(dst, cap, "%s", src);
 *
 * It writes at most `cap` bytes INCLUDING the terminator, truncating if it must,
 * and always terminates. (strncpy is also bounded but does NOT always terminate.
 * Prefer snprintf.)
 *
 * Notice that copy_into takes the capacity as a parameter. It has to: inside the
 * function `dst` is just a pointer, and sizeof would measure the pointer - which
 * is exactly the trap from exercise 18.
 *
 * TODO: make copy_into respect cap.
 *
 * Your program must print EXACTLY this:
 *
 *     copied: this is
 *     that is 7 characters into an 8-byte buffer
 *
 * Check yourself with:  make test-25        (or: make run-25 to just see it)
 */

#include <stdio.h>
#include <string.h>

static void copy_into(char *dst, size_t cap, const char *src)
{
    snprintf(dst, cap, "%s", src);
}

int main(void)
{
    char small[8];

    copy_into(small, sizeof small, "this is far too long");

    printf("copied: %s\n", small);
    printf("that is %zu characters into an %zu-byte buffer\n",
           strlen(small), sizeof small);

    return 0;
}
