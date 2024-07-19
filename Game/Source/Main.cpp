//#include "../../Engine/Source/Test.h"
#include "Engine.h"
#include "Player.h"
#include "Enemy.h"
#include "Scene.h";
#include "GameData.h"
#include "TheGame.h"

int main(int argc, char* argv[])
{
	g_engine.Initalize();
	TheGame* game = new TheGame(&g_engine);
	game->Initialize();
	while (!g_engine.IsQuit()) 
	{
		g_engine.Update();
		game->Update(g_engine.GetTime().GetDeltaTime());

		RENDERER.SetColor(0, 0, 0, 0);
		RENDERER.BeginFrame();

		game->Draw(RENDERER);

		RENDERER.EndFrame();
	}
	
	return 0;
}
//
//	//Variables/Systems
//	
//	float offset = 0;
//	//Creating a random shape
//	/*for (int i = 0; i < 100; i++)
//		{
//			points.push_back(Vector2{ rand() % 800, rand() % 600 });
//	}*/	
//	std::vector<Particle> particles;
//	//Random particle generator
//	/*for (int i = 0; i < 100; i++)
//	{
//		particles.push_back(Particle{ {rand() % 800, rand() % 600}, { randomf(0.1f,0.3f) , 0.0f} });
//	}*/
//	
//	//Sound Library
//	/*
//	AUDIO.AddSound("bass.wav");
//	AUDIO.AddSound("snare.wav");
//	AUDIO.AddSound("close-hat.wav");
//	*/
//	
//	Color color{ 1,1,1,0 };
//	
//	//Actor
//	Model* model = new Model{GameData::shipPoints, color};
//	Scene* scene = new Scene();
//
//	Transform transform{ {RENDERER.GetWidth() >> 1, RENDERER.GetHeight() >> 1}, 0, 5 };
//	Player* player = new Player(200, transform, model);
//	player->SetDamping(2.1f);
//	player->SetTag("Player");
//	scene->AddActor(player);
//
//	float spawnTimer = 2.0f;
//
//	//Random Player Generator
//	/*
//	for (int i = 0; i < 100; i++)
//	{
//		Transform randTransform{ {(rand() % 800), (rand() % 600)}, 0, randomf(0.1f,0.5f)};
//		Player* randPlayer = new Player(randomf(200,500), randTransform, model);
//		randPlayer->SetDamping(2.0f);
//		scene->AddActor(randPlayer);
//	}
//	*/
//
//	//Penrose Model
//	/*
//	std::vector<Vector2> penPoints;
//	penPoints.push_back(Vector2{ 0, 5});
//	penPoints.push_back(Vector2{ 1, 5});
//	penPoints.push_back(Vector2{ 5, -2});
//	penPoints.push_back(Vector2{ 4, -3});
//	penPoints.push_back(Vector2{ -3, -3});
//	penPoints.push_back(Vector2{ -4, -2});
//	penPoints.push_back(Vector2{ 0, 5 });
//	penPoints.push_back(Vector2{ 3, -1 });
//	penPoints.push_back(Vector2{ -1, -1 });
//	penPoints.push_back(Vector2{ 0.5f, 1.5f });
//	penPoints.push_back(Vector2{ 0, 3 });
//	penPoints.push_back(Vector2{ -3, -3 });
//	penPoints.push_back(Vector2{ 4, -3 });
//	penPoints.push_back(Vector2{ 5, -2 });
//	penPoints.push_back(Vector2{ -1.5f, -2.0f });
//	penPoints.push_back(Vector2{ 0.5f, 1.5f });
//	penPoints.push_back(Vector2{ 2, -1 });
//	penPoints.push_back(Vector2{ 3, -1 });
//	penPoints.push_back(Vector2{ 0, 5 });
//	
//	Model penroseTri{ penPoints, color };
//	Transform penTransform{ {RENDERER.GetWidth() / 4, RENDERER.GetHeight() / 4}, 0, 10};
//	*/
//	
//	
//	//main loop
//	while (!g_engine.IsQuit())
//	{
//		//INPUT
//		//INPUT.Update();
//		g_engine.Update();
//		
//		// UPDATE
//		spawnTimer -= g_engine.GetTime().GetDeltaTime();
//		/*if (spawnTimer <= 0)
//		{
//			Transform enemyTransform{ {(rand() % 800), (rand() % 600)}, 0, randomf(0.1f,0.5f) };
//			auto* enemyModel = new Model{ points, color };
//			auto* enemy = new Enemy{ 2.0f, enemyTransform, enemyModel};
//			enemy->SetDamping(2.0f);
//			enemy->SetTag("Enemy");
//			scene->AddActor(enemy);
//			spawnTimer = 2.0f;
//		}*/
//		
//		scene->Update(g_engine.GetTime().GetDeltaTime());
//		
//		//Mouse Tracking
//		Vector2 mousePosition = INPUT.GetMousePostision();
//		/*if (INPUT.GetMouseButtonDown(0) && !INPUT.GetPrevMouseButtonDown(0))
//		{
//			std::cout << "mouse pressed" << std::endl;
//			points.push_back(mousePosition);
//		}
//		if (INPUT.GetMouseButtonDown(0) && INPUT.GetPrevMouseButtonDown(0))
//		{
//			float distance = (points.back() - mousePosition).Length();
//			if (distance > 5) points.push_back(mousePosition);
//		}
//		if (INPUT.GetMouseButtonDown(0))
//		{
//			//std::cout << "mouse pressed" << std::endl;
//			for (int i = 0; i < 10; i++) {
//				particles.push_back(Particle{ mousePosition, randomOnUnitCirlce() * randomf(10,100), randomf(1.0f, 5.0f) });
//		
//			}
//		
//		}*/
//
//		//Audio Update and Button Tracking
//		/*AUDIO.Update();
//		if (INPUT.GetKeyDown(SDL_SCANCODE_Q) && !INPUT.GetPrevKeyDown(SDL_SCANCODE_Q))
//		{
//			AUDIO.PlaySound("bass.wav");
//		}
//		if (INPUT.GetKeyDown(SDL_SCANCODE_W) && !INPUT.GetPrevKeyDown(SDL_SCANCODE_W))
//		{
//			AUDIO.PlaySound("snare.wav");
//		}
//		if (INPUT.GetKeyDown(SDL_SCANCODE_E) && !INPUT.GetPrevKeyDown(SDL_SCANCODE_E))
//		{
//			AUDIO.PlaySound("close-hat.wav");
//		}
//		*/
//
//		//Particle Update
//		for (Particle& particle : particles)
//		{
//			particle.Update(0.1f);
//		
//			//if (particle.position.x > 800) particle.position.x = 0;
//			//if (particle.position.x < 0) particle.position.x = 800;
//		}
//		
//		//std::cout << mousePosition.x << ", " << mousePosition.y << std::endl;
//		/*Vector2 speed{0.5f, -0.5f};
//		for (Vector2& point : points)
//		{
//			point = point + speed;
//		}*/
//		
//		// Begin Render
//		RENDERER.SetColor(0, 0, 0, 0);
//		RENDERER.BeginFrame();
//		
//		
//		RENDERER.SetColor(255, 255, 255, 0);
//		
//		//Drawing Circles (Doesnt Work)
//		/*
//		float radius = 30.0f;
//		offset += (90 + g_engine.GetTime().GetDeltaTime());
//		for (float angle = 0; angle > 360; angle += 360 / 30)
//		{
//		
//			float x = Math::Cos(Math::DegtToRad(angle + offset)) * Math::Sin(offset) * radius;
//			float y = Math::Sin(Math::DegtToRad(angle + offset)) * Math::Sin(offset) * radius;
//		
//			RENDERER.DrawRect(800 + x, 300 + y, 4.0f, 4.0f);
//		}
//		*/
//
//		//DRAW
//		//Particle Effects
//		/*
//		for (Particle particle : particles)
//			{
//				particle.Draw(RENDERER);
//			}
//		*/
//		//Drawing Using Vectors
//		/*//RENDERER.DrawLine(v1.x, v1.y, v2.x, v2.y);
//			RENDERER.SetColor(255, 255, 255, 0);
//			for (int i = 0; points.size() > 1 && i < (points.size() - 1); i++)
//			{
//				RENDERER.SetColor(rand() % 256, rand() % 256, rand() % 256, 0); // create random color
//				RENDERER.DrawLine(points[i].x, points[i].y, points[i + 1].x , points[i + 1].y );
//			}*/
//		
//		//Random Line Generator
//		/*int value = rand() % 1000;
//			for (int i = 0; i <= value; i++)
//			{
//				//RENDERER.SetColor( 255, 255, 255, 0);
//				RENDERER.SetColor(rand() % 256, rand() % 256, rand() % 256, 0); // create random color
//				RENDERER.DrawPoint(400, 300);
//				// draw line
//				RENDERER.DrawLine(rand() % 800, rand() % 600, rand() % 800, rand() % 600);
//			}
//			*/
//		
//		// Geometric Shape
//		/*outside lines
//			RENDERER.SetColor(255, 255, 255, 0);
//			RENDERER.DrawLine(100, 450, 350, 50);
//			RENDERER.DrawLine(100, 450, 175, 525);
//			RENDERER.DrawLine(350, 50, 450, 50);
//			RENDERER.DrawLine(450, 50, 700, 450);
//			RENDERER.DrawLine(700, 450, 625, 525);
//			RENDERER.DrawLine(175, 525, 625, 525);
//			//inside lines
//			RENDERER.DrawLine(175, 525, 350, 225);
//			RENDERER.DrawLine(350, 225, 435, 375);
//			RENDERER.DrawLine(350, 50, 538, 375);
//			RENDERER.DrawLine(325, 450, 700, 450);
//			RENDERER.DrawLine(362, 375, 538, 375);
//			RENDERER.DrawLine(395, 307, 325, 450);
//			*/
//
//		scene->Draw(RENDERER);
//		//penroseTri.Draw(RENDERER, penTransform);
//
//		// show screen
//		RENDERER.EndFrame();
//	}
//	return 0;
//}