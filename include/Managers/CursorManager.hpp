#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window/Cursor.hpp>

enum class CursorType 
{
    Arrow, Hand, 
    SizeVertical, SizeHorizontal
};

class CursorManager 
{
public:
    CursorManager();

    void Set(CursorType type);

    void Draw(sf::RenderWindow& window);

private:
    void AssignCurToWindow(sf::RenderWindow& window);

    sf::Cursor m_arrow;
    sf::Cursor m_hand;
    sf::Cursor m_sizeVertical;
    sf::Cursor m_sizeHorizontal;

    CursorType m_curType;

    bool m_isCursorSpecified;
};
