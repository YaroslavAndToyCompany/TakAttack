#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <array>
#include "UI/View.hpp"
#include "UI/Widgets/CheckBox.hpp"

class DebugPanel {
public:
    static void Init(View& view);

    static void AddText(const std::string& text);
    static void AddText(const int& number);

    template<typename T>
    static void AddText(const sf::Vector2<T>& vec);

    static void OnMove();

    static void AddCheckBox(bool state = false, const std::string& text = "Text");
    static void ToggleActive() { m_isActive = !m_isActive; }
    static void ToggleMoving() { m_isMoving = !m_isMoving; }

    static bool IsMouseHover(sf::RenderWindow& window);

    static void HandleEvents(sf::Event& event, sf::RenderWindow& window);
    static void Update(sf::RenderWindow& window);
    static void Draw(sf::RenderWindow& window);

private:
    enum class ResizeSideType {
        Top, Bottom, Left, Right, Count
    };

    DebugPanel() { }
    static void CreatePanel(const sf::Vector2f& size, int leftMargin, int topMargin);
    static void CreateResizeHandlers(sf::RectangleShape& side, const sf::Vector2f& size, ResizeSideType sideType);
    static void UpdateResizeHandlers(sf::RectangleShape& side, ResizeSideType sideType);

    static sf::RectangleShape m_panel;

    static std::array<sf::RectangleShape, static_cast<size_t>(ResizeSideType::Count)> m_resizeSides;

    static sf::Text m_text;
    static CheckBox m_checkBox;

    static bool m_isActive;
    static bool m_isMoving;
};

template<typename T>
void DebugPanel::AddText(const sf::Vector2<T>& vec)
{
    AddText(std::to_string(vec.x) + ", " + std::to_string(vec.y));
}