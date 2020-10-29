#include "wall.h"


wall::wall()
{
	rect.setSize(sf::Vector2f(50, 50));
	rect.setPosition(0, 0);
	rect.setFillColor(sf::Color::White);
	//sprite.setTextureRect(sf::IntRect(0, 0, 641, 535));
}
/*
void player::update()
{
	sprite.setPosition(rect.getPosition());
}
*/