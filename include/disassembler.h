#ifndef DISASSEMBLER_H
#define DISASSEMBLER_H

#include "../include/system.h"

uint16_t get_rightmost_byte(uint16_t opcode);
uint16_t get_rightmost_nibble(uint16_t opcode);
void print_opcode(system_t* system);

#endif
