#include "Game/Engine.hpp"
#include "UI/DebugPanel.hpp"
#include "Managers/CursorManager.hpp"

const unsigned int WINDOW_WIDTH = 1920;
const unsigned int WINDOW_HEIGHT = 1080;

Engine::Engine()
    : m_window("TakAttack", sf::Vector2u(WINDOW_WIDTH, WINDOW_HEIGHT))
{
    ResourceManager::Init();
    CursorManager::LoadCursors();
    DebugPanel::Init(m_window.GetUiView());


    m_map = std::make_unique<Map>("Map1");
    m_mainMenu = std::make_unique<MainMenu>(m_window);

    m_window.GetGameView().SetCenter(m_map->GetGlobalCenter());
    m_window.GetGameView().SetSize(m_map->GetSize());
    DebugPanel::AddCheckBox();
   
    Entity::CreatePlayer(m_registry);
    Entity::CreateArtillery(m_registry);
}

Engine::~Engine()
{
}

void Engine::HandleInput()
{
    m_input.Input(m_registry, m_window, *m_map);
}

void Engine::ProcessEvents() {
    sf::Event event;
    while (m_window.GetRenderWindowPtr()->pollEvent(event)) {
        m_window.HandleEvents(event);
        DebugPanel::HandleEvents(event, *m_window.GetRenderWindowPtr());
    }
}

void Engine::Update()
{
    m_mainMenu->Update(*m_window.GetRenderWindowPtr());
    DebugPanel::Update(*m_window.GetRenderWindowPtr());
}

void Engine::Render()
{
    m_window.BeginDraw();
    
    m_window.SwitchToGameView();
    
    m_map->Draw(*m_window.GetRenderWindowPtr());
    m_rendersystem.draw(m_registry, m_window);
    m_window.SwitchToUiView();

    m_mainMenu->Draw(*m_window.GetRenderWindowPtr());
    DebugPanel::Draw(*m_window.GetRenderWindowPtr());

    m_window.EndDraw();
}
