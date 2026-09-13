/*
 * CSC 139 - A0 C Warm-Up - Exercise 26: locals die when the function returns
 *
 * CONCEPT: A local variable's storage is reclaimed the moment its function returns. A pointer to it is garbage.
 *
 * `buf` below lives on the stack. When greeting() returns, that stack space is
 * handed back and the next function call overwrites it. The address is still a
 * valid-looking number; the bytes it points at are no longer yours.
 *
 * This is the one memory bug gcc catches without any help - it is compiled here
 * with -Werror, so the warning stops the build. Read it. `-Wreturn-local-addr`
 * is telling you something true and serious.
 *
 * There are three honest ways out:
 *   1. the caller supplies the buffer, and the function fills it in
 *   2. the function allocates on the heap and the caller frees it (exercise 27)
 *   3. the data is static and therefore never dies (rarely what you want)
 *
 * Option 1 is what C libraries overwhelmingly do, and it is why so many
 * functions take a destination pointer plus a capacity. You are about to meet
 * the most important example: read(fd, buf, count) fills a buffer that YOU own.
 *
 * TODO: rewrite greeting() to take a destination buffer and its capacity, and
 * update main to pass one in.
 *
 * Your program must print EXACTLY this:
 *
 *     hello, world
 *     hello, CSC 139
 *
 * Check yourself with:  make test-26        (or: make run-26 to just see it)
 */

#include <stdio.h>

static void greeting(char *out, size_t cap, const char *name)
{
    snprintf(out, cap, "hello, %s", name);
}

int main(void)
{
    char line[64];

    greeting(line, sizeof line, "world");
    printf("%s\n", line);

    greeting(line, sizeof line, "CSC 139");
    printf("%s\n", line);

    return 0;
}
