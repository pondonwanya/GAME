#include "player.h"

player::player()
{
	rect.setSize(sf::Vector2f(50, 50));
	rect.setOrigin(rect.getSize() / 2.f);
	rect.setPosition(400, 200);
	rect.setFillColor(sf::Color::Blue);
	sprite.setSize(sf::Vector2f(641, 535));
	sprite.setOrigin(sprite.getSize() / 2.f);
	sprite.setTextureRect(sf::IntRect(0, 1080, 641, 542));
}

const sf::Vector2f& player::getPos() const
{
	return this->rect.getPosition();
}

void player::update()
{
	//sprite.setOrigin(rect.getSize().x/2,rect.getSize().y/2);
	sprite.setPosition(rect.getPosition());
}

void player::updateMovement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		if (rect.getPosition().x > 19) {
			rect.move(-movementSpeed, 0);
			faceRight = 0;
			sprite.setTextureRect(sf::IntRect(counterRunning * 641, 0, 641, 535));
			direction = 3;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		if (rect.getPosition().x < 780) {
			rect.move(movementSpeed, 0);
			faceRight = 1;
			sprite.setTextureRect(sf::IntRect(counterRunning * 641, 0, 641, 535));
			direction = 4;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
		if (rect.getPosition().y > 29) {
			rect.move(0, -movementSpeed);
			sprite.setTextureRect(sf::IntRect(counterRunning * 641, 0, 641, 535));
			direction = 1;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
		if (rect.getPosition().y < 575) {
			rect.move(0, movementSpeed);
			sprite.setTextureRect(sf::IntRect(counterRunning * 641, 0, 641, 535));
			direction = 2;
		}
	}
	

	counterRunning++;
	if (counterRunning == 7)
	{
		counterRunning = 0;
	}

	if (faceRight) {
		sprite.setScale(0.1, 0.1);
	}
	else {
		sprite.setScale(-0.1, 0.1);
	}
}
