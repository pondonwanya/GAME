#include "pickUp.h"

pickUp::pickUp()
{
	rect.setSize(sf::Vector2f(25, 32));
	rect.setPosition(500, 500);
	rect.setFillColor(sf::Color::Red);
	sprite.setSize(sf::Vector2f(29, 35));
	sprite.setOrigin(sprite.getSize() / 2.f);
}

void pickUp::update()
{
	sprite.setPosition(rect.getPosition());
}


