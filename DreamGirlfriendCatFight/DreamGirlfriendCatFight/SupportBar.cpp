#include "SupportBar.h"

SupportBar::SupportBar(int _health1, int _health2, Girlfriend* _a, Girlfriend* _b)
{
	health1 = _health1;
	health2 = _health2;

	slider1 = 0;
	slider2 = 0;

	gFriendA = _a;
	gFriendB = _b;

}

SupportBar::~SupportBar()
{
}

void SupportBar::Update()
{
	this->TakeInput();
	this->Support();
}

void SupportBar::TakeInput()
{
	const Uint8* key = SDL_GetKeyboardState(NULL);

	if (key[SDL_SCANCODE_SPACE])
	{
		slider1 += 10;
	}
	else if (key[SDL_SCANCODE_5])
	{
		slider2 += 10;
	}
}

void SupportBar::Support()
{
	if (slider1 < 41)
	{
		if (slider2 < 41)
		{
			gFriendA->ResetBuffs(); // player1 neutral 
			gFriendB->ResetBuffs(); // player2 neutral
		}
		else if (slider2 > 70)
		{
			gFriendA->ResetBuffs(); // player1 neutral 
			gFriendB->setDebuffed(); // player2 debuff
		}
		else
		{
			gFriendA->ResetBuffs(); // player1 neutral
			gFriendB->setBuffed(); // player2 buff
		}
	}
	else if (slider1 > 70)
	{
		if (slider2 < 41)
		{
			gFriendA->setDebuffed(); // player1 debuff
			gFriendB->ResetBuffs(); // player2 neutral
		}
		else if (slider2 > 70)
		{ 
			gFriendA->setDebuffed(); // player1 debuff
			gFriendB->setDebuffed(); // player2 debuff
		}
		else
		{
			gFriendA->setDebuffed(); // player1 debuff
			gFriendB->setBuffed(); // player2 buff
		}
	}
	else
	{
		if (slider2 < 41)
		{
			gFriendA->setBuffed(); // player1 buff 
			gFriendB->ResetBuffs(); // player2 neutral
		}
		else if (slider2 > 70)
		{
			gFriendA->setBuffed(); // player1 buff
			gFriendB->setDebuffed(); // player2 debuff
		}
		else
		{
			gFriendA->setBuffed(); // player1 buff
			gFriendB->setBuffed(); // player2 buff
		}
	}
}