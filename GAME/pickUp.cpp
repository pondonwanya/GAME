#include "pickUp.h"

pickUp::pickUp()
{
	rect.setSize(sf::Vector2f(25, 35));
	rect.setPosition(500, 500);
	rect.setFillColor(sf::Color::Yellow);
	//sprite.setTextureRect(sf::IntRect(500, 500, 29, 35));
}

void pickUp::update()
{
	sprite.setPosition(rect.getPosition());
}


