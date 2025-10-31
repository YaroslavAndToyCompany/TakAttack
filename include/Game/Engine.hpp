#pragma once

#include <memory>

#include "Game/Window.hpp"
#include "Systems/InputSystem.hpp"
#include "Entities/Entity.hpp"
#include "Game/Map.hpp"
#include "Managers/CursorManager.hpp"
#include "Managers/EventManager.hpp"
#include "Managers/ResourceManager.hpp"
#include "UI/MainMenu.hpp"
#include "UI/Widgets/CheckBox.hpp"
#include "Systems/RenderSystem.hpp"
#include "Systems/UISystem.hpp"

class Engine {
public:
    Engine();
    ~Engine();

    void HandleInput();
    void ProcessEvents();
    void Update(); // Update function for logic staff
    void Render(); // Render for drawing things to the screen
    
    Window* GetWindowPtr() { return &m_window; }

private:
    ResourceManager m_resManager;
	CursorManager m_curManager;
    EventManager m_eventManager;

    Window m_window;
    InputSystem m_input;
    entt::registry m_registry;
    
    RenderSystem m_rendersystem;
    std::unique_ptr<Map> m_map;
    std::unique_ptr<MainMenu> m_mainMenu;
};
