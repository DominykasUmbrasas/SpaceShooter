#include "Player.h"

void Player::initVariables()
{
	if (this->type == 1)
	{
		this->moveSpeed = 2.f;
		this->attackCooldownMax = 24.f;
		this->attackCooldown = this->attackCooldownMax;
		this->hpMax = 5;
		this->hp = this->hpMax;
	}
	else if (this->type == 2)
	{
		this->moveSpeed = 3.f;
		this->attackCooldownMax = 4.5f;
		this->attackCooldown = this->attackCooldownMax;
		this->hpMax = 3;
		this->hp = this->hpMax;
	}
	else if (this->type == 3)
	{
		this->moveSpeed = 1.5f;
		this->attackCooldownMax = 19.f;
		this->attackCooldown = this->attackCooldownMax;
		this->hpMax = 7;
		this->hp = this->hpMax;
	}
	this->abilityMax = 3;
	this->ability = this->abilityMax;
	this->abilityBool = false;
	this->timer = 720;
	this->abilityDmg = true;
	this->abilityShoot = false;
}

//	Private functions
void Player::initTexture()
{
	// Load texture
	//if (!this->playerTexture.loadFromFile("Textures/Player/Plane.png"))
	//{
	//	std::cout << "Missing Player Texture\n";
	//}
}

void Player::initSprite()
{
	// Give texture to sprite
	
	this->playerSprite.setPosition(375,900);
	// Resize te sprite
	this->playerSprite.scale(1.f, 1.f);

}

// Cons/Des
Player::Player(sf::Texture* playerTexture, int type)
{
	this->type = type;
	this->initVariables();
	this->initTexture();
	this->playerSprite.setTexture(*playerTexture);
	this->initSprite();
}

Player::~Player()
{
}

const sf::Vector2f Player::getPos() const
{
	return this->playerSprite.getPosition();
}

const sf::FloatRect Player::getBounds() const
{
	return this->playerSprite.getGlobalBounds();
}



//Public functions
void Player::move(const float dirX, const float dirY)
{
	this->playerSprite.move(this->moveSpeed * dirX, this->moveSpeed * dirY);
}

void Player::dmg(int x)
{
	if (this->abilityDmg)
	{
		this->hp += x;
	}
}

void Player::abilityUse(int x)
{
	if (this->ability!=0 && this->timer >= 720 && x==-1)
	{
		this->ability += x;
		this->abilityBool = true;
		this->timer = 0;
	}
	else if (x==1)
	{
		this->ability += x;
	}

}

int Player::getHp()
{
	return this->hp;
}

int Player::getHpMax()
{
	return this->hpMax;
}

int Player::getAbility()
{
	return this->ability;
}

int Player::getAbilityMax()
{
	return this->abilityMax;
}

bool Player::getAbilityShoot()
{
	return this->abilityShoot;
}

const bool Player::canAttack()
{
	if (this->attackCooldown >= this->attackCooldownMax)
	{
		this->attackCooldown = 0.f;
		return true;
	}
	return false;
}

void Player::updateAttack()
{
	if (this->attackCooldown < this->attackCooldownMax)
	{
		this->attackCooldown += 0.5f;
	}
}

void Player::updateTimer()
{
	if (this->timer!=INT_MAX)
	{
		this->timer++;
	}
}

void Player::updateAbility()
{
	if (this->abilityBool)
	{
		switch (this->type) {
		case 1:
			this->abilityShoot = true;
			break;
		case 2:
			this->attackCooldownMax = 1.5f;
			break;
		case 3:
			this->abilityDmg = false;
			this->moveSpeed = 4.f;
			break;
		}
		if (this->timer > 720)
		{
			this->abilityBool = false;
			switch (this->type) {
			case 1:
				this->abilityShoot = false;
				break;
			case 2:
				this->attackCooldownMax = 4.5f;
				break;
			case 3:
				this->abilityDmg = true;
				this->moveSpeed = 1.5f;
				break;
			}
		}
	}
}

void Player::update()
{
	this->updateAttack();
	this->updateTimer();
	this->updateAbility();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->playerSprite);
}
