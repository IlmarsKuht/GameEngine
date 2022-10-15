// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "JiaoState.h"

//Initiliazer functions

void JiaoState::initVariables()
{
	heartSpawnTimerMax = 50.0f;
	heartSpawnTimer = heartSpawnTimerMax;
}

void JiaoState::initTextures()
{
	if (!textures["HEART"].loadFromFile("Resources/Images/Sprites/heart.png"))
	{
		throw "ERROR::JIAO_STATE::COULD_NOT_LOAD_HEART_TEXTURE";
	}
}

void JiaoState::initFonts()
{
	if (!font.loadFromFile("Fonts/Dosis-Light.ttf"))
	{
		throw("ERROR::JIAOSTATE:: COULD NOT LOAD FONT");
	}
}

void JiaoState::initBackground()
{
	background.setSize(sf::Vector2f(static_cast<float>(window->getSize().x), static_cast<float>(window->getSize().y)));

	if (!backgroundTexture.loadFromFile("Resources/Images/Backgrounds/main_menu.png"))
	{
		throw "ERROR::JIAOSTATE::FAILES_TO_LOAD_BACKGROUDN_IMAGE";
	}
	background.setTexture(&backgroundTexture);
}


void JiaoState::initKeybinds()
{
	std::ifstream ifs("Config/jiaostate_keybinds.ini");
	
	if (ifs.is_open())
	{
		std::string key_;
		std::string key2_;
		while (ifs >> key_ >> key2_)
		{
			keybinds[key_] = supportedKeys.at(key2_);
		}
	}

	ifs.close();
}




JiaoState::JiaoState(sf::RenderWindow* _window, std::map<std::string, int>& _supportedKeys, std::stack<State*>* _states)
	: State(_window, _supportedKeys, _states)
{
	initTextures();
	initVariables();
	initFonts();
	initBackground();
	initKeybinds();
}

JiaoState::~JiaoState()
{
	auto heart = hearts.begin();
	while (heart != hearts.end())
	{
		delete (*heart);
	}
}

void JiaoState::spawnHeart()
{
	if (heartSpawnTimer >= heartSpawnTimerMax)
	{
		hearts.push_back(new Heart(window, static_cast<float>(rand() % window->getSize().x), static_cast<float>(rand() % window->getSize().y), textures["HEART"], 100.0f, 100.0f));
		heartSpawnTimer = 0.0f;
	}	
	else
		heartSpawnTimer += 1.0f;
}

void JiaoState::updateInput(const float _dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keybinds.at("CLOSE"))))
		endState();
}


void JiaoState::update(const float _dt)
{
	updateMousePositions();
	updateInput(_dt);

	spawnHeart();

	//updates hearts and deletes if they have become completely transparent
	auto heart = hearts.begin();
	while (heart != hearts.end())
	{
		(*heart)->update(_dt);
		if ((*heart)->getTransparency() <= 0.0f)
		{
			delete (*heart);
			heart = hearts.erase(heart);
		}
		else 
			++heart;
	}
	
}


void JiaoState::render(sf::RenderTarget& _target)
{
	_target.draw(background);

	auto heart = hearts.begin();

	//renders all the hearts
	while (heart != hearts.end())
	{
		(*heart)->render(_target);
		++heart;
	}
}
