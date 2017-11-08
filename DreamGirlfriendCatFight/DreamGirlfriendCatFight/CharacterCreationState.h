#pragma once
#include <SDL.h>
#include <vector>
#include <string>
#include <fstream>
#include "Sprite.h"


class CharacterCreationState
{
public:

	CharacterCreationState(SDL_Window* _window, SDL_Renderer* _renderer, int &_volume, int &_state);
	~CharacterCreationState();

	void Update();
	void Draw();
	void StateLoop();

	Sprite GetOutfit(int _player);
	std::vector<int> GetOutfitStats(int _player);

protected:

	int x, y = 0;
	int h = 1920;
	int w = 1080;

	SDL_Window* window;
	SDL_Renderer * renderer;
	int volume;
	int state;

	std::vector<Sprite> race;
	std::vector<Sprite> hair;
	std::vector<Sprite> eyes;
	std::vector<Sprite> lips;
	std::vector<Sprite> top;
	std::vector<Sprite> bottom;

	std::vector<int> outfitData;

	//void readFile(char* _file, int _numWords, SDL_Renderer* _renderer);
};