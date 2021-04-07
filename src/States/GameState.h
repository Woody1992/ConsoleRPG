//
// Created by Vadik on 05.04.2021.
//

#ifndef RPG_GAMESTATE_H
#define RPG_GAMESTATE_H

#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stack>
#include "State.h"
#include "../Character.h"
#include "CharacterMenuState.h"
#include "TravelMenuState.h"
#include "../Enemy.h"

class GameState :
        public State
{
private:
    Character*& character;
    std::stack<State*>*states;

public:
    GameState(Character*& character, std::stack<State*>*states);
    virtual ~GameState();

    //Functions
    void printMenu() const;
    void updateMenu();
    virtual void update();
};

#endif //RPG_GAMESTATE_H
