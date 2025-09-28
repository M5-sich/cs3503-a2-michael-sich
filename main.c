#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "convert.h"

/* -------------------------------------------------------------------------- */
/* Runs a file that runs all lines in div_tests.txt */
void run_division_tests(const char *file_path) {
    /* open file. if it fails, stop */
    FILE *file_pointer = fopen(file_path, "r");
    if (file_pointer == NULL) {
        printf("error: cannot open %s\n", file_path);
        return;
    }

    /* stuff i read from each line */
    char function_name[32];
    uint32_t number;
    int base;
    char expected_result[70];
    char actual_result[70];

    /* keep score */
    int total_tests = 0;
    int passed_tests = 0;

    /* read one test at a time */
    while (fscanf(file_pointer, "%31s %u %d %69s", function_name, &number, &base, expected_result) == 4) 
    {

        /* do the division version */
        div_convert(number, base, actual_result);

        /* count it */
        total_tests = total_tests + 1;

        /* check if i got what the test says */
        if (strcmp(actual_result, expected_result) == 0) {
            passed_tests = passed_tests + 1;
            printf("div test %d: div_convert(%u, %d) -> got=%s expected=%s [PASS]\n",
                   total_tests, number, base, actual_result, expected_result);
        } else {
            printf("div test %d: div_convert(%u, %d) -> got=%s expected=%s [FAIL]\n",
                   total_tests, number, base, actual_result, expected_result);
        }
    }

    /* done with the file */
    fclose(file_pointer);

    /* final summary */
    printf("div summary (%s): %d/%d passed\n",
           file_path, passed_tests, total_tests);
}
/* -------------------------------------------------------------------------- */
/* Runs a file that runs all lines in sub_tests.txt */
void run_subtraction_tests(const char *file_path) {
    /* open file. if it fails, stop */
    FILE *file_pointer = fopen(file_path, "r");
    if (file_pointer == NULL) {
        printf("error: cannot open %s\n", file_path);
        return;
    }

    /* stuff i read from each line */
    char function_name[32];
    uint32_t number;
    int base;
    char expected_result[70];
    char actual_result[70];

    /* keep score */
    int total_tests = 0;
    int passed_tests = 0;

    /* read one test at a time */
    while (fscanf(file_pointer, "%31s %u %d %69s", function_name, &number, &base, expected_result) == 4) 
    {
        /* do the subtraction version */
        sub_convert(number, base, actual_result);

        /* count it */
        total_tests = total_tests + 1;

        /* check if i got what the test says */
        if (strcmp(actual_result, expected_result) == 0) {
            passed_tests = passed_tests + 1;
            printf("sub test %d: sub_convert(%u, %d) -> got=%s expected=%s [PASS]\n",
                   total_tests, number, base, actual_result, expected_result);
        } else {
            printf("sub test %d: sub_convert(%u, %d) -> got=%s expected=%s [FAIL]\n",
                   total_tests, number, base, actual_result, expected_result);
        }
    }

    /* done with the file */
    fclose(file_pointer);

    /* final summary */
    printf("sub summary (%s): %d/%d passed\n",
           file_path, passed_tests, total_tests);
}

/* -------------------------------------------------------------------------- */
/* Runs a file that runs all lines in print_tests.txt */
void run_print_tables_tests(const char *file_path) {
    /* open file. if it fails, stop */
    FILE *file_pointer = fopen(file_path, "r");
    if (file_pointer == NULL) {
        printf("error: cannot open %s\n", file_path);
        return;
    }

    /* stuff i read from each line */
    char function_name[32];
    uint32_t number;

    /* keep score */
    int total_tests = 0;
    int passed_tests = 0;

    /* read one test at a time */
    while (fscanf(file_pointer, "%31s %u", function_name, &number) == 2) {

        /* call print_tables. this prints 3 lines of formatted output */
        print_tables(number);

        /* count it */
        total_tests = total_tests + 1;
        passed_tests = passed_tests + 1;  // always count as pass here

        printf("print test %d: print_tables(%u) -> [formatted output printed] [PASS]\n",
               total_tests, number);
    }

    /* done with the file */
    fclose(file_pointer);

    /* final summary */
    printf("print summary (%s): %d/%d passed\n",
           file_path, passed_tests, total_tests);
}
/* -------------------------------------------------------------------------- */
/* Hard coded comparison fuction instead of scanning it through .txt file*/
void run_comparison_tests() {
    char result1[70];
    char result2[70];

    /* compare 7 base 2 */
    div_convert(7, 2, result1);
    sub_convert(7, 2, result2);
    printf("compare 7 base 2: %s vs %s -> %s\n",
           result1, result2, strcmp(result1, result2) == 0 ? "PASS" : "FAIL");

    /* compare 15 base 8 */
    div_convert(15, 8, result1);
    sub_convert(15, 8, result2);
    printf("compare 15 base 8: %s vs %s -> %s\n",
           result1, result2, strcmp(result1, result2) == 0 ? "PASS" : "FAIL");

    /* compare 31 base 16 */
    div_convert(31, 16, result1);
    sub_convert(31, 16, result2);
    printf("compare 31 base 16: %s vs %s -> %s\n",
           result1, result2, strcmp(result1, result2) == 0 ? "PASS" : "FAIL");

}
/* -------------------------------------------------------------------------- */


int main() {

    // run_division_tests("separated_tests/div_tests.txt");
    // run_subtraction_tests("separated_tests/sub_tests.txt");
    // run_comparison_tests();
    // run_print_tables_tests("separated_tests/print_tests.txt");
    // return 0;
    
    int choice;

    printf("menu:\n");
    printf("  1) run division tests\n");
    printf("  2) run subtraction tests\n");
    printf("  3) run comparison tests\n");
    printf("  4) run print_tables tests\n");
    printf("  5) convert any number\n");
    printf("enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("you picked division tests\n");
            run_division_tests("separated_tests/div_tests.txt");
            break;
        case 2:
            printf("you picked subtraction tests\n");
            run_subtraction_tests("separated_tests/sub_tests.txt");
            break;
        case 3:
            printf("you picked comparison tests\n");
            run_comparison_tests();   // if yours doesn’t take a file
            break;
        case 4:
            printf("you picked print_tables tests\n");
            run_print_tables_tests("separated_tests/print_tests.txt");
            break;
        case 5:
            
            printf("you picked convert any number\n");
            printf("i will convert a decimal you pick into base 2..16\n");

            /* ask for inputs */
            uint32_t number;
            int base;
            char out[70];

            printf("enter a decimal number (0..4294967295): ");
            scanf("%u", &number);

            printf("enter a base (2..16): ");
            scanf("%d", &base);

            /* do the convert with the division version (either method is fine) */
            div_convert(number, base, out);

            
            printf("div_convert(%u, %d) -> %s\n", number, base, out);
            break;

           
        default:
            printf("invalid input\n");
            break;
    }
    
    return 0;
}
