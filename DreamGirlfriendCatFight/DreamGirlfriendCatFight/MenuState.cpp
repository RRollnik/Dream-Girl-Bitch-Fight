#include "MenuState.h"

MenuState(sdl_window window, sdl_renderer renderer, int volume, int state)
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

		startButton->draw(stuff)
			helpButton->draw(stuff)
			exitButton->draw(stuff)



			//background->draw();

			SDL_RenderPresent(_renderer);

	}
