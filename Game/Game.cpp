#include "Game.h"


//Private functions

void Game::initializeWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 1040), "Space", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);
}

void Game::initTextures()
{
	this->textures["BULLET1"] = new sf::Texture();
	this->textures["BULLET1"]->loadFromFile("Textures/Bullets/Bullet1.png");
	this->textures["BULLET2"] = new sf::Texture();
	this->textures["BULLET2"]->loadFromFile("Textures/Bullets/Bullet2.png");
	this->textures["BULLET3"] = new sf::Texture();
	this->textures["BULLET3"]->loadFromFile("Textures/Bullets/Bullet3.png");

	this->textures["PLAYER1"] = new sf::Texture();
	this->textures["PLAYER1"]->loadFromFile("Textures/Player/Plane.png");
	this->textures["PLAYER2"] = new sf::Texture();
	this->textures["PLAYER2"]->loadFromFile("Textures/Player/DoubleBarr.png");
	this->textures["PLAYER3"] = new sf::Texture();
	this->textures["PLAYER3"]->loadFromFile("Textures/player/BigBoy.png");

	this->textures["LIFEEMTY"] = new sf::Texture();
	this->textures["LIFEEMTY"]->loadFromFile("Textures/Player/LifeEmty.png");
	this->textures["LIFEFULL"] = new sf::Texture();
	this->textures["LIFEFULL"]->loadFromFile("Textures/player/LifeFull.png");

	this->textures["ABILITYEMTY"] = new sf::Texture();
	this->textures["ABILITYEMTY"]->loadFromFile("Textures/Player/AbilityEmty.png");
	this->textures["ABILITYFULL"] = new sf::Texture();
	this->textures["ABILITYFULL"]->loadFromFile("Textures/player/AbilityFull.png");

	this->textures["ENEMY1"] = new sf::Texture();
	this->textures["ENEMY1"]->loadFromFile("Textures/Enemys/B.png");
	this->textures["ENEMY2"] = new sf::Texture();
	this->textures["ENEMY2"]->loadFromFile("Textures/Enemys/G.png");
	this->textures["ENEMY3"] = new sf::Texture();
	this->textures["ENEMY3"]->loadFromFile("Textures/Enemys/R.png");
	this->textures["ENEMY4"] = new sf::Texture();
	this->textures["ENEMY4"]->loadFromFile("Textures/Enemys/Y.png");

	this->textures["BACKGROUND"] = new sf::Texture();
	this->textures["BACKGROUND"]->loadFromFile("Textures/Background/SpacePix.jpg");
	this->textures["BACKGROUND2"] = new sf::Texture();
	this->textures["BACKGROUND2"]->loadFromFile("Textures/Background/Back1.jpg");
	this->textures["BACKGROUND3"] = new sf::Texture();
	this->textures["BACKGROUND3"]->loadFromFile("Textures/Background/GameOver.jpg");
}

//Creats Player based on a type
void Game::initPlayer()
{
	this->alive = true;
	if (this->type == 1)
	{
		this->player = new Player(this->textures["PLAYER1"], this->type);
	}
	else if (this->type == 2)
	{
		this->player = new Player(this->textures["PLAYER2"], this->type);
		this->type2Extra = true;
	}
	else if (this->type == 3)
	{
		this->player = new Player(this->textures["PLAYER3"], this->type);
	}
	else
	{
		this->player = new Player(this->textures["PLAYER3"], this->type);
	}
}

void Game::initEnemys()
{
	this->spawnTimerMax = 500.f;
	this->spawnTimer = this->spawnTimerMax;
	
}

void Game::initText()
{
	this->font.loadFromFile("Fonts/HackbotFreeTrial-8MgA2.otf");

	this->text.setFont(this->font);
	this->text.setCharacterSize(30);
	this->text.setFillColor(sf::Color::White);
	this->text.setOutlineColor(sf::Color::Black);
	this->text.setOutlineThickness(1);
	this->text.setString("NONE");
}

void Game::initLife()
{
	this->hp = this->player->getHpMax();
	for (int i = 0; i < hp; i++)
	{
		this->lifes.push_back(new Life(this->textures["LIFEFULL"], 760 - i * 40, 10));
	}
}

