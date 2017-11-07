#include "FightState.h"

FightState::FightState(Girlfriend* _a, Girlfriend* _b)
{
	gFriendA = _a;
	gFriendB = _b;
	quit = false;
}

FightState::~FightState()
{
}

void FightState::StateLoop()
{
	while (!quit)
	{

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