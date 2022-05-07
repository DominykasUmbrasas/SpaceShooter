#pragma once

#include <SFML/Graphics.hpp>
class Ability
{
private:

	sf::Sprite Sprite;
	sf::Texture* abilityTexture;

public:

	// Cons/Des
	Ability();
	Ability(sf::Texture* abilityTexture, float posX, float posY);
	virtual ~Ability();


	// Public functions
	void update(sf::Texture* abilityTexture);
	void render(sf::RenderTarget* target);
};


