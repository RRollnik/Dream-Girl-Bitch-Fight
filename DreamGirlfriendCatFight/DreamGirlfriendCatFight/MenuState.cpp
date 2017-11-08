#include "MenuState.h"

MenuState::MenuState(SDL_Window* _window, SDL_Renderer* _renderer, int volume, int _state)
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

		Sprite* menubkg = new Sprite(_renderer, "bkg.bmp", 0, 0, 1920, 1080);
		startButton->Draw();
		helpButton->Draw();
		exitButton->Draw();


		
		menubkg->Draw();

			SDL_RenderPresent(_renderer);

	}
