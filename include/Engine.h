#pragma once

#include "Window.h"
#include "InputSystem.h"
#include "Entity.h"
#include "Map.h"
#include "ResourceManager.h"

class Engine {
public:
    Engine();
    ~Engine();

    void HandleInput();
    void Update(); // Update function for logic staff
    void Render(); // Render for drawing things to the screen
    Window* GetWindowPtr() { return &m_window; }

private:
    void UploadResources();

    Window m_window;
    InputSystem m_input;
    entt::registry m_registry;

    Map m_map;
};