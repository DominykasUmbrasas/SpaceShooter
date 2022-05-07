#include "Bullet.h"



// Cons/Des
Bullet::Bullet()
{

}

Bullet::Bullet(sf::Texture* bulletTexture, float posX, float posY, float dirX, float dirY, float moveeSpeed)
{
	this->Sprite.setTexture(*bulletTexture);

	this->Sprite.setPosition(posX, posY);
	this->direction.x = dirX;
	this->direction.y = dirY;
	this->moveSpeed = moveeSpeed;
}

Bullet::~Bullet()
{

}

const sf::FloatRect Bullet::getBounds() const
{
	return this->Sprite.getGlobalBounds();
}

// Public functions
void Bullet::update()
{
	//Movement
	this->Sprite.move(this->moveSpeed * this->direction);
}

void Bullet::render(sf::RenderTarget* target)
{
	target->draw(this->Sprite);
}
