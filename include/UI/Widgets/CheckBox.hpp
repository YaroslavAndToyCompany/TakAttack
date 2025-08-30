#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class CheckBox
{
public:
    CheckBox(bool state = false, const std::string& text = "Text");

    bool GetChecked() { return m_isChecked; }
    sf::FloatRect GetCheckBoxGlobalBounds() { return m_outerBox.getGlobalBounds(); };

    void SetPosition(const sf::Vector2f& pos);
    void ToggleChecked() { m_isChecked = !m_isChecked; }

    void Draw(sf::RenderWindow& window);

private:
    sf::Text m_text;

    sf::RectangleShape m_outerBox;
    sf::RectangleShape m_innerBox;

    sf::Vector2f m_position;
    bool m_isChecked;
};