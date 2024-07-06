//#include "../../Engine/Source/Test.h"
#include "Vector2.h"
#include "Renderer.h"
#include "Input.h"
#include "Particle.h"
#include "Random.h"
#include "ETime.h"
#include <SDL.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

int main(int argc, char* argv[])
{
	//Variables/Systems

	
	Renderer renderer;
	renderer.Initialize();
	renderer.CreateWindow("Game Engine", 800, 600);

	Input input;
	input.Initialize();

	Time time;
	std::vector<Vector2> points;
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
				particles.push_back(Particle{ mousePosition, {randomf(-0.5f,0.5f) , randomf(-0.5f,0.5f)}, randomf(1.0f, 5.0f)});
				
			}
			
		}
		for (Particle& particle : particles)
		{
			if (particle.lifespan != 0) {
				particle.Update(particle.lifespan -= 0.1f);
			}
			
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

		//DRAW
		//Particle Effects
		renderer.SetColor(rand() % 256, rand() % 256, rand() % 256, 0);
		for (Particle particle : particles) 
		{
			if (particle.lifespan >= 0) {
				particle.Draw(renderer);
			}
			
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

		// show screen
		renderer.EndFrame();
	}
	
	

	return 0;
}