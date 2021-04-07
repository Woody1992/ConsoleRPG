//
// Created by Vadik on 05.04.2021.
//

#include "GameState.h"

GameState::GameState(Character*& character, std::stack<State*>*states):character(character), State()
{

    this->states = states;
}

GameState::~GameState()
{

}

//Functions
void GameState::updateMenu()
{
    switch (this->getChoice())
    {
        case -1:
            this->setQuit(true);
            break;
        case 1:
            this->states->push(new CharacterMenuState(this->character, this->states));
            break;
        case 2:

            break;
        case 3:
            this->states->push(new TravelMenuState(this->character, this->states));
            break;
        case 4:

            break;
        case 5:
            this->combatTest(); // REMOVE LATER
            break;
        default:
            std::cout << "--- Wrong Option --- " << "\n";
            break;
    }
}


void GameState::printMenu() const
{


    std::cout
            << "--- GAME MENU ---" << "\n" << "\n"
            << this->character->getMenuBar()<< "\n" << "\n"
            << "(-1) Quit to main menu"<< "\n"
            << "(1) Character Menu" << "\n"
            << "(2) Shop menu" << "\n"
            << "(3) Travel menu" << "\n"
            << "(5) Combat TEST" << "\n"
            << "(4) Rest menu" << "\n" << "\n";

}


void GameState::update()
{
    this->printMenu();

    this->updateMenu();
}

void GameState::combatTest() //REMOVE LATER
{
    Enemy enemy(this->character->getLevel());
    bool end_combat = false;

    while(!end_combat)
    {
        if (this->character->isDead())
        {
            end_combat = true;
        }
        else if (enemy.isDead())
        {
            end_combat = true;
        }
    }
}