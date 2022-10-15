// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "ShootingComponent.h"

ShootingComponent::ShootingComponent(sf::Sprite& _sprite, sf::Texture& _projectileTexture, sf::Vector2f _scale, float _speed, float _timer, sf::RenderWindow* _window)
	: sprite(_sprite), speed(_speed)
{
	projectile.setTexture(_projectileTexture);
	projectile.setScale(_scale);

	maxTimer = _timer;
	timer = maxTimer;

	hitboxComponent = new HitboxComponent(projectile, sf::FloatRect(1.0f, 1.0f, 38.0f, 38.0f));

	collisionComponent = new CollisionComponent(projectile, hitboxComponent->getHitbox());
}

ShootingComponent::~ShootingComponent()
{
	for (auto &proj : projectiles)
	{
		delete proj;
	}
	delete collisionComponent;
}

void ShootingComponent::shoot(sf::Vector2f _dir, float _dt)
{
	//Calculate on which side of the sprite to spawn the bullet
	if (timer > maxTimer)
	{
		//puts the projectile in the middle of the sprite
		sf::FloatRect hitbox_(hitboxComponent->getHitbox());

		sf::Vector2f projectilePos_(sprite.getPosition().x + sprite.getGlobalBounds().width / 2.0f - hitbox_.left - hitbox_.width / 2.0f ,
			sprite.getPosition().y + sprite.getGlobalBounds().height / 2.0f - hitbox_.top - hitbox_.height / 2.0f);

		if (_dir.x > 0.0f)
			projectilePos_.x += sprite.getGlobalBounds().width / 2.0f;
		else if (_dir.x < 0.0f)
			projectilePos_.x -= sprite.getGlobalBounds().width / 2.0f;
		if (_dir.y > 0.0f)
			projectilePos_.y += sprite.getGlobalBounds().height / 2.0f;
		else if (_dir.y < 0.0f)
			projectilePos_.y -= sprite.getGlobalBounds().height / 2.0f;

		projectiles.push_back(new Projectile(_dir, projectilePos_));

		timer = 0.0f;
	}
	
	
}

void ShootingComponent::update(sf::RenderWindow& _window, float _dt)
{
	//updates shooting timer
	timer += 1000.0f * _dt;

	//Gets size of the projectiles

	

	sf::Vector2f projSize_;
	projSize_.x = projectile.getGlobalBounds().width;
	projSize_.y = projectile.getGlobalBounds().height;

	auto it = projectiles.begin();
	while(it != projectiles.end())
	{
		//updates projectiles positions depenidng on speed
		(*it)->update(speed, _dt);

		projectile.setPosition((*it)->getPos());
		 //deletes if out of bounds
		if (collisionComponent->BorderCollision(_window) != sf::Vector2i(0,0))
		{
			delete *it;
			it = projectiles.erase(it);
		}
		else ++it;
	}
}

void ShootingComponent::render(sf::RenderTarget & _target)
{
	for (auto &proj : projectiles)
	{
		projectile.setPosition(proj->getPos());
		_target.draw(projectile);

		//Updates and renders the hitbox
		hitboxComponent->update();
		hitboxComponent->render(_target);
	}
}
