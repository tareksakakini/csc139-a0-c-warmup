/*
 * CSC 139 - A0 C Warm-Up - Exercise 41: write() may not write it all
 *
 * CONCEPT: write() can accept fewer bytes than you gave it. You must loop until everything is out.
 *
 * This is the last rung, and it is the exact loop Assignment 1 is graded on.
 *
 * write() returns how many bytes it actually took. That can be less than n - a
 * pipe filled up, a signal arrived, the device took what it could. It is not an
 * error, and if you ignore it you silently lose the rest of your data. The
 * truncated output you get from the code below is what that failure looks like.
 *
 * The loop has to track how much has gone out and restart from there:
 *
 *     while (written < n) {
 *         ssize_t w = write(fd, buf + written, n - written);
 *         if (w < 0) ...error...
 *         written += w;
 *     }
 *
 * `buf + written` is "the part not sent yet" and `n - written` is "how much is
 * left" - exercise 19, doing real work.
 *
 * `stubborn_write` below is provided. It behaves like write() but never takes
 * more than 7 bytes at a time, so the short-write case actually happens every
 * run instead of once a month in production.
 *
 * The byte count includes the trailing newline, which is why it is one more than
 * the number of visible characters.
 *
 * TODO: make write_all keep going until all n bytes are written.
 *
 * Your program must print EXACTLY this:
 *
 *     this message needs more than one write
 *     wrote 39 bytes
 *
 * Check yourself with:  make test-41        (or: make run-41 to just see it)
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>

/* Provided. Just like write(2), but never accepts more than 7 bytes at a
   time. Real write() does this too - less predictably. Do not change it. */
static ssize_t stubborn_write(int fd, const void *buf, size_t n)
{
    if (n > 7)
        n = 7;

    return write(fd, buf, n);
}

/* Write all n bytes of buf to fd.
   Return the number written, or -1 on error. */
static ssize_t write_all(int fd, const char *buf, size_t n)
{
    /* TODO: loop until all n bytes have gone out. Use stubborn_write, not
             write. Return -1 if a call fails. */
    return stubborn_write(fd, buf, n);
}

int main(void)
{
    const char *msg = "this message needs more than one write\n";
    size_t      n   = strlen(msg);

    ssize_t w = write_all(1, msg, n);

    if (w < 0) {
        perror("write");
        return 1;
    }

    printf("wrote %zd bytes\n", w);

    return 0;
}
