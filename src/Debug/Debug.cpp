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
}

Debug& Debug::GetInstance()
{
    if (!s_isInitialized)
        throw std::logic_error("Debug hasn't been initialized. Call Init() first");
    
    return *s_instance;
}

void Debug::OnMove() 
{
    sf::FloatRect panelGlobalBounds = m_panel.getGlobalBounds();

    for (int i = 0; i < m_resizeSides.size(); i++) 
    {
		m_resizeSides[i].Update(panelGlobalBounds);
    }
    
    for (auto& [name, widgetMarg] : m_widgets) 
    {
        sf::Vector2f upperLeftCorner = { m_panel.getPosition().x - (m_panel.getSize().x / 2.0f), m_panel.getPosition().y - (m_panel.getSize().y / 2.0f) };
        upperLeftCorner.x += widgetMarg.widgetLeftMargin;
        upperLeftCorner.y += widgetMarg.distanceFromPreviousWidget;

        widgetMarg.widget.get()->SetPosition(upperLeftCorner);
    }
}

// void Debug::AddWidget(const std::string name, std::unique_ptr<IWidget> widget) 
// {
//     m_distanceFromPreviousElement += 30;

//     sf::Vector2f upperLeftCorner = { m_panel.getPosition().x - (m_panel.getSize().x / 2.0f), m_panel.getPosition().y - (m_panel.getSize().y / 2.0f) };
//     upperLeftCorner.x += m_widgetLeftMargin;
//     upperLeftCorner.y += m_widgetTopMargin;

//     widget.get()->SetPosition(upperLeftCorner);
    
//     WidgetPlace dWidget = { std::move(widget), m_widgetLeftMargin, m_widgetTopMargin };
//     m_widgetTopMargin += m_distanceToNextWidget;

//     m_widgets.emplace(name, std::move(dWidget));
// }

Label* Debug::CreateLabel(const std::string& widgetName)
{
    std::unique_ptr<Label> label = std::make_unique<Label>(m_resManager);
    Label* labelPtr = label.get();
    
    std::unique_ptr<IWidget> widget = static_cast<std::unique_ptr<IWidget>>(std::move(label));

    m_distanceFromPreviousElement += 35;
    int widgetLeftMargin = m_defaultWidgetLeftMargin + (widget.get()->GetSize().x / 2) - 20;

    sf::Vector2f upperLeftCorner = { m_panel.getPosition().x - (m_panel.getSize().x / 2.0f), m_panel.getPosition().y - (m_panel.getSize().y / 2.0f) };
    upperLeftCorner.x += widgetLeftMargin;
    upperLeftCorner.y += m_distanceFromPreviousElement;

    widget.get()->SetPosition(upperLeftCorner);

    WidgetPlace dWidget = { std::move(widget), widgetLeftMargin, m_distanceFromPreviousElement };

    m_widgets.emplace(widgetName, std::move(dWidget));

    return labelPtr;
}

CheckBox* Debug::CreateCheckBox(const std::string& widgetName)
{
    std::unique_ptr<CheckBox> checkBox = std::make_unique<CheckBox>(m_resManager);
    CheckBox* checkBoxPtr = checkBox.get();
    
    std::unique_ptr<IWidget> widget = static_cast<std::unique_ptr<IWidget>>(std::move(checkBox));
    
    m_distanceFromPreviousElement += 40;
    int widgetLeftMargin = m_defaultWidgetLeftMargin + (widget.get()->GetSize().x / 2) + 7;    

    sf::Vector2f upperLeftCorner = { m_panel.getPosition().x - (m_panel.getSize().x / 2.0f), m_panel.getPosition().y - (m_panel.getSize().y / 2.0f) };
    upperLeftCorner.x += widgetLeftMargin;
    upperLeftCorner.y += m_distanceFromPreviousElement;

    widget.get()->SetPosition(upperLeftCorner);

    WidgetPlace dWidget = { std::move(widget), widgetLeftMargin, m_distanceFromPreviousElement };

    m_widgets.emplace(widgetName, std::move(dWidget));

    return checkBoxPtr;
}

Button* Debug::CreateButton(const std::string& widgetName)
{
    std::unique_ptr<Button> button = std::make_unique<Button>(m_resManager);
    Button* buttonPtr = button.get();
    
    std::unique_ptr<IWidget> widget = static_cast<std::unique_ptr<IWidget>>(std::move(button));

    m_distanceFromPreviousElement += 40;
    int widgetLeftMargin = m_defaultWidgetLeftMargin + widget.get()->GetSize().x;

    sf::Vector2f upperLeftCorner = { m_panel.getPosition().x - (m_panel.getSize().x / 2.0f), m_panel.getPosition().y - (m_panel.getSize().y / 2.0f) };
    upperLeftCorner.x += widgetLeftMargin;
    upperLeftCorner.y += m_distanceFromPreviousElement;

    widget.get()->SetPosition(upperLeftCorner);

    WidgetPlace dWidget = { std::move(widget), widgetLeftMargin, m_distanceFromPreviousElement };

    m_widgets.emplace(widgetName, std::move(dWidget));

    buttonPtr->SetSize({ 100, 30 });

    // sf::Vector2f newPos = { buttonPtr->GetPosition().x + (buttonPtr->GetSize().x / 2) - 11, buttonPtr->GetPosition().y };
    // buttonPtr->SetPosition(newPos);
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
            m_panelPosBeforeMove = m_panel.getPosition();

            m_isMoving = false;
        }
        break;
    }
    default:
        break;
    }

    for (auto& [name, widgetPlace] : m_widgets)
    {
        widgetPlace.widget.get()->HandleEvents(event, window);
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

    for (auto& [name, widgetPlace] : m_widgets)
    {
        widgetPlace.widget.get()->Update(window);
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

    for (auto& [name, dWidget] : m_widgets) 
    {
        dWidget.widget.get()->Draw(window);
    }
}

void Debug::CreatePanel(const sf::Vector2f& size, int leftMargin, int topMargin) 
{
    m_panel.setFillColor(sf::Color::White);
    m_panel.setSize(size);

    sf::FloatRect panelLocalBounds = m_panel.getLocalBounds();

    m_panel.setOrigin(CalcRectOriginCenter(panelLocalBounds));
    m_panel.move(panelLocalBounds.width / 2.0f + leftMargin, panelLocalBounds.height / 2.0f + topMargin);

    m_panelPosBeforeMove = m_panel.getPosition();
}