#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>

class inheritObj
{
private:

	sf::Sprite Sprite;

public:

	// Cons/Des
	inheritObj();
	virtual ~inheritObj();

	virtual const sf::FloatRect getBounds() const;

	// Public functions
	virtual void render(sf::RenderTarget* target);
};





