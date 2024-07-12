#pragma once
#include "Vector2.h"
#include "Renderer.h"
#include "Input.h"
#include "Particle.h"
#include "Random.h"
#include "ETime.h"
#include "MathUtil.h"
#include "Model.h"
#include "Color.h"
#include "Transform.h"
#include "Audio.h"
#include <SDL.h>
#include <fmod.hpp>
#include <stdlib.h>
#include <iostream>
#include <vector>

class Engine
{
public:
	Engine() = default;
	~Engine() = default;

	bool Initalize();
	void Shutdown();
	void Update();

	Renderer* GetRenderer() { return m_renderer; }
	Input* GetInput() { return m_input; }
	Auydio* GetAudio() { return m_audio; }

private:
	Renderer* m_renderer{ nullptr };
	Input* m_input{ nullptr };
	Auydio* m_audio{ nullptr };
};

extern Engine g_engine;

#define RENDERER g_engine.GetRenderer()
#define INPUT g_engine.GetInput()
#define AUDIO g_engine.GetAudio()