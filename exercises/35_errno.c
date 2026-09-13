/*
 * CSC 139 - A0 C Warm-Up - Exercise 35: errno says why
 *
 * CONCEPT: When a system call fails it sets errno, a global that explains the failure.
 *
 * open() returning -1 tells you something went wrong. `errno` tells you what:
 * the file does not exist (ENOENT), you lack permission (EACCES), the path is a
 * directory (EISDIR), and so on.
 *
 * Three rules, all of which matter:
 *
 *   - errno is only meaningful AFTER a call has told you it failed. It is not
 *     cleared on success, so a stale value from an earlier call will happily
 *     mislead you. Check the return value first, then read errno.
 *   - strerror(errno) turns it into a readable string.
 *   - perror("open") prints  open: No such file or directory  to stderr in one
 *     call. It is what you will use in Assignment 1.
 *
 * <errno.h> declares errno and the E-names; <string.h> declares strerror.
 *
 * TODO: report the failure using errno.
 *
 * Your program must print EXACTLY this:
 *
 *     opening data/sample.txt: ok
 *     opening /no/such/file: No such file or directory
 *     errno was ENOENT: yes
 *
 * Check yourself with:  make test-35        (or: make run-35 to just see it)
 */

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    int fd = open("data/sample.txt", O_RDONLY);
    if (fd < 0) {
        printf("opening data/sample.txt: %s\n", strerror(errno));
        return 1;
    }
    printf("opening data/sample.txt: ok\n");
    close(fd);

    int bad = open("/no/such/file", O_RDONLY);
    if (bad >= 0) {
        printf("that should not have worked\n");
        close(bad);
        return 1;
    }

    /* TODO: print the reason this failed, using strerror on errno. */
    printf("opening /no/such/file: %s\n", "???");

    /* TODO: was the reason ENOENT? */
    printf("errno was ENOENT: %s\n", 0 ? "yes" : "no");

    return 0;
}
