#pragma once
#include "Vector2.h"
#include <vector>
#include <array>

class Input
{
public:
	Input() = default;
	~Input() = default;

	bool Initialize();
	void Shutdown();
	void Update();

	Vector2 GetMousePostision() { return m_mousePosition; };
	bool GetMouseButtonDown(uint8_t button) { return m_mouseButtonStates[button]; }
	bool GetPrevMouseButtonDown(uint8_t button) { return m_prevMouseButtonStates[button]; }
private:
	Vector2 m_mousePosition{ 0,0 };
	std::array<uint8_t,3> m_mouseButtonStates;
	std::array<uint8_t, 3> m_prevMouseButtonStates;
};