#pragma once

#include <SFML/Graphics.hpp>


class MovementComponent
{
private:
	sf::Sprite& sprite;
	float speed;
	sf::Vector2f direction;

public:
	MovementComponent(sf::Sprite& _sprite, float _speed);
	virtual ~MovementComponent();

	//Functions
	const sf::Vector2f getDirection() const;

	const void move(const float _dirX, const float _dirY, const float _dt);
};

