#include "Input.h"
#include <SDL.h>

bool Input::Initialize()
{
	int numKeys;
	const uint8_t* keyboardState = SDL_GetKeyboardState(&numKeys);

	m_keyboardStates.resize(numKeys);

	std::copy(keyboardState, keyboardState + numKeys, m_keyboardStates.begin());
	m_prevKeyboardStates = m_keyboardStates;

	return true;
}

void Input::Shutdown()
{

}

void Input::Update()
{
	
	//keyboard state
	m_prevKeyboardStates = m_keyboardStates;
	const uint8_t* keyboardState = SDL_GetKeyboardState(nullptr);
	std::copy(keyboardState, keyboardState + m_keyboardStates.size(), m_keyboardStates.begin());

	//mouse input
	int x, y;
	uint32_t buttonState = SDL_GetMouseState(&x, &y);

	m_mousePosition.x = (float)x;
	m_mousePosition.y = (float)y;

	m_prevMouseButtonStates = m_mouseButtonStates;

	m_mouseButtonStates[0] = buttonState & SDL_BUTTON_LMASK;
	m_mouseButtonStates[1] = buttonState & SDL_BUTTON_MMASK;
	m_mouseButtonStates[2] = buttonState & SDL_BUTTON_RMASK;
}
