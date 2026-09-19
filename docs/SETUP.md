# Setting up

You need a **Linux** shell with `gcc` and `make`. Pick one. If you have no
strong preference, use Codespaces - it needs nothing installed on your laptop.

## Option A - GitHub Codespaces (recommended)

1. Create a free GitHub account: <https://github.com/signup>
2. *(Worth doing)* Apply for the GitHub Student Developer Pack at
   <https://education.github.com/pack> with your `@csus.edu` address. It raises
   your free Codespaces allowance from 120 to 180 core-hours a month.
3. Open this repository on GitHub and click **Code → Codespaces → Create
   codespace on main**.
4. Wait about a minute for the container to build the first time.
5. A full VS Code opens in your browser with a terminal at the bottom.
6. Run `make check-env`.

**Watch your usage.** A codespace costs core-hours while it is *running*, not
while it exists. It auto-stops after 30 minutes idle, but stop it yourself
when you finish: the Codespaces menu (bottom-left) → **Stop Current
Codespace**.

This is the same container definition as Assignment 1, so nothing you learn
here about the environment goes to waste.

## Option B - Dev Container in VS Code (local, no quota)

1. Install [Docker Desktop](https://www.docker.com/products/docker-desktop/)
   and start it.
2. Install [VS Code](https://code.visualstudio.com/) and the **Dev Containers**
   extension.
3. Clone this repo, open the folder, and accept **Reopen in Container**.
4. Run `make check-env`.

## Option C - plain Docker

```bash
docker build -t csc139-a0 .devcontainer
docker run -it --rm -v "$PWD":/work -w /work csc139-a0 bash
make check-env
```

---

## Not on Linux? Then not at all

`make check-env` will stop you, on purpose. This is not fussiness about
platforms:

- **Exercise 29 cannot be checked off Linux.** The memory-leak detector ships
  with AddressSanitizer on Linux only. Everywhere else a leaking program is
  reported as *correct* - and a green check that does not mean your code is
  right is worse than no check at all.
- **Assignment 1 does not work off Linux.** Its system-call tracing has no
  equivalent on macOS, and `dtruss` is blocked by System Integrity Protection.
- **You are graded on Linux.** Whatever passes on your laptop is not the thing
  being marked.

Option A above costs you nothing and takes a minute. Use it.
