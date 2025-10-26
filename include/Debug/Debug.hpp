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
#include "UI/Widgets/IWidget.hpp"
#include "Managers/ResourceManager.hpp"

class Debug {
public:
    Debug(const Debug&) = delete;
    Debug& operator=(const Debug&) = delete;

    static void Init(ResourceManager& resManager, CursorManager& curManager);
    static void Shutdown();
    static Debug& GetInstance();

    void OnMove();

    void AddWidget(const std::string name, std::unique_ptr<IWidget> widget);
    void ToggleActive() { m_isActive = !m_isActive; }
    void ToggleMoving() { m_isMoving = !m_isMoving; }

    void HandleEvents(sf::Event& event, sf::RenderWindow& window);
    void Update(sf::RenderWindow& window);
    void Draw(sf::RenderWindow& window);

private:
    struct DebugWidget 
    {
        std::unique_ptr<IWidget> widget;
        int widgetLeftMargin;
        int widgetTopMargin;
    };

    Debug(ResourceManager& resManager, CursorManager& curManager);
	
	ResourceManager& m_resManager;
	CursorManager& m_curManager;

    void CreatePanel(const sf::Vector2f& size, int leftMargin, int topMargin);

    sf::RectangleShape m_panel;

    std::vector<ResizeSide> m_resizeSides;

    std::unordered_map<std::string, DebugWidget> m_widgets;
    sf::Vector2f m_panelPosBeforeMove;

    int m_widgetLeftMargin = 30;
    int m_widgetTopMargin = 30;
    int m_distanceWithinWidgets = 40;

    bool m_isActive = false;
    bool m_isMoving = false;

    static std::unique_ptr<Debug> s_instance;
    static bool s_isInitialized;
};