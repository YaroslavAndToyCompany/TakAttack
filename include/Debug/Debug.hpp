#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <memory>
#include "Managers/CursorManager.hpp"
#include "SFML/Window/Cursor.hpp"
#include "UI/View.hpp"
#include "UI/Widgets/CheckBox.hpp"
#include "UI/Widgets/ResizeSide.hpp"
#include "UI/Widgets/Button.hpp"
#include "UI/Widgets/IWidget.hpp"
#include "Managers/ResourceManager.hpp"

class Debug {
public:
    Debug(const Debug&) = delete;
    Debug& operator=(const Debug&) = delete;

    static void Init(ResourceManager& resManager, CursorManager& curManager);
    static void Shutdown();
    static Debug& GetInstance();

    Label* CreateLabel(const std::string& widgetName);
    CheckBox* CreateCheckBox(const std::string& widgetName);
    Button* CreateButton(const std::string& widgetName);

    template <typename T>
    T* GetWidgetPtr(const std::string& name);

    void ToggleActive() { m_isActive = !m_isActive; }
    void ToggleMoving() { m_isMoving = !m_isMoving; }

    void HandleEvents(sf::Event& event, sf::RenderWindow& window);
    void Update(sf::RenderWindow& window);
    void Draw(sf::RenderWindow& window);

private:
    void OnMove(const sf::Vector2f& mousePos);

    Debug(ResourceManager& resManager, CursorManager& curManager);
	
	ResourceManager& m_resManager;
	CursorManager& m_curManager;

    void CreatePanel(const sf::Vector2f& size, int leftMargin, int topMargin);

    sf::RectangleShape m_panel;

    std::vector<ResizeSide> m_resizeSides;

    std::unordered_map<std::string, std::unique_ptr<IWidget>> m_widgets;

    int m_defaultWidgetLeftMargin = 10;
    int m_distanceFromPreviousElement = 10;

    bool m_isActive = false;
    bool m_isMoving = false;

    static std::unique_ptr<Debug> s_instance;
    static bool s_isInitialized;
};

template <typename T>
T* Debug::GetWidgetPtr(const std::string& name)
{
    auto it = m_widgets.find(name);
    if (it == m_widgets.end())
    {
        throw std::runtime_error("Can't find " + name + " Widge in Debug panel!");
    }

    return dynamic_cast<T*>(it->second.get());
}