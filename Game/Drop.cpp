#include "Drop.h"

// Cons/Des
Drop::Drop()
{

}

Drop::Drop(sf::Texture* dropTexture, float posX, float posY, float dirX, float dirY, float moveeSpeed, int type)
{
	this->dropSprite.setTexture(*dropTexture);
	this->type = type;
	this->dropSprite.setPosition(posX, posY);
	this->direction.x = dirX;
	this->direction.y = dirY;
	this->moveSpeed = moveeSpeed;
}

Drop::~Drop()
{

}

const sf::FloatRect Drop::getBounds() const
{
	return this->dropSprite.getGlobalBounds();
}

int Drop::getType()
{
	return this->type;
}

// Public functions
void Drop::update()
{
	//Movement
	this->dropSprite.move(this->moveSpeed * this->direction);
}

void Drop::render(sf::RenderTarget* target)
{
	target->draw(this->dropSprite);
}
