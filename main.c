
#include <stdio.h>
#include <stdlib.h>

#include <SDL3/SDL_main.h>
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>


#define CLAY_IMPLEMENTATION
#include "clay.h"


int main(int argc, char **argv){

	SDL_Window *window;
	Clay_SDL3RendererData * renderer;

	SDL_CreateWindowAndRenderer("Delta", 640, 480, 0, &window, &renderer->renderer);


	uint64_t totalMemorySize = Clay_MinMemorySize();
	Clay_Arena clayMemory = (Clay_Arena) {
		.memory = SDL_malloc(totalMemorySize),
		.capacity = totalMemorySize
	};



	_Bool running=true;
	while(running){

		SDL_Event * event;
		while(SDL_PollEvent(event)) {

			switch(event->type){

				case(SDL_EVENT_QUIT || SDL_EVENT_WINDOW_CLOSE_REQUESTED): running = false; break;

				case SDL_EVENT_WINDOW_RESIZED:
					Clay_SetLayoutDimensions((Clay_Dimensions) { (float) event->window.data1, (float) event->window.data2 });
					break;
				case SDL_EVENT_MOUSE_WHEEL:
					Clay_UpdateScrollContainers(true, (Clay_Vector2) { event->wheel.x, event->wheel.y }, 0.01f);
					break;
			}
		}

	}


	return 0;
}
