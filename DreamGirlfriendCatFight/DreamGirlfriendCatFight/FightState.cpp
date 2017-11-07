#include "FightState.h"

FightState::FightState(Girlfriend* _a, Girlfriend* _b)
{
	gFriendA = _a;
	gFriendB = _b;
	quit = false;

	HealthBarA(SDL_Renderer* _renderer, char* _HealthBarImage, int _x, int _y, int _w, int gFriendA.health())
	HealthBarB(SDL_Renderer* _renderer, char* _HealthBarImage, int _x, int _y, int _w, int gFriendB.health())
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

		//gFriendA()->Update();
		//gFriendB()->Update();
		//Since we'll make changes directly to the gFriend in Fight(), presumably, we don't need to update them. Probably.

		AreYouAGoodBoyfriend->Update();
		//I'm not sure how much we want the gFriend to move, but if we do we'll need to improve the DrawOutfit, and potentially make a new DrawGirlfriend that'll get the offset add it to the current X and Y of
		//the image, and so on

		background->draw();
		AreYouAGoodBoyfriend()->draw();
		gFriendA->DrawOutfit();
		gFriendB->DrawOutfit();

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

void FightState::Fight(Girlfriend* _myTurn, Girlfriend* _notMyTurn)
{
	if (_myTurn.Insult() > _notMyTurn.Insult())
	{
		_notMyTurn->setDebuffed();
	}
	else if (_notMyTurn.Insult() > _myTurn.Insult())
	{
		_myTurn->setDebuffed;
	}

	//if bar is between buff for both myTurn and notMyTurn, need bar to work first before implemtation


	int AttackPower = _myTurn.Attack();

	_notMyTurn.Dodge(AttackPower);

}