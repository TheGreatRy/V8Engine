//#include "../../Engine/Source/Test.h"
#include "Renderer.h"
#include "Input.h"
#include "Vector2.h"
#include <SDL.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

int main(int argc, char* argv[])
{
	
	
	Renderer renderer;
	renderer.Initialize();
	renderer.CreateWindow("Game Engine", 800, 600);

	Input input;

	Vector2 v1{ 400, 300 };
	Vector2 v2{ 700, 500 };

	std::vector<Vector2> points;
	/*for (int i = 0; i < 100; i++)
	{
		points.push_back(Vector2{ rand() % 800, rand() % 600 });
	}*/

	//main loop
	while (true)
	{
		//input
		// update
		// draw

		//INPUT
		input.Update();
		
		// UPDATE
		Vector2 mousePosition = input.GetMousePostision();
		//std::cout << mousePosition.x << ", " << mousePosition.y << std::endl;

		if (input.GetMouseButtonDown(0) && !input.GetPrevMouseButtonDown(0))
		{
			std::cout << "mouse pressed" << std::endl;
			points.push_back(mousePosition);
		}

		/*Vector2 speed{ 0.5f, -0.5f };
		for (Vector2& point : points)
		{
			point = point + speed;
		}*/
		// clear screen
		renderer.SetColor(0, 0, 0, 0);
		renderer.BeginFrame();

		//DRAW
		//renderer.SetColor(255, 255, 255, 0);
		//renderer.DrawLine(v1.x, v1.y, v2.x, v2.y);
		//renderer.SetColor(255, 255, 255, 0);
		//for (int i = 0; i < points.size() - 1;i++)
		//{
		//	
		//	renderer.DrawLine(points[i].x, points[i].y, points[i].x + 1, points[i].y + 1);
		//}

		////Random Line Generator
		//int value = rand() % 1000;
		//for (int i = 0; i <= value; i++)
		//{
		//	//renderer.SetColor( 255, 255, 255, 0);
		//	renderer.SetColor(rand() % 256, rand() % 256, rand() % 256, 0); // create random color
		//	renderer.DrawPoint(400, 300);
		//	// draw line
		//	renderer.DrawLine(rand() % 800, rand() % 600, rand() % 800, rand() % 600);
		//}
		//
		//// Geometric Shape
		////outside lines
		//renderer.SetColor(255, 255, 255, 0);
		//renderer.DrawLine(100, 450, 350, 50);
		//renderer.DrawLine(100, 450, 175, 525);
		//renderer.DrawLine(350, 50, 450, 50);
		//renderer.DrawLine(450, 50, 700, 450);
		//renderer.DrawLine(700, 450, 625, 525);
		//renderer.DrawLine(175, 525, 625, 525);
		////inside lines
		//renderer.DrawLine(175, 525, 350, 225);
		//renderer.DrawLine(350, 225, 435, 375);
		//renderer.DrawLine(350, 50, 538, 375);

		//renderer.DrawLine(325, 450, 700, 450);
		//renderer.DrawLine(362, 375, 538, 375);
		//renderer.DrawLine(395, 307, 325, 450);


		// show screen
		renderer.EndFrame();
	}
	
	

	return 0;
}