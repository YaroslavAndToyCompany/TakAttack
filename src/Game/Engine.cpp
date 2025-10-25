#include "Game/Engine.hpp"
#include "Debug/Debug.hpp"
#include "Managers/CursorManager.hpp"

const unsigned int WINDOW_WIDTH = 1920;
const unsigned int WINDOW_HEIGHT = 1080;

Engine::Engine()
    : m_window("TakAttack", sf::Vector2u(WINDOW_WIDTH, WINDOW_HEIGHT))
{
    Debug::Init(m_resManager, m_curManager);

    m_map = std::make_unique<Map>(m_resManager, "Map1");
    m_mainMenu = std::make_unique<MainMenu>(m_window, m_resManager, m_curManager);

    m_window.GetGameView().SetCenter(m_map->GetGlobalCenter());
    m_window.GetGameView().SetSize(m_map->GetSize());

    // Temp CheckBox() (It was created for testing purposes)
    std::unique_ptr<IWidget> checkBox = std::make_unique<CheckBox>(m_resManager);
    Debug::GetInstance().AddWidget("Test", std::move(checkBox));

    std::unique_ptr<IWidget> checkBox2 = std::make_unique<CheckBox>(m_resManager);
    Debug::GetInstance().AddWidget("Tesasd", std::move(checkBox2));

    Entity::CreatePlayer(m_resManager, m_registry);
    Entity::CreateArtillery(m_resManager, m_registry);
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
        Debug::GetInstance().HandleEvents(event, *m_window.GetRenderWindowPtr());
        m_mainMenu.get()->HandleEvents(event, m_window);
    }
}

void Engine::Update()
{
    m_mainMenu->Update(*m_window.GetRenderWindowPtr());
    Debug::GetInstance().Update(*m_window.GetRenderWindowPtr());
}

void Engine::Render()
{
    m_window.BeginDraw();
    
    m_window.SwitchToGameView();
    
    m_map->Draw(*m_window.GetRenderWindowPtr());
    m_rendersystem.draw(m_registry, m_window);
    m_window.SwitchToUiView();

    m_mainMenu->Draw(*m_window.GetRenderWindowPtr());
    Debug::GetInstance().Draw(*m_window.GetRenderWindowPtr());
    m_curManager.Draw(*m_window.GetRenderWindowPtr());

    m_window.EndDraw();
}
