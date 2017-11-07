#include "SupportBar.h"

SupportBar::SupportBar(SDL_Renderer* _renderer, char* _file, int _x, int _y, int _w, int _h, Girlfriend* _a, Girlfriend* _b) : Sprite(_renderer, _file, _x, _y, _w, _h)
{
	slider1 = 0;
	slider2 = 0;

	gFriendA = _a;
	gFriendB = _b;

	buffMin = 41;
	buffMax = 70;

	barMax = 100;
}

void SupportBar::Update()
{
	this->TakeInput();
	this->Support();
	this->Draw();
	this->DecreaseSlider();
}

void SupportBar::TakeInput()
{
	const Uint8* key = SDL_GetKeyboardState(NULL);

	if (key[SDL_SCANCODE_SPACE])
	{
		if (slider1 < 91)
		{
			slider1 += 10;
		}
	}
	else if (key[SDL_SCANCODE_5])
	{
		if (slider2 < 91)
		{
			slider2 += 10;
		}
	}
}

void SupportBar::Support()
{
	//slider 1//

	if (slider1 < buffMin)
	{
		gFriendA->ResetBuffs();
	}
	else if ((slider1 > buffMin) && (slider1 < buffMax))
	{
		gFriendA->setBuffed();
	}
	else
	{
		gFriendA->setDebuffed();
	}

	//slider 2//

	if (slider2 < buffMin)
	{
		gFriendB->ResetBuffs();
	}
	else if ((slider2 > buffMin) && (slider2 < buffMax))
	{
		gFriendB->setBuffed();
	}
	else
	{
		gFriendB->setDebuffed();
	}
}

void SupportBar::DecreaseSlider()
{
	if (slider1 < 1)
	{
		--slider1;
	}
	
	if (slider2 < 1)
	{
		--slider2;
	}
}