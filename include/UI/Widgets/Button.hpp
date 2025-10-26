#pragma once

#include <SFML/Graphics.hpp>
#include <functional>
#include "Managers/ResourceManager.hpp"
#include "Managers/CursorManager.hpp"
#include "UI/Widgets/Label.hpp"
#include "UI/Widgets/IWidget.hpp"

class Button : public IWidget
{
public:
    Button(ResourceManager& resManager, const std::string& textureName);
    Button(ResourceManager& resManager, const sf::Vector2f& size);

    void ChangeCursor(sf::RenderWindow& window, CursorManager& curManager, CursorType curType = CursorType::Hand);
    
    sf::Sprite GetSprite() const;
    sf::Vector2f GetPosition() { return m_position; }
    
    void SetText(const std::string& text) { m_label.AddText(text); TransformText(); }
    void SetTextSize(unsigned int size) { m_label.SetCharacterSize(size); TransformText(); }
    void SetTextColor(const sf::Color& color) { m_label.SetFillColor(color); }
    void SetFont(const std::string& name) { m_label.SetFont(name); }
    
    void SetScale(const sf::Vector2f& scale) { m_buttonSpr.setScale(scale); TransformText(); }
    void SetPosition(const sf::Vector2f& pos);
    
    void HandleEvents(sf::RenderWindow& window) {}
    void Update(sf::RenderWindow& window) {}
    void Draw(sf::RenderWindow& window);

private:
    void TransformText();

    ResourceManager& m_resManager;
    
    Label m_label;

    sf::Sprite m_buttonSpr;
    sf::RectangleShape m_buttonDefault;
    sf::Vector2f m_position;

    bool m_isButtonDefault;
};