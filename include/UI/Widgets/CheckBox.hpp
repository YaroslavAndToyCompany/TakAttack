#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Managers/ResourceManager.hpp"
#include "UI/Widgets/IWidget.hpp"
#include "UI/Widgets/Label.hpp"

class CheckBox : public IWidget
{
public:
    CheckBox(ResourceManager& resManager, bool state = false, const std::string& text = "Text");

    bool GetChecked() { return m_isChecked; }
    sf::FloatRect GetCheckBoxGlobalBounds() { return m_outerBox.getGlobalBounds(); };
    sf::Vector2f GetPosition() override { return m_position; }
    sf::Vector2f GetSize() override { return m_outerBox.getSize(); }

    void SetPosition(const sf::Vector2f& pos) override;
    void ToggleChecked() { m_isChecked = !m_isChecked; }

	void HandleEvents(sf::RenderWindow& window) override;
	void Update(sf::RenderWindow& window) override;
    void Draw(sf::RenderWindow& window) override;

    const float CHECKBOX_SIZE = 30;

private:
    Label m_label;

    sf::RectangleShape m_outerBox;
    sf::RectangleShape m_innerBox;

    sf::Vector2f m_position;
    bool m_isChecked;
};
