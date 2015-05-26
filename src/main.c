#include <stdio.h>
#include "../include/main.h"
#include "../include/system.h"
#include "../include/window.h"

#include <SDL2/SDL.h>

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
	
	/* Initialize System */
	system_t* system = create_system(rom_file);
	if(!system) {
		printf("Failed to create the system\n");
		if(rom_file) {
			fclose(rom_file);
		}
		return 1;
	}
	printf("Created system successfuly\n");

	/* Create the window */
	window_t* window = create_window();
	if(!window) {
		printf("Failed to create window\n");
		return 1;
	} else {
		system->window = window;
		window = NULL;
	}
	printf("Created window successfuly\n");

	
	/* If we loaded everything just fine, we should initialize */
	init_system(system);
	init_window(system->window);
	printf("Initialized everything fine\n");

	/* Do the final cleanup */
	if(system) {
		destroy_system(system);
	}
	if(rom_file) {
		fclose(rom_file);
	}
	
	return 0;
}

