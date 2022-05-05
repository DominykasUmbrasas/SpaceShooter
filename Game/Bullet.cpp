#include "Bullet.h"



// Cons/Des
Bullet::Bullet()
{

}

Bullet::Bullet(sf::Texture* bulletTexture, float posX, float posY, float dirX, float dirY, float moveeSpeed)
{
	this->bulletSprite.setTexture(*bulletTexture);

	this->bulletSprite.setPosition(posX, posY);
	this->direction.x = dirX;
	this->direction.y = dirY;
	this->moveSpeed = moveeSpeed;
}

Bullet::~Bullet()
{

}

const sf::FloatRect Bullet::getBounds() const
{
	return this->bulletSprite.getGlobalBounds();
}

// Public functions
void Bullet::update()
{
	//Movement
	this->bulletSprite.move(this->moveSpeed * this->direction);
}

void Bullet::render(sf::RenderTarget* target)
{
	target->draw(this->bulletSprite);
}
