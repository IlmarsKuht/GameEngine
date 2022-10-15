// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "Game.h"

//Static functions


//Initializer functions

void Game::initVariables()
{
	dt = 0.f;
}

void Game::initWindow()
{
	std::ifstream ifs("Config/window.ini");

	std::string title_ = "None";
	

	if (ifs.is_open())
	{
		std::getline(ifs, title_);
	}
	ifs.close();
	
	window = new sf::RenderWindow(sf::VideoMode::getDesktopMode(),title_, sf::Style::Fullscreen);
}

void Game::initKeys()
{
	std::ifstream ifs("Config/supported_keys.ini");

	if (ifs.is_open())
	{
		std::string key_;
		int keyValue_;
		while (ifs >> key_ >> keyValue_)
		{
			supportedKeys[key_] = keyValue_;
		}
	}

	ifs.close();
}

void Game::initStates()
{
	states.push(new MainMenuState(window, supportedKeys, &states));
}



//Consturctor / Destructor
Game::Game()
{
	initVariables();
	initWindow();
	initKeys();
	initStates();

}

Game::~Game()
{
	delete window;
}

//Public functions



//UPDATE FUNCTIONS

void Game::updateDt()
{
	//updates deltatime with the time it takes to update and rener one frame
	dt = dtClock.restart().asSeconds();
}

void Game::updateSFMLEvents()
{
	while (window->pollEvent(sfEvent))
	{
		switch (sfEvent.type)
		{
		case sf::Event::Closed:
			window->close();
		}
	}
}

void Game::update()
{
	updateDt();
	updateSFMLEvents();

	if (!states.empty())
	{
		
		states.top()->update(dt);
		if (states.top()->getQuit())
		{
			states.top()->endState();
			states.pop();
		}
	}
	//Applications end
	else
	{
		window->close();
	}


}

//RENDER FUNCTIONS

void Game::render()
{
	window->clear();


	if (!states.empty())
		states.top()->render(*window);

	window->display();
}


//MAIN GAME LOOP
void Game::run()
{
	std::cout << "is window open: " << window->isOpen() << "\n";
	while (window->isOpen())
	{
		srand(time(0));
		update();
		render();
	}
}
