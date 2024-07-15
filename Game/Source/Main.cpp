//#include "../../Engine/Source/Test.h"
#include "Engine.h"
#include "Player.h"
#include "Scene.h";

int main(int argc, char* argv[])
{
	g_engine.Initalize();

	//Variables/Systems
	
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
	//Test to see if audio system is working
	/*audio.createSound("test.wav", FMOD_DEFAULT, 0, &sound);

	audio.playSound(sound, 0, false, nullptr);*/

	//Sound Library
	AUDIO.AddSound("bass.wav");
	AUDIO.AddSound("snare.wav");
	AUDIO.AddSound("close-hat.wav");

	
	Color color{ 1,1,1,0 };
	//Ship Model
	std::vector<Vector2> points;
	points.push_back(Vector2{ 5, 0 });
	points.push_back(Vector2{ -5 , -5 });
	points.push_back(Vector2{ -5 , 5 });
	points.push_back(Vector2{ 5 , 0 });

	//Actor
	Model* model = new Model{points, color};
	Transform transform{ {RENDERER.GetWidth() >> 1, RENDERER.GetHeight() >> 1}, 0, 5 };
	Player* player = new Player(200, transform, model);
	player->SetDamping(2.1f);
	Scene* scene = new Scene();
	scene->AddActor(player);

	for (int i = 0; i < 10; i++)
	{

	Transform transform{ {randomf(rand() % 800), randomf(rand() % 600)}, 0, randomf(1,5)};
	Player* player = new Player(randomf(100,200), transform, model);
	player->SetDamping(2.1f);
		scene->AddActor(player);
	}

	//Penrose Mode
	/*
	std::vector<Vector2> penPoints;
	penPoints.push_back(Vector2{ 0, 5});
	penPoints.push_back(Vector2{ 1, 5});
	penPoints.push_back(Vector2{ 5, -2});
	penPoints.push_back(Vector2{ 4, -3});
	penPoints.push_back(Vector2{ -3, -3});
	penPoints.push_back(Vector2{ -4, -2});
	penPoints.push_back(Vector2{ 0, 5 });
	penPoints.push_back(Vector2{ 3, -1 });
	penPoints.push_back(Vector2{ -1, -1 });
	penPoints.push_back(Vector2{ 0.5f, 1.5f });
	penPoints.push_back(Vector2{ 0, 3 });
	penPoints.push_back(Vector2{ -3, -3 });
	penPoints.push_back(Vector2{ 4, -3 });
	penPoints.push_back(Vector2{ 5, -2 });
	penPoints.push_back(Vector2{ -1.5f, -2.0f });
	penPoints.push_back(Vector2{ 0.5f, 1.5f });
	penPoints.push_back(Vector2{ 2, -1 });
	penPoints.push_back(Vector2{ 3, -1 });
	penPoints.push_back(Vector2{ 0, 5 });
	
	Model penroseTri{ penPoints, color };
	Transform penTransform{ {RENDERER.GetWidth() / 4, RENDERER.GetHeight() / 4}, 0, 10};
	*/
	
	bool quit = false;
	//main loop
	while (!quit)
	{
		time.Tick();
		//std::cout << time.GetTime() << std::endl;
		//std::cout << time.GetDeltaTime() << std::endl;
		
		//INPUT
		INPUT.Update();
		
		if (INPUT.GetKeyDown(SDL_SCANCODE_ESCAPE))
		{
			quit = true;
		}
		//transform.rotation = velocity.Angle();

		
		// UPDATE
		
		scene->Update(time.GetDeltaTime());
		
		//Mouse Tracking
		Vector2 mousePosition = INPUT.GetMousePostision();
		/*if (INPUT.GetMouseButtonDown(0) && !INPUT.GetPrevMouseButtonDown(0))
		{
			std::cout << "mouse pressed" << std::endl;
			points.push_back(mousePosition);
		}
		if (INPUT.GetMouseButtonDown(0) && INPUT.GetPrevMouseButtonDown(0))
		{
			float distance = (points.back() - mousePosition).Length();
			if (distance > 5) points.push_back(mousePosition);
		}
		if (INPUT.GetMouseButtonDown(0))
		{
			//std::cout << "mouse pressed" << std::endl;
			for (int i = 0; i < 10; i++) {
				particles.push_back(Particle{ mousePosition, randomOnUnitCirlce() * randomf(10,100), randomf(1.0f, 5.0f) });
		
			}
		
		}*/

		//Audio Update and Button Tracking
		AUDIO.Update();
		if (INPUT.GetKeyDown(SDL_SCANCODE_Q) && !INPUT.GetPrevKeyDown(SDL_SCANCODE_Q))
		{
			AUDIO.PlaySound("bass.wav");
		}
		if (INPUT.GetKeyDown(SDL_SCANCODE_W) && !INPUT.GetPrevKeyDown(SDL_SCANCODE_W))
		{
			AUDIO.PlaySound("snare.wav");
		}
		if (INPUT.GetKeyDown(SDL_SCANCODE_E) && !INPUT.GetPrevKeyDown(SDL_SCANCODE_E))
		{
			AUDIO.PlaySound("close-hat.wav");
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
		RENDERER.SetColor(0, 0, 0, 0);
		RENDERER.BeginFrame();
		
		
		RENDERER.SetColor(255, 255, 255, 0);
		
		float radius = 30.0f;
		offset += (90 + time.GetDeltaTime());
		for (float angle = 0; angle > 360; angle += 360 / 30)
		{
		
			float x = Math::Cos(Math::DegtToRad(angle + offset)) * Math::Sin(offset) * radius;
			float y = Math::Sin(Math::DegtToRad(angle + offset)) * Math::Sin(offset) * radius;
		
			RENDERER.DrawRect(800 + x, 300 + y, 4.0f, 4.0f);
		}
		
		//DRAW
		//Particle Effects
		/*
		for (Particle particle : particles)
			{
				particle.Draw(RENDERER);
			}
		*/
		//Drawing Using Vectors
		/*//RENDERER.DrawLine(v1.x, v1.y, v2.x, v2.y);
			RENDERER.SetColor(255, 255, 255, 0);
			for (int i = 0; points.size() > 1 && i < (points.size() - 1); i++)
			{
				RENDERER.SetColor(rand() % 256, rand() % 256, rand() % 256, 0); // create random color
				RENDERER.DrawLine(points[i].x, points[i].y, points[i + 1].x , points[i + 1].y );
			}*/
		
		//Random Line Generator
		/*int value = rand() % 1000;
			for (int i = 0; i <= value; i++)
			{
				//RENDERER.SetColor( 255, 255, 255, 0);
				RENDERER.SetColor(rand() % 256, rand() % 256, rand() % 256, 0); // create random color
				RENDERER.DrawPoint(400, 300);
				// draw line
				RENDERER.DrawLine(rand() % 800, rand() % 600, rand() % 800, rand() % 600);
			}
			*/
		
		// Geometric Shape
		/*outside lines
			RENDERER.SetColor(255, 255, 255, 0);
			RENDERER.DrawLine(100, 450, 350, 50);
			RENDERER.DrawLine(100, 450, 175, 525);
			RENDERER.DrawLine(350, 50, 450, 50);
			RENDERER.DrawLine(450, 50, 700, 450);
			RENDERER.DrawLine(700, 450, 625, 525);
			RENDERER.DrawLine(175, 525, 625, 525);
			//inside lines
			RENDERER.DrawLine(175, 525, 350, 225);
			RENDERER.DrawLine(350, 225, 435, 375);
			RENDERER.DrawLine(350, 50, 538, 375);
			RENDERER.DrawLine(325, 450, 700, 450);
			RENDERER.DrawLine(362, 375, 538, 375);
			RENDERER.DrawLine(395, 307, 325, 450);
			*/

		scene->Draw(RENDERER);
		//penroseTri.Draw(RENDERER, penTransform);

		// show screen
		RENDERER.EndFrame();
	}
	return 0;
}