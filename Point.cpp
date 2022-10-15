#include "Point.h"

Point::Point(float x_, float y_, sf::Color color_, float radius_)
	: x(x_), y(y_), color(color_), radius(radius_)
{

}

Point::Point(float x_, float y_, float radius_)
	: x(x_), y(y_), radius(radius_)
{

}

Point::~Point()
{

}
