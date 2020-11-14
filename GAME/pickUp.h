#pragma once
#include "entity.h"

class pickUp : public entity
{
public:

	int counterRunning = 0;
	bool isPotion = true;
	bool destroy = false;
	int potionValue = 5;

	pickUp();
	void update();
	void updateMovement();
};