void Game::initAbility()
{
	this->abil = this->player->getAbilityMax();
	for (int i = 0; i < abil; i++)
	{
		this->abilities.push_back(new Ability(this->textures["ABILITYFULL"], 763 - i * 40, 50));
	}
}


// Cons/Des
Game::Game()
{
	this->initializeWindow();
	this->initTextures();
	this->initEnemys();
	this->initText();

	this->type = 0;
	this->score = 0;
	this->backSprite.setTexture(*this->textures["BACKGROUND2"]);
	while (this->type == 0)
	{
		this->window->draw(backSprite);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::J))
		{
			this->type = 1;
			this->backSprite.setTexture(*this->textures["BACKGROUND"]);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::K))
		{
			this->type = 2;
			this->backSprite.setTexture(*this->textures["BACKGROUND"]);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::L))
		{
			this->type = 3;
			this->backSprite.setTexture(*this->textures["BACKGROUND"]);
		}
		this->window->display();
		this->updatePollEvents();
	}

	this->initPlayer();
	this->initLife();
	this->initAbility();
}
Game::~Game()
{
	delete this->window;
	delete this->player;

	//Delete bullets
	for (auto bullet : this->bullets)
	{
		delete bullet;
	}

	//Delete enemys
	for (auto enemy : this->enemys)
	{
		delete enemy;
	}

	//Delete lifes
	for (auto life : this->lifes)
	{
		delete life;
	}

	//Delete abilities
	for (auto ability : this->abilities)
	{
		delete ability;
	}

	//Delete drops
	for (auto drop : this->drops)
	{
		delete drop;
	}

	//Delete textures
	for (auto& texture : this->textures)
	{
		delete texture.second;
	}
}


//Public functions

//Game start function, main loop
void Game::start()
{
	//Game loop
	while (this->window->isOpen()/*this->running() && !this->endGame */)
	{
		//Update
		this->update();
		//Render
		this->render();
	}

}

