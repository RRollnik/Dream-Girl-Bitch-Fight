#include "GameStateMenu.h"

GameStateMenu::GameStateMenu(SDL_Window* _window, SDL_Renderer* _renderer, int _windowH, int _windowW, SDL_Event _e, bool *_bQuit) :
	GameState(_window, _renderer, _windowH, _windowW, _e, _bQuit)
{
	//The buttons width and height, as they will all be equal
	int iButtonHeight = 50;
	int iButtonWidth = 300;

	//Create sprites
	sBackground = new Sprite(m_renderer, "SpaceTheFinalFucktier.bmp", 0, 0, m_windowW, m_windowH);
	sLogo = new Sprite(m_renderer, "dd1017eb98d46fe40181e7ca830fe5f5.bmp", 100, m_windowH / 4 + 30, 1000, 100);
	
	//Create buttons
	bPlayButton = new Button(m_renderer, "StartGameButton.bmp", "StartGameButtonHovered.bmp", m_windowW / 5 - (iButtonWidth / 2), (m_windowH / 3 + 100) - (iButtonHeight / 2), iButtonWidth, iButtonHeight);
	bHowToButton = new Button(m_renderer, "HowToPlayButton.bmp", "HowToPlayButtonHovered.bmp", m_windowW / 5 - (iButtonWidth / 2), (m_windowH / 3 + 200) - (iButtonHeight / 2), iButtonWidth, iButtonHeight);
	bExitButton = new Button(m_renderer, "ExitButton.bmp", "ExitButtonHovered.bmp", m_windowW / 5 - (iButtonWidth / 2), (m_windowH / 3 + 300) - (iButtonHeight / 2), iButtonWidth, iButtonHeight);

	//Create a variable for our music, load music into that, then check if it worked, then play it
	soundtrack = LoadMusic("MenuST.wav");
	
	m_bMenuQuit = false;
}

GameStateMenu::~GameStateMenu()
{
	//delete all our images
	delete bPlayButton;
	delete bHowToButton;
	delete bExitButton;
	delete sBackground;

	//Free the memory we used for the music
	Mix_FreeMusic(soundtrack);
}

void GameStateMenu::Update()
{

	if (bPlayButton->Clicked())
	{
		m_iGameStateSelection = 1;
		m_bMenuQuit = true;
	}

	if (bHowToButton->Clicked())
	{
		m_iGameStateSelection = 2;
		m_bMenuQuit = true;
	}

	if (bExitButton->Clicked())
	{
		m_iGameStateSelection = 3;
		m_bMenuQuit = true;
	}

}

void GameStateMenu::Draw()
{
	sBackground->Draw();
	sLogo->Draw();
	bPlayButton->Draw();
	bHowToButton->Draw();
	bExitButton->Draw();
}

int GameStateMenu::GameMenuLoop()
{
	//Play loaded music
	Mix_PlayMusic(soundtrack, -1);

	//The menu loop
	while (!m_bMenuQuit)
	{
		//Allows quitting
		Quit();

		//Clear renderer
		Clear();

		//Update the images
		Update();

		//Draw
		Draw();

		//Check if the buttons are clicked or not
		Present();
	}

	return m_iGameStateSelection;
}

void GameStateMenu::Quit()
{
	while (SDL_PollEvent(&m_e)) // allow closing SDL window to quit
	{
		if (m_e.type == SDL_QUIT)
		{
			*m_bQuit = true;
			m_bMenuQuit = true;
		}
	}
}
