#pragma once

#include "SFML/Graphics.hpp"

class CollisionComponent
{
private:
	//Variables
	sf::FloatRect hitbox;
	sf::Sprite& sprite;


public: 
	CollisionComponent(sf::Sprite &_sprite, sf::FloatRect _hitbox);
	~CollisionComponent();


	//Public functions

	const sf::Vector2i BorderCollision(sf::RenderWindow& _window) const;


};

