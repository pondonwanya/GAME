#include "pickUp.h"

pickUp::pickUp()
{
	rect.setSize(sf::Vector2f(63.5, 64));
	rect.setPosition(500, 500);
	rect.setFillColor(sf::Color::Red);
	sprite.setSize(sf::Vector2f(63, 64));
	sprite.setTextureRect(sf::IntRect(0, 0, 65.3, 64));
	sprite.setScale(0.5, 0.5);
}

void pickUp::update()
{
	sprite.setPosition(rect.getPosition());
}

void pickUp::updateMovement()
{
	counterRunning++;
		sprite.setTextureRect(sf::IntRect(counterRunning * 63, 0, 63, 64));
		if (counterRunning == 7)
		{
			counterRunning = 0;
		}
}

