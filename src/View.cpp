#include "View.h"

View::View() {
    Setup(sf::Vector2f(320, 180), sf::Vector2f(640, 360));
}

View::View(const sf::Vector2f& center, const sf::Vector2f& size) {
    Setup(center, size);
}

View::View(const sf::RenderWindow & window)
{
    sf::Vector2f viewCenter = sf::Vector2f(window.getSize().x / 2.0f, window.getSize().y / 2.0f);

    Setup(viewCenter, static_cast<sf::Vector2f>(window.getSize()));
}

void View::ResizeView(const sf::RenderWindow & window)
{
    float aspectRatio = static_cast<float>(window.getSize().x) / static_cast<float>(window.getSize().y);
    m_view.setSize(320 * aspectRatio, 180 * aspectRatio);
}

void View::Setup(const sf::Vector2f& center, const sf::Vector2f& size)
{
    m_view = sf::View(center, size);
}
