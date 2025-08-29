#include "Game/Window.hpp"
#include "Utils/Screen.hpp"

Window::Window()
{
    Setup("Window", sf::Vector2u(1920, 1080));
}

Window::Window(const std::string& title, const sf::Vector2u& size)
{
    Setup(title, size);
}

Window::~Window()
{
    Destroy();
}

void Window::BeginDraw()
{
    m_window.clear(sf::Color::Black);
}

void Window::EndDraw()
{
    m_window.display();
}


bool Window::IsDone()
{
    return m_isDone;
}

bool Window::IsFullscreen()
{
    return m_isFullscreen;
}

sf::Vector2u Window::GetWindowSize()
{
    return m_windowSize;
}

void Window::ToggleFullscreen()
{
    m_isFullscreen = !m_isFullscreen;
    Destroy();
    Create();
}

void Window::SetResolution(Resolution resType)
{
    switch (resType)
    {
    case Resolution::r1920x1080:
        SetSize({1920, 1080});
        break;
    
    default:
        break;
    }
}

void Window::Draw(const sf::Drawable& drawable)
{
    m_window.draw(drawable);
}

sf::Vector2f Window::MapPixelToCoords(const sf::Vector2i& pixelPos, bool ui)
{
    return m_window.mapPixelToCoords(pixelPos, ui ? m_uiView.GetSfmlView() : m_gameView.GetSfmlView());
}


void Window::Setup(const std::string& title, const sf::Vector2u& size)
{
    m_windowTitle = title;
    m_windowSize = size;

    m_isFullscreen = false;
    m_isDone = false;

    m_gameView = View();
    m_uiView = View();

    Create();
}

void Window::Destroy()
{
    m_window.close();
}

void Window::Create()
{
    auto style = (m_isFullscreen ? sf::Style::Fullscreen : sf::Style::Default);
    
    m_window.create({ m_windowSize.x, m_windowSize.y, 32 }, m_windowTitle, style);

    MoveToCenter();   
}

void Window::MoveToCenter()
{
    utils::ScreenInfo screen = utils::GetPrimaryMonitorResoulution();

    int x = screen.x + (screen.width - m_windowSize.x) / 2;
    int y = screen.y + (screen.height - m_windowSize.y) / 2;

    m_window.setPosition(sf::Vector2i(x, y));
}

void Window::SetSize(const sf::Vector2u& newSize)
{
    m_windowSize = newSize;

    m_window.setSize(newSize);
    m_gameView.ResizeView(m_windowSize);

    MoveToCenter();
}

