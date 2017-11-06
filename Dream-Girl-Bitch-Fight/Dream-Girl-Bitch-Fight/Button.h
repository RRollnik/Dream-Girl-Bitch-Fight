#ifndef _Button_h_
#define _Button_h_

#include "Sprite.h"

class Button
{
public:
	Button(SDL_Renderer* _renderer, char* _file, char* _file2, int _x, int _y, int _w, int _h);
	~Button();

	void Draw();
	bool Hovered();
	bool Clicked();

private:
	Sprite* sButtonImage;
	Sprite* sButtonHoveredImage;
};

#endif