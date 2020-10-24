#pragma once

#include "entity.h"
#include "random.h"

class enemy: public entity
{
public:
	float movementSpeed = 3;
	int movementLength = 50;
	int attactDamage = 5;
	int counterRunning = 0;
	int direction = 0;   //  1-up , 2-down 3-left , 4-right
	int counter = 0;

	enemy();
	void update();
	void updateMovement();
};

