#include <iostream>
#include "Game.h"



int main()
{
    Game game;


    // Game loop
    while (!game.getQuit())
    {
        game.update();
    }
    return 0;
}
