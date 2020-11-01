#include "enemy.h"

enemy::enemy()
{
	rect.setSize(sf::Vector2f(32, 32));
	rect.setPosition(400, 200);
	rect.setFillColor(sf::Color::Black);
	sprite.setSize(sf::Vector2f(49,49));
	sprite.setOrigin(sprite.getSize() / 2.f);

}

void enemy::update()
{
	sprite.setPosition(rect.getPosition());
}

void enemy::updateMovement()
{
	
	if (direction == 4)    //	Up
	{
		rect.move(0, -movementSpeed);
	}
	else if (direction == 3)    // Down
	{
		rect.move(0, movementSpeed);
	}
	else if (direction==1)  // Left
	{
		rect.move(-movementSpeed,0);
		sprite.setTextureRect(sf::IntRect((49 * 4) + 49 * counterRunning, 0, 49, 49));
	}
	else if (direction == 2)  // Right
	{
		rect.move(movementSpeed,0);
		sprite.setTextureRect(sf::IntRect((49 * 6) + 49 * counterRunning, 0, 49, 49));
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