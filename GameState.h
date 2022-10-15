#pragma once

#include "State.h"
#include "Player.h"

class GameState :
	public State
{
private:
	Player* player;

	//Functions
	void initKeybinds();
	void initTextures();
	void initPlayers();

public:
	GameState(sf::RenderWindow* _window, std::map<std::string, int>& _supportedKeys, std::stack<State*>* _states);
	virtual ~GameState();

	//Functions
	void updateInput(const float _dt);
	void update(const float _dt);
	void render(sf::RenderTarget& _target);
};

