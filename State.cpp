// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "State.h"

State::State(sf::RenderWindow* _window, std::map<std::string, int>& _supportedKeys, std::stack<State*>* _states)
	:window(_window), supportedKeys(_supportedKeys), states(_states), quit(false)
{

}

State::~State()
{
}

const bool & State::getQuit() const
{
	return quit;
}


void State::endState()
{
	quit = true;
}

void State::updateMousePositions()
{
	mousePosScreen = sf::Mouse::getPosition();
	mousePosWindow = sf::Mouse::getPosition(*window);
	mousePosView = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
}
