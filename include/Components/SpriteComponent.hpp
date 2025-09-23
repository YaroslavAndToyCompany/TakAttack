#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "Managers/ResourceManager.hpp"
struct SpriteComponent
{
	sf::Sprite m_sprite;
	std::string m_textureID;

	SpriteComponent(const std::string& id, ResourceManager& resManager) : m_textureID(id) { 
		auto tex = resManager.GetResource<sf::Texture>(id);
		if(tex) 
		{
			m_sprite.setTexture(*tex);
			std::cout << "SpriteComponent: Loading texture with id complete" << std::endl;
		}
		else
		{
			std::cerr << "SpriteComponent: Failed to load texture with id " << id << std::endl;
		}
	}
};