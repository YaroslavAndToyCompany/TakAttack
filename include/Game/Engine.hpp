#pragma once

#include <memory>

#include "Game/Window.hpp"
#include "Systems/InputSystem.hpp"
#include "Entities/Entity.hpp"
#include "Game/Map.hpp"
#include "Managers/ResourceManager.hpp"
#include "UI/MainMenu.hpp"

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

    sf::Sprite m_cursor; // TEMP
};