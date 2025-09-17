#include "UI/DebugPanel.hpp" 
#include "Managers/ResourceManager.hpp"
#include "Managers/CursorManager.hpp"
#include "Utils/Widgets.hpp"

#include <string>

sf::RectangleShape DebugPanel::m_panel;

std::array<sf::RectangleShape, static_cast<size_t>(DebugPanel::ResizeSideType::Count)> DebugPanel::m_resizeSides;

sf::Text DebugPanel::m_text;
CheckBox DebugPanel::m_checkBox;

bool DebugPanel::m_draw = false;

void DebugPanel::Init(View& view)
{
    m_text.setFont(*ResourceManager::GetResource<sf::Font>("BoldPixels"));

    int debugPanelLeftMargin = 20;
    int debugPanelTopMargin = 20;
    sf::Vector2f debugPanelSize = sf::Vector2f(200, 200);

    CreatePanel(debugPanelSize, debugPanelLeftMargin, debugPanelTopMargin);

    // Panel resize sides creaction
    const sf::Vector2f horizontalSize = { 180, 5 };
    const sf::Vector2f verticalSize = { 5, 180 };

    for (int i = 0; i < m_resizeSides.size(); i++) 
    {
        auto type = static_cast<ResizeSideType>(i);
        auto& side = m_resizeSides[i];

        sf::Vector2f size = (type == ResizeSideType::Top || type == ResizeSideType::Bottom) ? horizontalSize : verticalSize;
        CreateResizeHandlers(side, size, type);
    }
    for (int i = 0; i < m_resizeSides.size(); i++) 
    {
        UpdateResizeHandlers(m_resizeSides[i], static_cast<ResizeSideType>(i));
    }

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

    for (int i = 0; i < m_resizeSides.size(); i++) 
    {
        UpdateResizeHandlers(m_resizeSides[i], static_cast<ResizeSideType>(i));
    }

    DebugPanel::AddText(sf::Vector2f(panelGlobalBounds.left, panelGlobalBounds.top));
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
            if (m_panel.getGlobalBounds().contains(mousePosInCoords)) 
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
        for (auto& side : m_resizeSides) 
        {
            window.draw(side);
        }
        window.draw(m_text);
        m_checkBox.Draw(window);
    }
}

void DebugPanel::CreatePanel(const sf::Vector2f& size, int leftMargin, int topMargin) 
{
    m_panel.setFillColor(sf::Color::White);
    m_panel.setSize(size);

    sf::FloatRect panelLocalBounds = m_panel.getLocalBounds();

    m_panel.setOrigin(SetRectOriginToCenter(panelLocalBounds));
    m_panel.move(panelLocalBounds.width / 2.0f + leftMargin, panelLocalBounds.height / 2.0f + topMargin);
}

void DebugPanel::CreateResizeHandlers(sf::RectangleShape& side, const sf::Vector2f& size, ResizeSideType sideType) 
{
    side.setSize(size);
    side.setFillColor(sf::Color::Black);
    side.setOrigin(SetRectOriginToCenter(side.getLocalBounds()));
}

void DebugPanel::UpdateResizeHandlers(sf::RectangleShape& side, ResizeSideType sideType)
{
    float finalXCoord;
    float finalYCoord;

    sf::FloatRect panelGlobalBounds = m_panel.getGlobalBounds();
    if (sideType == ResizeSideType::Top) 
    {
        finalXCoord = panelGlobalBounds.left + (panelGlobalBounds.width / 2.0f);
        finalYCoord = panelGlobalBounds.top + side.getOrigin().y;
    }
    else if (sideType == ResizeSideType::Bottom)
    {
        finalXCoord = panelGlobalBounds.left + (panelGlobalBounds.width / 2.0f);
        finalYCoord = panelGlobalBounds.top + panelGlobalBounds.height - side.getOrigin().y;
    }
    else if (sideType == ResizeSideType::Left) 
    {
        finalXCoord = panelGlobalBounds.left + side.getOrigin().x;
        finalYCoord = panelGlobalBounds.top + (panelGlobalBounds.height / 2.0f);
    }
    else if (sideType == ResizeSideType::Right)
    {
        finalXCoord = panelGlobalBounds.left + panelGlobalBounds.width - side.getOrigin().x;
        finalYCoord = panelGlobalBounds.top + (panelGlobalBounds.height / 2.0f);
    }

    side.setPosition(finalXCoord, finalYCoord);
}