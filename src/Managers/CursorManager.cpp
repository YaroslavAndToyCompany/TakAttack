#include "Managers/CursorManager.hpp"
#include "Managers/ResourceManager.hpp"

sf::Cursor CursorManager::s_arrow;
sf::Cursor CursorManager::s_hand;

sf::Cursor CursorManager::s_sizeTop;
sf::Cursor CursorManager::s_sizeBottom;
sf::Cursor CursorManager::s_sizeLeft;
sf::Cursor CursorManager::s_sizeRight;

void CursorManager::LoadCursors()
{
    s_arrow.loadFromSystem(sf::Cursor::Type::Arrow);
    s_hand.loadFromSystem(sf::Cursor::Type::Hand);

    s_sizeTop.loadFromSystem(sf::Cursor::Type::SizeVertical);
}

void CursorManager::SetArrow(sf::RenderWindow& window)
{
    window.setMouseCursor(s_arrow);
}

void CursorManager::SetHand(sf::RenderWindow& window)
{
    window.setMouseCursor(s_hand);
}

void CursorManager::SetSizeTop(sf::RenderWindow& window)
{
    window.setMouseCursor(s_sizeTop);
}