void Game::spawnWave()
{
	this->wave = rand() % 8;

	switch (this->wave) {
	case 0:
		// X B
		this->randX = rand() % 350;//740 60 60
		// 2 from middle
		this->enemys.push_back(new Enemy(this->textures["ENEMY1"], 1, 150.f + randX, -70.f));
		this->enemys.push_back(new Enemy(this->textures["ENEMY1"], 1, 390.f + randX, -70.f));
		this->enemys.push_back(new Enemy(this->textures["ENEMY1"], 1, 150.f + randX, -310.f));
		this->enemys.push_back(new Enemy(this->textures["ENEMY1"], 1, 390.f + randX, -310.f));
		// 1 from middle
		this->enemys.push_back(new Enemy(this->textures["ENEMY1"], 1, 210.f + randX, -130.f));
		this->enemys.push_back(new Enemy(this->textures["ENEMY1"], 1, 330.f + randX, -130.f));
		this->enemys.push_back(new Enemy(this->textures["ENEMY1"], 1, 210.f + randX, -250.f));
		this->enemys.push_back(new Enemy(this->textures["ENEMY1"], 1, 330.f + randX, -250.f));
		// Middel
		this->enemys.push_back(new Enemy(this->textures["ENEMY1"], 1, 270.f + randX, -190.f));
		break;
	case 1:
		// Triangle B
		this->randX = rand() % 290;//740 50 80
		// 1 row
		this->enemys.push_back(new Enemy(this->textures["ENEMY1"], 1, 150.f + randX, -70.f));
		this->enemys.push_back(new Enemy(this->textures["ENEMY1"], 1, 250.f + randX, -70.f));
		this->enemys.push_back(new Enemy(this->textures["ENEMY1"], 1, 350.f + randX, -70.f));
		this->enemys.push_back(new Enemy(this->textures["ENEMY1"], 1, 450.f + randX, -70.f));
		// 2 row
		this->enemys.push_back(new Enemy(this->textures["ENEMY1"], 1, 200.f + randX, -150.f));
		this->enemys.push_back(new Enemy(this->textures["ENEMY1"], 1, 300.f + randX, -150.f));
		this->enemys.push_back(new Enemy(this->textures["ENEMY1"], 1, 400.f + randX, -150.f));
		// 3 row
		this->enemys.push_back(new Enemy(this->textures["ENEMY1"], 1, 250.f + randX, -230.f));
		this->enemys.push_back(new Enemy(this->textures["ENEMY1"], 1, 350.f + randX, -230.f));
		// 4 row
		this->enemys.push_back(new Enemy(this->textures["ENEMY1"], 1, 300.f + randX, -310.f));
		break;
	case 2:
		// Circle G
		this->randX = rand() % 275;// 740 60 60  30
		// Left
		this->enemys.push_back(new Enemy(this->textures["ENEMY2"], 2, 0.f + randX, -160.f));
		// Left 2
		this->enemys.push_back(new Enemy(this->textures["ENEMY2"], 2, 30.f + randX, -100.f));
		this->enemys.push_back(new Enemy(this->textures["ENEMY2"], 2, 30.f + randX, -220.f));
		// Middle
		this->enemys.push_back(new Enemy(this->textures["ENEMY2"], 2, 90.f + randX, -70.f));
		this->enemys.push_back(new Enemy(this->textures["ENEMY2"], 2, 90.f + randX, -250.f));
		// Right 2
		this->enemys.push_back(new Enemy(this->textures["ENEMY2"], 2, 150.f + randX, -100.f));
		this->enemys.push_back(new Enemy(this->textures["ENEMY2"], 2, 150.f + randX, -220.f));
		// Right
		this->enemys.push_back(new Enemy(this->textures["ENEMY2"], 2, 180.f + randX, -160.f));
		break;
	case 3:
		// Half circle G
		// Corners
		this->enemys.push_back(new Enemy(this->textures["ENEMY2"], 2, 0.f, -127.f));
		this->enemys.push_back(new Enemy(this->textures["ENEMY2"], 2, 455.f, -127.f));
		// Middle
		this->enemys.push_back(new Enemy(this->textures["ENEMY2"], 2, 228.f, -62.f));
		// Sides
		this->enemys.push_back(new Enemy(this->textures["ENEMY2"], 2, 148.f, -70.f));
		this->enemys.push_back(new Enemy(this->textures["ENEMY2"], 2, 71.f, -92.f));
		this->enemys.push_back(new Enemy(this->textures["ENEMY2"], 2, 308.f, -70.f));
		this->enemys.push_back(new Enemy(this->textures["ENEMY2"], 2, 385.f, -92.f));
		break;
	case 4:
		// Colum R
		this->randX = rand() % 645;//745 50 70  35
		// Left
		this->enemys.push_back(new Enemy(this->textures["ENEMY3"], 3, 0.f + randX, -315.f));
		this->enemys.push_back(new Enemy(this->textures["ENEMY3"], 3, 0.f + randX, -245.f));
		this->enemys.push_back(new Enemy(this->textures["ENEMY3"], 3, 0.f + randX, -175.f));
		this->enemys.push_back(new Enemy(this->textures["ENEMY3"], 3, 0.f + randX, -105.f));
		// Midle
		this->enemys.push_back(new Enemy(this->textures["ENEMY3"], 3, 50.f + randX, -280.f));
		this->enemys.push_back(new Enemy(this->textures["ENEMY3"], 3, 50.f + randX, -210.f));
		this->enemys.push_back(new Enemy(this->textures["ENEMY3"], 3, 50.f + randX, -140.f));
		this->enemys.push_back(new Enemy(this->textures["ENEMY3"], 3, 50.f + randX, -70.f));
		// Right
		this->enemys.push_back(new Enemy(this->textures["ENEMY3"], 3, 100.f + randX, -315.f));
		this->enemys.push_back(new Enemy(this->textures["ENEMY3"], 3, 100.f + randX, -245.f));
		this->enemys.push_back(new Enemy(this->textures["ENEMY3"], 3, 100.f + randX, -175.f));
		this->enemys.push_back(new Enemy(this->textures["ENEMY3"], 3, 100.f + randX, -105.f));
		break;
	case 5:
		// Line R
		this->randX = 62;
		// Top
		for (int i = 0; i < 13; i++)
		{
			this->enemys.push_back(new Enemy(this->textures["ENEMY3"], 3, 0.f + randX * i, -130.f));
		}
		// Bottom
		for (int i = 0; i < 12; i++)
		{
			this->enemys.push_back(new Enemy(this->textures["ENEMY3"], 3, 31.f + randX * i, -70.f));
		}
		break;
	case 6:
		// Diamond Y
		this->randX = rand() % 460;//600 70 60 -390
		// Middle
		this->enemys.push_back(new Enemy(this->textures["ENEMY4"], 4, 0.f + randX, -190.f));
		this->enemys.push_back(new Enemy(this->textures["ENEMY4"], 4, 70.f + randX, -190.f));
		this->enemys.push_back(new Enemy(this->textures["ENEMY4"], 4, 140.f + randX, -190.f));
		// 1 from middle
		this->enemys.push_back(new Enemy(this->textures["ENEMY4"], 4, 35.f + randX, -250.f));
		this->enemys.push_back(new Enemy(this->textures["ENEMY4"], 4, 105.f + randX, -250.f));
		this->enemys.push_back(new Enemy(this->textures["ENEMY4"], 4, 35.f + randX, -130.f));
		this->enemys.push_back(new Enemy(this->textures["ENEMY4"], 4, 105.f + randX, -130.f));
		// 2 from middlee
		this->enemys.push_back(new Enemy(this->textures["ENEMY4"], 4, 70.f + randX, -310.f));
		this->enemys.push_back(new Enemy(this->textures["ENEMY4"], 4, 70.f + randX, -70.f));
		break;
	case 7:
		// Bolt Y
		this->randX = rand() % 460;//600 70 60 -60
		// Middle
		this->enemys.push_back(new Enemy(this->textures["ENEMY4"], 4, 0.f + randX, -250.f));
		this->enemys.push_back(new Enemy(this->textures["ENEMY4"], 4, 70.f + randX, -250.f));
		this->enemys.push_back(new Enemy(this->textures["ENEMY4"], 4, 140.f + randX, -250.f));
		// 1 from middle
		this->enemys.push_back(new Enemy(this->textures["ENEMY4"], 4, 35.f + randX, -310.f));
		this->enemys.push_back(new Enemy(this->textures["ENEMY4"], 4, 105.f + randX, -190.f));
		// 2 from middlee
		this->enemys.push_back(new Enemy(this->textures["ENEMY4"], 4, 70.f + randX, -370.f));
		this->enemys.push_back(new Enemy(this->textures["ENEMY4"], 4, 70.f + randX, -130.f));
		// 3 from middle
		this->enemys.push_back(new Enemy(this->textures["ENEMY4"], 4, 35.f + randX, -70.f));
		this->enemys.push_back(new Enemy(this->textures["ENEMY4"], 4, 105.f + randX, -430.f));
		break;
	default:
		std::cout << "Failed to spawn wave\n";
	}
}

