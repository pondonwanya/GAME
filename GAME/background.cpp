#include "background.h"

background::background()
{
	rect.setSize(sf::Vector2f(1200, 1200));
	rect.setPosition(sf::Vector2f(0,0));
	sprite.setSize(sf::Vector2f(1200, 1200));
	sprite.setOrigin(sprite.getSize() / 5.f);
}

void background::update()
{
	sprite.setPosition(rect.getPosition());
}
