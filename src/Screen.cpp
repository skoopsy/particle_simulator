/*
 * Screen.cpp
 *
 *  Created on: 11 Sept 2024
 *      Author: dave
 */

#include "Screen.h"

namespace dave_graphics {


Screen::Screen() :
		m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer1(NULL), m_buffer2(NULL) {

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
		m_renderer = SDL_CreateRenderer(m_window,
										-1,
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
		m_buffer1 = new Uint32[SCREEN_WIDTH*SCREEN_HEIGHT];
		m_buffer2 = new Uint32[SCREEN_WIDTH*SCREEN_HEIGHT];

		// --- DRAWING --- //

		// Simple static update window in a fixed colour:
		// Set value of everything in buffer to 0 (white)
		memset(m_buffer1, 0, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));
		memset(m_buffer2, 0, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));

	return true;

}

/*
void Screen::clear(){
	// Clear buffer / set to 0.
	memset(m_buffer1, 0, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));
	memset(m_buffer2, 0, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));
}
*/

void Screen::boxBlur(){
	// Swap the buffers, so pixel is in m_buffer2 and we are drawing to m_buffer1
	// Store loc of buffer1 memory
	Uint32 *temp = m_buffer1;
	m_buffer1 = m_buffer2;
	m_buffer2 = temp;

	// Iterate all pixels
	for (int y=0; y<Screen::SCREEN_HEIGHT; y++) {
		for(int x=0; x<Screen::SCREEN_WIDTH; x++) {

			int redTotal=0;
			int blueTotal=0;
			int greenTotal=0;

			// For each pixel iterate over each pixel around it as well
			for(int row=-1; row<=1; row++) {
				for(int col=-1; col<=1; col++){

					int currentX = x + col;
					int currentY = y + row;

					if(currentX >= 0
					&& currentX < Screen::SCREEN_WIDTH
					&& currentY >= 0
					&& currentY < Screen::SCREEN_HEIGHT) {

						// get color value at pixel index
						Uint32 color = m_buffer2[currentY * Screen::SCREEN_WIDTH + currentX];

						// Color in RGBA formate where each channel is 1 byte = 8 bits
						Uint8 red = color >> 24; // Shift 3 bytes tot he right to get just red value from RGBA
						Uint8 green = color >> 16;
						Uint8 blue = color >> 8;

						redTotal += red;
						greenTotal += green;
						blueTotal += blue;

					}
				}
			}

		// Add the blur
		Uint8 red = redTotal/9;
		Uint8 green = greenTotal/9;
		Uint8 blue = blueTotal/9;

		setPixel(x, y, red, green, blue);

		}
	}


}

void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {

	// Check if pixel is plotted out of bounds - could make more efficient
	// could be more efficient?
	if(x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT) {
		return;
	}

	//bit shifting to lump RGBA values into a 4 byte hex number
	// RGBA format
	Uint32 color = 0;
	color += red;
	color <<= 8; //shift 8 bits = 1 byte
	color += green;
	color <<= 8;
	color += blue;
	color <<= 8;
	color += 0xFF;

	// set pixel in the buffer based on "row" (y) and "column" (x)
	m_buffer1[(y * SCREEN_WIDTH) + x] = color;
}


void Screen::update() {
	// Update renderer
	int screen_pitch = SCREEN_WIDTH*sizeof(Uint32); // might not be needed
	SDL_UpdateTexture(m_texture, NULL, m_buffer1, screen_pitch);
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
	delete [] m_buffer1;
	delete [] m_buffer2;
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyTexture(m_texture);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

} /* namespace dave_graphics */
