#ifndef _AnimatedSprite_h_
#define _AnimatedSprite_h_

#include "Sprite.h"

class AnimatedSprite : public Sprite
{
public:
	AnimatedSprite(SDL_Renderer* _renderer, char* _file, int _x, int _y, int _w, int _h, int _cellsInRow, int _cellsInCol, int _speed);
	~AnimatedSprite();

	void Update();

	void Draw() override;

	bool GetCycle() { return cycle; }

private:

	int cellsInRow;
	int cellsInCol;
	int currentRow;
	int currentCol;

	SDL_Rect cellRect;

	int timer;
	int speed;

	bool cycle;

};

#endif 
