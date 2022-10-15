// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "Player.h"

#include <iostream>


//Initializer functions

void Player::initVariables()
{
 
}


//Constructor / Destructor

//TOO MANY ITEMS IN CONSTRUCTOR< MAKE THEM SEPEARET< CREATE A FUCNTION TO MAKE ALL THE COMPONENTS
Player::Player(float _x, float _y, sf::Texture& _playerTexture, sf::RenderWindow* _window)
	: Entity(_window)
{
	Entity::setPosition(_x, _y);

	setTexture(_playerTexture);
}

Player::~Player()
{

}

sf::Vector2i Player::BorderCollision()
{
	sf::Vector2i collDir_ = Entity::BorderCollision();

	//Collision resolving
	if (collDir_.x != 0.0f || collDir_.y != 0.0f)
	{
		
		sf::Vector2u windowSize_ = getWindowSize();
		sf::FloatRect hitBox_ = getHitbox();

		sf::Vector2f newPos_(getBounds().left, getBounds().top);

		if (collDir_.x < 0) //left collision
		{
			newPos_.x = -hitBox_.left;
		}
		else if (collDir_.x > 0) //right collision
		{
			newPos_.x = windowSize_.x - hitBox_.width - hitBox_.left;
		}

		if (collDir_.y < 0) //top collision
		{
			newPos_.y = -hitBox_.top;
		}
		else if (collDir_.y > 0)  //bottom collision
		{
			newPos_.y = windowSize_.y - hitBox_.height - hitBox_.top;
		}

		setPosition(newPos_.x, newPos_.y);
	}
	
	
	return collDir_;
}

void Player::update(float _dt)
{
	Entity::update(_dt);
}
