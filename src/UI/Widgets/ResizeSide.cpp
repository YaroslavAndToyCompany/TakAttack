#include "UI/Widgets/ResizeSide.hpp"
#include "Utils/Widgets.hpp"

ResizeSide::ResizeSide(const sf::Vector2f& size, ResizeSideType sideType) 
{
	m_side.setSize(size);
	m_side.setFillColor(sf::Color::Black);
	m_side.setOrigin(CalcRectOriginCenter(m_side.getLocalBounds()));

	m_sideType = sideType;
}

void ResizeSide::SetUp(const sf::FloatRect panelGlobalBounds)
{
    float finalXCoord;
    float finalYCoord;

    if (m_sideType == ResizeSideType::Top) 
    {
        finalXCoord = panelGlobalBounds.left + (panelGlobalBounds.width / 2.0f);
        finalYCoord = panelGlobalBounds.top + m_side.getOrigin().y;
    }
    else if (m_sideType == ResizeSideType::Bottom)
    {
        finalXCoord = panelGlobalBounds.left + (panelGlobalBounds.width / 2.0f);
        finalYCoord = panelGlobalBounds.top + panelGlobalBounds.height - m_side.getOrigin().y;
    }
    else if (m_sideType == ResizeSideType::Left) 
    {
        finalXCoord = panelGlobalBounds.left + m_side.getOrigin().x;
        finalYCoord = panelGlobalBounds.top + (panelGlobalBounds.height / 2.0f);
    }
    else if (m_sideType == ResizeSideType::Right)
    {
        finalXCoord = panelGlobalBounds.left + panelGlobalBounds.width - m_side.getOrigin().x;
        finalYCoord = panelGlobalBounds.top + (panelGlobalBounds.height / 2.0f);
    }
	else { throw std::logic_error("Wrong side type was specified"); }
	
    m_side.setPosition(finalXCoord, finalYCoord);
}

void ResizeSide::ChangeCursor(CursorManager& curManager, const sf::Vector2f& mousePos)
{
	if (m_side.getGlobalBounds().contains(mousePos))
    {
        if (m_sideType == ResizeSideType::Top || m_sideType == ResizeSideType::Bottom)
		    curManager.Set(CursorType::SizeVertical);
        else if (m_sideType == ResizeSideType::Left || m_sideType == ResizeSideType::Right)
            curManager.Set(CursorType::SizeHorizontal);
    }
}

void ResizeSide::Update(const sf::Vector2f& newPos)
{
    m_side.setPosition(m_side.getPosition() + newPos);
}

void ResizeSide::Draw(sf::RenderWindow& window)
{
	window.draw(m_side);
}
