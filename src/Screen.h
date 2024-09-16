/*
 * Screen.h
 *
 *  Created on: 11 Sept 2024
 *      Author: dave
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#include <SDL.h>

namespace dave_graphics {

class Screen {
public:
	const static int SCREEN_WIDTH = 800;
	const static int SCREEN_HEIGHT = 600;

	// m denotes an instance variable
private:
	SDL_Window *m_window;
	SDL_Renderer *m_renderer;
	SDL_Texture *m_texture;
	Uint32 *m_buffer;

public:
	Screen();
	bool init();
	bool processEvents();
	void close();
};

} /* namespace dave_graphics */

#endif /* SCREEN_H_ */
