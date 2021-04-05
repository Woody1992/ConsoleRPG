

#ifndef CONSOLERPG_GAME_H
#define CONSOLERPG_GAME_H
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stack>
#include "State.h"
#include "Character.h"
#include "States/GameState.h"



class Game
{
private:
    bool quit;
    std::stack<State*> states;

    Character* character;
public:
    Game();
    virtual ~Game();


    // Accessors
    const bool& getQuit() const;

    // Functions
    void update();
};


#endif //CONSOLERPG_GAME_H
