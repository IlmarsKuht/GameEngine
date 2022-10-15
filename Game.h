
#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "MainMenuState.h"
#include <stack>



class Game
{
private:
	//Variables
	sf::RenderWindow* window;
	sf::Event sfEvent;

	sf::Clock dtClock;
	float dt; //deltaTime

	std::stack<State*> states;

	std::map<std::string, int> supportedKeys;

	//Initialization functions
	void initVariables();
	void initWindow();
	void initKeys();
	void initStates();


public:
	//Constructors / Destructors
	Game();
	virtual ~Game();

	//Public Functions

	//Update
	void updateDt();
	void updateSFMLEvents();
	void update();

	//Render

	void render();

	//Core
	void run();
};

