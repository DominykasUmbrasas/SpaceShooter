#include "Drop.h"

// Cons/Des
Drop::Drop()
{

}

Drop::Drop(sf::Texture* dropTexture, float posX, float posY, float dirX, float dirY, float moveeSpeed, int type)
{
	this->Sprite.setTexture(*dropTexture);
	this->type = type;
	this->Sprite.setPosition(posX, posY);
	this->direction.x = dirX;
	this->direction.y = dirY;
	this->moveSpeed = moveeSpeed;
}

Drop::~Drop()
{

}

const sf::FloatRect Drop::getBounds() const
{
	return this->Sprite.getGlobalBounds();
}

int Drop::getType()
{
	return this->type;
}

// Public functions
void Drop::update()
{
	//Movement
	this->Sprite.move(this->moveSpeed * this->direction);
}

void Drop::render(sf::RenderTarget* target)
{
	target->draw(this->Sprite);
}
