//
// Created by Vadik on 06.04.2021.
//

#ifndef RPG_CHARACTERMENUSTATE_H
#define RPG_CHARACTERMENUSTATE_H
#include<iostream>
#include<iomanip>
#include<stack>
#include "../Character.h"
#include "State.h"
#include "CharacterStatMenuState.h"


class CharacterMenuState : public State
{
private:
    Character *& character;
    std::stack<State*>*states;

public:
    CharacterMenuState(Character*& character,
                       std::stack<State*>* states);
    virtual ~CharacterMenuState();

    //Functions
    void printMenu();

    void updateMenu();
    void update();
};

#endif //RPG_CHARACTERMENUSTATE_H
