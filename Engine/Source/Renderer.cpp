#include "Renderer.h"
#include <iostream>

bool Renderer::Initialize()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cerr << "Error initializing SDL: " << SDL_GetError() << std::endl;
		return false;
	}
	return true;
}

void Renderer::Shutdown()
{
}

bool Renderer::CreateWindow(std::string title, int width, int height)
{
	m_window = SDL_CreateWindow(title.c_str(),
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		800, 600,
		SDL_WINDOW_SHOWN);
	if (m_window == nullptr)
	{
		std::cerr << "Error creating SDL window: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return false;
	}
	m_renderer = SDL_CreateRenderer(m_window, -1, 0);

	return true;
}

void Renderer::BeginFrame()
{
	SDL_RenderClear(m_renderer);
}

void Renderer::EndFrame()
{
	SDL_RenderPresent(m_renderer);
}

void Renderer::SetColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	SDL_SetRenderDrawColor(m_renderer, r, g, b, a);
}

void Renderer::DrawLine(float x1, float y1, float x2, float y2)
{
	SDL_RenderDrawLine(m_renderer, x1, y1, x2, y2);
}

void Renderer::DrawPoint(int x, int y)
{
	SDL_RenderDrawPoint(m_renderer, x, y);
}

void Renderer::DrawPoint(float x, float y)
{
	SDL_RenderDrawPoint(m_renderer, x, y);
}
