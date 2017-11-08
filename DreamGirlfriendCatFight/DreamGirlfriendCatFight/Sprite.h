#ifndef _Sprite_h_
#define _Sprite_h_

#include <vector>
#include <string>
#include <SDL.h>
#include <iostream>

class Sprite
{
public:
	Sprite(SDL_Renderer* _renderer, char* _file, int _x, int _y, int _w, int _h); //constructor
	~Sprite(); //destructor

	virtual void Draw();

	void mergeImage(char* &_1, char* _2, bool _create);

	void SetY(int _y) { position.y = _y; }
	void SetX(int _x) { position.x = _x; }
	void SetH(int _h) { position.h = _h; }
	void SetW(int _w) { position.w = _w; }
	void SetTexture(SDL_Texture* _t) { image = _t; }

	int GetY() { return position.y; }
	int GetX() { return position.x; }
	int GetW() { return position.w; }
	int GetH() { return position.h; }


	SDL_Texture* image; // image used by the sprite

protected:
	SDL_Renderer* renderer; //SDL renderer used for drawing

	SDL_Rect position; //x/y position and width/height of sprite

};

#endif