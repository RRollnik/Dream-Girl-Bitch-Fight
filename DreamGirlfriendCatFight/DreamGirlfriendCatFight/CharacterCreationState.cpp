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
	InputManager* input = new InputManager();
	// This is done once in case the user if holding the mouse down upon entering the state.
	input->LMB();

	bool quit = false;
	SDL_Event e;

	Sprite* bkg = new Sprite(renderer, "bkg.bmp", 0, 0, 1920, 1080);

	Button* btn1 = new Button(renderer, "btn1.bmp", "btn2.bmp", 400, 500, 159, 64);
	Button* btn2 = new Button(renderer, "btn1.bmp", "btn2.bmp", 100, 500, 159, 64);

	Button* btn3 = new Button(renderer, "btn3.bmp", "btn4.bmp", 400, 600, 159, 64);
	Button* btn4 = new Button(renderer, "btn3.bmp", "btn4.bmp", 100, 600, 159, 64);

	Button* btn5 = new Button(renderer, "btn5.bmp", "btn6.bmp", 400, 700, 159, 64);
	Button* btn6 = new Button(renderer, "btn5.bmp", "btn6.bmp", 100, 700, 159, 64);

	Button* btn7 = new Button(renderer, "btn7.bmp", "btn8.bmp", 400, 800, 159, 64);
	Button* btn8 = new Button(renderer, "btn7.bmp", "btn8.bmp", 100, 800, 159, 64);

	Button* btn9 = new Button(renderer, "btn9.bmp", "btn10.bmp", 400, 900, 159, 64);
	Button* btn10 = new Button(renderer, "btn9.bmp", "btn10.bmp", 100, 900, 159, 64);

	Button* btn11 = new Button(renderer, "btn11.bmp", "btn12.bmp", 400, 1000, 159, 64);
	Button* btn12 = new Button(renderer, "btn11.bmp", "btn12.bmp", 100, 1000, 159, 64);

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

		if ((input->LMB() == 1))
		{
			if (btn1->Clicked())
			{
				if (raceNum1 < (race.size() - 1))
					raceNum1++;
			}
			else if (btn2->Clicked())
			{
				if (raceNum1 > 0)
					raceNum1--;
			}
			else if (btn3->Clicked())
			{
				if (hairNum1 < (hair.size() - 1))
					hairNum1++;
			}
			else if (btn4->Clicked())
			{
				if (hairNum1 > 0)
					hairNum1--;
			}
			else if (btn5->Clicked())
			{
				if (eyeNum1 < (eyes.size() - 1))
					eyeNum1++;
			}
			else if (btn6->Clicked())
			{
				if (eyeNum1 > 0)
					eyeNum1--;
			}
			else if (btn7->Clicked())
			{
				if (lipsNum1 < (lips.size() - 1))
					lipsNum1++;
			}
			else if (btn8->Clicked())
			{
				if (lipsNum1 > 0)
					lipsNum1--;
			}
			else if (btn9->Clicked())
			{
				if (topNum1 < (top.size() - 1))
					topNum1++;
			}
			else if (btn10->Clicked())
			{
				if (topNum1 > 0)
					topNum1--;
			}
			else if (btn11->Clicked())
			{
				if (bottomNum1 < (bottom.size() - 1))
					bottomNum1++;
			}
			else if (btn12->Clicked())
			{
				if (bottomNum1 > 0)
					bottomNum1--;
			}
		}

		SDL_RenderClear(renderer);

		bkg->Draw();

		race.at(raceNum1)->Draw();
		hair.at(hairNum1)->Draw();
		eyes.at(eyeNum1)->Draw();
		lips.at(lipsNum1)->Draw();
		top.at(topNum1)->Draw();
		bottom.at(bottomNum1)->Draw();

		btn1->Draw();
		btn2->Draw();

		btn3->Draw();
		btn4->Draw();

		btn5->Draw();
		btn6->Draw();

		btn7->Draw();
		btn8->Draw();

		btn9->Draw();
		btn10->Draw();

		btn11->Draw();
		btn12->Draw();

		SDL_RenderPresent(renderer);
	}


	//outfit1 = GetOutfit(1);
	//outfit2 = GetOutfit(2);

}

std::vector<SDL_Texture*> CharacterCreationState::GetOutfit(int _player)
{
	/*
	Sprite* outfit = new Sprite(renderer, "temp.bmp", x, y, w, h);

	outfit->mergeImage(char* race, char* hair, false);
	outfit->mergeImage(char* race, char* eyes, false);
	outfit->mergeImage(char* race, char* lips, false);
	outfit->mergeImage(char* race, char* top, false);
	outfit->mergeImage(char* race, char* bottom, true);
	*/

	if (_player == 0)
	{
		outfit1.push_back(race.at(raceNum1)->image);
		outfit1.push_back(hair.at(hairNum1)->image);
		outfit1.push_back(eyes.at(eyeNum1)->image);
		outfit1.push_back(lips.at(lipsNum1)->image);
		outfit1.push_back(top.at(topNum1)->image);
		outfit1.push_back(bottom.at(bottomNum1)->image);

		return outfit1;
	}
	else if (_player == 1)
	{
		outfit2.push_back(race.at(raceNum2)->image);
		outfit2.push_back(hair.at(hairNum2)->image);
		outfit2.push_back(eyes.at(eyeNum2)->image);
		outfit2.push_back(lips.at(lipsNum2)->image);
		outfit2.push_back(top.at(topNum2)->image);
		outfit2.push_back(bottom.at(bottomNum2)->image);

		return outfit2;
	}

	return outfit1;
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