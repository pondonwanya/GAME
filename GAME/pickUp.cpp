#include "pickUp.h"

pickUp::pickUp()
{
	rect.setSize(sf::Vector2f(25, 32));
	rect.setPosition(500, 500);
	rect.setFillColor(sf::Color::Red);
	sprite.setTextureRect(sf::IntRect(0, 0, 29, 35));
}

void pickUp::update()
{
	sprite.setPosition(rect.getPosition());
}


