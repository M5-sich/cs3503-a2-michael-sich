# CS3503 Assignment 2

# CS3503 Assignment 2

**Assignment 2 – Number Representation Conversions**

This project implements and tests **six conversion functions** related to number representations and base conversions.  
It also includes a simple testing framework that reads test cases from files and reports pass/fail results.

---

## Implemented Functions

The following functions are defined in `convert.c` and declared in `convert.h`:

- `void to_sign_magnitude(int32_t n, char out[33])`
- `void to_ones_complement(int32_t n, char out[33])`
- `void to_twos_complement(int32_t n, char out[33])`
- `void oct_to_bin(const char *x, char *out)`
- `void oct_to_hex(const char *x, char *out)`
- `void hex_to_bin(const char *x, char *out)`

---

## Project Structure

cs3503-a2-michael-sich/
│── main.c # Test driver
│── convert.c # Function implementations
│── convert.h # Function prototypes
│── a2_tests/ # Test case files
│ ├── oct_to_bin_tests.txt
│ ├── oct_to_hex_tests.txt
│ ├── hex_to_bin_tests.txt
│ ├── sign_magnitude_tests.txt
│ ├── ones_complement_tests.txt
│ └── twos_complement_tests.txt
│── README.md # This file

---

## How to Compile and Run

### Step 1: Navigate to the repo folder

```bash
cd ~/Desktop/"Computer Organization Arch/Assignment 2/cs3503-a2-michael-sich"
```

Compile the program
gcc main.c convert.c -o a2
• main.c → test driver that loads test cases
• convert.c → all six conversion functions
• -o a2 → creates an executable named a2

Run the program
./a2
