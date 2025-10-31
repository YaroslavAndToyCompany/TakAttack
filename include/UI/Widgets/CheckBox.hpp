#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Managers/ResourceManager.hpp"
#include "UI/Widgets/IWidget.hpp"
#include "UI/Widgets/Label.hpp"
#include "UI/Elements/Circle.hpp"

class CheckBox : public IWidget
{
public:
    CheckBox(ResourceManager& resManager, bool state = false, const std::string& text = "Text");
    void AlignTo(Alignment alignment) override;

    bool GetChecked() { return m_isChecked; }
    sf::FloatRect GetCheckBoxGlobalBounds() { return m_outerBox.getGlobalBounds(); };
    sf::Vector2f GetPosition() override { return m_position; }
    sf::Vector2f GetSize() override { return m_outerBox.getSize(); }
    sf::FloatRect GetGlobalBounds() override { return m_outerBox.getGlobalBounds(); }

    void SetOriginOuter(const sf::Vector2f& pos);
    void SetOriginInner(const sf::Vector2f& pos);
    void SetPosition(const sf::Vector2f& pos) override;
    void ToggleChecked() { m_isChecked = !m_isChecked; }
    void ToggleDisplayBorders() { m_isDisplayBordersSet = !m_isDisplayBordersSet; }

	void HandleEvents(const sf::Event& event, sf::RenderWindow& window) override;
	void Update(sf::RenderWindow& window) override;
    void Draw(sf::RenderWindow& window) override;

    const float CHECKBOX_SIZE = 30;

private:
    Label m_label;

    sf::RectangleShape m_outerBox;
    sf::RectangleShape m_innerBox;

    sf::Vector2f m_position;
    Alignment m_alignment;

    Circle m_outerOriginPoint;
    Circle m_innerOriginPoint;
    bool m_isDisplayBordersSet;

    bool m_isChecked;
};
