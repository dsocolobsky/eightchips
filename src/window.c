#include "../include/window.h"

window_t* create_window() {
	window_t *window = calloc(1, sizeof(window_t));
	window->sdl_window = SDL_CreateWindow(WINDOW_SETTINGS);
	window->sdl_surface = SDL_GetWindowSurface(window->sdl_window);

	return window;
}

void init_window(window_t* window) {
	SDL_Init(SDL_INIT_VIDEO);	
}

void destroy_window(window_t* window) {
	free(window);
}
