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

	// --- Main game loop --- //
	while (true) {

		// Update Particles
		// Draw particles
		// Check for messages/events

		// Quit check
		if(screen.processEvents() == false ) {
			break;
		}
	}

	screen.close();

	return 0;
}
