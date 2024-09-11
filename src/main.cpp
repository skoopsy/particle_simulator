//============================================================================
// Name        : sdl_particle_simulator.cpp
// Author      : David O'Connor
// Version     : 0.001
// Copyright   : 2024
// Description : Small particle simulator using SDL C++, Ansi-style
//============================================================================

#include <iostream>
#include <SDL.h>
<<<<<<< HEAD
#include <math.h> // for sin function
#include <stdlib.h> // for srand to seed rand num generator
#include <time.h> // for seeding rand num

#include "Screen.h"
#include "Swarm.h"
#include "Particle.h"


int main() {

	// Random number gen seed based on time value
	srand(time(NULL));

	// Initialise Sceen instance
	dave_graphics::Screen screen;
=======
#include "Screen.h"

int main() {

	dave_graphics::Screen screen;

>>>>>>> 22e5ed0 (refactored Screen, successful build-run)
	if(screen.init() == false) {
		std::cout << "Error initialising SDL." << std::endl;
	}

<<<<<<< HEAD
	// Initialise swarm of particles
	dave_graphics::Swarm swarm;

	// --- Main game loop --- //
	while (true) {

		// Cycle color values
		int timeElapsed = SDL_GetTicks();
		unsigned char green = ((1 + sin(timeElapsed * 0.001))/2) * 255; // Using sin to cyclically change the value based on time elapsed, casts into char
		unsigned char red = ((1 + sin(timeElapsed * 0.002))/2) * 255; // Using sin to cyclically change the value based on time elapsed, casts into char
		unsigned char blue = ((1 + sin(timeElapsed * 0.003))/2) * 255; // Using sin to cyclically change the value based on time elapsed, casts into char

		// Draw Particles
		const dave_graphics::Particle * const pParticles = swarm.getParticles();

		for(int i=0; i<dave_graphics::Swarm::N_PARTICLES; i++) {
			dave_graphics::Particle particle = pParticles[i];

			int x = (particle.m_x + 1) * dave_graphics::Screen::SCREEN_WIDTH/2;
			int y = (particle.m_y + 1) * dave_graphics::Screen::SCREEN_HEIGHT/2;

			screen.setPixel(x, y, red, green, blue);
		}

		// Draw the screen
		screen.update();

		// Quit check
		if(screen.processEvents() == false ) {
			break;
		}
	}

=======
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


>>>>>>> 22e5ed0 (refactored Screen, successful build-run)
	screen.close();

	return 0;
}
