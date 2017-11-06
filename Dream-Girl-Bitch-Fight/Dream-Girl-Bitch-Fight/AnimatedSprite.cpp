#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite(SDL_Renderer* _renderer, char* _file, int _x, int _y, int _w, int _h, int _cellsInRow, int _cellsInCol, int _speed) :
	Sprite (_renderer, _file, _x, _y, _w, _h)
{
	cellsInRow = _cellsInRow;
	cellsInCol = _cellsInCol;

	currentRow = 0;
	currentCol = 0;

	cellRect.x = 0;
	cellRect.y = 0;
	cellRect.w = _w;
	cellRect.h = _h;

	timer = 0;
	speed = _speed;

	cycle = false;
}

AnimatedSprite::~AnimatedSprite()
{
	
}

void AnimatedSprite::Update()
{
	timer++;

	if (timer >= speed)
	{
		timer = 0;

		currentCol++;
		if (currentCol > cellsInRow - 1)
		{
			currentCol = 0;

			currentRow++;
			if (currentRow > cellsInCol - 1)
			{
				cycle = true;
			}
		}
	}
}

void AnimatedSprite::Draw()
{
	cellRect.x = currentCol * cellRect.w;
	cellRect.y = currentRow * cellRect.h;

	if (image)
	{
		SDL_RenderCopy(renderer, image, &cellRect, &position);
	}
}