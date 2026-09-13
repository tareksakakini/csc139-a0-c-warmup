# CSC 139 — Assignment 0: the C warm-up

**41 exercises. One new idea each. Assume you can already program; assume you
have never written C.**

The last four exercises are, between them, most of Assignment 1. That is the
point: by the time you open `filecopy.c` you will have already written the
loop it is graded on.

Budget 8–10 focused hours. Phase 4 (pointers) is the one that matters — if you
are short on time, go slower there and faster everywhere else.

---

## Start here

1. Open the repo — see **[docs/SETUP.md](docs/SETUP.md)**. Codespaces is the
   zero-install option.
2. Run the environment check. Every line must pass:

   ```bash
   make check-env
   ```

3. Read **[docs/CHEATSHEET.md](docs/CHEATSHEET.md)**. It is one page, and it is
   the whole delta between C and the language you already know.
4. Begin:

   ```bash
   make run-01
   ```

## How each exercise works

Every exercise is a single file in `exercises/`. Open it and read the comment
at the top: it states the one concept, explains it, and shows the exact output
your program must produce. Then fill in the `TODO`s.

```bash
make run-07        # build exercise 07 and show what it prints
make test-07       # check it
make test          # check everything
make progress      # the scoreboard
```

You pass an exercise when it compiles with **no warnings**, exits cleanly, and
prints exactly what the header said.

Work in order. Each exercise assumes the ones before it.

## When you are stuck

In this order:

1. **Read the compiler output.** Fix the *first* error, then rebuild. One real
   mistake produces a cascade of fake ones underneath it.
2. **Read the sanitizer report.** From exercise 12 on, every build has
   AddressSanitizer switched on. When it fires it names your file and line —
   the cheat sheet explains how to read the report in three lines.
3. **Read the manual.** `man 2 read` is the real documentation, and getting
   comfortable with it now pays off all semester.
4. **Look at the answer.** `solutions/` has a worked version of every exercise.
   Use it after a real attempt, not instead of one — then close it, and write
   yours again from scratch. Nothing here is worth cheating on; the exam is in
   October and it does not care what is in this folder.

```bash
make solution-07   # build and run the reference version
```

## Submitting

This is completion credit, not a graded assignment. When `make test` is green:

```bash
make report        # writes progress.txt
```

Upload `progress.txt` to Canvas. If some exercises are still failing when the
deadline arrives, submit it anyway — a partial run tells me where the class is
stuck, which is more useful to me than a perfect score.

## Then

Open Assignment 1. `filecopy.c` will look like a exercise 41 with a second
file descriptor, because that is essentially what it is.

---

## The ladder

### Phase 1 - the toolchain

Before any real C: compile something, break it, read what the compiler says.

- **01** &nbsp;hello
- **02** &nbsp;reading compiler errors
- **03** &nbsp;warnings are bugs

### Phase 2 - values and control flow

The fast tour. You already know loops; these are the places C differs.

- **04** &nbsp;types have sizes
- **05** &nbsp;integer division
- **06** &nbsp;there is no boolean
- **07** &nbsp;the for loop
- **08** &nbsp;declare before you use
- **09** &nbsp;integers wrap around

### Phase 3 - arrays, and nobody checking them

Fixed-size storage, and what happens when you walk off the end.

- **10** &nbsp;arrays
- **11** &nbsp;arrays do not know their length
- **12** &nbsp;nobody checks your indexes
- **13** &nbsp;let the sanitizer find it

### Phase 4 - pointers

The heart of it. Do not skip ahead; every later exercise assumes these.

- **14** &nbsp;variables have addresses
- **15** &nbsp;following a pointer
- **16** &nbsp;pass by value, always
- **17** &nbsp;pointer arithmetic counts elements
- **18** &nbsp;arrays decay into pointers
- **19** &nbsp;indexing IS pointer arithmetic
- **20** &nbsp;NULL and the check you must write

### Phase 5 - strings

A string is an array of bytes with a zero on the end. That is all it is.

- **21** &nbsp;a string is bytes plus a zero
- **22** &nbsp;length is not capacity
- **23** &nbsp;literals are read-only
- **24** &nbsp;== compares addresses
- **25** &nbsp;the classic buffer overflow

### Phase 6 - the heap

Memory that outlives the function that made it, and the four ways to get it wrong.

- **26** &nbsp;locals die when the function returns
- **27** &nbsp;asking for memory at run time
- **28** &nbsp;freed memory is not yours
- **29** &nbsp;what you allocate, you free
- **30** &nbsp;growing a block

### Phase 7 - structs and headers

Grouping data, and what #include has been doing this whole time.

- **31** &nbsp;grouping values together
- **32** &nbsp;the arrow operator
- **33** &nbsp;what #include actually does

### Phase 8 - how C reports failure

No exceptions. Return values, errno, and the signed/unsigned trap.

- **34** &nbsp;errors come back as values
- **35** &nbsp;errno says why
- **36** &nbsp;arguments arrive as strings
- **37** &nbsp;size_t is unsigned

### Phase 9 - talking to the kernel

Four system calls. By the end of this phase you have written most of Assignment 1.

- **38** &nbsp;file descriptors
- **39** &nbsp;read() fills a buffer you own
- **40** &nbsp;one read is not enough
- **41** &nbsp;write() may not write it all

---

## Layout

```
exercises/   the files you edit            solutions/  worked answers
tests/       the checker + expected output data/       input files for phase 9
include/     a header, for exercise 33     docs/       setup + cheat sheet
```
