#include "InputManager.h"
#include <iostream>

InputManager::InputManager()
{
	keyState = SDL_GetKeyboardState(&numKeys);

	// make two new arrays with 'numKeys' number of elements
	currentKeys = new Uint8[numKeys];
	prevFrameKeys = new Uint8[numKeys];
	lastLMB = 0;
}

InputManager::~InputManager()
{
	// delete the arays that we new'ed in te constructor 
	delete[] currentKeys;
	delete[] prevFrameKeys;
}

void InputManager::UpdateKeyboard()
{
	// store keys from last frame in prevFrameKeys array
	std::memcpy(prevFrameKeys, currentKeys, numKeys);

	// overwrite currentKeys array with state of KB now
	std::memcpy(currentKeys, keyState, numKeys);
}

bool InputManager::WasKeyPressed(SDL_Scancode _key)
{
	if (currentKeys[_key] && !prevFrameKeys[_key])
		return true;
	else
		return false;
}

bool InputManager::IsKeyDown(SDL_Scancode _key)
{
	if (currentKeys[_key] && prevFrameKeys[_key])
		return true;
	else
		return false;
}

bool InputManager::WasKeyReleased(SDL_Scancode _key)
{
	if (!currentKeys[_key] && prevFrameKeys[_key])
		return true;
	else
		return false;
}

int InputManager::LMB()
{
	int state = 0;
	int mouseX, mouseY;
	if ((SDL_GetMouseState(&mouseX, &mouseY) & SDL_BUTTON(SDL_BUTTON_LEFT)))
	{
		state = 1;
	}
	if (((SDL_GetMouseState(&mouseX, &mouseY) & SDL_BUTTON(SDL_BUTTON_LEFT))) && (lastLMB == 1))
	{
		state = 2;
		return state;
	}
	lastLMB = state;
	return state;
}