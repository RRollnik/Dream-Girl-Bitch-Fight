#pragma once
#include "Sprite.h"
#include "Girlfriend.h"

class HealthBar : public Sprite
{
public:
	HealthBar(SDL_Renderer* _renderer, char* _file, int _x, int _y, int _w, int _h, Girlfriend* _girlfriend);
	
	void Update();

private:

	Girlfriend* girlfriend;

	int health;
	int maxHealth;
	int maxBarWidth;
};

