#include "Window.h"
#include "Utils/Screen.h"

Window::Window()
{
    Setup("Window", sf::Vector2u(640, 360));
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

void Window::Update()
{
    sf::Event event;
    while (m_window.pollEvent(event)) {
        switch (event.type)
        {
        case sf::Event::Closed:
            m_isDone = true;
            break;
        
        case sf::Event::Resized:
            m_view.ResizeView(m_window);
            break;

        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::F5)
                ToggleFullscreen();
            break;

        default:
            break;
        }
    }

    m_window.setView(m_view.GetSfmlView());
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
        m_window.setSize(sf::Vector2u(1920, 1080));
        m_view.ResizeView(m_window);
        break;
    
    default:
        break;
    }
}

void Window::Draw(const sf::Drawable& drawable)
{
    m_window.draw(drawable);
}

void Window::Setup(const std::string& title, const sf::Vector2u& size)
{
    m_windowTitle = title;
    m_windowSize = size;

    m_isFullscreen = false;
    m_isDone = false;

    Create();
    m_view = View(m_window); 
}

void Window::Destroy()
{
    m_window.close();
}

void Window::Create()
{
    ScreenInfo screen = GetPrimaryMonitorResoulution();

    auto style = (m_isFullscreen ? sf::Style::Fullscreen : sf::Style::Titlebar | sf::Style::Close);
    
    m_window.create({ m_windowSize.x, m_windowSize.y, 32 }, m_windowTitle, style);

    int x = screen.x + (screen.width - m_windowSize.x) / 2;
    int y = screen.y + (screen.height - m_windowSize.y) / 2;

    m_window.setPosition(sf::Vector2i(x, y));
}

