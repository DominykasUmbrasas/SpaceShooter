#include "Ability.h"

Ability::Ability()
{
}

Ability::Ability(sf::Texture* abilityTexture, float posX, float posY)
{
	this->Sprite.setTexture(*abilityTexture);
	this->Sprite.setPosition(posX, posY);
}

Ability::~Ability()
{
}

//Public function
void Ability::update(sf::Texture* abilityTexture)
{
	this->Sprite.setTexture(*abilityTexture);
}

void Ability::render(sf::RenderTarget* target)
{
	target->draw(this->Sprite);
}
