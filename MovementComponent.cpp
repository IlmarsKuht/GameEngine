// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "MovementComponent.h"

#include <iostream>

MovementComponent::MovementComponent(sf::Sprite& _sprite, float _speed)
	: sprite(_sprite), speed(_speed), direction(sf::Vector2f(1.0f, 0.0f)) 
{

}

MovementComponent::~MovementComponent()
{

}


//Functions

const sf::Vector2f MovementComponent::getDirection() const
{	
	return direction;
}



const void MovementComponent::move(const float _dirX, const float _dirY, const float _dt)
{
	//changes where the sprite is looking
	if (_dirX > 0.0f)
	{
		if (sprite.getScale().x < 0.0f) //checks if sprite is already rotated, if not then rotate it
		{
			sprite.scale(-1.0f,1.0f);
			sprite.setOrigin(0.0f, 0.0f);
		}
	}
		
		
	else if (_dirX < 0.0f)
	{
		if (sprite.getScale().x > 0.0f)
		{
			sprite.scale(-1.0f, 1.0f);
			sprite.setOrigin(sprite.getTexture()->getSize().x, 0.0f);	//moves the origin to the new top left corner of the sprite					
		}
	}

	sprite.move(_dirX * speed * _dt, _dirY * speed * _dt);

	//Updates the state of the entity
	direction.x = _dirX;
	direction.y = _dirY;
}

