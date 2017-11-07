#pragma once
#include "Sprite.h"

class Girlfriend : public Sprite
{
public:
	Girlfriend(SDL_Renderer* _renderer, char* _file, int _x, int _y, int _w, int _h);

	void ResetBuffs() { isBuffed = false; isDebuffed = false; }
	void setBuffed() { isBuffed = true; isDebuffed = false; }
	void setDebuffed() { isDebuffed = true; isBuffed = false; }

	int getHealth() { return health; }
	void setHealth(int _health) { health = _health; }

	void Status();
	void OutfitStats();

	void Draw() override;

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

	float buff;
	float debuff;

	int strBonus;
	int agiBonus;
	int athBonus;
	int bitBonus;

	std::vector<Sprite*> outfit;
};

