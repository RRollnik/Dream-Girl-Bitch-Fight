#include "FightState.h"

FightState::FightState(SDL_Window* _window, SDL_Renderer * _renderer, int &_volume, int &_state, Girlfriend* _a, Girlfriend* _b)
{
	window = _window;
	renderer = _renderer;
	volume = _volume;
	state = _state;

	girlFriendA = _a;
	girlFriendB = _b;
	quit = false;

	healthBarA = new HealthBar(renderer, "_HealthBarImage", 0, 0, 100, 50, girlFriendA);
	healthBarB = new HealthBar(renderer, "_HealthBarImage", 0, 0, 0, 0, girlFriendA);

	player1Turn = true;
	player2Turn = false;
}

FightState::~FightState()
{

}

void FightState::StateLoop()
{
	while (!quit)
	{
		SDL_RenderClear(renderer);

		//Fight(gFriendA, gFriendB);
		//Fight(gFriendB, gFriendA);

		//gFriendA()->Update();
		//gFriendB()->Update();
		//Since we'll make changes directly to the gFriend in Fight(), presumably, we don't need to update them. Probably.

	//	AreYouAGoodBoyfriend->Update();
		//I'm not sure how much we want the gFriend to move, but if we do we'll need to improve the DrawOutfit, and potentially make a new DrawGirlfriend that'll get the offset add it to the current X and Y of
		//the image, and so on

		//background->draw();
		//AreYouAGoodBoyfriend()->draw();
		girlFriendA->Draw();
		girlFriendB->Draw();

		SDL_RenderPresent(renderer);
	}

}

void FightState::Fight()
{
	if (player1Turn = true)
	{
		//Player1 attacks

		player1Turn = false;
		player2Turn = true;
	}
	else if (player2Turn = true)
	{
		//Player2 attacks

		player1Turn = true;
		player2Turn = false;
	}

}