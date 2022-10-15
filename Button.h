#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>

enum button_states { BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE };

class Button
{
private:
	short unsigned buttonState;

	sf::RectangleShape shape;
	sf::Text text;

	sf::Color textIdleColor;
	sf::Color textHoverColor;
	sf::Color textActiveColor;

	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;

	float timeout;
	float maxTimeout;

public:
	Button(float x_, float y_, float width_, float height_,
		sf::Font &font_, std::string text_, unsigned characterSize_,
		sf::Color textIdleColor_, sf::Color textHoverColor_, sf::Color textActiveColor_,
		sf::Color idleColor_, sf::Color hoverColor_, sf::Color activeColor_, float timeout_ = 1.0f);
	~Button();

	//Accessors
	const bool isPressed();

	//Functions
	void update(const sf::Vector2f& mousePos_, float dt_);
	void render(sf::RenderTarget& target_);

};

