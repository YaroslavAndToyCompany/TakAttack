#include "Debug/Debug.hpp" 
#include "Managers/CursorManager.hpp"
#include "Utils/Widgets.hpp"
#include "Utils/Utils.hpp"

#include <string>

std::unique_ptr<Debug> Debug::s_instance = nullptr;
bool Debug::s_isInitialized = false;

Debug::Debug(ResourceManager& resourceManager)
{
    m_text.setFont(*resourceManager.GetResource<sf::Font>("BoldPixels"));

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

void Debug::Init(ResourceManager& resourceManager)
{
    if (s_isInitialized)
        return;

    s_instance.reset(new Debug(resourceManager));
    s_isInitialized = true;
}

Debug& Debug::GetInstance()
{
    if (!s_isInitialized)
        throw std::logic_error("Debug hasn't been initialized. Call Init() first");
    
    return *s_instance;
}

void Debug::AddText(const std::string& text)
{
    m_text.setString(text);
    m_text.setCharacterSize(28);
    m_text.setFillColor(sf::Color::Black);
}

void Debug::AddText(const int& number) 
{
    AddText(std::to_string(number));
}

void Debug::OnMove() 
{
    sf::FloatRect panelGlobalBounds = m_panel.getGlobalBounds();

    for (int i = 0; i < m_resizeSides.size(); i++) 
    {
        UpdateResizeHandlers(m_resizeSides[i], static_cast<ResizeSideType>(i));
    }
}

void Debug::AddCheckBox(ResourceManager& resManager, bool state, const std::string& text)
{
    m_checkBox = std::make_unique<CheckBox>(resManager, state, text);
    m_checkBox->SetPosition({ 50, 150 });
}

void Debug::UpdateCursor(const sf::Vector2f& mousePos, sf::RenderWindow& window)
{
    if (m_resizeSides[0].getGlobalBounds().contains(mousePos))
    {
        CursorManager::SetSizeVertical(window);
        m_isCursorSetted = true;
    }
}

void Debug::HandleEvents(sf::Event& event, sf::RenderWindow& window)
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F9)
    {
        ToggleActive();
    }
    if (!m_isActive)
    {
        return;
    }

    switch (event.type)
    {
    case sf::Event::MouseButtonPressed:
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            sf::Vector2i mousePos = sf::Vector2i(event.mouseButton.x, event.mouseButton.y);
            sf::Vector2f mousePosInCoords = window.mapPixelToCoords(mousePos);

            if (m_panel.getGlobalBounds().contains(mousePosInCoords))
            {
                m_isMoving = true;
            }
        }
        break;
    }
    case sf::Event::MouseButtonReleased:
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            m_isMoving = false;
        }
        break;
    }
    default:
        break;
    }
}

void Debug::Update(sf::RenderWindow& window) 
{
    if (!m_isActive) 
    {
        return;
    }

    m_isCursorSetted = false;

    sf::Vector2f mousePos = utils::ConvertMousePixelsToCoords(sf::Mouse::getPosition(window), window);
    UpdateCursor(mousePos, window);

    if (m_isMoving)
    {
        m_panel.setPosition(mousePos);
        OnMove();
    }
}

void Debug::Draw(sf::RenderWindow& window)
{
    if (!m_isActive)
    {
        return;
    }

    window.draw(m_panel);

    for (auto& side : m_resizeSides) 
    {
        window.draw(side);
    }

    window.draw(m_text);
    m_checkBox->Draw(window);
}

void Debug::CreatePanel(const sf::Vector2f& size, int leftMargin, int topMargin) 
{
    m_panel.setFillColor(sf::Color::White);
    m_panel.setSize(size);

    sf::FloatRect panelLocalBounds = m_panel.getLocalBounds();

    m_panel.setOrigin(SetRectOriginToCenter(panelLocalBounds));
    m_panel.move(panelLocalBounds.width / 2.0f + leftMargin, panelLocalBounds.height / 2.0f + topMargin);
}

void Debug::CreateResizeHandlers(sf::RectangleShape& side, const sf::Vector2f& size, ResizeSideType sideType) 
{
    side.setSize(size);
    side.setFillColor(sf::Color::Black);
    side.setOrigin(SetRectOriginToCenter(side.getLocalBounds()));
}

void Debug::UpdateResizeHandlers(sf::RectangleShape& side, ResizeSideType sideType)
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