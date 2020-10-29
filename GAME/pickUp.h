#pragma once
#include "entity.h"

class pickUp : public entity
{
public:
	bool isPotion = true;
	bool destroy = false;
	int potionValue = 5;

	pickUp();
	void update();
};
