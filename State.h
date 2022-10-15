#pragma once

#include <SFML/Graphics.hpp>

#include <stack>
#include <fstream>
#include <iostream>

class State
{
private:

protected:
	std::stack<State*>* states;
	sf::RenderWindow* window;
	std::map<std::string, int> supportedKeys;
	std::map<std::string, int> keybinds;
	bool quit;

	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	//Resoursces
	std::map<std::string, sf::Texture> textures;


	//Functions
	virtual void initKeybinds() = 0;

public:
	State(sf::RenderWindow* _window, std::map<std::string, int>& _supportedKeys, std::stack<State*>* _states);
	virtual ~State();

	const bool& getQuit() const;


	void endState();

	virtual void updateMousePositions();
	virtual void updateInput(const float _dt) = 0;
	virtual void update(const float _dt) = 0;
	virtual void render(sf::RenderTarget& _target) = 0;
};



