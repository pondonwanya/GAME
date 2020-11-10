#pragma once

#include "entity.h"

class player : public entity
{
public:

	int movementSpeed = 10;
	int attactDamage = 5;
	bool faceRight = 1;
	int counterRunning = 0;
	int direction = 0;   //  1-up , 2-down 3-left , 4-right
	int hp = 10;
	int gil = 0;
	int gil1 = 0;
	
	player();

	const sf::Vector2f& getPos() const;

	void update();
	void updateMovement();
};

