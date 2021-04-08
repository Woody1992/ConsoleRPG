//
// Created by Vadik on 07.04.2021.
//

#ifndef RPG_COMBATSTATE_H
#define RPG_COMBATSTATE_H


#include<vector>
#include<iostream>
#include<fstream>
#include<iomanip>
#include<stack>
#include "State.h"
#include "../Character.h"
#include "../Enemy.h"
#include "TravelMenuState.h"
#include "CharacterMenuState.h"

class CombatState :
        public State
{
private:
    Character * & character;
    std::stack<State*>*states;

public:
    CombatState(Character*& character,
                std::stack<State*>*states);
    virtual ~CombatState();

	//Functions
	void display(std::string atkStr, std::string defStr, int round, std::string encounterLog, float hitRating, float hitPercent, float defence, float defPercent, Enemy enemy);
    void beginCombat();
    void printMenu();
    void updateMenu();
    void update();
};


#endif //RPG_COMBATSTATE_H
