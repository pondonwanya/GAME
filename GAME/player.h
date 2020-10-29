#pragma once

#include "entity.h"

class player : public entity
{
public:

	int movementSpeed = 5;
	int attactDamage = 5;
	bool faceRight = 1;
	int counterRunning = 0;
	int direction = 0;   //  1-up , 2-down 3-left , 4-right
	int hp = 10;
	int gil = 0;
	
	player();
	void update();
	void updateMovement();
};

