#include "Player.h"
#include "Bullet.h"
#include "Scene.h"
#include "Engine.h"
#include "TheGame.h"

void Player::OnCollision(Actor* actor)
{
	if (actor->GetTag() == "Enemy")
	{
		if ((INPUT.GetKeyDown(SDL_SCANCODE_F) && !INPUT.GetPrevKeyDown(SDL_SCANCODE_F)) ||
			(INPUT.GetKeyDown(SDL_SCANCODE_G) && !INPUT.GetPrevKeyDown(SDL_SCANCODE_G)) ||
			(INPUT.GetKeyDown(SDL_SCANCODE_H) && !INPUT.GetPrevKeyDown(SDL_SCANCODE_H)) ||
			(INPUT.GetKeyDown(SDL_SCANCODE_J) && !INPUT.GetPrevKeyDown(SDL_SCANCODE_J)) )
		{
			//m_destroy = true;
			m_scene->GetGame()->AddPoints(100);
		}
	}
	
}

void Player::Update(float dt)
{
	//Normal controls (EW!!!!!)
	/*
	float thrust = 0;
	Vector2 direction{ 0,0 };
	if (INPUT.GetKeyDown(SDL_SCANCODE_W)) direction.x = 1;
	if (INPUT.GetKeyDown(SDL_SCANCODE_S)) direction.x = -1;
	
	if (INPUT.GetKeyDown(SDL_SCANCODE_Q)) direction.y = -1;
	if (INPUT.GetKeyDown(SDL_SCANCODE_E)) direction.y = 1;

	if (INPUT.GetKeyDown(SDL_SCANCODE_A)) m_transform.rotation += Math::DegtToRad(100) * dt;
	if (INPUT.GetKeyDown(SDL_SCANCODE_D)) m_transform.rotation -= Math::DegtToRad(100) * dt;
	*/

	if (INPUT.GetKeyDown(SDL_SCANCODE_F) && !INPUT.GetPrevKeyDown(SDL_SCANCODE_F))
	{
		m_transform.position = { RENDERER.GetWidth() * 0.2f, RENDERER.GetHeight() * 0.8f };
		AUDIO.PlaySound("keypress.wav");
	}
	if (INPUT.GetKeyDown(SDL_SCANCODE_G) && !INPUT.GetPrevKeyDown(SDL_SCANCODE_G))
	{
		m_transform.position = { RENDERER.GetWidth() * 0.4f, RENDERER.GetHeight() * 0.8f };
		AUDIO.PlaySound("keypress.wav");
	}
	if (INPUT.GetKeyDown(SDL_SCANCODE_H) && !INPUT.GetPrevKeyDown(SDL_SCANCODE_H))
	{
		m_transform.position = { RENDERER.GetWidth() * 0.6f, RENDERER.GetHeight() * 0.8f };
		AUDIO.PlaySound("keypress.wav");
	}
	if (INPUT.GetKeyDown(SDL_SCANCODE_J) && !INPUT.GetPrevKeyDown(SDL_SCANCODE_J))
	{
		m_transform.position = { RENDERER.GetWidth() * 0.8f, RENDERER.GetHeight() * 0.8f };
		AUDIO.PlaySound("keypress.wav");
	}


	//Vector2 acceleration = direction.Rotate(m_transform.rotation) * m_speed;
	//m_velocity += acceleration * dt;

	//m_transform.position.x = Math::Wrap(m_transform.position.x, (float)RENDERER.GetWidth());
	//m_transform.position.y = Math::Wrap(m_transform.position.y, (float)RENDERER.GetHeight());

	//fire
	/*
	m_fireTimer -= dt;
	if (INPUT.GetKeyDown(SDL_SCANCODE_SPACE) && m_fireTimer <=0)
	{
		m_fireTimer = 0.2f * m_fireModifier;

		Vector2 direction = INPUT.GetMousePostision() - m_transform.position;
		float angle = direction.Angle();

		//actor
		Color color{ 1,1,0 };
		std::vector<Vector2> points;
		points.push_back(Vector2{ 5, 0 });
		points.push_back(Vector2{ -5 , -5 });
		points.push_back(Vector2{ -5 , 5 });
		points.push_back(Vector2{ 5 , 0 });

		Model* model = new Model{ points, color };
		Transform transform{ m_transform.position, angle, 1 };

		auto bullet = std::make_unique<Bullet>( 400.f, transform, model );
		bullet->SetLifespan( 1 );
		bullet->SetTag("Player");
		m_scene->AddActor(std::move(bullet));
	}*/

	Actor::Update(dt);
}
