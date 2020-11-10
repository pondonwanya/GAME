#include "enemy.h"

enemy::enemy()
{
	rect.setSize(sf::Vector2f(25, 28));
	rect.setPosition(400, 200);
	rect.setFillColor(sf::Color::Black);
	sprite.setSize(sf::Vector2f(49, 49));
	sprite.setTextureRect(sf::IntRect(49 * 4, 0, 49, 49));

	rectHp.setSize(sf::Vector2f(100, 10));
	rectHp.setFillColor(sf::Color::Red);

	rectHpBack = rectHp;
	rectHpBack.setFillColor(sf::Color(25, 25, 25, 200));
}


void enemy::update()
{
	sprite.setPosition(rect.getPosition());
	rectHp.setPosition(rect.getPosition().x+10,rect.getPosition().y+30);
}

void enemy::updateHpBar()
{
	float hpPercent = (float)hp / (float)hpMax;
	rectHp.setSize(sf::Vector2f(60.f * hpPercent, rectHp.getSize().y));
}

void enemy::updateMovement()
{
	
	if (direction == 1)    //	Up
	{
		if (rect.getPosition().y > 25) {
			rect.move(0, -movementSpeed);
			rectHp.move(0.f, -1.f);
		}
	}
	else if (direction == 2)    // Down
	{
		if (rect.getPosition().y < 596) {
			rect.move(0, movementSpeed);
			rectHp.move(0.f, 1.f);
		}
	}
	else if (direction==3)  // Left
	{
		if (rect.getPosition().x > 19) {
			rect.move(-movementSpeed, 0);
			sprite.setTextureRect(sf::IntRect((49 * 4) + 49 * counterRunning, 0, 49, 49));
			rectHp.move(-1.f, 0.f);
		}
	}
	else if (direction == 4)  // Right
	{
		if (rect.getPosition().x < 800) {
			rect.move(movementSpeed, 0);
			sprite.setTextureRect(sf::IntRect((49 * 6) + 49 * counterRunning, 0, 49, 49));
			rectHp.move(1.f, 0.f);
		}
	}
	else
	{
		// No movement
	}

	counterRunning++;
	if (counterRunning == 1)
	{
		counterRunning = 0;
	}

	counter++;
	if (counter >= movementLength)
	{
		direction = generateRandom(10);
		counter = 0;
	}
}