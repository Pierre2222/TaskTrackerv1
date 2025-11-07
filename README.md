# TaskTracker (TaskTrackerv1)

A simple command-line Task Tracker written in C++.

## Overview

This small CLI program lets you add, list, update, and delete tasks from the terminal. It's intended as a learning project and a base for adding features like file persistence, search, and task categories.

Repository: https://github.com/Pierre2222/TaskTrackerv1

## Prerequisites

- A C++ compiler (g++ recommended)
- Git (already used to manage this repository)

On Windows with MSYS2 / MinGW, make sure `g++` is on your PATH. In PowerShell you can check:

```powershell
g++ --version
git --version
```

## Build

From the project root (where `TaskTracker.c++` resides), run:

```powershell
# compile
g++ TaskTracker.c++ -o TaskTracker
```

This produces an executable called `TaskTracker` in the same directory.

## Run

Run the program from PowerShell:

```powershell
# run the compiled binary
.\TaskTracker
```

When the program runs it prints commands help. Example interactive commands:

- Add a task (note the comma separating name and due date):

```text
add Complete C++ project, 2025-11-15
```

- List tasks:

```text
list
```

- Update a task's status:

```text
update 1 completed
```

- Delete a task:

```text
delete 1
```

- Show help:

```text
help
```

- Exit:

```text
exit
```

## Git / Push README

If you want to add the README locally and push it to GitHub, these are the commands (PowerShell):

```powershell
# stage
git add README.md
# commit
git commit -m "Add README.md"
# push (assumes origin and branch main are configured)
git push
```

You can verify the file on GitHub at the repository URL above.

## Next steps / Ideas

- Add persistence (save tasks to JSON or plain text file)
- Add more command flags (e.g., `--filter`, `--sort`)
- Add tests and CI
- Fix the task input parsing to support quoted names rather than comma separator

## Contributing

If you want to contribute, create a branch and open a PR. Keep changes small and include a short description in your commit messages.

## License

Add a license if you want this project to be reusable by others. MIT is a common permissive choice.

---

If you'd like, I can also:
- Add persistence to save tasks to `tasks.json` and load on start
- Improve the CLI parsing to support quoted arguments
- Add a short `Makefile` or PowerShell build script
