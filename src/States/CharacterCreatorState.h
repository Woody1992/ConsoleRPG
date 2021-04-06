//
// Created by Vadik on 06.04.2021.
//

#ifndef RPG_CHARACTERCREATORSTATE_H
#define RPG_CHARACTERCREATORSTATE_H
#include <iostream>
#include <iomanip>
#include <stack>
#include "../Character.h"
#include "State.h"

class CharacterCreatorState : public State
{
private:
    Character*& character;
    std::stack<State*>*states;

public:
    CharacterCreatorState(Character*& character, std::stack<State*>*states);
    virtual ~CharacterCreatorState();

    //Functions
    void createCharacter();
    void printMenu();
    const int getChoice() const;
    void updateMenu();
    void update();
};


#endif //RPG_CHARACTERCREATORSTATE_H
