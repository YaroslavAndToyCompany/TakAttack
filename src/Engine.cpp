#include "Engine.h"

Engine::Engine()
    : m_window("TakAttack", sf::Vector2u(800, 600))
{ }

void Engine::HandleInput()
{
}

void Engine::Update()
{
    m_window.Update();
    // ...
}

void Engine::Render()
{
    m_window.BeginDraw();
    // ...
    m_window.EndDraw();
}
