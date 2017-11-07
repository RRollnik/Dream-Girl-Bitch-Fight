#include "HealthBar.h"

HealthBar::HealthBar(SDL_Renderer* _renderer, char* _file, int _x, int _y, int _w, int _h, Girlfriend* _girlfriend) : Sprite(_renderer, _file, _x, _y, _w, _h)
{
	girlfriend = _girlfriend;
	maxHealth = girlfriend->getHealth();
	maxBarWidth = _w;
}

void HealthBar::Update()
{
	position.w = maxBarWidth * (health / maxHealth);
}