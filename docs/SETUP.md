# Setting up GitHub Codespaces

This is the only supported environment for CSC 139 coding assignments. It runs
in your browser. There is nothing to install and it costs you nothing.

Total time: about five minutes, most of it waiting.

---

## 1. Get a GitHub account

If you do not have one: <https://github.com/signup>. Any email works.

**Then apply for the GitHub Student Developer Pack** at
<https://education.github.com/pack> using your `@csus.edu` address. It is free
and it raises your monthly Codespaces allowance from 120 core-hours to 180.
Approval can take a day or two, so do this now - you do not need it to start.

## 2. Make your own copy

On the repository page, click the green **Use this template** button, then
**Create a new repository**.

- Owner: your own account
- Repository name: `csc139-a0-c-warmup` is fine
- Visibility: **Private**

Click **Create repository**. Work in *your* copy, not the original - you
cannot save changes to the original.

## 3. Open a codespace

On your new repository, click the green **Code** button, then the
**Codespaces** tab, then **Create codespace on main**.

The first one takes two to four minutes while it builds the environment.
Later ones are faster.

When it finishes, a full Visual Studio Code opens in your browser tab: file
list on the left, editor in the middle, terminal at the bottom. If you do not
see the terminal, press <code>Ctrl + `</code> (Control and backtick).

## 4. Check that it works

The environment check runs automatically when the codespace is created. To run
it yourself, type this in the terminal:

```bash
make check-env
```

You want it to end with `Good to go. Start with: make run-01`.

## 5. Work

Open `exercises/01_hello.c` from the file list on the left and edit it like any
editor. In the terminal:

```bash
make run-01     # build exercise 01 and show what it prints
make test-01    # check it
make progress   # the scoreboard for all 41
```

Your files are saved automatically and survive between sessions. Even so, save
your work back to GitHub regularly - it takes one command:

```bash
git add -A && git commit -m "progress" && git push
```

## 6. Stop the codespace when you finish

This is the only housekeeping that matters. A codespace uses your monthly
allowance while it is **running**, not while it exists.

Click the **Codespaces** menu in the bottom-left corner of the window, then
**Stop Current Codespace**. It also stops on its own after 30 idle minutes.

To come back later: go to your repository, **Code -> Codespaces**, and click
the codespace you already have. Everything is where you left it. Do not create
a new one each time.

## How much can I use?

120 core-hours a month on a free account, 180 with the Student Pack. The
default machine is 2 cores, so that is 60 or 90 actual hours a month. These
exercises need eight to ten. You are not going to run out unless you leave
several codespaces running for days.

You will not be charged. Free accounts cannot overspend - Codespaces simply
stops working until the month resets. If that somehow happens, email me, do
not add a credit card.

---

## Why only Codespaces, and why not my own laptop?

Because two of these checks cannot work anywhere else, and a check that lies to
you is worse than no check:

- **Exercise 29 cannot be verified off Linux.** The memory-leak detector ships
  with AddressSanitizer on Linux only. On macOS a leaking program is reported
  as *correct*.
- **`timeout`, which stops runaway loops, is not on macOS.** An infinite loop
  hangs your terminal instead of being cut off.
- **Assignment 1 does not work off Linux at all.** Its system-call tracing has
  no macOS equivalent, and `dtruss` is blocked by Apple's security settings.

`make check-env` and the test runner both stop if they are not on Linux. That
is deliberate.

---

## Troubleshooting

**`gcc: command not found`.**
You are looking at a terminal on your own machine rather than the codespace.
The bottom-left corner of the window should say *Codespaces*.

**`make check-env` fails on any line.**
Post on Canvas with a screenshot of the whole output. Do not try to work
around it.

**I cannot push my changes.**
You are probably working in the original repository instead of your own copy.
Go back to step 2.

**My codespace will not start, or GitHub says my quota is exhausted.**
Email me. There is a fallback, but I want to know it happened.

**Something else.**
Post it on Canvas rather than emailing, so the answer reaches everyone. Include
what you typed and what came back, as text, not a photo of your screen.
