#pragma once
#include "Girlfriend.h"
#include "SupportBar.h"


class FightState
{
public:
	FightState(Girlfriend* _a, Girlfriend* _b);
	~FightState();

	void StateLoop();
	void Fight(Girlfriend* _a, Girlfriend* _b);
	void BarBuffs(int _buffs);

private:

	Girlfriend* gFriendA;
	Girlfriend* gFriendB;
	SupportBar AreYouAGoodBoyfriend;
	Sprite HealthBarA;
	Sprite HealthBarB;

	bool quit;
};

