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

Clone or download the repo, then open a terminal and `cd` into the project folder:

```bash
cd cs3503-a2-michael-sich
```

Use gcc to compile:

```bash
gcc main.c convert.c -o a2
```

Run it

```bash
./a2
```

### How the Tests Work

Each test case is stored in the `a2_tests/` folder.  
Every line in a test file follows this format:

function_name input expected_output

When you run `./a2`, the program will:

- Read each line from the test files,
- Run the corresponding function with the given input,
- Compare the actual output with the expected output,
- Print `[PASS]` or `[FAIL]` for each test case.

---

### Example Output

Assignment 2 Tests:

[PASS] oct_to_bin (725) -> 111010101
[PASS] oct_to_bin (345) -> 011100101
[PASS] oct_to_bin (777) -> 111111111

Summary: 51/51 tests passed

## Transparency Note

During development, the main challenge was implementing the `oct_to_hex` conversion.  
At first, the function produced outputs with leading zeros (e.g., `0E5` instead of `E5`).  
This was fixed by trimming unnecessary leading zeros while keeping valid single-digit results.

All other functions (`oct_to_bin`, `hex_to_bin`, `to_sign_magnitude`, `to_ones_complement`, `to_twos_complement`) passed their respective tests as expected.  
The testing framework ensures that every case in the `a2_tests` folder is parsed and checked for correctness.
