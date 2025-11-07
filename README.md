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
