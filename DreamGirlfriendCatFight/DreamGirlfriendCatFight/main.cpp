#include <SDL.h>
#undef main;
#include <SDL_mixer.h>
#include <SDL_ttf.h>

#include <iostream>
#include <time.h>
#include <string>

#include "CharacterCreationState.h"
#include "FightState.h"
#include "Girlfriend.h"

#ifdef _MSC_VER
#include <windows.h>
#else
#include <unistd.h>
#endif

int main(int argc, char*argv[])
{
	SDL_Window* window;
	SDL_Renderer* renderer;

	srand(time(NULL));

	// try initialising SDL, log error and pause if fail
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cout << "SDL_Init Error: " << SDL_GetError() << "\n";
		system("pause");
		return 0;
	}

	// initialise text
	if (TTF_Init() == -1) {
		printf("TTF_Init: %s\n", TTF_GetError());
		exit(2);
	}

	// initialise audio
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);

	int volume = 20;
	Mix_VolumeMusic(volume);
	Mix_Volume(-1, volume);

	//printf("Error: %s \n", Mix_GetError());

	// try to create the window, log error and pause if fail
	window = SDL_CreateWindow("DreamGirlfriendCatFight", 0, 0, 1920, 1080, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		system("pause");
		return 0;
	}

	// try to create the renderer, log error and pause if fail
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == NULL)
	{
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		return false;
	}

	Girlfriend* player1 = player1 = new Girlfriend(renderer, 0, 0, 1080, 1920);
	Girlfriend* player2 = player2 = new Girlfriend(renderer, 0, 0, 1080, 1920);;

	int state = 1;

	//states?
	CharacterCreationState b(window, renderer, volume, state);

	// This is the game state manager...
	while (state > 0)
	{
		switch (state)
		{
		case 1:
			//MenuState* a = new MenuState(window, renderer, volume, state);
			//delete a;
			state = 2;
			break;
		case 2:
			b.StateLoop();
			player1->outfit = b.GetOutfit(0);
			player1->outfitData = b.GetOutfitStats(0);
			player2->outfit = b.GetOutfit(1);
			player2->outfitData = b.GetOutfitStats(1);
			if (b.getNextState() == 3)
			{
				state = 3;
			}
			else
			{
				state = 0;
			}
			//delete b;
			break;
		case 3:
			//FightState* a = new FightState(window, renderer, volume, state);
			//delete a;
			state = 1;
			break;
		}
	}

	delete player1;
	delete player2;

	// clean up, free any memeory we have used
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

#ifdef _MSC_VER
	Sleep(3000);
#else
	sleep(3);
#endif

	return 0;
}