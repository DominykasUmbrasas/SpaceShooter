#include "Life.h"

Life::Life()
{
}

Life::Life(sf::Texture* lifeTexture, float posX, float posY)
{
	this->Sprite.setTexture(*lifeTexture);
	this->Sprite.setPosition(posX, posY);
}

Life::~Life()
{
}

//Public function
void Life::update(sf::Texture* lifeTexture)
{
	this->Sprite.setTexture(*lifeTexture);
}

void Life::render(sf::RenderTarget* target)
{
	target->draw(this->Sprite);
}
