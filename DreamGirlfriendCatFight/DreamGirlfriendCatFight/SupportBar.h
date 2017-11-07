#pragma once
#include "Sprite.h"
#include "SDL.h"
#include "SDL_keyboard.h"
#include "Girlfriend.h"

class SupportBar : public Sprite
{
public:
	SupportBar(SDL_Renderer* _renderer, char* _file, int _x, int _y, int _w, int _h, Girlfriend* _a, Girlfriend* _b);

	void Update();
	void TakeInput();
	void Support();
	void DecreaseSlider();

private:

	int slider1;
	int slider2;

	int health1;
	int health2;

	int buffMin;
	int buffMax;

	int barMax;

	Girlfriend* gFriendA;
	Girlfriend* gFriendB;
};

