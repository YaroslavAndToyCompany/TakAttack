#pragma once
#include <SFML/Graphics.hpp>

class View {
public:
    View();
    View(const sf::Vector2f& center, const sf::Vector2f& size);
    void ResizeView(const sf::Vector2u& windowSize);

    sf::View GetSfmlView() { return m_view; }
    sf::Vector2f GetCenter() { return m_center; }
    sf::Vector2f GetSize() { return m_size; }

    void SetCenter(const sf::Vector2f& center) { m_view.setCenter(center); m_center = center; } 
    void SetSize(const sf::Vector2f& size) { m_view.setSize(size); m_size = size; }
    void SetViewport(const sf::FloatRect& rect) { m_view.setViewport(rect); }

private:
    void Setup(const sf::Vector2f& center, const sf::Vector2f& size);

    sf::View m_view;

    sf::Vector2f m_center;
    sf::Vector2f m_size;
};