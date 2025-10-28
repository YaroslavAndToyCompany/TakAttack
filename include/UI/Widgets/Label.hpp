#pragma once

#include <SFML/Graphics.hpp>
#include "Managers/ResourceManager.hpp"
#include "UI/Widgets/IWidget.hpp"

class Label : public IWidget 
{
public:
    Label(ResourceManager& resManager);

    void AddText(const std::string& text);
    void AddText(const int& number);

    template<typename T>
    void AddText(const sf::Vector2<T>& vec);

    void AlignTextToLeft();
    void AlignTextToCenter();

    sf::Vector2f GetPosition() override { return m_position; }
    sf::Vector2f GetSize() override;

    void SetFont(const std::string& fontName);
    void SetPosition(const sf::Vector2f& pos) override;
    void SetFillColor(const sf::Color& color) { m_text.setFillColor(color); }
    void SetCharacterSize(unsigned int size) { m_text.setCharacterSize(size); }

    void HandleEvents(sf::RenderWindow& window) override {}
    void Update(sf::RenderWindow& window) override {}
    void Draw(sf::RenderWindow& window) override { window.draw(m_text); }

private:
    sf::Text m_text;

    sf::Vector2f m_position;

    ResourceManager& m_resManager;
};

template<typename T>
void Label::AddText(const sf::Vector2<T>& vec)
{
    AddText(std::to_string(vec.x) + ", " + std::to_string(vec.y));
}