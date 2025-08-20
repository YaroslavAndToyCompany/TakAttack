#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "View.h"

class Map {
public:
    Map(const std::string& mapName);

    void SetMap(const std::string& mapName);
    
    void Draw(sf::RenderWindow& window);
    
    sf::Sprite GetSprite() const { return m_map; }
    sf::Vector2f GetGlobalCenter() const { return m_globalCenter; }
    sf::Vector2f GetSize() const { return m_size; }

private:
    void SetUpMap(const std::string& mapName);
    void CalculateGlobalMapCenter();

    sf::Sprite m_map;
    sf::Vector2f m_size;
    sf::Vector2f m_globalCenter;
};