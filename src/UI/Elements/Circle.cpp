#include "UI/Elements/Circle.hpp"
#include "Utils/Widgets.hpp"

Circle::Circle()
    : CircleShape()
{
    SetOriginToCenter();
}

void Circle::SetOriginToCenter()
{
    setOrigin(CalcRectOriginCenter(getLocalBounds()));
}