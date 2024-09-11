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
		for(int y=0; y < dave_graphics::Screen::SCREEN_HEIGHT; y++) { // for each row
			for(int x=0; x < dave_graphics::Screen::SCREEN_WIDTH; x++) { // for each column
				screen.setPixel(x, y, 128, 0, 255);
			}
		}
		screen.setPixel(400, 300, 255, 255, 255); // set white pixel in middle of frame

		// Draw the screen
		screen.update();

		// Quit check
		if(screen.processEvents() == false ) {
			break;
		}
	}

	screen.close();

	return 0;
}
