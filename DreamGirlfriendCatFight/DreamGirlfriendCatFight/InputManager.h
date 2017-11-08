#pragma once

#include <SDL.h>
#include <map>

class InputManager
{
public:

	// ctor / dtor
	InputManager();
	~InputManager();

	// should be called every frame, reads KB, remembers last frame KB
	void UpdateKeyboard();

	// call these to ask if a was just pressed, is held, or was ust released
	bool WasKeyPressed(SDL_Scancode _key);
	bool IsKeyDown(SDL_Scancode _key);
	bool WasKeyReleased(SDL_Scancode _key);
	int LMB();

private:

	const Uint8* keyState;	// for SDL_GetKeyboardState() to use
	int numKeys;			// number of keys we have...
	Uint8* currentKeys;		// ... which is used to say how many elements
	Uint8* prevFrameKeys;	// < these two arrays have
	int lastLMB;
};