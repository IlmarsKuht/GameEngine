#pragma once

#include "MovementComponent.h"
#include "ShootingComponent.h"
#include "CollisionComponent.h"
#include "HitboxComponent.h"
#include "GravityComponent.h"

class Entity
{

private:
	sf::Sprite sprite;
	sf::RenderWindow* window;
	

	MovementComponent* movementComponent;
	ShootingComponent* shootingComponent;
	CollisionComponent* collisionComponent;
	HitboxComponent* hitboxComponent;
	GravityComponent* gravityComponent;

	bool canJump;


	void initVariables();


public:

	Entity(sf::RenderWindow* _window);
	virtual ~Entity();

	//Component functions
	void setTexture(sf::Texture& _texture);

	void createMovementComponent(const float _speed);
	void createShootingComponent(sf::Texture& _projectileTexture, sf::Vector2f _scale, float _speed, float _timer);
	void createCollisionComponent();
	void createHitboxComponent(sf::FloatRect _area);
	void createGravityComponent(float _increment, float _maxVelocity);
	

	//Functions
	virtual sf::FloatRect getBounds() const;
	virtual sf::Vector2u getWindowSize() const;
	virtual sf::FloatRect getHitbox() const;

	virtual void setSize(const float _x, const float _y);
	virtual void setPosition(const float _x, const float _y);
	virtual void setScale(const float _x, const float _y);
	virtual void setColor(sf::Color _color);
	 
	virtual sf::Vector2f getDirection();

	virtual void move(const float _dirX, const float _dirY, const float _dt);
	virtual void jump(const float _velocity);
	virtual void shoot(sf::Vector2f _dir, float _dt);
	virtual sf::Vector2i BorderCollision();

	virtual void update(const float _dt);
	virtual void render(sf::RenderTarget& _target);

};



