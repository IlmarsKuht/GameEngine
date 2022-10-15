#pragma once

#include "Entity.h"


class Player :
	public Entity
{
private:
	//Variables

	//Initializer functions
	void initVariables();

public:
	Player(float _x, float _y, sf::Texture& _playerTexture, sf::RenderWindow* _window);
	virtual ~Player();

	//Functions
	sf::Vector2i BorderCollision();

	void update(float _dt);
	
};

