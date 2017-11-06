#include "GameState.h"

GameState::GameState(SDL_Window* _window, SDL_Renderer* _renderer, int _windowH, int _windowW, SDL_Event _e, bool *_bQuit)
{
	m_window = _window;
	m_renderer = _renderer;
	m_windowH = _windowH;
	m_windowW = _windowW;
	m_e = _e;
	m_bQuit = _bQuit;
}

GameState::~GameState()
{

}

void GameState::Clear()
{
	SDL_RenderClear(m_renderer);
}

void GameState::Present()
{
	SDL_RenderPresent(m_renderer);
}

Mix_Music* GameState::LoadMusic(char* _file)
{

	//load music
	Mix_Music *check = Mix_LoadMUS(_file);

	//check if music loaded
	if (check == NULL)
	{
		std::cout << "Error loading music";
		system("pause");
	}

	//returns the loaded music
	return check;
}

SDL_Surface* GameState::MakeText(TTF_Font* _tFont, char* _text)
{
	return (TTF_RenderText_Solid(_tFont, _text, { 255, 255, 255 }));
}

void GameState::Update()
{

}

void GameState::Draw()
{

}

void GameState::Quit()
{
	while (SDL_PollEvent(&m_e)) // allow closing SDL window to quit
	{
		if (m_e.type == SDL_QUIT)
		{
			*m_bQuit = true;
		}
	}
}