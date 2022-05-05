#include "Life.h"

Life::Life()
{
}

Life::Life(sf::Texture* lifeTexture, float posX, float posY)
{
	this->lifeSprite.setTexture(*lifeTexture);
	this->lifeSprite.setPosition(posX, posY);
}

Life::~Life()
{
}

//Public function
void Life::update(sf::Texture* lifeTexture)
{
	this->lifeSprite.setTexture(*lifeTexture);
}

void Life::render(sf::RenderTarget* target)
{
	target->draw(this->lifeSprite);
}
