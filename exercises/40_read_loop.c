/*
 * CSC 139 - A0 C Warm-Up - Exercise 40: one read is not enough
 *
 * CONCEPT: read() returns what is available now, not what you asked for. Loop until it returns 0.
 *
 * A single read() gives you up to `count` bytes. It is free to give you fewer -
 * because the file ended, because a pipe has only delivered part of the data,
 * because a signal interrupted it. Only a return of 0 means end of file.
 *
 * So reading a whole file is always a loop:
 *
 *     while ((n = read(fd, buf, sizeof buf)) > 0) {
 *         ...do something with the first n bytes...
 *     }
 *     if (n < 0) { ...error... }
 *
 * Note the loop condition captures n and tests it in one step, and that the
 * error case is handled after the loop, not inside it.
 *
 * We use a deliberately tiny 4-byte buffer here so the loop runs many times on a
 * small file. That is also the point of the buffer-size experiment in Assignment
 * 1: the smaller the buffer, the more system calls, and system calls are not
 * free.
 *
 * TODO: read the whole file, counting total bytes and how many times you called
 * read(). Count every call, including the final one that returns 0.
 *
 * Your program must print EXACTLY this:
 *
 *     total bytes: 46
 *     read() calls: 13
 *
 * Check yourself with:  make test-40        (or: make run-40 to just see it)
 */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    char   buf[4];
    size_t total = 0;
    int    calls = 0;

    int fd = open("data/sample.txt", O_RDONLY);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    /* TODO: loop, reading up to sizeof buf bytes at a time, until read()
             returns 0. Add each result to total and count every call.
             Bail out with perror("read") if a call returns -1. */

    printf("total bytes: %zu\n", total);
    printf("read() calls: %d\n", calls);

    close(fd);

    return 0;
}
