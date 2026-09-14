
#include <stdio.h>
#include <stdlib.h>

#include <SDL3/SDL_main.h>
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>


#define CLAY_IMPLEMENTATION
#include "clay.h"


int main(int argc, char **argv){

	SDL_Window *window;
	SDL_Renderer * renderer;

	SDL_CreateWindowAndRenderer("Delta", 640, 480, 0, &window, &renderer);

	_Bool running=true;
	while(running){

		SDL_Event event;
		while(SDL_PollEvent(&event)) {

			if (event.type == SDL_EVENT_QUIT || event.type == SDL_EVENT_WINDOW_CLOSE_REQUESTED) running = false;

		}

	}


	return 0;
}
