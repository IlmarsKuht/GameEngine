// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "HitboxComponent.h"

HitboxComponent::HitboxComponent(sf::Sprite& _sprite, sf::FloatRect _area)
	: sprite(_sprite), area(_area)
{
	initHitbox(area);
}

HitboxComponent::~HitboxComponent()
{

}

void HitboxComponent::initHitbox(sf::FloatRect _area)
{
	hitbox.setOutlineColor(sf::Color::Red);
	hitbox.setOutlineThickness(1.0f);
	hitbox.setFillColor(sf::Color::Transparent);
	hitbox.setSize(sf::Vector2f(_area.width, _area.height));

}

const sf::FloatRect HitboxComponent::getHitbox() const
{
	return area;
}

void HitboxComponent::update()
{
	hitbox.setPosition(sprite.getGlobalBounds().left + area.left, sprite.getGlobalBounds().top + area.top);
}

void HitboxComponent::render(sf::RenderTarget & _target)
{
	_target.draw(hitbox);
}
