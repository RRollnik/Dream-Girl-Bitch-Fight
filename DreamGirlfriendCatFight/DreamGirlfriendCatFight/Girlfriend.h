#pragma once

#include "Sprite.h"

class Girlfriend
{
public:
	Girlfriend(SDL_Renderer* _renderer, int _x, int _y, int _w, int _h);

	void ResetBuffs() { isBuffed = false; isDebuffed = false; }
	void setBuffed() { isBuffed = true; isDebuffed = false; }
	void setDebuffed() { isDebuffed = true; isBuffed = false; }

	int getHealth() { return health; }
	int getStrength() { return strength; }
	int getAgility() { return agility; }
	int getAthleticism() { return athleticism; }
	int getBitchiness() { return bitchiness; }

	void setHealth(int _health) { health = _health; }

	void Status();
	void OutfitStats();

	void Update();

	bool getDefeated() { return isDefeated; }

	std::vector<SDL_Texture*> outfit;
	std::vector<int> outfitData;

private:

	bool isBuffed;
	bool isDebuffed;
	bool isDefeated;

	int defaultStatVal;
	int maxHealth;

	int health;
	int strength;
	int agility;
	int athleticism;
	int bitchiness;

	float buff;
	float debuff;

	int strBonus;
	int agiBonus;
	int athBonus;
	int bitBonus;
};

