#include "Heart.h"
#include <iostream>

Heart::Heart(sf::RenderWindow* _window, float _xPos, float _yPos, sf::Texture _texture, float _sizeX, float _sizeY)
	:Entity(_window)
{
	initVariables();

	setPosition(_xPos, _yPos);
	setTexture(_texture);
	setSize(_sizeX, _sizeY);

	createGravityComponent(4.0f, 300.0f);
}

Heart::~Heart()
{

}

short int Heart::getTransparency()
{
	return transparency;
}

void Heart::initVariables()
{
	transparency = 255;
}

void Heart::update(float _dt)
{
	Entity::update(_dt);
	setColor(sf::Color(255, 255, 255, transparency));
	transparency -= 0.5f;
}

void Heart::render(sf::RenderTarget & _target)
{ 
	Entity::render(_target);
}
