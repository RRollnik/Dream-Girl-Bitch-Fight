#include "GameStatePlay.h"

GameStatePlay::GameStatePlay(SDL_Window* _window, SDL_Renderer* _renderer, int _windowH, int _windowW, SDL_Event _e, bool *_bQuit) :
	GameState(_window, _renderer, _windowH, _windowW, _e, _bQuit)
{
	//definitions
	bPause = false;
	m_bPlayQuit = false;

	iScore = 0;
	iRound = 1;
	iEnemyHealthBoost = 0;

	pausetime = time(NULL);
	RoundInterval = NULL;
	EndInterval = NULL;
	key = SDL_GetKeyboardState(NULL);

	//initiliase a font variable
	tFont = TTF_OpenFont("Xanadu.ttf", 28);
	//check to make sure nothing went wrong;
	if (tFont == NULL)
	{
		std::cout << TTF_GetError();
		system("pause");
	}

	soundtrack = LoadMusic("PlayST.wav");
	ShootChunkSE = Mix_LoadWAV("ShootChunk.wav");
	ExplosionSE = Mix_LoadWAV("ExplosionSE.wav");
	DeathSE = Mix_LoadWAV("Death.wav");

	//Score text
	surfacetext = MakeScoreText(iScore, tFont);
	tScoreText = new Text(_renderer, surfacetext, 100, 600, 100, 30);

	//Death text
	tDeathText = new Text(_renderer, MakeText(tFont, "You Died"), (_windowW / 2) - 100, (_windowH / 2) - 50, 200, 50);
	
	//Some text written to the scren between rounds
	tWaveIncomingText = new Text(_renderer, MakeText(tFont, "Wave Incoing"), (_windowW / 2) - 100, (_windowH / 2) - 25, 200, 50);

	//variables for storing stuff
	background = new ScrollingBackground(_renderer, "space-1.bmp", 5, 1680, 1050);
	pPlayer0 = new Player(_renderer, "PlayerSprite.bmp", 372/3, 422/3, _windowH, _windowW, ShootChunkSE, ExplosionSE);
}

GameStatePlay::~GameStatePlay()
{
	//Delete everything created (hopefully, unless I forget something in which case "Goddammit!"
	delete background;
	delete pPlayer0;
	delete tScoreText;
	delete tDeathText;
	delete tWaveIncomingText;

	//iterate through and destroy them all!!!!!!!!!!!!!!!
	for (int i = 0; i != bPlayerBulletVect.size(); i++)
	{
		delete bPlayerBulletVect[i];
	}
	for (int i = 0; i != bEnemyBulletVect.size(); i++)
	{
		delete bEnemyBulletVect[i];
	}

	for (int i = 0; i != eEnemyVect.size(); i++)
	{
		delete eEnemyVect[i];
	}
	for (int i = 0; i != eExplosionVect.size(); i++)
	{
		delete eExplosionVect[i];
	}

	Mix_FreeMusic(soundtrack);
	Mix_FreeChunk(ExplosionSE);
	Mix_FreeChunk(DeathSE);
	Mix_FreeChunk(ShootChunkSE);
}

void GameStatePlay::Update()
{
	//Update functions
	background->Update();
	//explosion->Update();

	for (int i = 0; i != eEnemyVect.size();)
	{
		if (!eEnemyVect[i]->GetHealth())
		{
			//Play death sound on death
			Mix_PlayChannel(-1, DeathSE, 0);
			//deletes the object at that location in the vector, and then removes that entry from the vector
			delete eEnemyVect[i];
			eEnemyVect.erase(eEnemyVect.begin() + i);

			//Incremenets score when an enemy is defeated
			if (iScore != INT_MAX)
			{
				iScore++;
			}
		}
		else
		{
			eEnemyVect[i]->Update(bPlayerBulletVect, bEnemyBulletVect, eExplosionVect);
			i++;
		}
	}

	for (int i = 0; i != eExplosionVect.size();)
	{
		if (!eExplosionVect[i]->GetCycle())
		{
			eExplosionVect[i]->Update();
			i++;
		}
		else
		{
			delete eExplosionVect[i];
			eExplosionVect.erase(eExplosionVect.begin() + i);
		}
	}

	if (pPlayer0->GetHealth())
	{
		pPlayer0->Update(bEnemyBulletVect, bPlayerBulletVect, eExplosionVect);
	}
	else
	{
		EndingGame();
	}

	//iterate through the enemy bullets to check if they should be delete or updated
	for (int i = 0; i != bEnemyBulletVect.size();)
	{
		//Checks if the bullet is on screen
		if (bEnemyBulletVect[i]->GetY() < -50 || bEnemyBulletVect[i]->GetY() > m_windowH)
		{
			//we both delete the object and then its place in the vector, we only iterate i if this function doesn't trigger as i will represent a new value if the former i is deleted
			delete bEnemyBulletVect[i];
			bEnemyBulletVect.erase(bEnemyBulletVect.begin() + i);
		}
		else
		{
			bEnemyBulletVect[i]->Update();
			i++;
		}
	}

	//player bullets
	for (int i = 0; i != bPlayerBulletVect.size();)
	{
		//Checks if the bullet is on screen
		if (bPlayerBulletVect[i]->GetY() < -50 || bPlayerBulletVect[i]->GetY() > m_windowH)
		{
			//we both delete the object and then its place in the vector, we only iterate i if this function doesn't trigger as i will represent a new value if the former i is deleted
			delete bPlayerBulletVect[i];
			bPlayerBulletVect.erase(bPlayerBulletVect.begin() + i);
		}
		else
		{
			bPlayerBulletVect[i]->Update();
			i++;
		}
	}

	tScoreText->Update(MakeScoreText(iScore, tFont));
}

