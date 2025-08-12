#include "Engine.h"

Engine::Engine()
    : m_window("TakAttack", sf::Vector2u(800, 600))
{
    ResourceManager::Init();

    m_map = std::make_unique<Map>("Map1");

    Entity::CreatePlayer(m_registry);
}

Engine::~Engine()
{
    ResourceManager::ReleaseResources();
}

void Engine::HandleInput()
{
    m_input.Input(m_registry);
}

void Engine::Update()
{
    m_window.Update();
    // ...
}

void Engine::Render()
{
    m_window.BeginDraw();
    m_window.Draw(m_map->GetSprite());
    m_window.EndDraw();
}

void Engine::LoadResources()
{   

}
