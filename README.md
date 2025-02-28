# A Study on Quines

But... what is a Quine?
A Quine is a program that, when executed, produces its own source code as output.\
This project consists of three quines: Colleen, Grace and Sully;
each with unique requirements and behaviour.
The programs are implemented in both C and Nasm (only the first one in Nasm xD),
with separate Makefiles for each language.

## 📂 Project Structure

```sh
.
├── README.md               # This file
├── asm/                   # Assembly implementations
│   ├── Makefile           # Makefile for Assembly projects
│   └── ex00/              # First Assembly quine (Colleen)
│       ├── Colleen.s      # Assembly source code
│       └── obj/           # Compiled object files
├── c/                     # C implementations
│   ├── Makefile           # Makefile for C projects
│   ├── ex00/              # First C quine (Colleen)
│   │   ├── Colleen.c      # C source code
│   │   └── obj/           # Compiled object files
│   ├── ex01/              # Second C quine (Grace)
│   │   ├── Grace.c        # C source code
│   │   └── obj/           # Compiled object files
│   └── ex02/              # Third C quine (Sully)
│       ├── Sully.c        # C source code
│       └── obj/           # Compiled object files
```

## Quine Programs

### Colleen

Output:\
Displays its own source code when executed.

Requirements:

1. A main function.
1. A function declared outside main and called in main.
1. Two different comments: One in main and another one outside main.

### Grace

Output:\
Writes its own source code to a file named Grace_kid.c.

Requirements:

1. No main function.
1. One comment.
1. At most three macros
1. Program execution is triggered by a macro.

### Sully

Output:\
Writes its own source code to a file named Sully_X.c (where X is an integer),
compiles and runs the new program if X is greater than or equal to 0.

Requirements:

1. Contains an integer initialized to 5, which decrements with each iteration.
1. Recursively generates and compiles new programs until X is less than 0.

## Makefile Automation

Each language directory (asm and c) contains a Makefile with the following rules:

```sh
all/help:    Displays available Makefile rules.
build:       Compiles the executables for all programs.
clean:       Deletes transitive dependencies (object files).
fclean:      Deletes object files and executables.
re:          Runs fclean followed by build.
test0x:      Runs tests for the x exercise (e.g: test00, test01).
test:        Runs all tests
```

## Testing

Just go into the asm or the c directories and run

```sh
make test0X # where X is the exercise number
```

or, to run all tests:

```sh
make test
```
