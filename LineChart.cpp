#include "LineChart.h"

LineChart::LineChart(sf::Vector2f pos_, sf::Vector2f size_, float xMin_, float xMax_, float yMin_, float yMax_, float xIncr_, float yIncr_, std::vector<Point> points_)
	:Graph(pos_, size_, xMin_, xMax_, yMin_, yMax_, xIncr_, yIncr_, points_)
{
}

LineChart::~LineChart()
{

}

void LineChart::addPoint(Point point_)
{
	points.push_back(point_);
}

void LineChart::render(sf::RenderTarget& target_)
{
	Graph::render(target_);

	//graph the points
	sf::Vector2f _graphPos = getPos();
	sf::Vector2f _graphSize = getGraphSize();

	sf::Vertex vertices[] =
	{
		sf::Vertex(sf::Vector2f(0,0), sf::Color::Red),
		sf::Vertex(sf::Vector2f(0,0), sf::Color::Red)
	};
	

	for (int i = 1; i < points.size(); i++)
	{
		vertices[0].position.x = _graphPos.x + (points[i-1].x * getUnitSize().x);
		vertices[0].position.y = _graphPos.y + _graphSize.y - (points[i-1].y * getUnitSize().y);

		vertices[1].position.x = _graphPos.x + (points[i].x * getUnitSize().x);
		vertices[1].position.y = _graphPos.y + _graphSize.y - (points[i].y * getUnitSize().y);

		target_.draw(vertices, 2, sf::Lines);
	}

}
