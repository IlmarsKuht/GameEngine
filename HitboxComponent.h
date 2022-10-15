#pragma once
#include <SFML/Graphics.hpp>

class HitboxComponent
{

private:
	sf::Sprite& sprite;
	sf::RectangleShape hitbox;
	sf::FloatRect area;
public:

	HitboxComponent(sf::Sprite& _sprite, sf::FloatRect _area);
	~HitboxComponent();

	void initHitbox(sf::FloatRect _area);

	//getters and setters

	const sf::FloatRect getHitbox() const;

	void update();
	void render(sf::RenderTarget& _target);

};

