#include "Pickup.h"
#include "Enemy.h"
#include "Engine.h"
#include "TheGame.h"
#include "Scene.h"

void Pickup::OnCollision(Actor* actor)
{
	if (actor->GetTag() == "Enemy")
	{
		AUDIO.PlaySound("miss.wav");
		dynamic_cast<TheGame*>(m_scene->GetGame())->OnPlayerDeath();
		//dynamic_cast<Player*>(actor)->SetFireModifier(0.5f);
		//m_destroy = true;
	}
}
