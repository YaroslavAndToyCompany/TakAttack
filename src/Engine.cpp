#include "Engine.h"
#include "UI/DebugPanel.h"
#include "Managers/CursorManager.h"

Engine::Engine()
    : m_window("TakAttack", sf::Vector2u(1920, 1080))
{
    ResourceManager::Init();
    CursorManager::LoadCursors();

    DebugPanel::Init(m_window.GetView());

    m_map = std::make_unique<Map>("Map1");
    m_mainMenu = std::make_unique<MainMenu>(m_window);

    m_window.GetView().SetCenter(m_map->GetGlobalCenter());
    m_window.GetView().SetSize(m_map->GetSize());

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
    m_mainMenu->Update(*m_window.GetRenderWindowPtr());
    DebugPanel::SetString(std::to_string(m_window.GetView().GetSize().x));
}

void Engine::Render()
{
    m_window.BeginDraw();
    m_window.SwitchToGameView();

    m_map->Draw(*m_window.GetRenderWindowPtr());

    m_window.SwitchToUiView();

    m_mainMenu->Draw(*m_window.GetRenderWindowPtr());
    DebugPanel::Draw(*m_window.GetRenderWindowPtr());
    m_window.EndDraw();
}
