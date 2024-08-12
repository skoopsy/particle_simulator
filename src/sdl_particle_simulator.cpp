//============================================================================
// Name        : sdl_particle_simulator.cpp
// Author      : David O'Connor
// Version     : 0.001
// Copyright   : 2024
// Description : Small particle simulator using SDL C++, Ansi-style
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
<<<<<<< HEAD
										  SDL_WINDOWPOS_UNDEFINED,
										  SDL_WINDOWPOS_UNDEFINED,
										  SCREEN_WIDTH, SCREEN_HEIGHT,
										  SDL_WINDOW_SHOWN);

	// Window initialisation, failing will return a null

	if (window == NULL) {
		SDL_Quit();
		return 2;
	}

<<<<<<< HEAD
	// Initialise renderer using window instance
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1,
												SDL_RENDERER_PRESENTVSYNC);

	// Initialise texture from renderer
	SDL_Texture *texture = SDL_CreateTexture(renderer,
											 SDL_PIXELFORMAT_RGBA8888,
											 SDL_TEXTUREACCESS_STATIC,
											 SCREEN_WIDTH, SCREEN_HEIGHT);

	// Basic error handling for renderer and texture

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

<<<<<<< HEAD

	// Allocate memory for texture, 4 bytes per pixel: RGBA
	Uint32 *buffer = new Uint32[SCREEN_WIDTH*SCREEN_HEIGHT];

	// Simple static update window in a fixed colour:
<<<<<<< HEAD
	// Set value of everything in buffer to 0 (white)
	memset(buffer, 0, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));

	// Set color per pixel, using hexi-decimal for RGBA, each channel is a byte.
	for(int i=0; i < SCREEN_WIDTH*SCREEN_HEIGHT; i++) {
		buffer[i] = 0xFF00FFFF;
	}


	// Update renderer
=======
	// Set colour for all pixels
	memset(buffer, 0xFF, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));
>>>>>>> e278fa7 (updated gitignore)

	// Update renderer
	int screen_pitch = SCREEN_WIDTH*sizeof(Uint32);
	SDL_UpdateTexture(texture, NULL, buffer, screen_pitch);
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL); // NULLs: copies entire renderer and entire texture
	SDL_RenderPresent(renderer);

<<<<<<< HEAD
	// Quit check


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
