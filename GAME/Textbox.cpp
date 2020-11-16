#include "Textbox.h"

Textbox::Textbox()
{
}

Textbox::Textbox(int size, sf::Color color, bool sel)
{
	textbox.setCharacterSize(size);
	//textbox.setColor(color);
	isSelected = sel;
	if (sel) {
		textbox.setString("_");
	}
	else {
		textbox.setString("");
	}
}