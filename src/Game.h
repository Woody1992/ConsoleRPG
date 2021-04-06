

#ifndef CONSOLERPG_GAME_H
#define CONSOLERPG_GAME_H
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stack>
#include "States/MainMenuState.h"




class Game
{
private:
    bool quit;

    unsigned activeCharacter;
    std::vector<Character*> characterList;
    std::stack<State*> states;

public:
    Game();
    virtual ~Game();


    // Accessors
    const bool& getQuit() const;

    // Functions
    void update();
};


#endif //CONSOLERPG_GAME_H
