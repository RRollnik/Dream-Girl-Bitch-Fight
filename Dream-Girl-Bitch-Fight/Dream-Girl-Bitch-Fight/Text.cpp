#include "Text.h"

Text::Text(SDL_Renderer * _renderer, SDL_Surface* _text, int _x, int _y, int _w, int _h)
{
	position.x = _x;
	position.y = _y;
	position.w = _w;
	position.h = _h;

	renderer = _renderer;

	Update(_text);
}

Text::~Text()
{
	if (image)
	{
		SDL_DestroyTexture(image);
	}
}
void Text::Update(SDL_Surface* _text)
{
	if (!_text)
	{
		std::cout << "Error loading text " << _text;
	}

	image = SDL_CreateTextureFromSurface(renderer, _text);
	SDL_FreeSurface(_text);
}

void Text::Draw()
{
	if (image)
	{
		SDL_RenderCopy(renderer, image, NULL, &position);
	}
}