

#ifndef CONSOLERPG_GAME_H
#define CONSOLERPG_GAME_H
#include <vector>
#include <iostream>
#include <fstream>
#include "State.h"


class Game
{
private:
    bool quit;

public:
    Game();
    virtual ~Game();


    // Accessors
    bool getQuit();

    // Functions
    void printMenu();
    int getChoice();
    void update();
};


#endif //CONSOLERPG_GAME_H
