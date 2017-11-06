#ifndef _Text_h_
#define _Text_h_

#include <SDL.h>
#include <iostream>

class Text
{
public:
	Text(SDL_Renderer * _renderer, SDL_Surface* _text, int _x, int _y, int _w, int _h); //constructor
	~Text(); //destructor

	void Draw();
	void Update(SDL_Surface* _text);

	void SetY(int _y) { position.y = _y; }
	void SetX(int _x) { position.x = _x; }

	int GetY() { return position.y; }
	int GetX() { return position.x; }
	int GetW() { return position.w; }
	int GetH() { return position.h; }

protected:
	SDL_Renderer* renderer; //SDL renderer used for drawing

	SDL_Texture* image; // image used by the sprite

	SDL_Rect position; //x/y position and width/height of sprite

};

#endif
