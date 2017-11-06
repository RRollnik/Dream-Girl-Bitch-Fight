#include "SDL.h"
#include <iostream>

int main(int argc, char* argv[])
{
	// try initialising SDL, log error and pause if fail
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cout << "SDL_Init Error: " << SDL_GetError() << "\n";
		system("pause");
	}

	return 0;
}