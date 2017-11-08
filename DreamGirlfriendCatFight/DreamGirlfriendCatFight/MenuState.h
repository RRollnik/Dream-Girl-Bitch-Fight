#pragma once

#ifndef _MenuState_h_
#define _MenuState_h_

#include "Button.h"
#include "Sprite.h"

class MenuState
{
public:
	MenuState(SDL_Window* _window, SDL_Renderer* _renderer, int &_volume, int &_state);
	~MenuState();

	void StateLoop();

protected:
	SDL_Window* window;
	SDL_Renderer* renderer;
	int volume;
	int state;
};

#endif