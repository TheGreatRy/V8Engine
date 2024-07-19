#include "TheGame.h"
#include "Scene.h"
#include "Engine.h"
#include "Player.h"
#include "Enemy.h"
#include "GameData.h"

bool TheGame::Initialize()
{
    m_scene = new Scene();
    return true;
}

void TheGame::Shutdown()
{
}

void TheGame::Update(float dt)
{
    switch (m_state)
    {
    case eState::TITLE:
        if (m_engine->GetInput().GetKeyDown(SDL_SCANCODE_SPACE))
        {
            m_state = eState::START_GAME;
        }
        break;
    case eState::START_GAME:
        m_score = 0;
        m_state = eState::START_LEVEL;
        break;
    case eState::START_LEVEL:
    {
        Color color{ 1,1,1,0 };
        Model* model = new Model{ GameData::shipPoints, color };
        Transform transform{ {RENDERER.GetWidth() >> 1, RENDERER.GetHeight() >> 1}, 0, 5 };
        Player* player = new Player(200, transform, model);
        player->SetDamping(2.1f);
        player->SetTag("Player");
        m_scene->AddActor(player);
    }
    m_SpawnTime = 3;
    m_SpawnTimer = m_SpawnTimer;
        m_state = eState::GAME;
        break;
    case eState::GAME:
        m_SpawnTimer -= dt;
        if (m_SpawnTimer <= 0)
        {
            m_SpawnTime -= 0.2f;
            m_SpawnTimer = m_SpawnTime;

            Color color{ 1,1,1,0 };
            Transform enemyTransform{ {(rand() % 800), (rand() % 600)}, 0, randomf(0.1f,0.5f) };
            auto* enemyModel = new Model{ GameData::shipPoints, color };
            auto* enemy = new Enemy{ 2.0f, enemyTransform, enemyModel};
            enemy->SetDamping(2.0f);
            enemy->SetTag("Enemy");
            m_scene->AddActor(enemy);
        }
        break;
    case eState::PLAYER_DED:
        break;
    case eState::GAME_OVER:
        break;
    default:
        break;
    }
    m_scene->Update(dt);
}

void TheGame::Draw(Renderer& renderer)
{
    
    m_scene->Draw(renderer);
}
