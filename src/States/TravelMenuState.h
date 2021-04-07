//
// Created by Vadik on 06.04.2021.
//

#ifndef RPG_TRAVELMENUSTATE_H
#define RPG_TRAVELMENUSTATE_H
#include <iostream>
#include <iomanip>
#include <stack>
#include <ctime>
#include "../Character.h"
#include "State.h"

enum encounters { EMPTY = 0, FARM, CITY, SHOP, CHEST };

class TravelMenuState :
        public State
{
private:
    Character *& character;
    std::stack<State*>*states;
    std::string locationString; //Keeps track of where the player is
    std::string minimapString;
    int nrOfLocations;

public:
    TravelMenuState(
            Character*& character,
            std::stack<State*>* states);
    virtual ~TravelMenuState();

    //Functions
    void travel();

    void printMenu();
    void updateEncounterMenu();
    void updateMinimap();
    void updateMenu();
    void update();
};

#endif //RPG_TRAVELMENUSTATE_H
