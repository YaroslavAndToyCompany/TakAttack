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

    bool IsDone();
    bool IsFullscreen();
    sf::RenderWindow* GetRenderWindowPtr() { return &m_window; }
    sf::Vector2u GetWindowSize();

    View& GetGameView() { return m_gameView; }
    View& GetUiView() { return m_uiView; }
    const View& GetGameView() const { return m_gameView; }
    const View& GetUiView() const { return m_uiView; }

    void SwitchToGameView() { m_window.setView(m_gameView.GetSfmlView()); }
    void SwitchToUiView() { m_window.setView(m_uiView.GetSfmlView()); }

    void ToggleFullscreen();
    void ToggleDone() { m_isDone = !m_isDone; }

    void SetResolution(Resolution resType);

    void Draw(const sf::Drawable& drawable);

    sf::Vector2f MapPixelToCoords(const sf::Vector2i& pixelPos, bool ui = false);

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