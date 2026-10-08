# Intermediate Code Representations: Quadruples, Triples & Indirect Triples

[![Language](https://img.shields.io/badge/Language-C99%20%2F%20C11-00599C.svg?logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))
[![IR](https://img.shields.io/badge/Intermediate%20Code-Quadruples%20%7C%20Triples-green.svg)](https://gcc.gnu.org/)
[![Course](https://img.shields.io/badge/Course-BCSE306L%20Compiler%20Design-red.svg)](https://vit.ac.in)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

## Author Information
- **Author:** Shrri Dharshan D R
- **GitHub:** [@shrridharshan27](https://github.com/shrridharshan27)
- **Registration Number:** `23BPS1090`
- **Course:** Compiler Design Laboratory (`BCSE306L`)
- **Lab Slot:** `L23+L24`

---

## Overview
This repository implements and compares the three standard structural representations of **Three Address Code (TAC)**:
1. **Quadruples**: Records containing four fields: `(Op, Arg1, Arg2, Result)`. Explicitly stores temporary variables.
2. **Triples**: Records containing three fields: `(Op, Arg1, Arg2)`. Refers to temporary results by statement positional index `(k)`.
3. **Indirect Triples**: An array of pointers pointing into a Triple table. Provides superior optimization flexibility (code motion and instruction reordering without updating argument indices).

---

## Compilation & Execution
```bash
# Compile and run with GCC
gcc -std=c99 -Wall -Wextra src/intermediate_representations.c -o build/ir_tables
./build/ir_tables
```

---

## License
MIT License - see [LICENSE](LICENSE) for details.
