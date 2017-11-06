#ifndef _GameStatePlay_h_
#define _GameStatePlay_h_

#include "GameState.h"

class GameStatePlay : public GameState
{
public:
	GameStatePlay(SDL_Window* _window, SDL_Renderer* _renderer, int _windowH, int _windowW, SDL_Event _e, bool *_bQuit);
	~GameStatePlay();

	virtual void Update();
	virtual void Draw();

	void GamePlayLoop();
	SDL_Surface* MakeScoreText(int _iScore, TTF_Font* _tFont);
	void PlayPause();
	void RoundCheck();
	void Round();
	void Quit();
	void EndingGame();

private:
	bool bPause;
	bool bGameQuit;
	bool m_bPlayQuit;
	int iScore;
	int iRound;
	int iEnemyHealthBoost;
	time_t pausetime;
	time_t RoundInterval;
	time_t EndInterval;
	Mix_Music *soundtrack;
	Mix_Chunk *ShootChunkSE;
	Mix_Chunk *ExplosionSE;
	Mix_Chunk *DeathSE;
	const Uint8* key;
	TTF_Font *tFont;
	SDL_Surface* surfacetext;
	Text* tScoreText;
	Text* tDeathText;
	Text* tWaveIncomingText;
	ScrollingBackground* background;
	Player* pPlayer0;

	std::vector<Enemy*> eEnemyVect;
	std::vector<AnimatedSprite*> eExplosionVect;
	std::vector<Bullet*> bEnemyBulletVect;
	std::vector<Bullet*> bPlayerBulletVect;
};

#endif
