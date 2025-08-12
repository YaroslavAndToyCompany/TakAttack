#include "Engine.h"

Engine::Engine()
    : m_window("TakAttack", sf::Vector2u(800, 600))
{
    ResourceManager::Init();

    m_map = std::make_unique<Map>("Map1");
    m_mainMenu = std::make_unique<MainMenu>();

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
    m_map->Draw(*m_window.GetRenderWindowPtr());
    m_mainMenu->Draw(*m_window.GetRenderWindowPtr());
    m_window.EndDraw();
}

void Engine::LoadResources()
{   

}
