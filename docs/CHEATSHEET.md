# C for people who already program

You are not learning to program. You are learning four things your previous
language did for you silently. Everything else is syntax you will absorb by
Wednesday.

### 1. Memory is explicit, and it has addresses

A variable is a box of bytes at a numbered location. `&x` is that number.
A *pointer* is a variable that holds one. `*p` means "the thing at p".

```c
int  x = 10;
int *p = &x;     /* p holds the address of x */
*p = 99;         /* x is now 99 */
```

Arguments are always copied. To let a function change your variable, hand it
the address: that is why so many C functions take pointers.

### 2. Arrays are not objects

No length, no bounds check, no append. An array is raw storage, and the
moment you pass it to a function it decays to a bare pointer and its length
is gone. That is why nearly every array-taking function also takes a count -
including `read()` and `write()`.

```c
int a[6];
size_t n = sizeof(a) / sizeof(a[0]);   /* 6 - but only in this scope */
```

A string is just a `char` array whose last byte is `0`. Nothing else marks
where it ends.

### 3. There is no safety net

No exceptions, no traceback, no line number. Out-of-bounds access is not an
error; it reads whatever bytes are there and carries on. Failure is reported
by return value - `-1` or `NULL` - and if you do not check it, nothing does.

Switch the net on yourself. Every exercise here is built with
`-fsanitize=address,undefined`, which turns a silent corruption into a report
naming your file and line. Use it on your own code too.

### 4. There is a build step and a manual

`gcc` turns your text into a program. Warnings are bugs it already found for
you - fix all of them. `#include <stdio.h>` just pastes in a file of
declarations; nothing magic.

`man 2 open` is the real documentation for a system call, and reading it is a
skill worth practising. Section 2 is system calls, section 3 is library
functions.

---

### The five things that will actually bite you

| Symptom | Cause |
|---|---|
| `Segmentation fault` and nothing else | dereferenced NULL, or a pointer to memory that is gone |
| Works, then breaks somewhere unrelated | you wrote past the end of a buffer |
| `undefined reference to 'foo'` | that is the *linker*: declared but never defined |
| A loop that never ends | you subtracted from a `size_t` that was 0 |
| Garbage string, or output that keeps going | you forgot the `'\0'` |

### Reading a sanitizer report

You need three lines out of the wall of text:

1. the first line - what kind of error, and whether it was a READ or a WRITE
2. the first stack frame naming one of **your** files - that is the line to fix
3. where the object was allocated

Go to that line. The bug is almost always obvious once you are standing on it.
