// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "CollisionComponent.h"

CollisionComponent::CollisionComponent(sf::Sprite &_sprite, sf::FloatRect _hitbox)
	: sprite(_sprite), hitbox(_hitbox)
{

}

CollisionComponent::~CollisionComponent()
{

}

const sf::Vector2i CollisionComponent::BorderCollision(sf::RenderWindow& _window) const //USE THE HITBOX NOT THE SPRITE SIZE
{
	sf::Vector2f sPos_ = sprite.getPosition();
	sf::Vector2i direction_(0, 0);

	if (sPos_.x + hitbox.left < 0.0f)
		direction_.x = -1;
	else if (sPos_.x + hitbox.width + hitbox.left > _window.getSize().x)
		direction_.x = 1;
	if (sPos_.y + hitbox.top < 0.0f)
		direction_.y = -1;
	else if (sPos_.y + hitbox.height + hitbox.top > _window.getSize().y)
		direction_.y = 1;

	return direction_;
}
