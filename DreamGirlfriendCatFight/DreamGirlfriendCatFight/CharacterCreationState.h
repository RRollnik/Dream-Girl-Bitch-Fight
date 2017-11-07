#pragma once
#include <SDL.h>
#include <vector>
#include <string>
#include <fstream>
#include "Sprite.h"


class CharacterCreationState
{
public:

	CharacterCreationState(SDL_Renderer * _renderer);
	~CharacterCreationState();

	void Update();
	void Draw();

protected:

	int x, y = 0;
	int h = 1920;
	int w = 1080;

	std::vector<Sprite> race;
	std::vector<Sprite> hair;
	std::vector<Sprite> eyeSize;
	std::vector<Sprite> eyeColour;
	std::vector<Sprite> mouth;
	std::vector<Sprite> top;
	std::vector<Sprite> bottom;

	void readFile(char* _file, int _numWords, SDL_Renderer* _renderer);
};