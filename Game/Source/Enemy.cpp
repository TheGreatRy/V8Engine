#include "Enemy.h"
#include "Scene.h"
#include "Player.h"
#include "Pickup.h"
#include "Game.h"
#include "Engine.h"

void Enemy::OnCollision(Actor* actor)
{

	if (actor->GetTag() == "Player")
	{
		if (INPUT.GetKeyDown(SDL_SCANCODE_F) ||
			INPUT.GetKeyDown(SDL_SCANCODE_G) ||
			INPUT.GetKeyDown(SDL_SCANCODE_H) ||
			INPUT.GetKeyDown(SDL_SCANCODE_J))
		{
			
			m_destroy = true;
		}
	}
	else
	{
		m_destroy = true;
	}
}

void Enemy::Update(float dt)
{  
	
	Particle::Data data
	{
		m_transform.position,
		Vector2{1,0}.Rotate(randomf(Math::TwoPi)),
		randomf(0.1f, 5.0f),
		rand() % 256 ,
		rand() % 256 ,
		rand() % 256 ,
		0 

	};
	g_engine.GetPartSys().AddParticles(data);

	Pickup* missBox = m_scene->GetActor<Pickup>();
	if (missBox->GetTag() == "BBoxL" ||
		missBox->GetTag() == "BBoxML" ||
		missBox->GetTag() == "BBoxMR" ||
		missBox->GetTag() == "BBoxR")
	{
		Vector2 direction = missBox->GetTransform().position - m_transform.position;
		m_velocity += direction.Normalize() * m_speed * dt;
		m_transform.rotation = direction.Angle();
	}
	 
	g_engine.GetPartSys().Update(dt);
	
	Actor::Update(dt);
}
