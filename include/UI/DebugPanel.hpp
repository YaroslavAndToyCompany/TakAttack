#pragma once

#include <SFML/Graphics.hpp>
#include <string>
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
    static void ToggleDraw() { m_draw = !m_draw; }

    static bool IsMouseHover(sf::RenderWindow& window);

    static void ProcessEvents();
    static void Update(sf::RenderWindow& window);
    static void Draw(sf::RenderWindow& window);

private:
    DebugPanel() { }

    static sf::RectangleShape m_panel;
    static sf::RectangleShape m_bottomSide;

    static sf::Text m_text;
    static CheckBox m_checkBox;

    static bool m_draw;
};

template<typename T>
void DebugPanel::AddText(const sf::Vector2<T>& vec)
{
    AddText(std::to_string(vec.x) + ", " + std::to_string(vec.y));
}