#pragma once
#include "Girlfriend.h"
#include "HealthBar.h"
#include "SupportBar.h"
#include "InputManager.h"

class FightState
{
public:
	FightState(SDL_Window* _window, SDL_Renderer* _renderer, int &_volume, int &_state, Girlfriend* _a, Girlfriend* _b);
	~FightState();

	void StateLoop();
	void Fight(Girlfriend* _g1, Girlfriend* _g2);

private:

	SDL_Window* window;
	SDL_Renderer* renderer;
	int volume;
	int state;

	Girlfriend* girlFriendA;
	Girlfriend* girlFriendB;

	SupportBar* supportBar;

	Sprite* bkgBarA;
	Sprite* bkgBarB;

	HealthBar* healthBarA;
	HealthBar* healthBarB;

	bool quit;
};