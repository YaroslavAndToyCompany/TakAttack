#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class DebugPanel {
public:
    static void Init();
    static void SetString(const std::string& text);
    static void Draw(sf::RenderWindow& window);

private:
    DebugPanel() { }

    static sf::Text m_text;
};