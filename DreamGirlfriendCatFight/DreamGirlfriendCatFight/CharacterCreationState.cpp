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
		char* a2[4];

		for (int i = 0; i < 4; ++i)
		{
			file >> a2[i];
			race.push_back(Sprite(_renderer, a2[i], x, y, w, h));
		}
	}

	std::ifstream file("hairColour.txt");
	if (file.is_open())
	{
		char* a3[4];

		for (int i = 0; i < 4; ++i)
		{
			file >> a3[i];
			race.push_back(Sprite(_renderer, a3[i], x, y, w, h));
		}
	}

	std::ifstream file("eyeSize.txt");
	if (file.is_open())
	{
		char* a4[4];

		for (int i = 0; i < 4; ++i)
		{
			file >> a4[i];
			race.push_back(Sprite(_renderer, a4[i], x, y, w, h));
		}
	}

	std::ifstream file("eyeColour.txt");
	if (file.is_open())
	{
		char* a5[4];

		for (int i = 0; i < 4; ++i)
		{
			file >> a5[i];
			race.push_back(Sprite(_renderer, a5[i], x, y, w, h));
		}
	}

	std::ifstream file("lips.txt");
	if (file.is_open())
	{
		char* a6[4];

		for (int i = 0; i < 4; ++i)
		{
			file >> a6[i];
			race.push_back(Sprite(_renderer, a6[i], x, y, w, h));
		}
	}

	std::ifstream file("top.txt");
	if (file.is_open())
	{
		char* a7[4];

		for (int i = 0; i < 4; ++i)
		{
			file >> a7[i];
			race.push_back(Sprite(_renderer, a7[i], x, y, w, h));
		}
	}

	std::ifstream file("bottom.txt");
	if (file.is_open())
	{
		char* a8[4];

		for (int i = 0; i < 4; ++i)
		{
			file >> a8[i];
			race.push_back(Sprite(_renderer, a8[i], x, y, w, h));
		}
	}

	StateLoop(_window, _renderer, _volume, _state);
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

void CharacterCreationState::StateLoop(SDL_Window* _window, SDL_Renderer * _renderer, int &_volume, int &_state)
{
	bool quit = false;
	SDL_Event e;

	while (!quit)
	{
		while (SDL_PollEvent(&e)) // allow closing SDL window to quit
		{
			if (e.type == SDL_QUIT)
			{
				_state = 0;
				quit = true;
			}
		}

		SDL_RenderClear(_renderer);

		//background->draw();

		SDL_RenderPresent(_renderer);
	}

}

Sprite CharacterCreationState::GetOutfit(int _player)
{



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