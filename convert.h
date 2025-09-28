#ifndef CONVERT_H
#define CONVERT_H
#include <stdint.h>

// Assignment 1 Functions

void div_convert(uint32_t n, int base, char *out);
void sub_convert(uint32_t n, int base, char *out);
void print_tables(uint32_t n);

// Assignment 2 Functions
void oct_to_bin(const char *oct, char *out);
void oct_to_hex(const char *oct, char *out);
void hex_to_bin(const char *hex, char *out);
void to_sign_mag(int n, char *out);
void to_ones_complement(int n, char *out);
void to_twos_complement(int n, char *out);


#endif