#ifndef DISASSEMBLER_H
#define DISASSEMBLER_H

uint16_t get_rightmost_byte(uint16_t opcode);
uint16_t get_rightmost_nibble(uint16_t opcode);
void print_hexadecimal(char* buffer);

#endif
