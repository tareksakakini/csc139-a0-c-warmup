/*
 * stats.h - the CONTRACT for exercise 33.
 *
 * A header file contains declarations, not code: it tells the compiler what
 * exists and what shape it has. This one promises that two functions exist
 * somewhere, and describes what they do. It does not say how they work.
 *
 * The #ifndef / #define / #endif wrapper is an include guard. If two files
 * both include this header, the second inclusion expands to nothing, so the
 * declarations are not duplicated. Every header you write should have one.
 */
#ifndef STATS_H
#define STATS_H

#include <stddef.h>

/* Return the largest value in a[0..n-1]. n must be at least 1. */
int stats_max(const int *a, size_t n);

/* Return the sum of a[0..n-1]. Returns 0 when n is 0. */
int stats_sum(const int *a, size_t n);

#endif /* STATS_H */
