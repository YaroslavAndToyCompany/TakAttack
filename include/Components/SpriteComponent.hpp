#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
struct SpriteComponent
{
	sf::Sprite m_sprite;
	std::string m_textureID;

	SpriteComponent(std::string id) : m_textureID(id) { }
};