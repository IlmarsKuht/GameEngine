// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "Entity.h"
#include <iostream>

void Entity::initVariables()
{
	movementComponent = nullptr;
	shootingComponent = nullptr;
	collisionComponent = nullptr;
	hitboxComponent = nullptr;
	gravityComponent = nullptr;

	canJump = false;
}

Entity::Entity(sf::RenderWindow* _window)
	: window(_window)
{
	initVariables();
}

Entity::~Entity()
{
	delete movementComponent;
	delete shootingComponent;
	delete collisionComponent;
	delete hitboxComponent;
	delete gravityComponent;
}

//component functions
void Entity::setTexture(sf::Texture& _texture)
{
	sprite.setTexture(_texture);
}


void Entity::createMovementComponent(const float _speed)
{
	movementComponent = new MovementComponent(sprite, _speed);
}

void Entity::createShootingComponent(sf::Texture & _projectileTexture, sf::Vector2f _scale, float _speed, float _timer)
{
	shootingComponent = new ShootingComponent(sprite, _projectileTexture, _scale, _speed, _timer, window);
}

void Entity::createCollisionComponent()
{
	collisionComponent = new CollisionComponent(sprite, hitboxComponent->getHitbox());
}

void Entity::createHitboxComponent(sf::FloatRect _area)
{
	hitboxComponent = new HitboxComponent(sprite, _area);
}

void Entity::createGravityComponent(float _increment, float _maxVelocity)
{
	gravityComponent = new GravityComponent(_increment, _maxVelocity, sprite);
}





//Funtions

sf::FloatRect Entity::getBounds() const
{
	return sprite.getGlobalBounds();
}

sf::Vector2u Entity::getWindowSize() const
{
	return window->getSize();
}

sf::FloatRect Entity::getHitbox() const
{
	return hitboxComponent->getHitbox();
}

void Entity::setSize(const float _x, const float _y)
{
	sprite.setScale(
		_x / sprite.getGlobalBounds().width,
		_y / sprite.getGlobalBounds().height
	);
	
}

void Entity::setPosition(const float _x, const float _y)
{
	sprite.setPosition(_x, _y);
}

void Entity::setScale(const float _x, const float _y)
{
	sprite.setScale(_x, _y);
}

void Entity::setColor(sf::Color _color)
{
	sprite.setColor(_color);
}


sf::Vector2f Entity::getDirection()
{
	return movementComponent->getDirection();
}

void Entity::move(const float _dirX, const float _dirY, const float _dt)
{
	if (movementComponent)
	{
		movementComponent->move(_dirX, _dirY, _dt); //sets velocity

	}
}

void Entity::jump(const float _velocity)
{
	if (canJump)
	{
		gravityComponent->updateVelocity(_velocity);
		canJump = false;
	}
		
}

void Entity::shoot(sf::Vector2f _dir, float _dt)
{
	if (shootingComponent)
	{
		shootingComponent->shoot(_dir, _dt);
	}
}

sf::Vector2i Entity::BorderCollision()
{
	if (collisionComponent)
	{
		if (collisionComponent->BorderCollision(*window).y == 1) 
			canJump = true;

		return collisionComponent->BorderCollision(*window);
		
	}
		
}

void Entity::update(const float _dt)
{
	if (shootingComponent)
		shootingComponent->update(*window, _dt);
	if (gravityComponent)
		gravityComponent->update(_dt);
	if (collisionComponent)
		BorderCollision();
	if (hitboxComponent)
		hitboxComponent->update();
	
}


void Entity::render(sf::RenderTarget& _target)
{
	_target.draw(sprite);
	if (shootingComponent)
		shootingComponent->render(_target);
	if (hitboxComponent)
		hitboxComponent->render(_target);
}
