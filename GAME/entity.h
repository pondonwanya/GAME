#pragma once

#include <SFML\Graphics.hpp>

class entity
{

public:
	sf::RectangleShape rect;
	sf::RectangleShape sprite;
	sf::Text text;
	sf::Font* font;

	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;

private	:

protected:

};

