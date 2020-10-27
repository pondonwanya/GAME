#include "textDisplay.h"

textDisplay::textDisplay()
{
	text.setCharacterSize(30);
	text.setString(myString);
}

void textDisplay::update()
{
	text.move(0, -movementSpeed);
	counter++;

	if (counter >= lifeTime)
	{
		destroy = true;
	}
}
