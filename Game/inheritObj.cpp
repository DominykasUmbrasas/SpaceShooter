#include "inheritObj.h"

// Cons/Des
inheritObj::inheritObj()
{

}

inheritObj::~inheritObj()
{

}

const sf::FloatRect inheritObj::getBounds() const
{
	return this->Sprite.getGlobalBounds();
}

void inheritObj::render(sf::RenderTarget* target)
{
	target->draw(this->Sprite);
}
