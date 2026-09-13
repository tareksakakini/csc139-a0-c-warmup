/*
 * CSC 139 - A0 C Warm-Up - Exercise 39: read() fills a buffer you own
 *
 * CONCEPT: read() does not return data. It copies bytes into memory you provide and tells you how many.
 *
 *     ssize_t n = read(fd, buf, count);
 *
 * Three things, and every one of them is a place people go wrong:
 *
 *   - `buf` is YOUR memory. The kernel writes into it. If buf is too small for
 *     `count`, you have just let the kernel overflow your buffer - so `count`
 *     must never exceed the size of buf.
 *   - the return value is how many bytes actually arrived. It is a SIGNED
 *     ssize_t: 0 means end of file, -1 means error, and a positive number may be
 *     smaller than what you asked for.
 *   - read() knows nothing about strings. It does not add a terminator. If you
 *     intend to use those bytes with %s, you must write the '\0' yourself, which
 *     is why we read at most (sizeof buf - 1) bytes and terminate at buf[n].
 *
 * data/sample.txt begins with "the first line\n", which is 15 bytes. We ask for
 * 14 so the line comes back without its newline.
 *
 * TODO: read 14 bytes into buf, terminate it, and print it.
 *
 * Your program must print EXACTLY this:
 *
 *     read 14 bytes
 *     they say: the first line
 *
 * Check yourself with:  make test-39        (or: make run-39 to just see it)
 */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    char buf[64];

    int fd = open("data/sample.txt", O_RDONLY);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    /* TODO: replace this -1 with a real read() of 14 bytes into buf.
             Until you do, the error branch just below fires and the program
             stops - that is expected, not a second bug to chase. */
    ssize_t n = -1;

    if (n < 0) {
        perror("read");
        close(fd);
        return 1;
    }

    /* TODO: make buf a valid string by terminating it after the n bytes. */

    printf("read %zd bytes\n", n);
    printf("they say: %s\n", buf);

    close(fd);

    return 0;
}
