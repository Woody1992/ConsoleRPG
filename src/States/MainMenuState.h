//
// Created by Vadik on 06.04.2021.
//

#ifndef RPG_MAINMENUSTATE_H
#define RPG_MAINMENUSTATE_H
#include <vector>
#include <iostream>
#include <iomanip>
#include <stack>
#include "CharacterCreatorState.h"
#include "GameState.h"

class MainMenuState: public State
{
private:
    std::vector<Character*>* characterList;
    unsigned& activeCharacter;
    std::stack<State*>* states;


public:
    MainMenuState(
            std::vector<Character*>* characterList,
            unsigned& activeCharacter,
            std::stack<State*>* states);
    virtual ~MainMenuState();

    void printMenu();
    void updateMenu();
    void update();
};


#endif //RPG_MAINMENUSTATE_H
