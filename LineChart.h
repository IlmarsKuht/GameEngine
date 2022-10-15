#pragma once
#include "Graph.h"

class LineChart :
	public Graph
{
private:

public:
	LineChart(sf::Vector2f pos_, sf::Vector2f size_, float xMin_, float xMax_, float yMin_, float yMax_, float xIncr_, float yIncr_, std::vector<Point> points_);
	~LineChart();

	void addPoint(Point point_);

	void render(sf::RenderTarget& target_);
};

