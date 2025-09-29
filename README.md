# CS3503 Assignment 2

# CS3503 Assignment 2

## Assignment 2 — Number Representation Conversions

This project implements and tests **six conversion functions** for number representations and base conversions.  
A small test runner reads cases from files and prints PASS/FAIL.

---

## Implemented Functions

Defined in `convert.c` and declared in `convert.h`:

- `void to_sign_magnitude(int32_t n, char out[33]);`
- `void to_ones_complement(int32_t n, char out[33]);`
- `void to_twos_complement(int32_t n, char out[33]);`
- `void oct_to_bin(const char *x, char *out);`
- `void oct_to_hex(const char *x, char *out);`
- `void hex_to_bin(const char *x, char *out);`

---

## Project Structure

```text
cs3503-a2-michael-sich/
├─ main.c                   # test driver (reads files in a2_tests/)
├─ convert.c                # all function implementations
├─ convert.h                # prototypes for the functions
├─ a2_tests/                # test files (one per function group)
│  ├─ oct_to_bin_tests.txt
│  ├─ oct_to_hex_tests.txt
│  ├─ hex_to_bin_tests.txt
│  ├─ sign_magnitude_tests.txt
│  ├─ ones_complement_tests.txt
│  └─ twos_complement_tests.txt
└─ README.md
```

## How to Compile and Run

### Step 1: Navigate to the repo folder

cd ~/Desktop/"Computer Organization Arch/Assignment 2/cs3503-a2-michael-sich"

### Step 2: Compile the program

gcc main.c convert.c -o a2

### Step 3: Run it

./a2
