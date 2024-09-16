//============================================================================
// Name        : sdl_particle_simulator.cpp
// Author      : David O'Connor
// Version     : 0.001
// Copyright   : 2024
// Description : Small particle simulator using sdl C++, Ansi-style
//============================================================================

#include <iostream>
#include <SDL.h>

int main() {

	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;

	// Checks if the SDL library has been linked and functional:
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL init. failed." << std::endl;
		return 1;
	}

	// Initialise a window
	SDL_Window *window = SDL_CreateWindow("Particle Fire Explosion",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH, SCREEN_HEIGHT,
			SDL_WINDOW_SHOWN);

	// window initialisation failing will return a null
	if(window == NULL) {
		SDL_Quit();
		return 2;
	}

	// for quit check
	bool quit = false;
	SDL_Event event;

	// Main game loop
	while(!quit) {
		// Update Particles
		// Draw particles
		// Check for messages/events

		// Check if quit has been pressed on the window decorator:
		while(SDL_PollEvent(&event)) {
			if(event.type == SDL_QUIT) {
				quit = true;
			}
		}
	}

	// Cleanup
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
