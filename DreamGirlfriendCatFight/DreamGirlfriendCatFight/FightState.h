#pragma once
#include "Girlfriend.h"
#include "SupportBar.h"


class FightState
{
public:
	FightState(Girlfriend* _a, Girlfriend* _b);
	~FightState();

	void StateLoop();
	void Fight();

private:

	Girlfriend* gFriendA;
	Girlfriend* gFriendB;
	SupportBar AreYouAGoodBoyfriend;
	Sprite HealthBarA;
	Sprite HealthBarB;

	bool player1Turn;
	bool player2Turn;

	bool quit;
};

