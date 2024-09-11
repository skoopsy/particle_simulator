/*
 * Screen.cpp
 *
 *  Created on: 11 Sept 2024
 *      Author: dave
 */

#include "Screen.h"

namespace dave_graphics {

Screen::Screen() :
		m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer(NULL) {

}

bool Screen::init() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
			return false;
		}

		// Initialise a window
		m_window = SDL_CreateWindow("Particle Fire Explosion",
									SDL_WINDOWPOS_UNDEFINED,
									SDL_WINDOWPOS_UNDEFINED,
									SCREEN_WIDTH, SCREEN_HEIGHT,
									SDL_WINDOW_SHOWN);

		// Window initialisation, failing will return a null
		if (m_window == NULL) {
			SDL_Quit();
			return false;
		}

		// Initialise renderer using window instance
		m_renderer = SDL_CreateRenderer(m_window, -1,
										SDL_RENDERER_PRESENTVSYNC);

		// Initialise texture from renderer
		m_texture = SDL_CreateTexture(m_renderer,
									  SDL_PIXELFORMAT_RGBA8888,
									  SDL_TEXTUREACCESS_STATIC,
									  SCREEN_WIDTH, SCREEN_HEIGHT);

		// Basic error handling for renderer and texture
		if(m_renderer == NULL) {
			SDL_DestroyWindow(m_window);
			SDL_Quit();
			return false;
		}

		if(m_texture == NULL) {
			SDL_DestroyRenderer(m_renderer);
			SDL_DestroyWindow(m_window);
			SDL_Quit();
			return false;
		}

		// Allocate memory for texture, 4 bytes per pixel: RGBA
		m_buffer = new Uint32[SCREEN_WIDTH*SCREEN_HEIGHT];

		// --- DRAWING --- //

		// Simple static update window in a fixed colour:
		// Set value of everything in buffer to 0 (white)
		memset(m_buffer, 0, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));

	return true;

}

void Screen::update() {
	// Update renderer
	int screen_pitch = SCREEN_WIDTH*sizeof(Uint32); // might not be needed
	SDL_UpdateTexture(m_texture, NULL, m_buffer, screen_pitch);
	SDL_RenderClear(m_renderer);
	SDL_RenderCopy(m_renderer, m_texture, NULL, NULL); // NULLs: copies entire renderer and entire texture
	SDL_RenderPresent(m_renderer);

}

bool Screen::processEvents() {
	// Check for quit button on window GUI dectorator
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			return false;
		}
	}

	return true;

}



void Screen::close() {
	delete [] m_buffer;
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyTexture(m_texture);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

} /* namespace dave_graphics */
