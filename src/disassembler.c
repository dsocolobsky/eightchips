#include <stdint.h>
#include <stdio.h>
#include "../include/disassembler.h"

#define MAXSIZE 4096

static char hexdigits[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

uint16_t get_rightmost_byte(uint16_t opcode) {
	return opcode & 0xFF00;
}

uint16_t get_rightmost_nibble(uint16_t opcode) {
	return opcode & 0xF000;
}

void print_byte(FILE* file) {

}

void print_hexadecimal(char* buffer) {
	char lo, ho;
	int seg = 0;
	
	for(int i = 0; i <= 4096; i++) {
		char c = buffer[i];
		ho = c & 0xFF00;
		lo = c & 0x00FF;
		printf("%x%x\t", ho, lo);
		seg += 2;
		if(seg == 80) {
			printf("\n");
		}
	}
	printf("\n");
}
