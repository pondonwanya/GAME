#pragma once
#include "entity.h"

class warp : public entity
{
public:
	bool isDoor = false;

	warp();
	void update();
};

