#include "warp.h"

warp::warp()
{
	rect.setSize(sf::Vector2f(100, 300));
	rect.setPosition(100, 100);
	rect.setFillColor(sf::Color::Black);
	sprite.setSize(sf::Vector2f(100, 350));
	sprite.setOrigin(sprite.getSize() / 2.f);
}

void warp::update()
{
	sprite.setPosition(rect.getPosition());
}
