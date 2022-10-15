// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "Button.h"

Button::Button(float x_, float y_, float width_, float height_,
	sf::Font &font_, std::string text_, unsigned characterSize_,
	sf::Color textIdleColor_, sf::Color textHoverColor_, sf::Color textActiveColor_,
	sf::Color idleColor_, sf::Color hoverColor_, sf::Color activeColor_, float timeout_)
	
	: textIdleColor(textIdleColor_), textHoverColor(textHoverColor_), textActiveColor(textActiveColor_),
	idleColor(idleColor_), hoverColor(hoverColor_), activeColor(activeColor_), maxTimeout(timeout_), timeout(timeout_)
{
	buttonState = BTN_IDLE;

	shape.setPosition(sf::Vector2f(x_, y_));
	shape.setSize(sf::Vector2f(width_, height_));
	shape.setFillColor(idleColor_);

	text.setFont(font_);
	text.setString(text_);
	text.setFillColor(textIdleColor_);
	text.setCharacterSize(characterSize_);
	text.setPosition(
		shape.getPosition().x + shape.getSize().x / 2.0f - text.getGlobalBounds().width / 2.0f,
		shape.getPosition().y + shape.getSize().y / 2.0f - text.getGlobalBounds().height / 2.0f
	);
}

Button::~Button()
{

}

const bool Button::isPressed()
{
	if (timeout >= maxTimeout && buttonState == BTN_ACTIVE)
	{
		timeout = 0.0f;
		return true;
	}
	else
		return false;
}

//Functions

void Button::update(const sf::Vector2f& _mousePos, float dt_)
{
	if(timeout < maxTimeout)
		timeout += 1.0f * dt_;
	//Idle
	buttonState = BTN_IDLE;

	//Hover
	if (shape.getGlobalBounds().contains(_mousePos))
	{
		buttonState = BTN_HOVER;


		//Pressed
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			
			buttonState = BTN_ACTIVE;
		}
	}

	switch (buttonState)
	{
	case BTN_IDLE:
		shape.setFillColor(idleColor);
		text.setFillColor(textIdleColor);
		break;
	case BTN_HOVER:
		shape.setFillColor(hoverColor);
		text.setFillColor(textHoverColor);
		break;
	case BTN_ACTIVE:
		shape.setFillColor(activeColor);
		text.setFillColor(textActiveColor);
		break;
	default:
		//error case 
		shape.setFillColor(sf::Color::Red);
		text.setFillColor(sf::Color::Blue);
		break;
	}
}

void Button::render(sf::RenderTarget& _target)
{
	_target.draw(shape);
	_target.draw(text);
}
