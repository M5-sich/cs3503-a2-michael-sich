#include <stdio.h>
#include <stdint.h>
#include "convert.h"

void div_convert(uint32_t n, int base, char *out){

	int arraySize = 2; // the array will always have at least one digit plus '\0'


	//this function calculates the product of a number with itself x many times (i.e., exponentiation)  
	uint32_t temp = n;
	while (temp / base != 0) {
			temp = temp / base;
			arraySize++;
	}

	out[arraySize - 1] = '\0'; //leaving last index for '\0' since the output will ultimatly be a string

	for (int i = arraySize - 2; i >= 0; i--){
		int remainder = n % base;
		switch (remainder){
			case 10:
				out[i] = 'A';
				break;
			case 11:
				out[i] = 'B';
				break;
			case 12:
				out[i] = 'C';
				break;
			case 13:
				out[i] = 'D';
				break;
			case 14:
				out[i] = 'E';
				break;
			case 15:
				out[i] = 'F';
				break;
			default:
				out[i] = '0' + remainder;  // in ascii if you start at 0 its 49 then add the remainder will give the correct correspoding letter
				break;
		}

		n = n/base;
	}

}


void sub_convert(uint32_t n, int base, char *out){

	uint32_t arraySize = 2; // the array will always have at least one digit plus '\0'
	int exponent = 0;
	uint32_t power = 1;        

	while (power * (uint32_t)base <= n) {
			power *= (uint32_t)base;  
			exponent++;               
			arraySize++;        
	}

	out[arraySize - 1] = '\0'; //leaving last index for '\0' since the output will ultimatly be a string

	while(exponent>=0){
		
		int number_of_factors = n/power;

		switch (number_of_factors){
			case 10:
				out[(arraySize-2)-exponent] = 'A';
				break;
			case 11:
				out[(arraySize-2)-exponent] = 'B';
				break;
			case 12:
				out[(arraySize-2)-exponent] = 'C';
				break;
			case 13:
				out[(arraySize-2)-exponent] = 'D';
				break;
			case 14:
				out[(arraySize-2)-exponent] = 'E';
				break;
			case 15:
				out[(arraySize-2)-exponent] = 'F';
				break;
			default:
				out[(arraySize-2)-exponent] = '0' + number_of_factors;  // in ascii if you start at 0 its 49 then add the remainder will give the correct correspoding letter
				break;
		}
        
        if (exponent == 0) break;   
        n %= power;
        power /= (uint32_t)base;
        exponent--;
  }
}


void print_tables(uint32_t n) {
    char binary[50];
		char octal[50];
		char hexadecimal[50];

    // 1) Original
    div_convert(n, 2,  binary);
    div_convert(n, 8,  octal);
    div_convert(n, 16, hexadecimal);
    printf("Original: Binary=%s Octal=%s Decimal=%u Hex=%s\n", binary, octal, n, hexadecimal);

    // 2) Left Shift by 3
    uint32_t shifted = n << 3;
    div_convert(shifted, 2,  binary);
    div_convert(shifted, 8,  octal);
    div_convert(shifted, 16, hexadecimal);
    printf("Left Shift by 3: Binary=%s Octal=%s Decimal=%u Hex=%s\n", binary, octal, shifted, hexadecimal);

    // 3) AND with 0xFF
    uint32_t masked = n & 0xFFu;
    div_convert(masked, 2,  binary);
    div_convert(masked, 8,  octal);
    div_convert(masked, 16, hexadecimal);
    printf("AND with 0xFF: Binary=%s Octal=%s Decimal=%u Hex=%s\n", binary, octal, masked, hexadecimal);
}