#pragma once
#include <SFML/Graphics.hpp>

class View {
public:
    View();
    View(const sf::Vector2f& center, const sf::Vector2f& size);
    View(const sf::RenderWindow& window);
    void ResizeView(const sf::RenderWindow& window);

    sf::View GetSfmlView() { return m_view; }

private:
    void Setup(const sf::Vector2f& center, const sf::Vector2f& size);

    sf::View m_view;
};