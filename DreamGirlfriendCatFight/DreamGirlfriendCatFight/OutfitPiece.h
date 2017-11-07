#pragma once
#include "Sprite.h"


class OutfitPiece : public Sprite
{
public:
	OutfitPiece();
	~OutfitPiece();

	void GetStats(std::string _filename);

private:
	std::vector<int> stats;

};

OutfitPiece::OutfitPiece()
{
}

OutfitPiece::~OutfitPiece()
{
}