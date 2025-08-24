#pragma once

#include <SFML/Graphics.hpp>
#include "UI/View.hpp"

enum class Resolution {
    r1920x1080,
    r1280x720,
    r640x360
};

class Window {
public:
    Window();
    Window(const std::string& title, const sf::Vector2u& size);
    ~Window();

    void BeginDraw();
    void EndDraw();

    void Update();

    bool IsDone();
    bool IsFullscreen();
    sf::RenderWindow* GetRenderWindowPtr() { return &m_window; }
    sf::Vector2u GetWindowSize();
    View& GetView() { return m_gameView; }

    void SwitchToGameView() { m_window.setView(m_gameView.GetSfmlView()); }
    void SwitchToUiView() { m_window.setView(m_uiView.GetSfmlView()); }

    void ToggleFullscreen();

    void SetResolution(Resolution resType);

    void Draw(const sf::Drawable& drawable);

private:
    void Setup(const std::string& title, const sf::Vector2u& size);
    void Destroy();
    void Create();

    void MoveToCenter();
    void SetSize(const sf::Vector2u& newSize);

    sf::RenderWindow m_window;
    sf::Vector2u m_windowSize;
    std::string m_windowTitle;

    View m_gameView;
    View m_uiView;

    bool m_isDone;
    bool m_isFullscreen;
};