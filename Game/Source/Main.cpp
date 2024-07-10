//#include "../../Engine/Source/Test.h"
#include "Vector2.h"
#include "Renderer.h"
#include "Input.h"
#include "Particle.h"
#include "Random.h"
#include "ETime.h"
#include "MathUtil.h"
#include "Model.h"
#include "Color.h"
#include <SDL.h>
#include <fmod.hpp>
#include <stdlib.h>
#include <iostream>
#include <vector>


int main(int argc, char* argv[])
{
	//Variables/Systems
	FMOD::System* audio;
	FMOD::System_Create(&audio);

	void* extradriverdata = nullptr;
	audio->init(32, FMOD_INIT_NORMAL, extradriverdata);

	
	
	Renderer renderer;
	renderer.Initialize();
	renderer.CreateWindow("Game Engine", 800, 600);

	Input input;
	input.Initialize();

	Time time;
	float offset = 0;
	//std::vector<Vector2> points;
	//Creating a random shape
	/*for (int i = 0; i < 100; i++)
		{
			points.push_back(Vector2{ rand() % 800, rand() % 600 });
		}*/
	std::vector<Particle> particles;
	//Random particle generator
	/*for (int i = 0; i < 100; i++)
	{
		particles.push_back(Particle{ {rand() % 800, rand() % 600}, { randomf(0.1f,0.3f) , 0.0f} });
	}*/
	//Vector2 v1{ 400, 300 };
	//Vector2 v2{ 700, 500 };

	FMOD::Sound* sound = nullptr;
	//Test to see if audio system is working
	audio->createSound("test.wav", FMOD_DEFAULT, 0, &sound);

	audio->playSound(sound, 0, false, nullptr);

	//Sound Library
	std::vector<FMOD::Sound*> sounds;
	audio->createSound("bass.wav", FMOD_DEFAULT, 0, &sound);
	sounds.push_back(sound);

	audio->createSound("snare.wav", FMOD_DEFAULT, 0, &sound);
	sounds.push_back(sound);
	
	audio->createSound("close-hat.wav", FMOD_DEFAULT, 0, &sound);
	sounds.push_back(sound);

	Vector2 velocity{ 0,0 };
	Color color{ 1,1,1,0 };
	std::vector<Vector2> points;
	points.push_back(Vector2{ -5 , 5 });
	points.push_back(Vector2{ 0 , -5 });
	points.push_back(Vector2{ 5 , 5 });
	points.push_back(Vector2{ -5 , 5 });
	Model model{points, color};
	Vector2 position{ 400,300 };
	float rotation = 0;

	bool quit = false;
	//main loop
	while (!quit)
	{
		time.Tick();
		//std::cout << time.GetTime() << std::endl;
		//std::cout << time.GetDeltaTime() << std::endl;
		
		//INPUT
		input.Update();
		
		if (input.GetKeyDown(SDL_SCANCODE_ESCAPE))
		{
			quit = true;
		}
		
		if (input.GetKeyDown(SDL_SCANCODE_LEFT)) return velocity.x += -100;
		if (input.GetKeyDown(SDL_SCANCODE_RIGHT)) return velocity.x += 100;
		if (input.GetKeyDown(SDL_SCANCODE_UP)) return velocity.y += 100;
		if (input.GetKeyDown(SDL_SCANCODE_DOWN)) return velocity.y += -100;
		// UPDATE
		
		
		//Mouse Tracking
		Vector2 mousePosition = input.GetMousePostision();
		/*if (input.GetMouseButtonDown(0) && !input.GetPrevMouseButtonDown(0))
		{
			std::cout << "mouse pressed" << std::endl;
			points.push_back(mousePosition);
		}
		if (input.GetMouseButtonDown(0) && input.GetPrevMouseButtonDown(0))
		{
			float distance = (points.back() - mousePosition).Length();
			if (distance > 5) points.push_back(mousePosition);
		}*/
		if (input.GetMouseButtonDown(0))
		{
			//std::cout << "mouse pressed" << std::endl;
			for (int i = 0; i < 10; i++) {
				particles.push_back(Particle{ mousePosition, randomOnUnitCirlce() * randomf(10,100), randomf(1.0f, 5.0f) });
		
			}
		
		}
		//Audio Update and Tracking
		audio->update();
		if (input.GetKeyDown(SDL_SCANCODE_Q) && !input.GetPrevKeyDown(SDL_SCANCODE_Q))
		{
			audio->playSound(sounds[0], 0, false, nullptr);
		}
		if (input.GetKeyDown(SDL_SCANCODE_W) && !input.GetPrevKeyDown(SDL_SCANCODE_W))
		{
			audio->playSound(sounds[1], 0, false, nullptr);
		}
		if (input.GetKeyDown(SDL_SCANCODE_E) && !input.GetPrevKeyDown(SDL_SCANCODE_E))
		{
			audio->playSound(sounds[2], 0, false, nullptr);
		}

		//Particle Update
		for (Particle& particle : particles)
		{
			particle.Update(0.1f);
		
			//if (particle.position.x > 800) particle.position.x = 0;
			//if (particle.position.x < 0) particle.position.x = 800;
		}
		
		//std::cout << mousePosition.x << ", " << mousePosition.y << std::endl;
		/*Vector2 speed{0.5f, -0.5f};
		for (Vector2& point : points)
		{
			point = point + speed;
		}*/
		
		// Begin Render
		renderer.SetColor(0, 0, 0, 0);
		renderer.BeginFrame();
		
		
		renderer.SetColor(255, 255, 255, 0);
		
		float radius = 30.0f;
		offset += (90 + time.GetDeltaTime());
		for (float angle = 0; angle > 360; angle += 360 / 30)
		{
		
			float x = Math::Cos(Math::DegtToRad(angle + offset)) * Math::Sin(offset) * radius;
			float y = Math::Sin(Math::DegtToRad(angle + offset)) * Math::Sin(offset) * radius;
		
			renderer.DrawRect(800 + x, 300 + y, 4.0f, 4.0f);
		}
		
		//DRAW
		//Particle Effects
		for (Particle particle : particles)
			{
				particle.Draw(renderer);
			}
		//Drawing Using Vectors
		/*//renderer.DrawLine(v1.x, v1.y, v2.x, v2.y);
			renderer.SetColor(255, 255, 255, 0);
			for (int i = 0; points.size() > 1 && i < (points.size() - 1); i++)
			{
				renderer.SetColor(rand() % 256, rand() % 256, rand() % 256, 0); // create random color
				renderer.DrawLine(points[i].x, points[i].y, points[i + 1].x , points[i + 1].y );
			}*/
		
		//Random Line Generator
		/*int value = rand() % 1000;
			for (int i = 0; i <= value; i++)
			{
				//renderer.SetColor( 255, 255, 255, 0);
				renderer.SetColor(rand() % 256, rand() % 256, rand() % 256, 0); // create random color
				renderer.DrawPoint(400, 300);
				// draw line
				renderer.DrawLine(rand() % 800, rand() % 600, rand() % 800, rand() % 600);
			}
			*/
		
		// Geometric Shape
		/*outside lines
			renderer.SetColor(255, 255, 255, 0);
			renderer.DrawLine(100, 450, 350, 50);
			renderer.DrawLine(100, 450, 175, 525);
			renderer.DrawLine(350, 50, 450, 50);
			renderer.DrawLine(450, 50, 700, 450);
			renderer.DrawLine(700, 450, 625, 525);
			renderer.DrawLine(175, 525, 625, 525);
			//inside lines
			renderer.DrawLine(175, 525, 350, 225);
			renderer.DrawLine(350, 225, 435, 375);
			renderer.DrawLine(350, 50, 538, 375);
			renderer.DrawLine(325, 450, 700, 450);
			renderer.DrawLine(362, 375, 538, 375);
			renderer.DrawLine(395, 307, 325, 450);
			*/
		model.Draw(renderer, position, 0, 5);
		// show screen
		renderer.EndFrame();
	}
	return 0;
}