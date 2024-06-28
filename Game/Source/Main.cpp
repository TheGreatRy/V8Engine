//#include "../../Engine/Source/Test.h"
#include <SDL.h>
#include <stdlib.h>
#include <iostream>

int main(int argc, char* argv[])
{
	int value = rand() % 1000;// generate a number between 0-999
	// initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cerr << "Error initializing SDL: " << SDL_GetError() << std::endl;
		return 1;
	}

	// create window
	// returns pointer to window if successful or nullptr if failed
	SDL_Window* window = SDL_CreateWindow("Game Engine",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		800, 600,
		SDL_WINDOW_SHOWN);
	if (window == nullptr)
	{
		std::cerr << "Error creating SDL window: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}

	// create renderer
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

	while (true)
	{
		// clear screen
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderClear(renderer);
		/* Random Line Generator
		for (int i = 0; i <= value; i++)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
			SDL_SetRenderDrawColor(renderer, rand() % 256, rand() % 256, rand() % 256, 0); // create random color
			SDL_RenderDrawPoint(renderer, 400, 300);

			// draw line
			//SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
			SDL_RenderDrawLine(renderer, rand() % 800, rand() % 600, rand() % 800, rand() % 600);
		}
		*/
		// Geometric Shape
		//outside lines
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		SDL_RenderDrawLine(renderer, 100, 450, 350, 50);
		SDL_RenderDrawLine(renderer, 100, 450, 175, 525);
		SDL_RenderDrawLine(renderer, 350, 50, 450, 50);
		SDL_RenderDrawLine(renderer, 450, 50, 700, 450);
		SDL_RenderDrawLine(renderer, 700, 450, 625, 525);
		SDL_RenderDrawLine(renderer, 175, 525, 625, 525);
		//inside lines
		SDL_RenderDrawLine(renderer, 175, 525, 350, 225);
		SDL_RenderDrawLine(renderer, 350, 225, 435, 375);
		SDL_RenderDrawLine(renderer, 350, 50, 538, 375);

		SDL_RenderDrawLine(renderer, 325, 450, 700, 450);
		SDL_RenderDrawLine(renderer, 362, 375, 538, 375);
		SDL_RenderDrawLine(renderer, 395, 307, 325, 450);


		// show screen
		SDL_RenderPresent(renderer);
	}
	
	

	return 0;
}