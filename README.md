# Mini-libc

## Description

**Mini-libc** is a minimal implementation of the [C standard library](https://en.wikipedia.org/wiki/C_standard_library) for Linux systems.  
It can serve as a lightweight replacement for the system libc ([glibc](https://www.gnu.org/software/libc/)).  
The library is freestanding, built directly on Linux syscalls, and provides essential functionality for string handling, memory management, and POSIX file I/O.

---

## Objectives

- Learn about the structure and functionalities provided by the standard C library
- Accommodate with the syscall interface in Linux
- Gain a better understanding of strings and memory management functions
- Learn how the standard C library provides support for low-level input/output operations

---

## Project Structure

- `src/` – mini-libc implementation (with `TODO` parts to complete)
- `samples/` – example programs using mini-libc
- `tests/` – automated tests to validate the implementation

System calls are invoked via `syscall()` in `src/syscall.c`,  
which uses architecture-specific calls in `src/internal/arch/x86_64/syscall_arch.h`.

---

## API & Implementation Tasks

### String Functions (`<string.h>`)

- `strcpy()`, `strcat()`, `strlen()`, `strncpy()`, `strncat()`
- `strcmp()`, `strncmp()`, `strstr()`, `strrstr()`
- `memcpy()`, `memset()`, `memmove()`, `memcmp()`

### I/O Functions (`<stdio.h>` & `<unistd.h>`)

- `puts()`
- `open()`, `close()`, `lseek()`
- `stat()`, `fstat()`, `truncate()`, `ftruncate()`
- `nanosleep()`, `sleep()`

### Memory Management (`<stdlib.h>` & `<sys/mman.h>`)

- `malloc()`, `free()`, `calloc()`
- `realloc()`, `reallocarray()`
- `mmap()`, `mremap()`, `munmap()`

### Error Handling (`<errno.h>`)

- `errno` must be set appropriately on system call failures.

---

## Building Mini-libc

```bash
cd src
make

## Build sample programs

```bash
cd ../samples
make

## Testing & Grading

```bash
cd ../samples
make

Or run the checker only:

```bash
make check