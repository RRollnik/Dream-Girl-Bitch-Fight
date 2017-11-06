#ifndef _GameStateMenu_h_
#define _GameStateMenu_h_

#include "GameState.h"

class GameStateMenu : public GameState
{
public:
	GameStateMenu(SDL_Window* _window, SDL_Renderer* _renderer, int _windowH, int _windowW, SDL_Event _e, bool* _bQuit);
	~GameStateMenu();

	void Update();
	void Draw();
	void Quit();
	
	int GameMenuLoop();

private:
	Sprite* sBackground;
	Sprite* sLogo;
	Button* bPlayButton;
	Button* bHowToButton;
	Button* bExitButton;
	Mix_Music *soundtrack;
	int m_iGameStateSelection;
	bool m_bMenuQuit;
};

#endif