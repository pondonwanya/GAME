#include "Button.h"

Button::Button(float x, float y, float width, float height, 
	sf::Font* font, std::string text, 
	sf::Color idelColor, sf::Color hoverColor, sf::Color activeColor)

{
	this -> buttonState = BTN_IDLE;
	this->rect.setPosition(sf::Vector2f(x, y));
	this->rect.setSize(sf::Vector2f(width, height));

	this->font = font;
	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setFillColor(sf::Color::White);
	this->text.setCharacterSize(12);
	this->text.setPosition(
		this->rect.getPosition().x/2.f-this->text.getGlobalBounds().width/2.f,
		this->rect.getPosition().y/2.f- this->text.getGlobalBounds().height / 2.f
	);

	this->idleColor = idleColor;
	this->hoverColor = hoverColor;
	this->activeColor = activeColor;

	this->rect.setFillColor(this->idleColor);
}

Button::~Button()
{

}

const bool Button::isPressed() const
{
	if (this->buttonState == BTN_ACTIVE)
		return true;

	return false;
}


// Functions



void Button::update(const sf::Vector2f mousePos)
{
	/* Update the booleans for hover and pressed */

	// Idle
	this->buttonState = BTN_IDLE;

	//Hover
	if (this->rect.getGlobalBounds().contains(mousePos))
	{
		this->buttonState = BTN_HOVER;

		// Pressed
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->buttonState = BTN_ACTIVE;
		}
	}

	switch (this->buttonState)
	{
	case BTN_IDLE:
		this->rect.setFillColor(this->idleColor);
		break;

	case BTN_HOVER:
		this->rect.setFillColor(this->hoverColor);
		break;

	case BTN_ACTIVE:
		this->rect.setFillColor(this->activeColor);
		break;

	default:
		this->rect.setFillColor(sf::Color::Red);
		break;
	}

}

void Button::render(sf::RenderTarget* target)
{
	target->draw(this->rect);
}