void GameStatePlay::Draw()
{
	//Draw functions
	background->Draw();

	//draw vectored bullets
	for (int i = 0; i != bEnemyBulletVect.size(); i++)
	{
		bEnemyBulletVect[i]->Draw();
	}
	for (int i = 0; i != bPlayerBulletVect.size(); i++)
	{
		bPlayerBulletVect[i]->Draw();
	}

	//If the pPlayer0 isn't dead draw it
	if (pPlayer0->GetHealth())
	{
		pPlayer0->Draw();
	}
	else
	{
		tDeathText->Draw();
	}

	//draws the vectored enemyies
	for (int i = 0; i != eEnemyVect.size(); i++)
	{
		eEnemyVect[i]->Draw();
	}
	//draw vectored explosions
	for (int i = 0; i != eExplosionVect.size(); i++)
	{
		eExplosionVect[i]->Draw();
	}

	//Only draw this if a round has ended and a wave is incoming in the near future
	if (eEnemyVect.size() == 0)
	{
		tWaveIncomingText->Draw();
	}

	//Draws score text to the screen
	tScoreText->Draw();
}

void GameStatePlay::GamePlayLoop()
{
	//This initialises the rounds and load the first enemy
	Round();

	//This plays the music
	Mix_PlayMusic(soundtrack, -1);

	while (!m_bPlayQuit)
	{
		//Allows quitting
		Quit();

		//Clear renderer
		Clear();

		//Allows pressing escape to affectthe pausing
		if (key[SDL_SCANCODE_ESCAPE])
		{
			PlayPause();
		}

		//Prevents the from update if its paused
		if (bPause)
		{

		}
		else
		{
			//Update the images
			RoundCheck();
			Update();
		}

		//Draw
		Draw();

		//Check if the buttons are clicked or not
		Present();
	}
}

void GameStatePlay::PlayPause()
{
	//If the time since the last pause is not equal to the current time we enter
	if (pausetime != time(NULL))
	{
		//then we check if we're pause or not, and set it based off of that
		if (bPause)
		{
			bPause = false;
		}
		else
		{
			bPause = true;
		}

		//finally we set the pause timer back to the current time, this will prevent holding down pause to cause stuttering
		pausetime = time(NULL);
	}
}

SDL_Surface* GameStatePlay::MakeScoreText(int _iScore, TTF_Font* _tFont)
{
	//This creates two arrays and then shoves an int into the char array
	char cScoreTextNum[20] = { 0 };
	char cScoreText[20] = "Score ";
	sprintf_s(cScoreTextNum, "%d", _iScore);

	//This pastes the converted number number on the end of the char array
	for (int i = 0; cScoreTextNum[i] != NULL; i++)
	{
		cScoreText[i + 6] = cScoreTextNum[i];
	}

	return MakeText(_tFont, cScoreText);
}

void GameStatePlay::RoundCheck()
{
	//iterates round if all enemies dead
	if (eEnemyVect.size() == 0)
	{
		if (RoundInterval == NULL)
		{
			RoundInterval = time(NULL);
			RoundInterval += 5;
		}

		time_t CheckTime = time(NULL);
		if (CheckTime >= RoundInterval)
		{
			if (iRound == 10)
			{
				iRound = 1;
				//Increments enemy health by five points every 10 rounds
				iEnemyHealthBoost += 5;
			}
			else
			{
				iRound++;
				Round();
			}
			RoundInterval = NULL;
		}
	}
}

void GameStatePlay::EndingGame()
{
	if (EndInterval == NULL)
	{
		EndInterval = time(NULL);
		EndInterval += 5;
	}

	time_t CheckTime = time(NULL);
	if (CheckTime >= EndInterval)
	{

		m_bPlayQuit = true;
	}
}

void GameStatePlay::Round()
{
	for (int i = 0; i != iRound; i++)
	{
		eEnemyVect.push_back(new Enemy(m_renderer, "EnemySprite.bmp", 220/2, 154/2, m_windowH, m_windowW, pPlayer0, iEnemyHealthBoost, ShootChunkSE, ExplosionSE));
	}
}

void GameStatePlay::Quit()
{
	while (SDL_PollEvent(&m_e)) // allow closing SDL window to quit
	{
		if (m_e.type == SDL_QUIT)
		{
			*m_bQuit = true;
			m_bPlayQuit = true;
		}
	}
}