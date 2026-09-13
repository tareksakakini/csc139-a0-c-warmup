/*
 * CSC 139 - A0 C Warm-Up - Exercise 24: == compares addresses
 *
 * CONCEPT: Comparing two strings with == asks whether they are the same object, not whether they read the same.
 *
 * `a == b` on two char arrays compares two addresses. Two arrays holding the
 * same letters are still two different arrays at two different addresses, so the
 * answer is no.
 *
 * To compare contents, call strcmp, which returns:
 *
 *     0   the strings are equal
 *   < 0   the first sorts before the second
 *   > 0   the first sorts after it
 *
 * Note that "equal" is `strcmp(a, b) == 0` - the value that means success is
 * zero, which reads backwards the first hundred times. Write it out explicitly
 * rather than relying on truthiness.
 *
 * TODO: fill in the three blanks using strcmp.
 *
 * Your program must print EXACTLY this:
 *
 *     a == b: no
 *     strcmp(a, b) == 0: yes
 *     "apple" vs "banana": apple sorts first
 *
 * Check yourself with:  make test-24        (or: make run-24 to just see it)
 */

#include <stdio.h>
#include <string.h>

int main(void)
{
    char a[] = "abc";
    char b[] = "abc";

    printf("a == b: %s\n", (a == b) ? "yes" : "no");

    printf("strcmp(a, b) == 0: %s\n", (strcmp(a, b) == 0) ? "yes" : "no");

    printf("\"apple\" vs \"banana\": %s\n",
           (strcmp("apple", "banana") < 0) ? "apple sorts first"
                                           : "banana sorts first");

    return 0;
}
