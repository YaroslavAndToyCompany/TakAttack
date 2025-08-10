#pragma once

#include <SFML/Graphics.hpp>

class Map {
public:
    Map();
    Map(const std::string& mapPath);

    sf::Sprite GetSprite() { return m_map; };

    void SetMap(const std::string& mapPath);

private:
    void SetUpMap(const std::string& mapPath);

    sf::Texture m_mapTex;
    sf::Sprite m_map;
};