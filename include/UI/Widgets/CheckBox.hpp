#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Managers/ResourceManager.hpp"
#include "UI/Widgets/Widget.hpp"

class CheckBox : public Widget
{
public:
    CheckBox(ResourceManager& resManager, bool state = false, const std::string& text = "Text");

    bool GetChecked() { return m_isChecked; }
    sf::FloatRect GetCheckBoxGlobalBounds() { return m_outerBox.getGlobalBounds(); };

    void SetPosition(const sf::Vector2f& pos);
    void ToggleChecked() { m_isChecked = !m_isChecked; }

	void HandleEvents(sf::RenderWindow& window) override;
	void Update(sf::RenderWindow& window) override;
    void Draw(sf::RenderWindow& window) override;

private:
    sf::Text m_text;

    sf::RectangleShape m_outerBox;
    sf::RectangleShape m_innerBox;

    sf::Vector2f m_position;
    bool m_isChecked;
};