void Game::updatePollEvents()
{
	sf::Event e;
	while (this->window->pollEvent(e))
	{
		if (e.Event::type == sf::Event::Closed || e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape)
		{
			this->window->close();
			this->type = 10;
			this->alive = true;
		}
	}
}

void Game::updateInput()
{
	// Move player
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && this->player->getBounds().left >= 0)
	{
		this->player->move(-1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && this->player->getBounds().left <= 800 - this->player->getBounds().width)
	{
		this->player->move(1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && this->player->getBounds().top >= 0)
	{
		this->player->move(0.f, -0.7f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && this->player->getBounds().top <= 1040 - this->player->getBounds().height)
	{
		this->player->move(0.f, 0.7f);
	}

	// Ability
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift))
	{
		this->player->abilityUse(-1);
	}

	//Bullet creation
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && this->player->canAttack())
	{
		if (this->type == 1)
		{
			if (this->player->getAbilityShoot())
			{
				this->bullets.push_back(new Bullet(this->textures["BULLET1"], this->player->getPos().x + this->player->getBounds().width / 2.f - 5, this->player->getPos().y + 5, 0.05f, -1.f, 4.6f));
				this->bullets.push_back(new Bullet(this->textures["BULLET1"], this->player->getPos().x + this->player->getBounds().width / 2.f - 5, this->player->getPos().y + 5, -0.05f, -1.f, 4.6f));
			}
			this->bullets.push_back(new Bullet(this->textures["BULLET1"], this->player->getPos().x + this->player->getBounds().width / 2.f - 5, this->player->getPos().y + 5, 0.1f, -1.f, 4.5f));
			this->bullets.push_back(new Bullet(this->textures["BULLET1"], this->player->getPos().x + this->player->getBounds().width / 2.f - 5, this->player->getPos().y + 5, -0.1f, -1.f, 4.5f));
			this->bullets.push_back(new Bullet(this->textures["BULLET1"], this->player->getPos().x + this->player->getBounds().width / 2.f - 5, this->player->getPos().y + 5, 0.f, -1.f, 4.65f));
		}
		else if (this->type == 2)
		{
			if (this->type2Extra)
			{
				this->bullets.push_back(new Bullet(this->textures["BULLET2"], this->player->getPos().x + this->player->getBounds().width / 2.f - 19, this->player->getPos().y + 5, 0.f, -1.f, 5.5f));
				this->type2Extra = false;
			}
			else
			{
				this->bullets.push_back(new Bullet(this->textures["BULLET2"], this->player->getPos().x + this->player->getBounds().width / 2.f + 17, this->player->getPos().y + 5, 0.f, -1.f, 5.5f));
				this->type2Extra = true;
			}
		}
		else if (this->type == 3)
		{
			this->bullets.push_back(new Bullet(this->textures["BULLET3"], this->player->getPos().x + this->player->getBounds().width / 2.f - 17, this->player->getPos().y + 5, 0.f, -1.f, 3.f));
		}
	}
}

