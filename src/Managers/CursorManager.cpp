#include "Managers/CursorManager.hpp"
#include "Managers/ResourceManager.hpp"

sf::Cursor CursorManager::s_arrow;
sf::Cursor CursorManager::s_hand;

sf::Cursor CursorManager::s_sizeVertical;
sf::Cursor CursorManager::s_sizeHorizontal;

void CursorManager::LoadCursors()
{
    s_arrow.loadFromSystem(sf::Cursor::Arrow);
    s_hand.loadFromSystem(sf::Cursor::Hand);

    s_sizeVertical.loadFromSystem(sf::Cursor::SizeVertical);
}

void CursorManager::SetArrow(sf::RenderWindow& window)
{
    window.setMouseCursor(s_arrow);
}

void CursorManager::SetHand(sf::RenderWindow& window)
{
    window.setMouseCursor(s_hand);
}

void CursorManager::SetSizeVertical(sf::RenderWindow& window)
{
    window.setMouseCursor(s_sizeVertical);
}

void CursorManager::SetSizeHorizontal(sf::RenderWindow& window)
{
    window.setMouseCursor(s_sizeHorizontal);
}