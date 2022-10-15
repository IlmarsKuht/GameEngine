#include "Graph.h"
#include <iostream>

void Graph::initBox(sf::Vector2f pos_, sf::Vector2f size_)
{
	//Border
	box.setPosition(pos_);
	box.setSize(size_);
	box.setOutlineColor(sf::Color::Blue);
	box.setOutlineThickness(5.0f);
	box.setFillColor(sf::Color(192, 192, 192));

	//Sections
	
}

void Graph::initFonts()
{
	if (!font.loadFromFile("Fonts/Dosis-Light.ttf"))
	{
		throw("ERROR::MAINMENUSTATE:: COULD NOT LOAD FONT");
	}
}

void Graph::initText()
{
	text.setFont(font);
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(23);
	
}

Graph::Graph(sf::Vector2f pos_, sf::Vector2f size_, float xMin_, float xMax_, float yMin_, float yMax_, float xIncr_, float yIncr_, std::vector<Point> points_)
	: xIncr(xIncr_), yIncr(yIncr_), limits(xMax_, xMin_, yMax_, yMin_), points(points_)
{
	initFonts();
	initText();

	initBox(pos_, size_);
}

Graph::~Graph()
{

}

sf::Vector2f Graph::getUnitSize()
{
	return sf::Vector2f(box.getSize().x / (abs(limits.xMax) + abs(limits.xMin)), box.getSize().y / (abs(limits.yMax) + abs(limits.yMin)));
}



sf::Vector2f Graph::getGraphSize()
{
	return box.getSize();
}

sf::Vector2f Graph::getPos()
{
	return box.getPosition();
}

Limits Graph::getLimits()
{
	return limits;
}

void Graph::clearPoints()
{
	points.clear();
}

void Graph::render(sf::RenderTarget & target_)
{
	target_.draw(box);

	// define a 100x100 square, red, with a 10x10 texture mapped on it
	sf::Vertex vertices[] =
	{
		sf::Vertex(sf::Vector2f(box.getPosition().x,  box.getPosition().y + box.getSize().y), sf::Color::Red),
		sf::Vertex(sf::Vector2f(box.getPosition().x,  box.getPosition().y), sf::Color::Blue),
	};
	// draw it
	//places every 50 units x marker
	for (int i = xIncr; i < getUnitSize().x * (abs(limits.xMin) + abs(limits.xMax)); i += xIncr)
	{
		vertices[0].position.x += xIncr;
		vertices[1].position.x += xIncr;
		target_.draw(vertices, 2, sf::Lines);

		//give the number
		std::string number = std::to_string(i / getUnitSize().x);
		for (int j = 0; j < number.length(); j++)
		{
			if (number[j] == '.')
			{
				number.resize(j + 3);
			}
		}

		text.setString(number);
		
		text.setPosition(vertices[0].position.x - text.getGlobalBounds().width / 2.0f, vertices[0].position.y);
		target_.draw(text);
	}


	vertices[0].position.x = box.getPosition().x;
	vertices[0].position.y = box.getPosition().y + box.getSize().y;

	vertices[1].position.x = box.getPosition().x + box.getSize().x;
	vertices[1].position.y = box.getPosition().y + box.getSize().y;

	//places every 50 units x marker
	for (int i = yIncr; i < getUnitSize().y * (abs(limits.yMin) + abs(limits.yMax)); i += yIncr)
	{
		vertices[0].position.y -= yIncr;
		vertices[1].position.y -= yIncr;
		target_.draw(vertices, 2, sf::Lines);

		//Set the number
		std::string number = std::to_string(i / getUnitSize().y);
		for (int j = 0; j < number.length(); j++)
		{
			if (number[j] == '.')
			{
				number.resize(j + 3);
			}
		}

		text.setString(number);

		text.setPosition(box.getPosition().x - text.getGlobalBounds().width, vertices[0].position.y - text.getGlobalBounds().height);
		target_.draw(text);
	}
}
