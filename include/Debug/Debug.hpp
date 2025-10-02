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
#include "Managers/ResourceManager.hpp"

class Debug {
public:
    Debug(const Debug&) = delete;
    Debug& operator=(const Debug&) = delete;

    static void Init(ResourceManager& resManager, CursorManager& curManager);
    static void Shutdown();
    static Debug& GetInstance();

    void AddText(const std::string& text);
    void AddText(const int& number);

    template<typename T>
    void AddText(const sf::Vector2<T>& vec);

    void OnMove();

    void AddCheckBox(bool state = false, const std::string& text = "Text");
    void ToggleActive() { m_isActive = !m_isActive; }
    void ToggleMoving() { m_isMoving = !m_isMoving; }

    void HandleEvents(sf::Event& event, sf::RenderWindow& window);
    void Update(sf::RenderWindow& window);
    void Draw(sf::RenderWindow& window);

private:
    Debug(ResourceManager& resManager, CursorManager& curManager);
	
	ResourceManager& m_resManager;
	CursorManager& m_curManager;

    void CreatePanel(const sf::Vector2f& size, int leftMargin, int topMargin);

    sf::RectangleShape m_panel;

    std::vector<ResizeSide> m_resizeSides;

    sf::Text m_text;
    std::unique_ptr<CheckBox> m_checkBox;

    bool m_isActive = false;
    bool m_isMoving = false;

    static std::unique_ptr<Debug> s_instance;
    static bool s_isInitialized;
};

template<typename T>
void Debug::AddText(const sf::Vector2<T>& vec)
{
    AddText(std::to_string(vec.x) + ", " + std::to_string(vec.y));
}
