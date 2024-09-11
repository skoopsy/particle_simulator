//============================================================================
// Name        : sdl_particle_simulator.cpp
// Author      : David O'Connor
// Version     : 0.001
// Copyright   : 2024
// Description : Small particle simulator using SDL C++, Ansi-style
//============================================================================

#include <iostream>
#include <SDL.h>
#include "Screen.h"

int main() {

	dave_graphics::Screen screen;

	if(screen.init() == false) {
		std::cout << "Error initialising SDL." << std::endl;
	}

	// Quit check
	bool quit = false;
	SDL_Event event;

	// --- Main game loop --- //
	while (!quit) {
		// Update Particles
		// Draw particles
		// Check for messages/events

		// Check if quit has been pressed on the window decorator:
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				quit = true;
			}
		}
	}


	screen.close();

	return 0;
}
