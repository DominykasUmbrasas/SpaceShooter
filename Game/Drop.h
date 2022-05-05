#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>

class Drop
{
private:

	sf::Sprite dropSprite;
	sf::Texture* dropTexture;

	sf::Vector2f direction;
	float moveSpeed;
	int type;

public:

	// Cons/Des
	Drop();
	Drop(sf::Texture* dropTexture, float posX, float posY, float dirX, float dirY, float moveeSpeed, int type);
	virtual ~Drop();

	const sf::FloatRect getBounds() const;

	// Public functions
	int getType();
	void update();
	void render(sf::RenderTarget* target);
};



