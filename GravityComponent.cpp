#include "GravityComponent.h"

GravityComponent::GravityComponent(float _increment, float _maxVelocity, sf::Sprite& _sprite)
	: increment(_increment), maxVelocity(_maxVelocity), velocity(_maxVelocity), sprite(_sprite)
{

}

GravityComponent::~GravityComponent()
{

}

void GravityComponent::updateVelocity(float _velocity)
{
	velocity = _velocity;
}

void GravityComponent::update(float _dt)
{
	if (velocity < maxVelocity)
	{
		velocity += increment;
	}
	sprite.move(0.0f, velocity * _dt);
}
