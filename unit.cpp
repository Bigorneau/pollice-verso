#include <string>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "unit.h"

using std::string;

Unit::Unit(const std::string &filepath)
{
	m_texture.loadFromFile(filepath);

	m_sprite.setTexture(m_texture);
	m_sprite.setTextureRect(sf::IntRect(5, 5, 70, 70));
	m_sprite.setColor(sf::Color(255, 255, 255, 200));
	m_sprite.setPosition(100, 50);
}

Unit::~Unit()
{
}

sf::Sprite &Unit::getSprite()
{
	return m_sprite;
}
