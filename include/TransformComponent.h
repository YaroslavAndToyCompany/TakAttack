#pragma once
#include "SFML/Graphics.hpp"
struct TransformComponent 
{
	sf::Vector2f m_position;
	sf::Vector2f m_scale;
	sf::Vector2f m_size;
	float m_rotation;

	TransformComponent(const sf::Vector2f& m_pos, const sf::Vector2f& m_sc = { 0.0f, 0.0f }, 
		 float m_rot = 0.f)
		: m_position(m_pos), m_scale(m_sc), m_rotation(m_rot), m_size(0.0f, 0.0f) {
	}


	TransformComponent()
		: m_position(0.f, 0.f), m_scale(0.0f, 0.0f), m_rotation(0.f), m_size(0.0f, 0.0f) {
	}
};