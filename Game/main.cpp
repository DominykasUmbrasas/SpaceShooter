#include <iostream>
#include "Game.h"
#include <time.h>

//Test

int main() 
{
	srand(static_cast<unsigned int>(time(0)));
	Game game;
	
	game.start();
	return 0;
}