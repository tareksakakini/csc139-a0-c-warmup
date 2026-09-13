/*
 * CSC 139 - A0 C Warm-Up - Exercise 38: file descriptors
 *
 * CONCEPT: open() returns a small integer that stands for an open file. That integer is all you get.
 *
 * This is the first system call in the ladder, and the first thing your program
 * has asked the kernel to do for it.
 *
 *     int fd = open("data/sample.txt", O_RDONLY);
 *
 * The kernel opens the file, records everything about it in its own tables, and
 * hands you back an index into those tables: 0, 1, 2, 3... That index is the
 * file descriptor. It carries no information by itself - all the state lives in
 * the kernel, and you refer to it by number.
 *
 * Descriptors 0, 1 and 2 are already open when your program starts: standard
 * input, standard output and standard error. So a file you open gets 3 or
 * higher. (Run this under the sanitizer and you may see a larger number - the
 * sanitizer opens files of its own before your code runs.)
 *
 * open() returns -1 on failure. close() returns 0 on success and -1 on failure,
 * and you should check it too. <fcntl.h> declares open, <unistd.h> declares
 * close.
 *
 * TODO: open the file, check it, close it, check that too.
 *
 * Your program must print EXACTLY this:
 *
 *     open returned a non-negative fd: yes
 *     0, 1 and 2 were already taken, so fd is at least 3: yes
 *     close returned 0: yes
 *     opening a missing file returned -1: yes
 *
 * Check yourself with:  make test-38        (or: make run-38 to just see it)
 */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    int fd = open("data/sample.txt", O_RDONLY);

    printf("open returned a non-negative fd: %s\n", (fd >= 0) ? "yes" : "no");
    printf("0, 1 and 2 were already taken, so fd is at least 3: %s\n",
           (fd >= 3) ? "yes" : "no");

    int rc = close(fd);

    printf("close returned 0: %s\n", (rc == 0) ? "yes" : "no");

    int bad = open("/no/such/file", O_RDONLY);

    printf("opening a missing file returned -1: %s\n", (bad == -1) ? "yes" : "no");

    return 0;
}
