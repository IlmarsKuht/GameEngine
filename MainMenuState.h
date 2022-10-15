#pragma once

#include "Button.h"
#include "State.h"

class MainMenuState :
	public State
{
private:
	//variables
	sf::Texture backgroundTexture;
	sf::RectangleShape background;
	sf::Font font;

	std::map<std::string, Button*> buttons;

	//Functions
	void initVariables();
	void initFonts();
	void initBackground();
	void initKeybinds();
	void initButtons();

public:
	MainMenuState(sf::RenderWindow* _window, std::map<std::string, int>& _supportedKeys, std::stack<State*>* _states);
	virtual ~MainMenuState();

	//Functions
	void updateInput(const float _dt);
	void updateButtons(float dt_);
	void update(const float _dt);
	void renderButtons(sf::RenderTarget& _target);
	void render(sf::RenderTarget& _target);
};

