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
    float aspectRatio = static_cast<float>(windowSize.x) / static_cast<float>(windowSize.y);
    m_view.setSize(m_size.x * aspectRatio, m_size.y * aspectRatio);
}

void View::Setup(const sf::Vector2f& center, const sf::Vector2f& size)
{
    m_view = sf::View(center, size);
    m_center = center;
    m_size = size;
}
