#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>

class Enemy
{
private:
	sf::Sprite enemySprite;
	sf::Texture* enemyTexture;

	int type;
	float speed;
	int hp;
	int hpMax;
	int points;
	int frameCounter;
	int timer;

	// Private functions
	void initVariables();

public:
	// Cons/Des
	Enemy(sf::Texture* enemyTexture, int type, float posX, float posY);
	virtual ~Enemy();

	const sf::Vector2f getPos() const;
	const sf::FloatRect getBounds() const;

	//Public functions
	void hit(int hit);
	bool dead();
	int getPoints();

	void updateTime();
	void updateMove();
	void update();
	void render(sf::RenderTarget* target);

};

