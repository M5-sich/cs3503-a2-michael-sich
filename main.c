#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "convert.h"

// check if two strings are exactly the same
int strings_match(const char first[], const char second[]) {
    int i = 0;
    while (1) {
        if (first[i] != second[i]) {
            return 0; // not the same one
        }
        if (first[i] == '\0') {
            return 1; // both ended at same time
        }
        i++;
    }
}

// run all tests inside one file
int run_file(const char file_name[], int *passed_count, int *failed_count) {
    FILE *f = fopen(file_name, "r");
    if (!f) {
        printf("could not open %s\n", file_name);
        return -1;
    }

    char line[512];
    char func_name[64];
    char input_str[256];
    char expected_str[256];
    char actual_str[256];

    while (fgets(line, sizeof(line), f)) {
        // each line has: func input expected
        int read = sscanf(line, "%63s %255s %255s", func_name, input_str, expected_str);
        if (read != 3) {
            continue; // skip bad lines
        }

        actual_str[0] = '\0';

        // check which function we are testing
        if (strings_match(func_name, "oct_to_bin")) {
            oct_to_bin(input_str, actual_str);
        } else if (strings_match(func_name, "oct_to_hex")) {
            oct_to_hex(input_str, actual_str);
        } else if (strings_match(func_name, "hex_to_bin")) {
            hex_to_bin(input_str, actual_str);
        } else if (strings_match(func_name, "to_sign_magnitude")) {
            int32_t x = (int32_t)strtol(input_str, NULL, 10);
            to_sign_magnitude(x, actual_str);
        } else if (strings_match(func_name, "to_ones_complement")) {
            int32_t x = (int32_t)strtol(input_str, NULL, 10);
            to_ones_complement(x, actual_str);
        } else if (strings_match(func_name, "to_twos_complement")) {
            int32_t x = (int32_t)strtol(input_str, NULL, 10);
            to_twos_complement(x, actual_str);
        } else {
            continue; // unknown tag
        }

        // now compare actual with expected
        if (strings_match(actual_str, expected_str)) {
            printf("[PASS] %-20s (%s) -> %s\n", func_name, input_str, actual_str);
            *passed_count = *passed_count + 1;
        } else {
            printf("[FAIL] %-20s (%s) -> got %s, expected %s\n",
                   func_name, input_str, actual_str, expected_str);
            *failed_count = *failed_count + 1;
        }
    }

    fclose(f);
    return 0;
}

int main() {
    // list of test files to run
    const char *files[] = {
        "a2_tests/oct_to_bin_tests.txt",
        "a2_tests/oct_to_hex_tests.txt",
        "a2_tests/hex_to_bin_tests.txt",
        "a2_tests/sign_magnitude_tests.txt",
        "a2_tests/ones_complement_tests.txt",
        "a2_tests/twos_complement_tests.txt"
    };

    // counters for pass/fail
    int passed = 0;
    int failed = 0;


    printf("Assignment 2 Tests:\n\n");

    // looping through all test files
    int total_files = sizeof(files) / sizeof(files[0]);
    for (int i = 0; i < total_files; i++) {
        run_file(files[i], &passed, &failed);
    }


    printf("\nSummary: %d/%d tests passed\n", passed, passed + failed);


    if (failed == 0) {
        return 0;  
    } else {
        return 1;  
    }
}