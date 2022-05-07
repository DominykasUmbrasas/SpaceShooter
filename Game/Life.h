#pragma once

#include <SFML/Graphics.hpp>
class Life
{
private:

	sf::Sprite Sprite;
	sf::Texture* lifeTexture;

public:

	// Cons/Des
	Life();
	Life(sf::Texture* lifeTexture, float posX, float posY);
	virtual ~Life();


	// Public functions
	void update(sf::Texture* lifeTexture);
	void render(sf::RenderTarget* target);
};

