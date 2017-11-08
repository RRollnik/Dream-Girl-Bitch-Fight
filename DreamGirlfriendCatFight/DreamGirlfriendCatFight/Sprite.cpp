#include "Sprite.h"

Sprite::Sprite(SDL_Renderer * _renderer, char* _file, int _x, int _y, int _w, int _h)
{
	SDL_Surface* bmpFile = SDL_LoadBMP(_file);

	if (!bmpFile)
	{
		std::cout << "Error loading image " << _file;
	}

	image = SDL_CreateTextureFromSurface(_renderer, bmpFile);
	SDL_FreeSurface(bmpFile);

	position.x = _x;
	position.y = _y;
	position.w = _w;
	position.h = _h;

	renderer = _renderer;
}

Sprite::~Sprite()
{
	if (image)
	{
		SDL_DestroyTexture(image);
	}
}

void Sprite::Draw()
{
	if (image)
	{
		SDL_RenderCopy(renderer, image, NULL, &position);
	}
}

void Sprite::makeImage(char* _1, char* _2, char* _3, char* _4, char* _5, char* _6)
{
	/*
	SDL_Surface* bmpFile1 = SDL_LoadBMP(_1);
	SDL_Surface* bmpFile2 = SDL_LoadBMP(_2);
	SDL_Surface* bmpFile3 = SDL_LoadBMP(_3);
	SDL_Surface* bmpFile4 = SDL_LoadBMP(_4);
	SDL_Surface* bmpFile5 = SDL_LoadBMP(_5);
	SDL_Surface* bmpFile6 = SDL_LoadBMP(_6);


	SDL_BlitSurface(bmpFile1, NULL, combinedFiles, NULL);
	SDL_BlitSurface(bmpFile2, NULL, combinedFiles, NULL);
	SDL_BlitSurface(bmpFile3, NULL, combinedFiles, NULL);
	SDL_BlitSurface(bmpFile4, NULL, combinedFiles, NULL);
	SDL_BlitSurface(bmpFile5, NULL, combinedFiles, NULL);
	SDL_BlitSurface(bmpFile6, NULL, combinedFiles, NULL);

	image = SDL_CreateTextureFromSurface(renderer, combinedFiles);

	SDL_FreeSurface(bmpFile1);
	SDL_FreeSurface(bmpFile2);
	SDL_FreeSurface(bmpFile3);
	SDL_FreeSurface(bmpFile4);
	SDL_FreeSurface(bmpFile5);
	SDL_FreeSurface(bmpFile6);
	*/
}