#include "UI/DebugPanel.hpp" 
#include "Managers/ResourceManager.hpp"
#include "Managers/CursorManager.hpp"

sf::Text DebugPanel::m_text;
sf::RectangleShape DebugPanel::m_panel;
bool DebugPanel::m_draw = false;
CheckBox DebugPanel::m_checkBox;

void DebugPanel::Init(View& view)
{
    m_text.setFont(*ResourceManager::GetResource<sf::Font>("BoldPixels"));

    sf::Vector2f viewCenter = view.GetSfmlView().getCenter();
    // m_text.setPosition(viewCenter); // TEMP

    m_panel.setPosition(viewCenter);
    m_panel.setFillColor(sf::Color::White);
    m_panel.setSize({80, 25});
}

void DebugPanel::SetString(const std::string& text)
{
    m_text.setString(text);
    m_text.setCharacterSize(28);
    m_text.setFillColor(sf::Color::Black);
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

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && m_checkBox.GetCheckBoxGlobalBounds().contains(mousePosInCoords)) 
        {
            std::cout << "yep" << std::endl;
        }
    }
    
}

void DebugPanel::Draw(sf::RenderWindow& window)
{
    if (m_draw) 
    {
        // window.draw(m_panel); TODO: Panel that appears and stretchis when there is a text
        window.draw(m_text);
        m_checkBox.Draw(window);
    }
}
