#pragma once
#include "Girlfriend.h"
#include "HealthBar.h"
#include "SupportBar.h"


class FightState
{
public:
	FightState(SDL_Window* _window, SDL_Renderer* _renderer, int &_volume, int &_state, Girlfriend* _a, Girlfriend* _b);
	~FightState();

	void StateLoop();
	void Fight();

private:

	SDL_Window* window;
	SDL_Renderer* renderer;
	int volume;
	int state;

	Girlfriend* girlFriendA;
	Girlfriend* girlFriendB;

	SupportBar* supportBar;

	HealthBar* healthBarA;
	HealthBar* healthBarB;

	bool player1Turn;
	bool player2Turn;

	bool quit;
};