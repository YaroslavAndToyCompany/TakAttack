#include "UI/View.hpp"

View::View() {
    float viewWidth = 1920, viewHeight = 1080;
    sf::Vector2f viewCenter = sf::Vector2f(viewWidth / 2.0f, viewHeight / 2.0f);
    sf::Vector2f viewSize = sf::Vector2f(viewWidth, viewHeight);

    Setup(viewCenter, viewSize);
}

View::View(const sf::Vector2f& center, const sf::Vector2f& size) {
    Setup(center, size);
}

void View::ResizeView(const sf::Vector2u& windowSize)
{
    float windowAspectRatio = static_cast<float>(windowSize.x) / static_cast<float>(windowSize.y);
    float viewAspectRatio = m_size.x / m_size.y;

    float viewportWidth = 1.0f;
    float viewportHeight = 1.0f;
    float viewportX = 0.0f;
    float viewportY = 0.0f;

    if (windowAspectRatio > viewAspectRatio) 
    {
        viewportWidth = viewAspectRatio / windowAspectRatio;
        viewportX = (1.0f - viewportWidth) / 2.0f;
    }
    else 
    {
        viewportHeight = windowAspectRatio / viewAspectRatio;
        viewportY = (1.0f - viewportHeight) / 2.0f;
    }

    m_view.setViewport(sf::FloatRect(viewportX, viewportY, viewportWidth, viewportHeight));
}

void View::Setup(const sf::Vector2f& center, const sf::Vector2f& size)
{
    m_view = sf::View(center, size);
    m_center = center;
    m_size = size;
}
