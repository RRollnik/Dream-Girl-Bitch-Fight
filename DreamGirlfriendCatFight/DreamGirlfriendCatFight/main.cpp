#include <SDL.h>
#undef main;
#include <SDL_mixer.h>
#include <SDL_ttf.h>

#include <iostream>

#ifdef _MSC_VER
#include <windows.h>
#else
#include <unistd.h>
#endif

int main(int argc, char*argv[])
{
	std::cout << "testing\n";

#ifdef _MSC_VER
	Sleep(3000);
#else
	sleep(3);
#endif

	return 0;
}