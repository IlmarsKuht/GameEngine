#pragma once

#include <SFML/Graphics.hpp>
#include "Point.h"

struct Limits {
	float xMax;
	float xMin;
	float yMax;
	float yMin;

	Limits(float xMax_, float xMin_, float yMax_, float yMin_)
		: xMax(xMax_), xMin(xMin_), yMax(yMax_), yMin(yMin_)
	{

	}
};

class Graph
{
private:
	sf::RectangleShape box;
	Limits limits;
	float xIncr;
	float yIncr;
	sf::Font font;
	sf::Text text;

protected:
	std::vector<Point> points;


	void initBox(sf::Vector2f pos_, sf::Vector2f size_);
	void initFonts();
	void initText();

public:
	Graph(sf::Vector2f pos_, sf::Vector2f size_, float xMin_, float xMax_, float yMin_, float yMax_, float xIncr_, float yIncr_, std::vector<Point> points_);
	~Graph();

	sf::Vector2f getUnitSize();
	sf::Vector2f getGraphSize();
	sf::Vector2f getPos();
	Limits getLimits();

	void clearPoints();

	virtual void render(sf::RenderTarget& target_);
};

