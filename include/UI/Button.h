#pragma once

#include <SFML/Graphics.hpp>

class Button {
public:
    Button(const std::string& textureName,
           const sf::Vector2f& pos = sf::Vector2f(0, 0),
           const std::string& btnText = "Button",
           const sf::Vector2f& scale = sf::Vector2f(1, 1),
           const sf::Color& textColor = sf::Color::Black,
           const std::string& fontName = "BoldPixels");

    void Draw(sf::RenderWindow& window);

    void SetText(const std::string& text) { m_text.setString(text); }
    void SetTextSize(unsigned int size) { m_text.setCharacterSize(size); }
    void SetTextColor(const sf::Color& color) { m_text.setFillColor(color); }
    void SetFont(const sf::Font& font) { m_text.setFont(font); }

    void SetScale(const sf::Vector2f& scale) { m_button.setScale(scale); }
    void SetPosition(const sf::Vector2f& pos) { m_button.setPosition(pos); }

private:
    sf::Vector2f m_position;

    sf::Sprite m_button;
    sf::Text m_text;
};