#pragma once
#include <SFML/Window/VideoMode.hpp>

struct ScreenInfo {
    int x = 0;
    int y = 0;
    unsigned int width = 0;
    unsigned int height = 0;
};


ScreenInfo GetPrimaryMonitorResoulution();