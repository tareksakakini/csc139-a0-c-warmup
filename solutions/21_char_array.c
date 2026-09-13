/*
 * CSC 139 - A0 C Warm-Up - Exercise 21: a string is bytes plus a zero
 *
 * CONCEPT: C has no string type. A string is a char array whose last byte is 0.
 *
 *     char word[6] = { 'h', 'e', 'l', 'l', 'o', '\0' };
 *
 * Five letters, six bytes. That last byte - written '\0', value zero, called the
 * NUL terminator - is not decoration. It is the only thing that marks where the
 * string stops. printf("%s") starts at the address you give it and keeps
 * printing until it hits a zero byte.
 *
 * Forget the terminator and %s walks off the end of your array printing whatever
 * is next in memory until it happens to find a zero. That is not a hypothetical;
 * it is exercise 25.
 *
 * Note that 'h' in single quotes is a character - one byte, the number 104.
 * "h" in double quotes is a two-byte array: 'h' and '\0'. They are not
 * interchangeable.
 *
 * TODO: fill in the array by hand, including the terminator.
 *
 * Your program must print EXACTLY this:
 *
 *     as a string: hello
 *     byte 0 is 'h' with value 104
 *     byte 5 has value 0
 *
 * Check yourself with:  make test-21        (or: make run-21 to just see it)
 */

#include <stdio.h>

int main(void)
{
    char word[6];

    word[0] = 'h';
    word[1] = 'e';
    word[2] = 'l';
    word[3] = 'l';
    word[4] = 'o';
    word[5] = '\0';

    printf("as a string: %s\n", word);
    printf("byte 0 is '%c' with value %d\n", word[0], word[0]);
    printf("byte 5 has value %d\n", word[5]);

    return 0;
}
