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
	SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
			SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	// window initialisation failing will return a null
	if (window == NULL) {
		SDL_Quit();
		return 2;
	}

	// Init renderer and texture
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1,
			SDL_RENDERER_PRESENTVSYNC);
	SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

	if(renderer == NULL) {
		std::cout << "Renderer could not be created" << std::endl;
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 3;
	}

	if(texture == NULL) {
		std::cout << "Texture could not be created" << std::endl;
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 4;
	}

	// Allocate memory for texture
	Uint32 *buffer = new Uint32[SCREEN_WIDTH*SCREEN_HEIGHT];

	// Simple static update window in a fixed colour:
	// Set colour for all pixels
	memset(buffer, 0xFF, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));

	// Update renderer
	int screen_pitch = SCREEN_WIDTH*sizeof(Uint32);
	SDL_UpdateTexture(texture, NULL, buffer, screen_pitch);
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL); // NULLs: copies entire renderer and entire texture
	SDL_RenderPresent(renderer);

	// for quit check
	bool quit = false;
	SDL_Event event;

	// Main game loop
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

	// Cleanup
	delete [] buffer;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(texture);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
