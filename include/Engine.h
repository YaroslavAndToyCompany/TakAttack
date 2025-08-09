#pragma once

#include "Window.h"

class Engine {
public:
    Engine();
    ~Engine() { }

    void HandleInput();
    void Update(); // Update function for logic staff
    void Render(); // Render for drawing things to the screen
    Window* GetWindowPtr() { return &m_window; }

private:
    Window m_window;
};