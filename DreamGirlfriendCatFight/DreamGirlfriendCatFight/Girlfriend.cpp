#include "Girlfriend.h"

Girlfriend::Girlfriend(SDL_Renderer* _renderer, char* _file, int _x, int _y, int _w, int _h) : Sprite(_renderer, _file, _x, _y, _w, _h)
{
	isBuffed = false;
	isDebuffed = false;

	defaultStatVal = 10;
	maxHealth = 100;

	health = maxHealth;
	strength = defaultStatVal;
	agility = defaultStatVal;
	athleticism = defaultStatVal;
	bitchiness = defaultStatVal;

}

void Girlfriend::Status()
{
	if (isBuffed)
	{

	}
	else if (isDebuffed)
	{

	}
}

void Girlfriend::Gear()
{

}