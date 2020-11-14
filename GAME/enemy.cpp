#include "enemy.h"

enemy::enemy()
{
	rect.setSize(sf::Vector2f(29, 32));
	rect.setPosition(400, 200);
	rect.setFillColor(sf::Color::Black);



	sprite.setSize(sf::Vector2f(29, 32));
	sprite.setTextureRect(sf::IntRect(0, 0, 29, 32));

	rectHp.setSize(sf::Vector2f(100, 10));
	rectHp.setFillColor(sf::Color::Red);

	rectHpBack = rectHp;
	rectHpBack.setFillColor(sf::Color(25, 25, 25, 255));
}


void enemy::update()
{
	sprite.setPosition(rect.getPosition());
	rectHp.setPosition(rect.getPosition().x+12,rect.getPosition().y+35);
}

void enemy::updateHpBar()
{
	float hpPercent = (float)hp / (float)hpMax;
	rectHp.setSize(sf::Vector2f(60.f * hpPercent, rectHp.getSize().y));
}