void Game::updateBullets()
{
	unsigned counter = 0;
	for (auto* i : this->bullets)
	{
		i->update();

		if (i->getBounds().top + i->getBounds().height < 0.f)
		{
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
			--counter;
		}
		++counter;
	}
}

void Game::updateDrops()
{
	unsigned counter = 0;
	for (auto* i : this->drops)
	{
		i->update();

		if (i->getBounds().top + i->getBounds().height < 0.f)
		{
			delete this->drops.at(counter);
			this->drops.erase(this->drops.begin() + counter);
			--counter;
		}
		if (i->getBounds().intersects(this->player->getBounds()))
		{
			if (i->getType())
			{
				if (this->player->getHpMax() > this->player->getHp())
				{
					delete this->drops.at(counter);
					this->drops.erase(this->drops.begin() + counter);
					--counter;
					this->player->dmg(1);
				}
			}
			else
			{
				if (this->player->getAbilityMax() > this->player->getAbility())
				{
					delete this->drops.at(counter);
					this->drops.erase(this->drops.begin() + counter);
					--counter;
					this->player->abilityUse(1);
				}
			}
		}
		++counter;
	}
}

void Game::updateEnemysCombat()
{
	// Spawn enemys
	this->spawnTimer += rand() % 3 * 1.f;
	if (this->spawnTimer >= this->spawnTimerMax)
	{
		this->spawnWave();
		this->spawnTimer = 0.f;
	}
	// Combat
	for (int i = 0; i < this->enemys.size(); ++i)
	{
		bool enemyRemoved = false;
		this->enemys[i]->update();
		// Dmg enemy ||& remove enemy
		for (int j = 0; j < this->bullets.size() && !enemyRemoved; j++)
		{
			if (this->bullets[j]->getBounds().intersects(this->enemys[i]->getBounds()))
			{
				this->bullets.erase(this->bullets.begin() + j);
				if (this->type == 1)
				{
					this->enemys[i]->hit(2);
				}
				else if (this->type == 2)
				{
					this->enemys[i]->hit(1);
				}
				else if (this->type == 3)
				{
					this->enemys[i]->hit(6);
				}
				if (this->enemys[i]->dead())
				{
					score += this->enemys[i]->getPoints();
					if (rand()%100==0)
					{
						if (rand()%4)
						{
							this->drops.push_back(new Drop(this->textures["ABILITYFULL"], this->enemys[i]->getPos().x + this->enemys[i]->getBounds().width / 2.f - 14, this->enemys[i]->getPos().y, 0.f, 1.f, 0.5f, 0));
						}
						else
						{
							this->drops.push_back(new Drop(this->textures["LIFEFULL"], this->enemys[i]->getPos().x + this->enemys[i]->getBounds().width / 2.f - 14, this->enemys[i]->getPos().y, 0.f, 1.f, 0.5f, 1));
						}
						
					}
					this->enemys.erase(this->enemys.begin() + i);
				}
				enemyRemoved = true;
			}
		}
		//Remove enemy contact with player & dmg player
		if (!enemyRemoved)
		{
			if (this->player->getBounds().intersects(this->enemys[i]->getBounds()))
			{
				score += this->enemys[i]->getPoints();
				this->player->dmg(-1);
				if (rand() % 100 == 0)
				{
					if (rand() % 4)
					{
						this->drops.push_back(new Drop(this->textures["ABILITYFULL"], this->enemys[i]->getPos().x + this->enemys[i]->getBounds().width / 2.f - 14, this->enemys[i]->getPos().y, 0.f, 1.f, 0.5f, 0));
					}
					else
					{
						this->drops.push_back(new Drop(this->textures["LIFEFULL"], this->enemys[i]->getPos().x + this->enemys[i]->getBounds().width / 2.f - 14, this->enemys[i]->getPos().y, 0.f, 1.f, 0.5f, 1));
					}
				}
				this->enemys.erase(this->enemys.begin() + i);
				enemyRemoved = true;
			}
		}
		//Remove enemy at the bottom
		if (!enemyRemoved)
		{
			if (this->enemys[i]->getBounds().top > this->window->getSize().y)
			{
				score -= this->enemys[i]->getPoints();
				this->enemys.erase(this->enemys.begin() + i);
				enemyRemoved = true;
			}
		}
	}
}

