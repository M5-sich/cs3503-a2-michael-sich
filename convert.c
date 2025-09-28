#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "convert.h"

//=================================================================================================//
// Assignment 2 Functions

void oct_to_bin(const char *oct, char out[]) {
    int num = 0;

    // for every index in the input I take the digit and map it to its binary chunk inside out[]
    // Octal |--> Binary
    // 0     maps to    000
    // 1     maps to    001
    // 2     maps to    010
    // 3     maps to    011
    // 4     maps to    100
    // 5     maps to    101
    // 6     maps to    110
    // 7     maps to    111
    for (int i = 0; oct[i] != '\0'; ++i) {
        char x = oct[i];

        switch (x) {
            case '0':
                out[num++] = '0';
                out[num++] = '0';
                out[num++] = '0';
                break;

            case '1':
                out[num++] = '0';
                out[num++] = '0';
                out[num++] = '1';
                break;

            case '2':
                out[num++] = '0';
                out[num++] = '1';
                out[num++] = '0';
                break;

            case '3':
                out[num++] = '0';
                out[num++] = '1';
                out[num++] = '1';
                break;

            case '4':
                out[num++] = '1';
                out[num++] = '0';
                out[num++] = '0';
                break;

            case '5':
                out[num++] = '1';
                out[num++] = '0';
                out[num++] = '1';
                break;

            case '6':
                out[num++] = '1';
                out[num++] = '1';
                out[num++] = '0';
                break;

            case '7':
                out[num++] = '1';
                out[num++] = '1';
                out[num++] = '1';
                break;

            default:
                out[0] = '\0';
                return;
        }
    }

    out[num] = '\0'; // setting last index since this is a string 
}

void oct_to_hex(const char *x, char *out){
    char binary[128];
    oct_to_bin(x, binary);  // using logic implemented in octal to binary converter above this function and then my plan is to map those groups onto hex bits

 
    int length = strlen(binary);
    int pad = (4 - (length % 4)) % 4;
    for (int i = length - 1; i >= 0; i--){
        binary[i + pad] = binary[i];
    }
    for (int i = 0; i < pad; i++){
        binary[i] = '0';
    }
    binary[length + pad] = '\0';


    //looping through each four group bit and then mapping that group to a hex bit

    int num = 0;
    for (int i = 0; binary[i] != '\0'; i += 4){
        char b1 = binary[i];
        char b2 = binary[i+1];
        char b3 = binary[i+2];
        char b4 = binary[i+3];

        if (b1=='0' && b2=='0' && b3=='0' && b4=='0') 
            out[num++] = '0';
        else if (b1=='0' && b2=='0' && b3=='0' && b4=='1') 
            out[num++] = '1';
        else if (b1=='0' && b2=='0' && b3=='1' && b4=='0') 
            out[num++] = '2';
        else if (b1=='0' && b2=='0' && b3=='1' && b4=='1') 
            out[num++] = '3';
        else if (b1=='0' && b2=='1' && b3=='0' && b4=='0') 
            out[num++] = '4';
        else if (b1=='0' && b2=='1' && b3=='0' && b4=='1') 
            out[num++] = '5';
        else if (b1=='0' && b2=='1' && b3=='1' && b4=='0') 
            out[num++] = '6';
        else if (b1=='0' && b2=='1' && b3=='1' && b4=='1') 
            out[num++] = '7';
        else if (b1=='1' && b2=='0' && b3=='0' && b4=='0') 
            out[num++] = '8';
        else if (b1=='1' && b2=='0' && b3=='0' && b4=='1') 
            out[num++] = '9';
        else if (b1=='1' && b2=='0' && b3=='1' && b4=='0') 
            out[num++] = 'A';
        else if (b1=='1' && b2=='0' && b3=='1' && b4=='1') 
            out[num++] = 'B';
        else if (b1=='1' && b2=='1' && b3=='0' && b4=='0') 
            out[num++] = 'C';
        else if (b1=='1' && b2=='1' && b3=='0' && b4=='1') 
            out[num++] = 'D';
        else if (b1=='1' && b2=='1' && b3=='1' && b4=='0') 
            out[num++] = 'E';
        else if (b1=='1' && b2=='1' && b3=='1' && b4=='1') 
            out[num++] = 'F';
    }
    out[num] = '\0'; // setting last index since this is a string 
}

