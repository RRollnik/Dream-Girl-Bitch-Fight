#include "MenuState.h"

MenuState::MenuState(SDL_Window* _window, SDL_Renderer* _renderer, int &_volume, int &_state)
{
	window = _window;
	renderer = _renderer;
	volume = _volume;
	state = _state;
}

MenuState::~MenuState() 
{

}

void MenuState::StateLoop()
{
	bool quit = false;
	SDL_Event e;

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

		Sprite* menuBkg = new Sprite(renderer, "MenuBkg.bmp", 0, 0, 1920, 1080);
		Button* playButton = new Button(renderer, "PlayButton.bmp", "PlayButton.bmp", 600, 100, 1920, 1080);
		Button* exitButton = new Button(renderer, "QuitButton.bmp", "QuitButton.bmp", 600, 450, 1920, 1080);
		Button* helpButton = new Button(renderer, "HelpButton.bmp", "HelpButton.bmp", 600, 800, 1920, 1080);


		playButton->Draw();
		helpButton->Draw();
		exitButton->Draw();



		menubkg->Draw();

		if (playButton->Clicked())
		{
			quit = true;
		}

		if (helpButton->Clicked())
		{
			Button* helpFileButton = new Button(renderer, "HelpFile.bmp", "HelpFile.bmp", 600, 800, 1920, 1080);
		}


		if (exitButton->Clicked())
		{
			state = 0;
			quit = true;
		}

		SDL_RenderPresent(renderer);

	}
}