#include "Actor.h"
#include "Model.h"

void Actor::Update(float dt)
{
	if (m_lifespan != 0)
	{
		m_lifespan -= dt;
		if (m_lifespan <= 0)
		{
			m_destroy = true;
		}
	}
	m_transform.position += (m_velocity * dt);
	m_velocity *= 1.0f / (1.0f + m_damping * dt);
}

void Actor::Draw(Renderer& renderer)
{
	if (m_model)
	{
		m_model->Draw(renderer, m_transform);
	}
}

void Actor::OnCollision(Actor* actor)
{
}