void hex_to_bin(const char *hex, char out[]) {
    int num = 0;

    // for every index in the input I take the hex digit and map it to its four bit binary group in out[]
    for (int i = 0; hex[i] != '\0'; ++i) {
        char x = hex[i];
        if (x >= 'a' && x <= 'f') x = (char)(x - 'a' + 'A');  // handing uppercases

        switch (x) {
            case '0':
                out[num++] = '0'; 
                out[num++] = '0'; 
                out[num++] = '0'; 
                out[num++] = '0';
                break;
            case '1':
                out[num++] = '0'; 
                out[num++] = '0'; 
                out[num++] = '0'; 
                out[num++] = '1';
                break;
            case '2':
                out[num++] = '0'; 
                out[num++] = '0'; 
                out[num++] = '1'; 
                out[num++] = '0';
                break;
            case '3':
                out[num++] = '0'; 
                out[num++] = '0'; 
                out[num++] = '1'; 
                out[num++] = '1';
                break;
            case '4':
                out[num++] = '0'; 
                out[num++] = '1'; 
                out[num++] = '0'; 
                out[num++] = '0';
                break;
            case '5':
                out[num++] = '0'; 
                out[num++] = '1'; 
                out[num++] = '0'; 
                out[num++] = '1';
                break;
            case '6':
                out[num++] = '0'; 
                out[num++] = '1'; 
                out[num++] = '1'; 
                out[num++] = '0';
                break;
            case '7':
                out[num++] = '0'; 
                out[num++] = '1'; 
                out[num++] = '1'; 
                out[num++] = '1';
                break;
            case '8':
                out[num++] = '1'; 
                out[num++] = '0'; 
                out[num++] = '0'; 
                out[num++] = '0';
                break;
            case '9':
                out[num++] = '1'; 
                out[num++] = '0'; 
                out[num++] = '0'; 
                out[num++] = '1';
                break;
            case 'A':
                out[num++] = '1'; 
                out[num++] = '0'; 
                out[num++] = '1'; 
                out[num++] = '0';
                break;
            case 'B':
                out[num++] = '1'; 
                out[num++] = '0'; 
                out[num++] = '1'; 
                out[num++] = '1';
                break;
            case 'C':
                out[num++] = '1'; 
                out[num++] = '1'; 
                out[num++] = '0'; 
                out[num++] = '0';
                break;
            case 'D':
                out[num++] = '1';
                out[num++] = '1'; 
                out[num++] = '0'; 
                out[num++] = '1';
                break;
            case 'E':
                out[num++] = '1'; 
                out[num++] = '1'; 
                out[num++] = '1'; 
                out[num++] = '0';
                break;
            case 'F':
                out[num++] = '1'; 
                out[num++] = '1'; 
                out[num++] = '1'; 
                out[num++] = '1';
                break;
            default:
                out[0] = '\0';   // a non valid char
                return;
        }
    }

    out[num] = '\0'; // setting last index since this is a string 
}

void to_sign_magnitude(int32_t n, char out[33]) {
    uint32_t magnitude;
    char temporary[33];

     // setting left most index to 0 or 1 depending on if n is positive or negative. Zero will be included as positive. 
    if (n >= 0) {
        out[0] = '0';
        magnitude = (uint32_t)n;
    } else {
        out[0] = '1';
        int64_t t = (int64_t)n;
        t = -t;
        magnitude = (uint32_t)t;
    }

    div_convert(magnitude, 2, temporary); //using assignment 1 decimal to binary converter to my advatage

    size_t length = strlen(temporary);

    for (int i = 1; i <= 31; ++i) {
        out[i] = '0';
    }

    for (size_t i = 0; i < length && i < 31; ++i) {
        out[31 - i] = temporary[length - 1 - i];
    }

    out[32] = '\0'; // setting last index since this is a string 
}

void to_ones_complement(int32_t n, char out[33]) {
    uint32_t magnitude;
    int flip;

    // setting left most index to 0 or 1 depending on if n is positive or negative. Zero will be included as positive. 
    if (n >= 0) {
        flip = 0;
        magnitude = (uint32_t)n;
    } else {
        flip = 1;
        int64_t temp = (int64_t)n;
        temp = -temp;
        magnitude = (uint32_t)temp;
    }

    // loop through each bit, grab it and then flip if negative, then swtich to  '0' or '1' into the string
    for (int i = 31; i >= 0; --i) {
        int bit = (magnitude >> i) & 1;

        if (n >= 0) {
            if (bit == 0) {
                out[31 - i] = '0';
            } else {
                out[31 - i] = '1';
            }
        } 
        else {
            if (bit == 0) {
                out[31 - i] = '1';
            } else {
                out[31 - i] = '0';
            }
        }
    }

    out[32] = '\0'; // setting last index since this is a string 
}

void to_twos_complement(int32_t n, char out[33]) {
    uint32_t value = (uint32_t)n;

    // loop through each bit grab it, and then switch '0' or '1' into the string
    for (int i = 31; i >= 0; --i) {
        int bit = (value >> i) & 1;

        if (bit == 0) {
            out[31 - i] = '0';
        } else {
            out[31 - i] = '1';
        }
    }

    out[32] = '\0'; // setting last index since this is a string 
}



//=================================================================================================//
// Assignment 1 Functions

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

    // avoid overflow: use n / base instead of power * base
    while ( (uint32_t)base != 0 && power <= n / (uint32_t)base ) {
        power *= (uint32_t)base;  
        exponent++;               
        arraySize++;        
    }

    out[arraySize - 1] = '\0'; // leaving last index for '\0' since the output will ultimately be a string

    while (exponent >= 0){
        
        int number_of_factors = 0;
        while (n >= power){
            n -= power;
            number_of_factors++;
        }

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
                out[(arraySize-2)-exponent] = '0' + number_of_factors;
                break;
        }
        
        if (exponent == 0) break;   
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