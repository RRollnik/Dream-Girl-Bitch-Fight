#pragma once
#include <SDL.h>
#include <vector>
#include <string>
#include <fstream>
#include "Sprite.h"
#include "Button.h"
#include "InputManager.h"

class CharacterCreationState
{
public:
	std::vector<SDL_Texture*> outfit1;
	std::vector<SDL_Texture*> outfit2;

	int raceNum1, hairNum1, eyeNum1, lipsNum1, topNum1, bottomNum1 = 0;

	int raceNum2, hairNum2, eyeNum2, lipsNum2, topNum2, bottomNum2 = 0;

	CharacterCreationState(SDL_Window* _window, SDL_Renderer* _renderer, int &_volume, int &_state);
	~CharacterCreationState();

	void loadFile(char* _file, std::vector<Sprite*> &_vec);

	void Update();
	void Draw();
	void StateLoop();

	std::vector<SDL_Texture*> GetOutfit(int _player);
	std::vector<int> GetOutfitStats(int _player);

protected:

	int x, y = 0;
	int h = 1920;
	int w = 1080;

	SDL_Window* window;
	SDL_Renderer * renderer;
	int volume;
	int state;

	std::vector<Sprite*> race;
	std::vector<Sprite*> hair;
	std::vector<Sprite*> eyes;
	std::vector<Sprite*> lips;
	std::vector<Sprite*> top;
	std::vector<Sprite*> bottom;

	std::vector<int> outfitData;

	//void readFile(char* _file, int _numWords, SDL_Renderer* _renderer);
};