#pragma once

#include "State.h"
#include "Heart.h"

class JiaoState :
	public State
{
private:
	//variables
	sf::Texture backgroundTexture;
	sf::RectangleShape background;
	sf::Font font;

	std::vector<Heart*> hearts;

	float heartSpawnTimerMax;
	float heartSpawnTimer;

	//Functions
	void initTextures();
	void initVariables();
	void initFonts();
	void initBackground();
	void initKeybinds();
	
	

public:
	JiaoState(sf::RenderWindow* _window, std::map<std::string, int>& _supportedKeys, std::stack<State*>* _states);
	virtual ~JiaoState();

	//Functions
	void spawnHeart();

	void updateInput(const float _dt);
	void update(const float _dt);
	void render(sf::RenderTarget& _target);
};

