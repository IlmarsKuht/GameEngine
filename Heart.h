#pragma once
#include "Entity.h"

class Heart :
	public Entity
{
private:
	short int transparency;


	void initVariables();

public:

	Heart(sf::RenderWindow* _window, float _xPos, float _yPos, sf::Texture _texture, float _sizeX, float _sizeY);
	~Heart();

	short int getTransparency();


	void update(float _dt);
	void render(sf::RenderTarget& _target);
};

