#pragma once

#include <SFML/Graphics.hpp>

#include "CollisionComponent.h"
#include "HitboxComponent.h"

class ShootingComponent
{
private:
	sf::Sprite& sprite;
	sf::Sprite projectile;
	float speed;
	float timer;
	float maxTimer;

	CollisionComponent* collisionComponent;
	HitboxComponent* hitboxComponent;

	class Projectile {
	private:
		sf::Vector2f direction;
		sf::Vector2f pos;

	public:
		Projectile(sf::Vector2f _dir, sf::Vector2f _pos)
			: direction(_dir), pos(_pos)
		{

		}

		sf::Vector2f getPos()
		{
			return pos;
		}
	
		void update(float _speed, float _dt)
		{
			pos += direction * _speed * _dt;
		}
	};

	
	std::vector<Projectile*> projectiles;
	
	
public:
	ShootingComponent(sf::Sprite& _sprite, sf::Texture& _projectileTexture, sf::Vector2f _scale, float _speed, float _timer, sf::RenderWindow* _window);
	~ShootingComponent();

	void shoot(sf::Vector2f _dir, float _dt);

	void update(sf::RenderWindow& _window, float _dt);
	void render(sf::RenderTarget& _target);
};

