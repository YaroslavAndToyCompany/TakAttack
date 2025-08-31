#include "UI/DebugPanel.hpp" 
#include "Managers/ResourceManager.hpp"
#include "Managers/CursorManager.hpp"
#include "Utils/Widgets.hpp"

#include <string>

sf::RectangleShape DebugPanel::m_panel;
sf::RectangleShape DebugPanel::m_bottomSide;

sf::Text DebugPanel::m_text;
CheckBox DebugPanel::m_checkBox;

bool DebugPanel::m_draw = false;

void DebugPanel::Init(View& view)
{
    m_text.setFont(*ResourceManager::GetResource<sf::Font>("BoldPixels"));

    sf::Vector2f viewCenter = view.GetCenter();

    m_panel.setFillColor(sf::Color::White);
    m_panel.setSize({200, 200});

    sf::FloatRect panelLocalBounds = m_panel.getLocalBounds();

    m_panel.setOrigin(SetRectOriginToCenter(panelLocalBounds));
    m_panel.move(panelLocalBounds.width / 2.0f, panelLocalBounds.height / 2.0f);

    m_bottomSide.setSize({180, 5});
    m_bottomSide.setFillColor(sf::Color::Black);
    m_bottomSide.setOrigin(SetRectOriginToCenter(m_bottomSide.getLocalBounds()));

    sf::FloatRect panelGlobalBounds = m_panel.getGlobalBounds();
    m_bottomSide.setPosition(panelGlobalBounds.left + (panelGlobalBounds.width / 2.0f), panelGlobalBounds.top + panelGlobalBounds.height);
    m_bottomSide.move(0, -m_bottomSide.getOrigin().y);
}

void DebugPanel::AddText(const std::string& text)
{
    m_text.setString(text);
    m_text.setCharacterSize(28);
    m_text.setFillColor(sf::Color::Black);
}

void DebugPanel::AddText(const int& number) 
{
    AddText(std::to_string(number));
}

void DebugPanel::OnMove() 
{
    sf::FloatRect panelGlobalBounds = m_panel.getGlobalBounds();
    float finalXCoord = panelGlobalBounds.left + (panelGlobalBounds.width / 2.0f);
    float finalYCoord = panelGlobalBounds.top + panelGlobalBounds.height - m_bottomSide.getOrigin().y;

    m_bottomSide.setPosition(finalXCoord, finalYCoord);
}

void DebugPanel::AddCheckBox(bool state, const std::string& text)
{
    m_checkBox = CheckBox(state, text);
    m_checkBox.SetPosition({ 50, 150 });
}

bool DebugPanel::IsMouseHover(sf::RenderWindow& window)
{
    if (m_draw) 
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        sf::Vector2f mousePosInCoords = window.mapPixelToCoords(mousePos);

        if (m_checkBox.GetCheckBoxGlobalBounds().contains(mousePosInCoords)) {
            return true;
        }
    }
    return false;
}

void DebugPanel::Update(sf::RenderWindow& window) 
{
    if (m_draw) 
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        sf::Vector2f mousePosInCoords = window.mapPixelToCoords(mousePos);

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) 
        {
            if (m_bottomSide.getGlobalBounds().contains(mousePosInCoords)) 
            {
                m_panel.setSize({m_panel.getSize().x, mousePosInCoords.y});
            }
            else if (m_panel.getGlobalBounds().contains(mousePosInCoords)) 
            {
                m_panel.setPosition(mousePosInCoords);
                OnMove();
            }

            if (m_checkBox.GetCheckBoxGlobalBounds().contains(mousePosInCoords)) 
            {
                std::cout << "yep" << std::endl;
            }
        }

        
    }
    
}

void DebugPanel::Draw(sf::RenderWindow& window)
{
    if (m_draw) 
    {
        window.draw(m_panel);
        window.draw(m_bottomSide);
        window.draw(m_text);
        m_checkBox.Draw(window);
    }
}
