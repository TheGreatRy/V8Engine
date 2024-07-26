#pragma once
#include "Game.h"
#include "Font.h"
#include "Text.h"
#include <memory>

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

	void OnPlayerDeath();
protected:
	eState m_state{ eState::TITLE };
	float m_bpm{ 0 };
	float m_stateTimer{ 0 };

	float m_spawnTimer{ 0 };
	float m_spawnTime{ 0 };
	

	Font* m_font{ nullptr };
	Font* m_titleFont{ nullptr };

	Text* m_title{ nullptr };
	Text* m_gameOver{ nullptr };

	Text* m_startText{ nullptr };
	Text* m_textScore{ nullptr };
	Text* m_textLives{ nullptr };
};
