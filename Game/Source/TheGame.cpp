#include "TheGame.h"
#include "Scene.h"
#include "Engine.h"
#include "Player.h"
#include "Enemy.h"
#include "Pickup.h"
#include "GameData.h"

bool TheGame::Initialize()
{
    m_scene = new Scene(this);

    m_font = new Font();
    m_font->Load("ka1.ttf", 20);
    m_textScore = new Text(m_font);
    m_textLives = new Text(m_font);
    m_startText = new Text(m_font);

    m_titleFont = new Font();
    m_titleFont->Load("ka1.ttf", 56);
    m_title = new Text(m_titleFont);
    m_gameOver = new Text(m_titleFont);

    AUDIO.AddSound("keypress.wav");
    AUDIO.AddSound("miss.wav");
    AUDIO.AddSound("main.mp3");
    AUDIO.AddSound("game.mp3");
    AUDIO.AddSound("death.mp3");

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
        AUDIO.AddSound("main.mp3");
        AUDIO.PlaySound("main.mp3");
        if (m_engine->GetInput().GetKeyDown(SDL_SCANCODE_SPACE) && !m_engine->GetInput().GetPrevKeyDown(SDL_SCANCODE_SPACE))
        {
            AUDIO.StopSound("main.mp3");
            AUDIO.AddSound("game.mp3");
            m_state = eState::START_GAME;
        }
        break;
    case eState::START_GAME:
        m_score = 0;
        m_lives = 3;
        m_state = eState::START_LEVEL;
        break;
    case eState::START_LEVEL:
        AUDIO.PlaySound("game.mp3");
        m_scene->RemoveAll();
        {
            Color color{ 1,1,1,0 };
            Model* model = new Model{ GameData::shipPoints, color };
            Transform transform{ {RENDERER.GetWidth() * 0.2f, RENDERER.GetHeight() * 0.8f}, 0, 5 };
            auto player = std::make_unique <Player>(200, transform, model);
            player->SetDamping(1.0f);
            player->SetTag("Player");
            m_scene->AddActor(std::move(player));

            Color boxColor{ 0,1,1,0 };
            Model* boxModel = new Model{ GameData::shipPoints, boxColor };

            Transform boxTransformL{ {RENDERER.GetWidth() * 0.2f, RENDERER.GetHeight() * 0.9f}, 0, 5 };
            auto BBoxL = std::make_unique <Pickup>(boxTransformL, boxModel);
            BBoxL->SetTag("BBoxL");
            m_scene->AddActor(std::move(BBoxL));

            Transform boxTransformML{ {RENDERER.GetWidth() * 0.4f, RENDERER.GetHeight() * 0.9f}, 0, 5 };
            auto BBoxML = std::make_unique <Pickup>(boxTransformML, boxModel);
            BBoxML->SetTag("BBoxML");
            m_scene->AddActor(std::move(BBoxML));

            Transform boxTransformMR{ {RENDERER.GetWidth() * 0.6f, RENDERER.GetHeight() * 0.9f}, 0, 5 };
            auto BBoxMR = std::make_unique <Pickup>(boxTransformMR, boxModel);
            BBoxMR->SetTag("BBoxMR");
            m_scene->AddActor(std::move(BBoxMR));

            Transform boxTransformR{ {RENDERER.GetWidth() * 0.8f, RENDERER.GetHeight() * 0.9f}, 0, 5 };
            auto BBoxR = std::make_unique <Pickup>(boxTransformR, boxModel);
            BBoxR->SetTag("BBoxR");
            m_scene->AddActor(std::move(BBoxR));
        }
        
    m_bpm = 120;
    m_spawnTime = 3;
    m_spawnTimer = m_spawnTimer;
        m_state = eState::GAME;
        break;
    case eState::GAME:
        
        m_spawnTimer -= dt;
        if (m_spawnTimer <= 0)
        {
            m_spawnTime -= 0.2f;
            m_spawnTimer = m_spawnTime;

            //create enemy
            Color color{ 1,1,1,0 };
            Transform enemyTransform{ {(float)(rand() % 800), 0.1f}, 0, 3 };
            auto* enemyModel = new Model{ GameData::shipPoints, color };
            auto enemy = std::make_unique <Enemy>(400, enemyTransform, enemyModel);
            enemy->SetDamping(2.0f);
            enemy->SetTag("Enemy");
            m_scene->AddActor(std::move(enemy));
            
            
        }
        
        break;
    case eState::PLAYER_DED:
        AUDIO.StopSound("game.mp3");
        m_stateTimer -= dt;
        if (m_stateTimer <= 0)
        {
            AUDIO.AddSound("game.mp3");
            m_state = eState::START_LEVEL;
        }
        break;
    case eState::GAME_OVER:
        m_scene->RemoveAll();
        AUDIO.StopSound("game.mp3");
        AUDIO.PlaySound("death.mp3");
        if (m_engine->GetInput().GetKeyDown(SDL_SCANCODE_SPACE))
        {
            AUDIO.StopSound("death.mp3");
            AUDIO.AddSound("main.mp3");
            m_state = eState::TITLE;
        }
        break;
    default:
        break;
    }
    g_engine.GetPartSys().Update(dt);
    m_scene->Update(dt);
}

void TheGame::Draw(Renderer& renderer)
{
    std::string text = "";
    switch (m_state)
    {
    case TheGame::eState::TITLE:
        //draw text
        text = "To The Beat";

        m_title->Create(renderer, text, { .75f,0,.5f,1 });
        m_title->Draw(renderer, (renderer.GetWidth() / 2 ) - (56*4), (renderer.GetHeight() / 2) - 56);
        
        text = "Press Space To Start!";
        m_startText->Create(renderer, text, { .75f,0,.5f,1 });
        m_startText->Draw(renderer, (renderer.GetWidth()/3.3f ), (renderer.GetHeight()/1.8f) );

        break;
    case TheGame::eState::GAME_OVER:
        //draw text
        text = "GAME OVER";

        m_gameOver->Create(renderer, text, { 1,0,0,1 });
        m_gameOver->Draw(renderer, (renderer.GetWidth() / 2) - (56 * 4), (renderer.GetHeight() / 2) - 56);

        text = "Press Space To Try Again!";
        m_startText->Create(renderer, text, { 1,0,0,1 });
        m_startText->Draw(renderer, (renderer.GetWidth() / 4 ), (renderer.GetHeight() / 1.8f));
        break;
    case TheGame::eState::GAME:
        //draw text
        // //draw score
        text = "Score " + std::to_string(m_score);
        m_textScore->Create(renderer, text, { 0,1,0,1 });
        m_textScore->Draw(renderer, 20, 20);
        //draw lives
        text = "Lives " + std::to_string(m_lives);
        m_textLives->Create(renderer, text, { 0,1,0,1 });
        m_textLives->Draw(renderer, 20, 40);
        break;
    default:
        break;
    }
    
    g_engine.GetPartSys().Draw(renderer);
    m_scene->Draw(renderer);
}

void TheGame::OnPlayerDeath()
{
    m_lives--;
    m_state = (m_lives == 0) ? eState::GAME_OVER : eState::PLAYER_DED;
}
