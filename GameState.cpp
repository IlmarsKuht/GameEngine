// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "GameState.h"
#include <iostream>

//Initializer functions
void GameState::initKeybinds()
{
	std::ifstream ifs("Config/gamestate_keybinds.ini");

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

void GameState::initTextures()
{
	if (!textures["PLAYER"].loadFromFile("Resources/Images/Sprites/Player/Player.png"))
	{
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_PLAYER_TEXTURE";
	}
	if (!textures["BULLET"].loadFromFile("Resources/Images/Bullets/bullet_green.png"))
	{
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_BULLET_TEXTURE";
	}
}

void GameState::initPlayers()
{
	player = new Player(window->getSize().x / 2.0f, window->getSize().y / 2.0f, textures["PLAYER"], window);

	player->setSize(200, 200);

	player->createMovementComponent(200.0f);

	player->createShootingComponent(textures["BULLET"], sf::Vector2f(0.02f, 0.02f), 400.0f, 400.0f);

	player->createHitboxComponent(sf::FloatRect(15.0f, 15.0f, 169.0f, 175.0f));

	player->createCollisionComponent();

	player->createGravityComponent(6.0f, 700.0f);
}
//Consutrctor destructors

GameState::GameState(sf::RenderWindow* _window, std::map<std::string, int>& _supportedKeys, std::stack<State*>* _states)
	: State(_window, _supportedKeys, _states)
{
	GameState::initKeybinds();
	initTextures();
	initPlayers();
}

GameState::~GameState()
{
	delete player;
}

void GameState::updateInput(const float _dt)
{
	sf::Vector2f direction_(0.0f, 0.0f);
	//Update player input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keybinds.at("MOVE_LEFT"))))
		direction_.x += -1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keybinds.at("MOVE_RIGHT"))))
		direction_.x += 1;
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keybinds.at("MOVE_UP"))))
		direction_.y += -1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keybinds.at("MOVE_DOWN"))))
		direction_.y += 1;*/
	
	if(direction_.x != 0.0f || direction_.y != 0.0f)
		player->move(direction_.x, direction_.y, _dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keybinds.at("JUMP"))))
		player->jump(-1000.0f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keybinds.at("SHOOT"))))
		player->shoot(player->getDirection(), _dt);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keybinds.at("CLOSE"))))
		endState();
	
}

void GameState::update(const float _dt)
{
	updateMousePositions();
	updateInput(_dt);
	player->update(_dt);
}

void GameState::render(sf::RenderTarget& _target)
{
	player->render(_target);
	
}
