#include "FightState.h"

FightState::FightState(Girlfriend* _a, Girlfriend* _b)
{
	gFriendA = _a;
	gFriendB = _b;
	quit = false;

	HealthBarA(SDL_Renderer* _renderer, char* _HealthBarImage, int _x, int _y, int _w, int gFriendA.health())
	HealthBarB =
}

FightState::~FightState()
{
}

void FightState::StateLoop()
{
	while (!quit)
	{
		SDL_RenderClear(renderer);

		Fight(gFriendA, gFriendB);
		Fight(gFriendB, gFriendA);
		
		AreYouAGoodBoyfriend->Update();


		background->draw();

		SDL_RenderPresent(renderer);
	}

}

void FightState::BarBuffs(int _buffs)
{
	switch (_buffs)
	{
		case 0:
		{
			break; //neither are getting buffs
		}
		
		case 1:
		{
			gFriendA->setBuffed();
		}

		case 2:
		{
			gFriendA->setDebuffed();
		}
	}
}

void FightState::Fight()
{
	 
}