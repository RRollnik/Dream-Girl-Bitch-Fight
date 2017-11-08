#include "FightState.h"

FightState::FightState(SDL_Window* _window, SDL_Renderer * _renderer, int &_volume, int &_state, Girlfriend* _a, Girlfriend* _b)
{
	window = _window;
	renderer = _renderer;
	volume = _volume;
	state = _state;

	girlFriendA = _a;
	girlFriendB = _b;

	bkgBarA = new Sprite(renderer, "_bkgBar.bmp", 200, 100, 100, 50);
	bkgBarB = new Sprite(renderer, "_bkgBar.bmp", 800, 100, 100, 50);

	healthBarA = new HealthBar(renderer, "_HealthBarImage.bmp", 200, 100, 100, 50, girlFriendA);
	healthBarB = new HealthBar(renderer, "_HealthBarImage.bmp", 800, 100, 100, 50, girlFriendB);

	player1Turn = true;
	player2Turn = false;
}

FightState::~FightState()
{

}

void FightState::StateLoop()
{

	InputManager* input = new InputManager();
	// This is done once in case the user if holding the mouse down upon entering the state.
	input->LMB();

	SDL_Event e;

	Sprite* bkg = new Sprite(renderer, "bkg2.bmp", 0, 0, 1920, 1080);

	quit = false;
	while (!quit)
	{
		while (SDL_PollEvent(&e)) // allow closing SDL window to quit
		{
			if (e.type == SDL_QUIT)
			{
				state = 0;
				quit = true;
			}
		}

		//if ((input->LMB() == 1))

		SDL_RenderClear(renderer);

		bkg->Draw();

		//Fight(gFriendA, gFriendB);
		//Fight(gFriendB, gFriendA);

		//gFriendA()->Update();
		//gFriendB()->Update();
		//Since we'll make changes directly to the gFriend in Fight(), presumably, we don't need to update them. Probably.

		//supportBar->Update();
		

		//background->draw();
		supportBar->Draw();

		SDL_RenderPresent(renderer);
	}

	delete input;
	delete healthBarA;
	delete healthBarB;
	delete bkgBarA;
	delete bkgBarB;

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