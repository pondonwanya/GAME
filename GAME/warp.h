#pragma once
#include "entity.h"

class warp : public entity
{
public:
	bool isDoor = false;
	bool isDoor2 = false;

	warp();
	void update();
};

