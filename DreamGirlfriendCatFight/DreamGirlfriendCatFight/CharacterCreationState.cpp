#include "CharacterCreationState.h"

CharacterCreationState::CharacterCreationState(SDL_Window* _window, SDL_Renderer * _renderer, int &_volume, int &_state)
{
	std::ifstream file("race.txt");
	if (file.is_open())
	{
		char* a1[4];

		for (int i = 0; i < 4; ++i)
		{
			file >> a1[i];
			race.push_back(Sprite(_renderer, a1[i], x, y, w, h));
		}
	}

	std::ifstream file("hair.txt");
	if (file.is_open())
	{
		char* a2[10];

		for (int i = 0; i < 10; ++i)
		{
			file >> a2[i];
			hair.push_back(Sprite(_renderer, a2[i], x, y, w, h));
		}
	}

	std::ifstream file("eyes.txt");
	if (file.is_open())
	{
		char* a3[13];

		for (int i = 0; i < 13; ++i)
		{
			file >> a3[i];
			eyes.push_back(Sprite(_renderer, a3[i], x, y, w, h));
		}
	}

	std::ifstream file("lips.txt");
	if (file.is_open())
	{
		char* a4[8];

		for (int i = 0; i < 8; ++i)
		{
			file >> a4[i];
			lips.push_back(Sprite(_renderer, a4[i], x, y, w, h));
		}
	}

	std::ifstream file("top.txt");
	if (file.is_open())
	{
		char* a5[20];

		for (int i = 0; i < 20; ++i)
		{
			file >> a5[i];
			top.push_back(Sprite(_renderer, a5[i], x, y, w, h));
		}
	}

	std::ifstream file("bottom.txt");
	if (file.is_open())
	{
		char* a6[8];

		for (int i = 0; i < 8; ++i)
		{
			file >> a6[i];
			bottom.push_back(Sprite(_renderer, a6[i], x, y, w, h));
		}
	}

	window = _window;
	renderer = _renderer;
	volume = _volume;
	state = _state;

	StateLoop();
}

CharacterCreationState::~CharacterCreationState()
{

}

/*
void CharacterCreationState::readFile(char* _file, int _numWords, SDL_Renderer* _renderer)
{

	std::ifstream file("race.txt");
	if (file.is_open())
	{
	char* a1[4];

	for (int i = 0; i < 4; ++i)
	{
	file >> a1[i];
	race.push_back(Sprite(_renderer, a1[i], x, y, w, h));
	}
	}

}
*/

void CharacterCreationState::StateLoop()
{
	bool quit = false;
	SDL_Event e;

	int raceNum = 0;
	int hairNum = 0;
	int hairColourNum = 0;
	int eyeNum = 0;
	int eyeColourNum = 0;
	int lipsNum = 0;
	int topNum = 0;
	int bottomNum = 0;

	Sprite* bkg = new Sprite(renderer, "Assets\\enterprise.bmp", 1, 1024, 600);

	while (!quit)
	{
		while (SDL_PollEvent(&e)) // allow closing SDL window to quit
		{
			if (e.type == SDL_QUIT)
			{
				state = 0;
				quit = true;
			}
		}

		SDL_RenderClear(renderer);

		//background->draw();

		SDL_RenderPresent(renderer);
	}

}

Sprite CharacterCreationState::GetOutfit(int _player)
{
	Sprite* outfit = new Sprite(renderer, "temp.bmp", x, y, w, h);
	
	outfit->makeImage(char* race, char* hair, char* eyes, char* lips, char* top, char* bottom);

	return *outfit;
}

std::vector<int> CharacterCreationState::GetOutfitStats(int _player)
{
	return outfitData;
}

void CharacterCreationState::Update()
{

	//->SetX()
	//->SetY()
}

void CharacterCreationState::Draw()
{

}