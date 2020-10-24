#pragma once

#include "entity.h"

class enemy: public entity
{
public:
	float movementSpeed = 5;
	int attactDamage = 5;
	bool faceRight = 1;
	int counterRunning = 0;
	int direction = 0;   //  1-up , 2-down 3-left , 4-right

	enemy();
	void update();
	//void updateMovement();
};

