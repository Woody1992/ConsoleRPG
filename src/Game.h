

#ifndef CONSOLERPG_GAME_H
#define CONSOLERPG_GAME_H
#include <vector>
#include <iostream>
#include <fstream>
#include "State.h"
#include "Character.h"


class Game
{
private:
    bool quit;
    std::vector<State> states;
    State* currentState;


    Character* character;
public:
    Game();
    virtual ~Game();


    // Accessors
    const bool& getQuit() const;

    // Functions
    void printMenu() const;
    const int getChoice() const;
    void updateMenu();
    void update();
};


#endif //CONSOLERPG_GAME_H
