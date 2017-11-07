#pragma once
#include "Girlfriend.h"

class FightState
{
public:
	FightState(Girlfriend* _a, Girlfriend* _b);
	~FightState();

	void StateLoop();
	void Fight();
	void BarBuffs(int _buffs);

private:

	Girlfriend* gFriendA;
	Girlfriend* gFriendB;

	bool quit;
};

