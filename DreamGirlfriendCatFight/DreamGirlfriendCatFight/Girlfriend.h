#pragma once
#include "Sprite.h"
#include <vector>

class Girlfriend
{
public:
	Girlfriend();
	~Girlfriend();

	void ResetBuffs() { isBuffed = false; isDebuffed = false; }
	void setBuffed() { isBuffed = true; isDebuffed = false; }
	void setDebuffed() { isDebuffed = true; isBuffed = false; }
	int getHealth() { return Health; }
	void SetOutfit(std::vector<Sprite> OutfitPiece, int i, int whereinvector) { Outfit.insert(Outfit.begin() + i, OutfitPiece.at(whereinvector)); }
	void DrawOutfit() { for (int i = 0; i < Outfit.size(); i++) { Outfit.at(i).Draw(); }; }

	void Status();

private:

	int Health;
	bool isBuffed;
	bool isDebuffed;
	std::vector<Sprite> Outfit;

	int 
};

