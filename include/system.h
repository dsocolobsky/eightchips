#ifndef SYSTEM_H
#define SYSTEM_H

#include <stdio.h>
#include <stdint.h>

/* Programs start at this address */
#define PROGRAM_START 0x200
/* 4096 Bytes, or 4 Kilobytes */
#define MEMORY_SIZE 4096

/* This structure represents the system's CPU, mainly being it's registers */
typedef struct cpu_t {
	/* Registers */
	uint8_t  V[16];		/* General Purpose Registers */
	uint16_t stack[16];	/* Stack Array 		     */
	uint16_t I;		/* Memory Address Register   */
	uint16_t PC;		/* Program Counter 	     */
	uint16_t SP;		/* Stack Pointer 	     */
	uint8_t  DT;		/* Delay Timer 		     */
	uint8_t  ST;		/* Sound Timer 		     */
} cpu_t;

/* 
 * This structure represents the actual System which is an aggregation of
 * the previously defined CPU, plus the memory array and the screen
*/
typedef struct system_h {
	cpu_t* cpu;
	uint8_t memory[MEMORY_SIZE];
	uint8_t screen[64][32];
} system_t;

cpu_t* create_cpu();
void init_cpu(cpu_t* cpu);
void destroy_cpu(cpu_t* cpu);

system_t* create_system(FILE* file);
void init_system(system_t* system);
void destroy_system(system_t* system);

void clear_screen(system_t* system);
void handle_opcode(system_t* system, uint16_t opcode);

#endif
