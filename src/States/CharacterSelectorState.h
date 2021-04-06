//
// Created by Vadik on 06.04.2021.
//

#ifndef RPG_CHARACTERSELECTORSTATE_H
#define RPG_CHARACTERSELECTORSTATE_H

#include<iostream>
#include<iomanip>
#include<stack>
#include<vector>

#include"../Character.h"
#include "State.h"

class CharacterSelectorState :
        public State
{
private:
    std::vector<Character*>* characterList;
    unsigned& activeCharacter;
    std::stack<State*>* states;

public:
    CharacterSelectorState(
            std::vector<Character*>* characterList,
            unsigned& activeCharacter,
            std::stack<State*>* states);

    virtual ~CharacterSelectorState();

    //Functions

    void printMenu();
    void updateMenu();
    void update();
};


#endif //RPG_CHARACTERSELECTORSTATE_H
