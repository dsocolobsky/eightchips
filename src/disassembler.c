#include <stdint.h>
#include <stdio.h>
#include "../include/disassembler.h"

static char hexdigits[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

uint16_t get_rightmost_byte(uint16_t opcode) {
	return opcode & 0xFF00;
}

uint16_t get_rightmost_nibble(uint16_t opcode) {
	return opcode & 0xF000;
}

void print_opcode(uint16_t opcode) {
	printf("%x", opcode);
}

void dump_rom(system_t* system) {
	for(int i = 0x200; i <= 4096; i++) {
		print_opcode(get_opcode(system, i));
	}
}
