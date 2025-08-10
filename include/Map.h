#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
class Map {
public:
    Map();
    Map(const std::string& mapName);

    sf::Sprite GetSprite() const { return m_map; };

    void SetMap(const std::string& mapName);

private:
    void SetUpMap(const std::string& mapName);

    sf::Sprite m_map;
};