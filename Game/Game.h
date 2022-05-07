#pragma once
/*#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>*/

#include <sstream>
#include <vector>
#include <map>
#include "Player.h" 
#include "Bullet.h"
#include "Enemy.h"
#include "Life.h"
#include "Ability.h"
#include "Drop.h"

class Game
{
private:
	//Window
	sf::RenderWindow* window;
	
	sf::Sprite backSprite;

	//Resources
	std::map<std::string, sf::Texture*> textures;


	enum ETextures 
	{
		ET_ENEMY1, ET_ENEMY2, ENEMY3
	};
	std::map<ETextures, sf::Texture*> textures1;

	std::vector<Bullet*> bullets;
	int score;
	int wave;
	std::vector<Life*> lifes;
	int hp;
	std::vector<Ability*> abilities;
	int abil;
	std::vector<Drop*> drops;

	//Player
	Player* player;
	int type;
	bool type2Extra;
	bool alive;

	//Enemys
	float spawnTimer;
	float spawnTimerMax;
	int randX;
	std::vector<Enemy*> enemys;

	//Text
	sf::Font font;
	sf::Text text;

	//Private functions
	void initializeWindow();
	void initTextures();
	void initPlayer();
	void initEnemys();
	void initText();
	void initLife();
	void initAbility();
	

public:
	Game();
	virtual ~Game();


	//Public functions
	void start();

	void spawnWave();

	void updatePollEvents();
	void updateInput();
	void updateBullets();
	void updateDrops();
	void updateEnemysCombat();
	void updateText();
	void updateLife();
	void updateAbility();

	void update();
	void render();
	
};

