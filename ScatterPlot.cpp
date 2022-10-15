#include "ScatterPlot.h"


void ScatterPlot::initPointBody()
{
	
}

ScatterPlot::ScatterPlot(sf::Vector2f pos_, sf::Vector2f size_, float xMin_, float xMax_, float yMin_, float yMax_, float xIncr_, float yIncr_, std::vector<Point> points_)
	: Graph(pos_, size_, xMin_, xMax_, yMin_, yMax_, xIncr_, yIncr_, points_)
{
	initPointBody();
}

ScatterPlot::~ScatterPlot()
{

}

void ScatterPlot::addPoint(Point point_)
{
	points.push_back(point_);
}

void ScatterPlot::render(sf::RenderTarget& target_)
{
	Graph::render(target_);
	sf::Vector2f _graphPos = getPos();
	sf::Vector2f _graphSize = getGraphSize();

	for (Point& _point : points)
	{
		pointBody.setPosition(_graphPos.x + (_point.x * getUnitSize().x),(_graphPos.y + _graphSize.y) - _point.y * getUnitSize().y);
		pointBody.setFillColor(_point.color);
		pointBody.setRadius(_point.radius);
		pointBody.setOrigin(_point.radius, _point.radius);
		target_.draw(pointBody);
	}

}
