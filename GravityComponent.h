#pragma once

#include <SFML/Graphics.hpp>

class GravityComponent
{
private:
	float increment;
	float velocity;
	float maxVelocity;
	sf::Sprite& sprite;

public:

	GravityComponent(float _increment, float _maxVelocity, sf::Sprite& _sprite);
	~GravityComponent();

	void updateVelocity(float _velocity);

	void update(float _dt);


};

