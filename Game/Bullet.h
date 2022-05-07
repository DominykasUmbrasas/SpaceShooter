#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>

class Bullet
{
private:

	sf::Sprite Sprite;
	sf::Texture* bulletTexture;

	sf::Vector2f direction;
	float moveSpeed;

public:

	// Cons/Des
	Bullet();
	Bullet(sf::Texture* bulletTexture, float posX, float posY, float dirX, float dirY, float moveeSpeed);
	virtual ~Bullet();

	const sf::FloatRect getBounds() const;

	// Public functions
	void update();
	void render(sf::RenderTarget* target);
};

