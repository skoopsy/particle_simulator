//============================================================================
// Name        : sdl_particle_simulator.cpp
// Author      : David O'Connor
// Version     : 0.001
// Copyright   : 2024
// Description : Small particle simulator using SDL C++, Ansi-style
//============================================================================

#include <iostream>
#include <SDL.h>
#include <math.h> // for sin function

#include "Screen.h"


int main() {

	dave_graphics::Screen screen;

	if(screen.init() == false) {
		std::cout << "Error initialising SDL." << std::endl;
	}


	// --- Main game loop --- //
	while (true) {

		// Draw particles

		// Cycle color values
		int timeElapsed = SDL_GetTicks();
		unsigned char green = ((1 + sin(timeElapsed * 0.001))/2) * 255; // Using sin to cyclically change the value based on time elapsed, casts into char
		unsigned char red = ((1 + sin(timeElapsed * 0.002))/2) * 255; // Using sin to cyclically change the value based on time elapsed, casts into char
		unsigned char blue = ((1 + sin(timeElapsed * 0.003))/2) * 255; // Using sin to cyclically change the value based on time elapsed, casts into char

		// Set pixel colors
		for(int y=0; y < dave_graphics::Screen::SCREEN_HEIGHT; y++) { // for each row
			for(int x=0; x < dave_graphics::Screen::SCREEN_WIDTH; x++) { // for each column
				screen.setPixel(x, y, red, green, blue);
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
