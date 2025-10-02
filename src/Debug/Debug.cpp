#include "Debug/Debug.hpp" 
#include "Managers/CursorManager.hpp"
#include "UI/Widgets/ResizeSide.hpp"
#include "Utils/Widgets.hpp"
#include "Utils/Utils.hpp"

#include <string>

std::unique_ptr<Debug> Debug::s_instance = nullptr;
bool Debug::s_isInitialized = false;

Debug::Debug(ResourceManager& resManager, CursorManager& curManager)
	: m_resManager(resManager), m_curManager(curManager)
{
    m_text.setFont(*m_resManager.GetResource<sf::Font>("BoldPixels"));

    int debugPanelLeftMargin = 20;
    int debugPanelTopMargin = 20;
    sf::Vector2f debugPanelSize = sf::Vector2f(200, 200);

    CreatePanel(debugPanelSize, debugPanelLeftMargin, debugPanelTopMargin);
    sf::FloatRect panelGlobalBounds = m_panel.getGlobalBounds();

	m_resizeSides.reserve(8);
	
    // Panel resize sides creaction
    const sf::Vector2f horizontalSize = { 180, 5 };
    const sf::Vector2f verticalSize = { 5, 180 };
	
    for (int i = 0; i < static_cast<int>(ResizeSide::ResizeSideType::Count); i++) 
    {
		ResizeSide::ResizeSideType type = static_cast<ResizeSide::ResizeSideType>(i);
        sf::Vector2f size = (type == ResizeSide::ResizeSideType::Top || type == ResizeSide::ResizeSideType::Bottom) ? horizontalSize : verticalSize;

		m_resizeSides.emplace_back(size, type);
		m_resizeSides[i].Update(panelGlobalBounds);
    }
}

void Debug::Init(ResourceManager& resManager, CursorManager& curManager)
{
    if (s_isInitialized)
        return;

    s_instance.reset(new Debug(resManager, curManager));
    s_isInitialized = true;
}

void Debug::Shutdown() 
{
    GetInstance().m_checkBox.release();
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
		m_resizeSides[i].Update(panelGlobalBounds);
    }
}

void Debug::AddCheckBox(bool state, const std::string& text)
{
    m_checkBox = std::make_unique<CheckBox>(m_resManager, state, text);
    m_checkBox->SetPosition({ 50, 150 });
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

    sf::Vector2f mousePos = utils::ConvertMousePixelsToCoords(sf::Mouse::getPosition(window), window);
    
    for (auto& resSide : m_resizeSides)
        resSide.ChangeCursor(m_curManager, mousePos);

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
		side.Draw(window);
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
