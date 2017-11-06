#include "Button.h"

Button::Button(SDL_Renderer* _renderer, char* _file, char* _file2, int _x, int _y, int _w, int _h)
{
	sButtonImage = new Sprite(_renderer, _file, _x, _y, _w, _h);
	sButtonHoveredImage = new Sprite(_renderer, _file2, _x, _y, _w, _h);

}

Button::~Button()
{
	delete sButtonImage;
	delete sButtonHoveredImage;
}

void Button::Draw()
{
	if (Hovered())
	{
		sButtonHoveredImage->Draw();
	}
	else
	{
		sButtonImage->Draw();
	}
}

bool Button::Hovered()
{
	int mouseX, mouseY;
	SDL_GetMouseState(&mouseX, &mouseY);

	if ( ( mouseX > sButtonImage->GetX() && mouseX < ( sButtonImage->GetX() + sButtonImage->GetW() ) ) && ( mouseY > sButtonImage->GetY() && mouseY < ( sButtonImage->GetY() + sButtonImage->GetH() ) ) )
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Button::Clicked()
{
	if (Hovered())
	{
		if (SDL_GetMouseState(NULL, NULL) == SDL_BUTTON_LEFT)
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}