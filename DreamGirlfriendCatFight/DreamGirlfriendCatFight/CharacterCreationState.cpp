#include "CharacterCreationState.h"

CharacterCreationState::CharacterCreationState(SDL_Window* _window, SDL_Renderer * _renderer, int &_volume, int &_state)
{
	window = _window;
	renderer = _renderer;
	volume = _volume;
	state = _state;

	loadFile("race.txt", race);
	loadFile("hair.txt", hair);
	loadFile("eyes.txt", eyes);
	loadFile("lips.txt", lips);
	loadFile("top.txt", top);
	loadFile("bottom.txt", bottom);

}

CharacterCreationState::~CharacterCreationState()
{

}

void CharacterCreationState::loadFile(char* _file, std::vector<Sprite*> &_vec)
{
	std::string line;

	std::ifstream file(_file);
	if (file.is_open())
	{
		while (getline(file, line))
		{
			std::cout << line << '\n';

			char *cstr = new char[line.length() + 1];
			strcpy_s(cstr, line.length() + 1, line.c_str());

			_vec.push_back(new Sprite(renderer, cstr, x, y, 540, 960));

			delete[] cstr;
		}
		file.close();
	}

	line.clear();
}

void CharacterCreationState::StateLoop()
{
	bool quit = false;
	SDL_Event e;

	int raceNum = 0;
	int hairNum = 0;
	int eyeNum = 0;
	int lipsNum = 0;
	int topNum = 0;
	int bottomNum = 0;

	Sprite* bkg = new Sprite(renderer, "bkg.bmp", 0, 0, 1920, 1080);

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

		bkg->Draw();

		race.at(raceNum)->Draw();
		hair.at(hairNum)->Draw();
		eyes.at(eyeNum)->Draw();
		lips.at(lipsNum)->Draw();
		top.at(topNum)->Draw();
		bottom.at(bottomNum)->Draw();



		SDL_RenderPresent(renderer);
	}

}

Sprite CharacterCreationState::GetOutfit(int _player)
{
	Sprite* outfit = new Sprite(renderer, "temp.bmp", x, y, w, h);
	
	//outfit->makeImage(char* race, char* hair, char* eyes, char* lips, char* top, char* bottom);

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