#pragma once
#include "Game.h"

class TheGame : public Game
{
public:
	enum class eState
	{
		TITLE,
		START_GAME,
		START_LEVEL,
		GAME,
		PLAYER_DED,
		GAME_OVER
	};
public:
	TheGame(Engine* engine) : Game{engine} {}
	bool Initialize() override;

	void Shutdown() override;

	void Update(float dt) override;

	void Draw(Renderer& renderer) override;
protected:
	eState m_state{ eState::TITLE };
	float m_SpawnTimer{ 0 };
	float m_SpawnTime{ 0 };
};
