# ONG Utils

A collection of basic system utilities for Linux, written in plain C.

> **ONG**: **O**NG is **N**ot **G**NU

## Development guide

Repeatedly re-compile the `cat` program and make it available at `cat.out`

```bash
watch -n 0.2 gcc src/cat.c -o cat.out -Wall -Wextra -Werror -fsanitize=address,undefined
```

Run it:

```bash
./cat.out
```