void Game::updateText()
{
	std::stringstream ss;
	ss << "SCORE: " << this->score;
	this->text.setString(ss.str());
}

void Game::updateLife()
{
	if (this->player->getHp()<this->hp && this->hp > 0)
	{
		this->hp--;
		this->lifes[this->hp]->update(this->textures["LIFEEMTY"]);
	}
	if (this->player->getHp() > this->hp && this->hp > 0)
	{
		this->lifes[this->hp]->update(this->textures["LIFEFULL"]);
		this->hp++;
	}
	if (this->hp == 0)
	{
		this->alive = false;
	}
}

void Game::updateAbility()
{
	if (this->player->getAbility() < this->abil && this->abil > 0)
	{
		this->abil--;
		this->abilities[this->abil]->update(this->textures["ABILITYEMTY"]);
	}
	if (this->player->getAbility() > this->abil)
	{
		this->abilities[this->abil]->update(this->textures["ABILITYFULL"]);
		this->abil++;
	}
}

void Game::update()
{
	this->updatePollEvents();
	this->updateInput();
	this->player->update();
	this->updateBullets();
	this->updateDrops();
	this->updateEnemysCombat();
	this->updateText();
	this->updateLife();
	this->updateAbility();
}

void Game::render()
{
	if (!this->alive)
	{
		this->backSprite.setTexture(*this->textures["BACKGROUND3"]);
		while (!this->alive)
		{
			this->window->draw(backSprite);
			this->window->draw(this->text);
			this->window->display();
			this->updatePollEvents();
		}
	}

	this->window->draw(backSprite);

	// Draw all
	for (auto bullet : this->bullets)
	{
		bullet->render(this->window);
	}

	this->player->render(*this->window);

	for (auto enemy : this->enemys)
	{
		enemy->render(this->window);
	}

	for (auto life : this->lifes)
	{
		life->render(this->window);
	}

	for (auto abil : this->abilities)
	{
		abil->render(this->window);
	}

	for (auto drop : this->drops)
	{
		drop->render(this->window);
	}

	this->window->draw(this->text);
	this->window->display();
}
