#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "../include/main.h"
#include "../include/system.h"
#include "../include/disassembler.h"

int main(int argc, char* argv[]) {
	FILE* rom_file;
	
	/* Print the version number */
	printf("eightchips version: %s\n", VERSION_NUMBER);
	
	/* Check if we provided a file */
	if(argc < 2 || argv[1] == NULL) {
		printf("%s\n", USAGE);
		return 1;
	}
	
	/* Load ROM File */
	rom_file = fopen(argv[1], "rb");
	if(!rom_file) {
		printf("Error loading rom file %s\n", argv[1]);
		return 1;
	}
	printf("Loaded correctly file %s\n", argv[1]);
	
	struct stat st;
	int fd = fileno(rom_file);
	fstat(fd, &st);
	int rom_size = st.st_size;
	
	/* Initialize System */
	system_t* system = create_system(rom_file, rom_size);
	if(!system) {
		printf("Failed to create the system\n");
		if(rom_file) {
			fclose(rom_file);
		}
		return 1;
	}
	printf("Created system successfuly\n");
	
	print_hexadecimal(system->rombuffer);
	
	if(system) {
		destroy_system(system);
	}
	if(rom_file) {
		fclose(rom_file);
	}
	
	return 0;
}

