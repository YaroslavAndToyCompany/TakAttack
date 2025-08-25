#pragma once
#include <SFML/Graphics.hpp>

class CursorManager {
public:
    static void LoadCursors();
    static void SetArrow(sf::RenderWindow& window);
    static void SetHand(sf::RenderWindow& window);

private:
    CursorManager() { };

    static sf::Cursor s_arrow;
    static sf::Cursor s_hand;
};