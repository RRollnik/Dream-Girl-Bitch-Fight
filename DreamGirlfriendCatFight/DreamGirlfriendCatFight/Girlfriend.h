#pragma once
#include <vector>
#include "Sprite.h"
#include "OutfitPiece.h"

class Girlfriend 
{
public:
	Girlfriend(SDL_Renderer* _renderer, char* _file, int _x, int _y, int _w, int _h);

	void ResetBuffs() { isBuffed = false; isDebuffed = false; }
	void setBuffed() { isBuffed = true; isDebuffed = false; }
	void setDebuffed() { isDebuffed = true; isBuffed = false; }

	int getHealth() { return health; }
	void setHealth(int _health) { health = _health; }

	void Status();
	void Gear();

private:

	bool isBuffed;
	bool isDebuffed;

	int defaultStatVal;
	int maxHealth;

	int health;
	int strength;
	int agility;
	int athleticism;
	int bitchiness;

	std::vector<OutfitPiece> Outfit;
};

