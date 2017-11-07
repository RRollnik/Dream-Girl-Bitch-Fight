#include "Girlfriend.h"

Girlfriend::Girlfriend()
{
	isBuffed = false;
	isDebuffed = false;

	Health = hp * X; //hp would be the stat HP, x is whatever, so that they don't have like 5 HP
}

Girlfriend::~Girlfriend()
{
}

void Girlfriend::Status()
{
	
}