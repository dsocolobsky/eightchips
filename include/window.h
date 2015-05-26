#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>

#define WINDOW_SETTINGS "EightChip", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, \
	800, 600, SDL_WINDOW_SHOWN

typedef struct window_t {
	SDL_Window  *sdl_window;
	SDL_Surface *sdl_surface;
} window_t;

window_t* create_window();
void init_window(window_t* window);
void destroy_window(window_t* window);

#endif
