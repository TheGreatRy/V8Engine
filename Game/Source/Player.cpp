#include "Player.h"
#include "Engine.h"

void Player::Update(float dt)
{
	float thrust = 0;
	if (INPUT.GetKeyDown(SDL_SCANCODE_LEFT)) m_transform.rotation += Math::DegtToRad(100) * dt;
	if (INPUT.GetKeyDown(SDL_SCANCODE_RIGHT)) m_transform.rotation -= Math::DegtToRad(100) * dt;

	if (INPUT.GetKeyDown(SDL_SCANCODE_UP)) thrust = m_speed;
	if (INPUT.GetKeyDown(SDL_SCANCODE_DOWN)) thrust = -m_speed;

	m_velocity = Vector2{ thrust, 0.0f }.Rotate(m_transform.rotation);
	
	m_transform.position.x = Math::Wrap(m_transform.position.x, (float)RENDERER.GetWidth());
	m_transform.position.y = Math::Wrap(m_transform.position.y, (float)RENDERER.GetHeight());

	Actor::Update(dt);
}
