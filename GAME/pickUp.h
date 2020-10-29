#pragma once
#include "entity.h"

class pickUp : public entity
{
public:
	bool isPotion = true;

	pickUp();
	void update();
};
