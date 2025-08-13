#pragma once

#include <memory>

#include "Window.h"
#include "InputSystem.h"
#include "Entity.h"
#include "Map.h"
#include "ResourceManager.h"
#include "UI/MainMenu.h"

class Engine {
public:
    Engine();
    ~Engine();

    void HandleInput();
    void Update(); // Update function for logic staff
    void Render(); // Render for drawing things to the screen
    Window* GetWindowPtr() { return &m_window; }

private:
    Window m_window;
    InputSystem m_input;
    entt::registry m_registry;

    std::unique_ptr<Map> m_map;
    std::unique_ptr<MainMenu> m_mainMenu;
};