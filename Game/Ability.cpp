#include "Ability.h"

Ability::Ability()
{
}

Ability::Ability(sf::Texture* abilityTexture, float posX, float posY)
{
	this->abilitySprite.setTexture(*abilityTexture);
	this->abilitySprite.setPosition(posX, posY);
}

Ability::~Ability()
{
}

//Public function
void Ability::update(sf::Texture* abilityTexture)
{
	this->abilitySprite.setTexture(*abilityTexture);
}

void Ability::render(sf::RenderTarget* target)
{
	target->draw(this->abilitySprite);
}
