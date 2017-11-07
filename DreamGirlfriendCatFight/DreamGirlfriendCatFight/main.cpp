#include <SDL.h>
#undef main;
#include <SDL_mixer.h>
#include <SDL_ttf.h>

#ifdef _MSC_VER
#include <windows.h>
#else
#include <unistd.h>
#endif

void GameLoop();

int main(int argc, char*argv[])
{
	GameLoop();

#ifdef _MSC_VER
	Sleep(3000);
#else
	sleep(3);
#endif

	return 0;
}

void GameLoop()
{
	bool quit = false;
	SDL_Event e;

	while (!quit)
	{
		while (SDL_PollEvent(&e)) // allow closing SDL window to quit
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
		}

		//Game loops go here
	}
}