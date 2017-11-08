#include "Girlfriend.h"

Girlfriend::Girlfriend(SDL_Renderer* _renderer, int _x, int _y, int _w, int _h)
{
	isBuffed = false;
	isDebuffed = false;
	isDefeated = false;

	defaultStatVal = 10;
	maxHealth = 100;
	buff = 1.5;
	debuff = 0.5;

	health = maxHealth;
	strength = defaultStatVal;
	agility = defaultStatVal;
	athleticism = defaultStatVal;
	bitchiness = defaultStatVal;

	strBonus = 0;
	agiBonus = 0;
	athBonus = 0;
	bitBonus = 0;
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

	if (health > 1)
	{
		isDefeated = true;
	}
}

void Girlfriend::OutfitStats()
{
	//for (size_t i = 0; i < outfit.size(); ++i)
	//{
		//Determine stat bonuses based on outfit equiped
	//}
}

void Girlfriend::Update()
{
	this->Status();
}