//
// Created by Vadik on 11.04.2021.
//

#ifndef RPG_CHARACTERSTATMENUSTATE_H
#define RPG_CHARACTERSTATMENUSTATE_H


#include<iostream>
#include<iomanip>
#include<stack>
#include "../Character.h"
#include "State.h"



class CharacterStatMenuState :
        public State
{
private:
    Character *&character;
    std::stack<State*> *states;

public:
    CharacterStatMenuState(
            Character*& character,
            std::stack<State*>* states);
    virtual ~CharacterStatMenuState();

    //Functions
    void printMenu();
    void updateMenu();
    void update();
};
#endif //RPG_CHARACTERSTATMENUSTATE_H
