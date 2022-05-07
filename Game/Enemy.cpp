#include "Enemy.h"

// Private functions

void Enemy::initVariables()
{
	this->frameCounter = 0;
	if (this->type == 1)
	{
		this->speed = 1.f;
		this->hpMax = 9;
		this->hp = hpMax;
		this->points = 20;
	}
	else if (this->type == 2)
	{
		this->speed = 1.f;
		this->hpMax = 15;
		this->hp = hpMax;
		this->points = 15;
	}
	else if (this->type == 3)
	{
		this->speed = 1.5f;
		this->hpMax = 1;
		this->hp = hpMax;
		this->points = 5;
	}
	else if (this->type == 4)
	{
		this->speed = 1.f;
		this->hpMax = 3;
		this->hp = hpMax;
		this->points = 10;
	}
}

// Cons/Des
Enemy::Enemy(sf::Texture* enemyTexture, int type, float posX, float posY)
{
	this->type = type;
	this->Sprite.setTexture(*enemyTexture);
	this->initVariables();
	this->Sprite.setPosition(posX, posY);
}

Enemy::~Enemy()
{
}

const sf::Vector2f Enemy::getPos() const
{
	return this->Sprite.getPosition();
}

const sf::FloatRect Enemy::getBounds() const
{
	return this->Sprite.getGlobalBounds();
}

void Enemy::hit(int hit)
{
	this->hp -= hit;
}

bool Enemy::dead()
{
	return this->hp<=0;
}

int Enemy::getPoints()
{
	return this->points;
}

void Enemy::updateTime()
{
	if (this->timer != INT_MAX)
	{
		this->timer++;
	}
}

void Enemy::updateMove()
{
	switch (this->type) {
	case 1:
		if (this->frameCounter <= 144)
		{
			this->Sprite.move(0.f, this->speed);
		}
		else if (this->frameCounter <= 288)
		{
			this->Sprite.move(this->speed * -1, 0.f);
		}
		else if (this->frameCounter <= 432)
		{
			this->Sprite.move(0.f, this->speed);
		}
		else if (this->frameCounter <= 576)
		{
			this->Sprite.move(this->speed, 0.f);
		}
		else
		{
			this->frameCounter = 0;
		}
		this->frameCounter++;
		break;
	case 2:
		if (this->frameCounter <= 144)
		{
			this->Sprite.move(this->speed, this->speed * this->frameCounter / 144.f);
		}
		else if (this->frameCounter <= 288)
		{
			this->Sprite.move(this->speed, this->speed * (this->frameCounter - 144) / 144.f / -2);
		}
		else if (this->frameCounter <= 432)
		{
			this->Sprite.move(this->speed * -1, this->speed * (this->frameCounter - 288) / 144.f);
		}
		else if (this->frameCounter <= 576)
		{
			this->Sprite.move(this->speed * -1, this->speed * (this->frameCounter - 432) / 144.f / -2);
		}
		else
		{
			this->frameCounter = 0;
		}
		this->frameCounter++;
		break;
	case 3:
		this->Sprite.move(0.f, this->speed);
		break;
	case 4:
		if (this->frameCounter <= 144)
		{
			this->Sprite.move(this->speed, this->speed);
		}
		else if (this->frameCounter <= 288)
		{
			this->Sprite.move(this->speed * -1, this->speed);
		}
		else
		{
			this->frameCounter = 0;
		}
		this->frameCounter++;
		break;
	}
}

// Public functions
void Enemy::update()
{
	this->updateMove();
}

void Enemy::render(sf::RenderTarget* target)
{
	target->draw(this->Sprite);
}
