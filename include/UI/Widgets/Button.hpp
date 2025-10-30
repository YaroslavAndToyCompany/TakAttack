#pragma once

#include <SFML/Graphics.hpp>
#include <functional>
#include "Managers/ResourceManager.hpp"
#include "Managers/CursorManager.hpp"
#include "UI/Widgets/Label.hpp"
#include "UI/Widgets/IWidget.hpp"
#include "Utils/Utils.hpp"

class Button : public IWidget
{
public:
    Button(ResourceManager& resManager);

    void ChangeCursor(sf::RenderWindow& window, CursorManager& curManager, CursorType curType = CursorType::Hand);
    
    sf::Vector2f GetPosition() { return m_position; }

    virtual sf::Vector2f GetSize() = 0;
    virtual sf::FloatRect GetGlobalBounds() = 0;

    bool GetIsClicked() { return m_isClicked; }
    
    void SetText(const std::string& text) { m_label.AddText(text); }
    void SetTextSize(unsigned int size) { m_label.SetCharacterSize(size); }
    void SetTextColor(const sf::Color& color) { m_label.SetFillColor(color); }
    void SetFont(const std::string& name) { m_label.SetFont(name); }
    
    virtual void SetPosition(const sf::Vector2f& pos) = 0;
    
    void HandleEvents(const sf::Event& event, sf::RenderWindow& window);
    void Update(sf::RenderWindow& window);
    virtual void Draw(sf::RenderWindow& window) = 0;

protected:
    void TransformText();

    ResourceManager& m_resManager;
    Label m_label;
    sf::Vector2f m_position;
    bool m_isClicked;
};