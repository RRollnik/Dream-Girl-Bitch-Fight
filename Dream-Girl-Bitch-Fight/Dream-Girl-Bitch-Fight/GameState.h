#ifndef _GameState_h_
#define _GameState_h_

#include <SDL.h>
#include <iostream>
#include <vector>
#include <time.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <string>

#include "Player.h"
#include "ScrollingBackground.h"
#include "AnimatedSprite.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Button.h"
#include "Text.h"


class GameState
{
public:
	GameState(SDL_Window* _window,	SDL_Renderer* _renderer, int _windowH, int _windowW, SDL_Event _e, bool *_bQuit);
	~GameState();

	void Clear();
	void Present();
	Mix_Music* LoadMusic(char* _file);
	SDL_Surface* MakeText(TTF_Font* _tFont, char* _text);


	virtual void Quit();
	virtual void Update();
	virtual void Draw();

protected:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	int m_windowH;
	int m_windowW;
	SDL_Event m_e;
	bool* m_bQuit;
};

#endif