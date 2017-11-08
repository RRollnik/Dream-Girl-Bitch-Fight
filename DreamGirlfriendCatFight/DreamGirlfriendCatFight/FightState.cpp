#include "FightState.h"

FightState::FightState(SDL_Window* _window, SDL_Renderer * _renderer, int &_volume, int &_state, Girlfriend* _a, Girlfriend* _b)
{
	window = _window;
	renderer = _renderer;
	volume = _volume;
	state = _state;

	girlFriendA = _a;
	girlFriendB = _b;

	bkgBarA = new Sprite(renderer, "BaseBar.bmp", 200, 100, 100, 50);
	bkgBarB = new Sprite(renderer, "BaseBar.bmp", 800, 100, 100, 50);

	healthBarA = new HealthBar(renderer, "BaseHealthBar.bmp", 200, 100, 100, 50, girlFriendA);
	healthBarB = new HealthBar(renderer, "BaseHealthBar.bmp", 800, 100, 100, 50, girlFriendB);
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

	Sprite* girl1 = new Sprite(renderer, "", 0, 0, 1920, 1080);
	Sprite* girl2 = new Sprite(renderer, "", 0, 0, 1920, 1080);

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

		if ((input->LMB() == 1))

		SDL_RenderClear(renderer);

		bkg->Draw();

		healthBarA->Update();
		healthBarA->Draw();

		healthBarB->Update();
		healthBarB->Draw();

		girlFriendA->Update();
		girlFriendB->Update();

		for (int i = 0; i < 6; i++)
		{
			girl1->SetTexture(girlFriendA->outfit[i]);
			girl1->SetH(960);
			girl1->SetW(540);
			girl1->Draw();
		}

		for (int i = 0; i < 6; i++)
		{
			girl2->SetTexture(girlFriendB->outfit[i]);
			girl2->SetX(1400);
			girl2->SetH(960);
			girl2->SetW(540);
			girl2->Draw();
		}

		//girlFriendA->outfit();
		//girlFriendB->outfit();

		//supportBar->Update();
		//supportBar->Draw();

		Fight(girlFriendA, girlFriendB);
		Fight(girlFriendB, girlFriendA);

		SDL_RenderPresent(renderer);
	}

	delete input;
	delete healthBarA;
	delete healthBarB;
	delete bkgBarA;
	delete bkgBarB;

}


/*
health = maxHealth;
strength = defaultStatVal;
agility = defaultStatVal;
athleticism = defaultStatVal;
*/

void FightState::Fight(Girlfriend* _g1, Girlfriend* _g2)
{
	//if(_g2->getAgility)
	_g2->setHealth(_g2->getHealth() - _g1->getStrength());
}