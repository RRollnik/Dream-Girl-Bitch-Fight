#include "Girlfriend.h"

Girlfriend::Girlfriend(SDL_Renderer* _renderer, char* _file, int _x, int _y, int _w, int _h) : Sprite(_renderer, _file, _x, _y, _w, _h)
{
	isBuffed = false;
	isDebuffed = false;

	defaultStatVal = 10;
	maxHealth = 100;
	buff = 1.5;
	debuff = 0.5;

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
		strength = (defaultStatVal + strBonus) * buff;
		agility = (defaultStatVal + agiBonus) * buff;
		athleticism = (defaultStatVal + athBonus) * buff;
		bitchiness = (defaultStatVal + bitBonus) * buff;
	}
	else if (isDebuffed)
	{
		strength = (defaultStatVal + strBonus) * debuff;
		agility = (defaultStatVal + agiBonus) * debuff;
		athleticism = (defaultStatVal + athBonus) * debuff;
		bitchiness = (defaultStatVal + bitBonus) * debuff;
	}
	else
	{
		strength = defaultStatVal + strBonus;
		agility = defaultStatVal + agiBonus;
		athleticism = defaultStatVal + athBonus;
		bitchiness = defaultStatVal + bitBonus;
	}
}

void Girlfriend::OutfitStats()
{
	for (size_t i = 0; i < outfit.size(); ++i)
	{
		//Determine stat bonuses based on outfit equiped
	}
	
}