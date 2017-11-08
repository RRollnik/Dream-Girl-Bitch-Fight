#include "CharacterCreationState.h"

CharacterCreationState::CharacterCreationState(SDL_Window* _window, SDL_Renderer * _renderer, int &_volume, int &_state)
{
	window = _window;
	renderer = _renderer;
	volume = _volume;
	state = _state;

	loadFile("race.txt", race, race2);
	loadFile("hair.txt", hair, hair2);
	loadFile("eyes.txt", eyes, eyes2);
	loadFile("lips.txt", lips, lips2);
	loadFile("top.txt", top, top2);
	loadFile("bottom.txt", bottom, bottom2);

}

CharacterCreationState::~CharacterCreationState()
{

}

void CharacterCreationState::loadFile(char* _file, std::vector<Sprite*> &_vec, std::vector<Sprite*> &_vec2)
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
			_vec2.push_back(new Sprite(renderer, cstr, x, y, 540, 960));

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

	Button* start = new Button(renderer, "StartButton.bmp", "StartButton.bmp", 801, 500, 159, 64);

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

	Button* btn13 = new Button(renderer, "btn1.bmp", "btn2.bmp", 1420, 500, 159, 64);
	Button* btn14 = new Button(renderer, "btn1.bmp", "btn2.bmp", 1720, 500, 159, 64);

	Button* btn15 = new Button(renderer, "btn3.bmp", "btn4.bmp", 1420, 600, 159, 64);
	Button* btn16 = new Button(renderer, "btn3.bmp", "btn4.bmp", 1720, 600, 159, 64);

	Button* btn17 = new Button(renderer, "btn5.bmp", "btn6.bmp", 1420, 700, 159, 64);
	Button* btn18 = new Button(renderer, "btn5.bmp", "btn6.bmp", 1720, 700, 159, 64);

	Button* btn19 = new Button(renderer, "btn7.bmp", "btn8.bmp", 1420, 800, 159, 64);
	Button* btn20 = new Button(renderer, "btn7.bmp", "btn8.bmp", 1720, 800, 159, 64);

	Button* btn21 = new Button(renderer, "btn9.bmp", "btn10.bmp", 1420, 900, 159, 64);
	Button* btn22 = new Button(renderer, "btn9.bmp", "btn10.bmp", 1720, 900, 159, 64);

	Button* btn23 = new Button(renderer, "btn11.bmp", "btn12.bmp", 1420, 1000, 159, 64);
	Button* btn24 = new Button(renderer, "btn11.bmp", "btn12.bmp", 1720, 1000, 159, 64);

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
			else if (btn13->Clicked())							// player 2 buttons starts here
			{
				if (raceNum2 < (race.size() - 1))
					raceNum2++;
			}
			else if (btn14->Clicked())
			{
				if (raceNum2 > 0)
					raceNum2--;
			}
			else if (btn15->Clicked())
			{
				if (hairNum2 < (hair.size() - 1))
					hairNum2++;
			}
			else if (btn16->Clicked())
			{
				if (hairNum2 > 0)
					hairNum2--;
			}
			else if (btn17->Clicked())
			{
				if (eyeNum2 < (eyes.size() - 1))
					eyeNum2++;
			}
			else if (btn18->Clicked())
			{
				if (eyeNum2 > 0)
					eyeNum2--;
			}
			else if (btn19->Clicked())
			{
				if (lipsNum2 < (lips.size() - 1))
					lipsNum2++;
			}
			else if (btn20->Clicked())
			{
				if (lipsNum2 > 0)
					lipsNum2--;
			}
			else if (btn21->Clicked())
			{
				if (topNum2 < (top.size() - 1))
					topNum2++;
			}
			else if (btn22->Clicked())
			{
				if (topNum2 > 0)
					topNum2--;
			}
			else if (btn23->Clicked())
			{
				if (bottomNum2 < (bottom.size() - 1))
					bottomNum2++;
			}
			else if (btn24->Clicked())
			{
				if (bottomNum2 > 0)
					bottomNum2--;
			}
			else if (start->Clicked())
			{
				nextState = 3;
				quit = true;
			}
		}

		SDL_RenderClear(renderer);

		bkg->Draw();

		start->Draw();

		race.at(raceNum1)->Draw();
		hair.at(hairNum1)->Draw();
		eyes.at(eyeNum1)->Draw();
		lips.at(lipsNum1)->Draw();
		top.at(topNum1)->Draw();
		bottom.at(bottomNum1)->Draw();

		race2.at(raceNum2)->SetX(1400);
		race2.at(raceNum2)->Draw();
		hair2.at(hairNum2)->SetX(1400);
		hair2.at(hairNum2)->Draw();
		eyes2.at(eyeNum2)->SetX(1400);
		eyes2.at(eyeNum2)->Draw();
		lips2.at(lipsNum2)->SetX(1400);
		lips2.at(lipsNum2)->Draw();
		top2.at(topNum2)->SetX(1400);
		top2.at(topNum2)->Draw();
		bottom2.at(bottomNum2)->SetX(1400);
		bottom2.at(bottomNum2)->Draw();

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

		btn13->Draw();
		btn14->Draw();

		btn15->Draw();
		btn16->Draw();

		btn17->Draw();
		btn18->Draw();

		btn19->Draw();
		btn20->Draw();

		btn21->Draw();
		btn22->Draw();

		btn23->Draw();
		btn24->Draw();

		SDL_RenderPresent(renderer);
	}

	delete input;
	delete bkg;
	delete btn1;
	delete btn2;
	delete btn3;
	delete btn4;
	delete btn5;
	delete btn6;
	delete btn7;
	delete btn8;
	delete btn9;
	delete btn10;
	delete btn11;
	delete btn12;
	delete btn13;
	delete btn14;
	delete btn15;
	delete btn16;
	delete btn17;
	delete btn18;
	delete btn19;
	delete btn20;
	delete btn21;
	delete btn22;
	delete btn23;
	delete btn24;
	delete start;

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