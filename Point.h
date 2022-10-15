#pragma once

#include <SFML/Graphics.hpp>

struct Point
{
	float x;
	float y;
	sf::Color color;
	float radius;

	Point(float x_, float y_, sf::Color color_, float radius_ = 10.0f);
	Point(float x_, float y_, float radius_ = 10.0f);
	~Point();
};

