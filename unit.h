#ifndef UNIT_H
#define UNIT_H

#include <string>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Unit
{
public:
	Unit(const std::string& filepath);
	~Unit();
	sf::Sprite &getSprite();
private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
};
#endif
