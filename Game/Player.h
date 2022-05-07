#pragma once

#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>


class Player
{
private:
	sf::Sprite playerSprite;
	sf::Texture* playerTexture;

	int type;
	float moveSpeed;
	float attackCooldown;
	float attackCooldownMax;
	int hpMax;
	int hp;
	int abilityMax;
	int ability;
	bool abilityBool;
	bool abilityDmg;
	bool abilityShoot;
	int timer;

	//Private functions
	void initVariables();
	void initSprite();
public:
	Player(sf::Texture* playerTexture, int type);
	virtual ~Player();

	const sf::Vector2f getPos() const;
	const sf::FloatRect getBounds() const;

	//Public functions
	void move(const float dirX, const float dirY);
	void dmg(int x);
	void abilityUse(int x);
	int getHp();
	int getHpMax();
	int getAbility();
	int getAbilityMax();
	bool getAbilityShoot();
	const bool canAttack();
	void updateAttack();
	void updateTimer();
	void updateAbility();
	void update();
	void render(sf::RenderTarget& target);
};

