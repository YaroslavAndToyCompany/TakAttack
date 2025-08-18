#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <View.h>

class DebugPanel {
public:
    static void Init(View& view);
    static void SetString(const std::string& text);
    static void Draw(sf::RenderWindow& window);

private:
    DebugPanel() { }

    static sf::RectangleShape m_panel;
    static sf::Text m_text;
};