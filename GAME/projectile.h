#pragma once

#include "entity.h"

class projectile:public entity
{

public:
	int movementSpeed = 10;
	int attactDamagr = 1;
	int lifeTime = 10;  //  Projectile Lifetime before being destroyed
	
	int direction = 0;   //  1-up , 2-down 3-left , 4-right
	bool destroy = false;
	int counterLifetime=0;

	projectile();
	void update();

};

