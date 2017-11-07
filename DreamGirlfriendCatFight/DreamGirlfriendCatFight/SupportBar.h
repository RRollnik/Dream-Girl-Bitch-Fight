#pragma once
#include "Sprite.h"
#include "SDL.h"
#include "SDL_keyboard.h"
#include "Girlfriend.h"

class SupportBar
{
public:
	SupportBar(int _health1, int _health2, Girlfriend* _a, Girlfriend* _b);
	~SupportBar();

	void Update();
	void TakeInput();
	void Support();

private:

	int slider1;
	int slider2;

	int health1;
	int health2;

	Girlfriend* gFriendA;
	Girlfriend* gFriendB;
};

