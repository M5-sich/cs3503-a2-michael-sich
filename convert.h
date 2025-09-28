#ifndef CONVERT_H
#define CONVERT_H
#include <stdint.h>

//=====================================================================//
// Assignment 2 Functions

void oct_to_bin(const char *oct, char *out);
void oct_to_hex(const char *oct, char *out);
void hex_to_bin(const char *hex, char *out);

void to_sign_magnitude(int32_t n, char out[33]);
void to_ones_complement(int32_t n, char out[33]);
void to_twos_complement(int32_t n, char out[33]);

//=====================================================================//
// Assignment 1 Functions

void div_convert(uint32_t n, int base, char *out);
void sub_convert(uint32_t n, int base, char *out);
void print_tables(uint32_t n);



#endif