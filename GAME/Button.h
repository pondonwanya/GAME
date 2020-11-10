#pragma once

#include "entity.h"

enum button_states
{
	BTN_IDLE=0,BTN_HOVER,BTN_ACTIVE
};

class Button : public entity
{
private:
	short unsigned buttonState;

public :
	Button(float x,float  y,float width ,float height,
		sf::Font* font,std::string text,
		sf::Color idelColor,sf::Color hoverColor, sf::Color activeColor);
	~Button();

	// Accessors
	const bool isPressed() const;

	//Functions
	void update(const sf::Vector2f mousePos);
	void render(sf::RenderTarget* target);
};

