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
    const unsigned maxCharacters;
    std::vector<Character*>* characterList;
    unsigned& activeCharacter;
    std::stack<State*>*states;

public:
    CharacterCreatorState(
            std::vector<Character*>* characterList,
            unsigned& activeCharacter,
            std::stack<State*>* states);
    virtual ~CharacterCreatorState();

    //Functions
    void createCharacter();
    void printMenu();
    void updateMenu();
    void update();
};


#endif //RPG_CHARACTERCREATORSTATE_H
