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
    int debugPanelLeftMargin = 20;
    int debugPanelTopMargin = 20;
    m_widgetMarginLeft = 10;
    m_widgetMarginTop = 20;

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
		m_resizeSides[i].SetUp(panelGlobalBounds);
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
}

Debug& Debug::GetInstance()
{
    if (!s_isInitialized)
        throw std::logic_error("Debug hasn't been initialized. Call Init() first");
    
    return *s_instance;
}

void Debug::OnMove(const sf::Vector2f& mousePos) 
{
    sf::FloatRect panelGlobalBounds = m_panel.getGlobalBounds();
    sf::Vector2f newPos = { mousePos.x - ((panelGlobalBounds.width / 2) + panelGlobalBounds.left), mousePos.y - ((panelGlobalBounds.height / 2) + panelGlobalBounds.top) };
    
    for (int i = 0; i < m_resizeSides.size(); i++) 
    {
		m_resizeSides[i].Update(newPos);
    }
    
    for (auto& [name, widget] : m_widgets) 
    {
        widget->SetPosition(widget->GetPosition() + newPos);
    }
}

Label* Debug::CreateLabel(const std::string& widgetName)
{
    std::unique_ptr<Label> label = std::make_unique<Label>(m_resManager);
    Label* labelPtr = label.get();
    
    std::unique_ptr<IWidget> widget = static_cast<std::unique_ptr<IWidget>>(std::move(label));

    sf::FloatRect rect = widget.get()->GetGlobalBounds();

    sf::Vector2f upperLeftCorner = { m_panel.getPosition().x - (m_panel.getSize().x / 2.0f), m_panel.getPosition().y - (m_panel.getSize().y / 2.0f) };
    upperLeftCorner.x += m_widgetMarginLeft;
    upperLeftCorner.y += m_widgetMarginTop;
    m_widgetMarginTop += rect.top + rect.height + 10;

    widget.get()->SetPosition(upperLeftCorner);

    m_widgets.emplace(widgetName, std::move(widget));

    return labelPtr;
}

CheckBox* Debug::CreateCheckBox(const std::string& widgetName)
{
    std::unique_ptr<CheckBox> checkBox = std::make_unique<CheckBox>(m_resManager);
    CheckBox* checkBoxPtr = checkBox.get();
    
    std::unique_ptr<IWidget> widget = static_cast<std::unique_ptr<IWidget>>(std::move(checkBox));
    
    sf::FloatRect rect = widget.get()->GetGlobalBounds();

    sf::Vector2f upperLeftCorner = { m_panel.getPosition().x - (m_panel.getSize().x / 2.0f), m_panel.getPosition().y - (m_panel.getSize().y / 2.0f) };
    upperLeftCorner.x += m_widgetMarginLeft;
    upperLeftCorner.y += m_widgetMarginTop;
    m_widgetMarginTop += rect.top + rect.height + 10;

    widget.get()->SetPosition(upperLeftCorner);

    m_widgets.emplace(widgetName, std::move(widget));

    return checkBoxPtr;
}

ButtonDefault* Debug::CreateButton(const std::string& widgetName)
{
    std::unique_ptr<ButtonDefault> button = std::make_unique<ButtonDefault>(m_resManager);
    ButtonDefault* buttonPtr = button.get();
    buttonPtr->ToggleDisplayBorders();
    
    std::unique_ptr<IWidget> widget = static_cast<std::unique_ptr<IWidget>>(std::move(button));

    sf::FloatRect rect = widget.get()->GetGlobalBounds();

    sf::Vector2f upperLeftCorner = { m_panel.getPosition().x - (m_panel.getSize().x / 2.0f), m_panel.getPosition().y - (m_panel.getSize().y / 2.0f) };
    upperLeftCorner.x += m_widgetMarginLeft;
    upperLeftCorner.y += m_widgetMarginTop;
    m_widgetMarginTop += rect.top + rect.height + 20;

    widget.get()->SetPosition(upperLeftCorner);

    m_widgets.emplace(widgetName, std::move(widget));

    buttonPtr->SetSize({ 120, 35 });

    return buttonPtr;
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
    // case sf::Event::MouseButtonPressed:
    // {
    //     if (event.mouseButton.button == sf::Mouse::Left)
    //     {
    //         sf::Vector2i mousePos = sf::Vector2i(event.mouseButton.x, event.mouseButton.y);
    //         sf::Vector2f mousePosInCoords = window.mapPixelToCoords(mousePos);

    //         if (m_panel.getGlobalBounds().contains(mousePosInCoords))
    //         {
    //             m_isMoving = true;
    //         }
    //     }
    //     break;
    // }
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

    for (auto& [name, widget] : m_widgets)
    {
        widget.get()->HandleEvents(event, window);
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

    if (m_isMoving && m_panel.getPosition() != mousePos)
    {
        OnMove(mousePos);
        m_panel.setPosition(mousePos);
    }

    for (auto& [name, widget] : m_widgets)
    {
        widget.get()->Update(window);
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

    for (auto& [name, widget] : m_widgets) 
    {
        widget.get()->Draw(window);
    }
}

void Debug::CreatePanel(const sf::Vector2f& size, int leftMargin, int topMargin) 
{
    m_panel.setFillColor(sf::Color::White);
    m_panel.setSize(size);

    sf::FloatRect panelLocalBounds = m_panel.getLocalBounds();

    m_panel.setOrigin(CalcRectOriginCenter(panelLocalBounds));
    m_panel.move(panelLocalBounds.width / 2.0f + leftMargin, panelLocalBounds.height / 2.0f + topMargin);
}