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
void GameState::printMenu() const
{
    std::cout
            << "--- GAME MENU ---" << "\n" << "\n"
            << this->character->getMenuBar()<< "\n" << "\n"
            << "(-1) Quit to main menu"<< "\n"
            << "(1) Character Menu" << "\n"
            << "(2) Shop menu" << "\n"
            << "(3) Travel menu" << "\n"
            << "(4) Rest menu" << "\n" << "\n";
}

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
            if (this->character->getLocation() == CITY)
            {
                this->character->reset();
                std::cout << "You have rested..." << "\n";
            }
            else
            {
                std::cout << "You need to be in a city to rest!" << "\n";
            }
            system("pause");
            break;
        default:
            std::cout << "--- Wrong Option --- " << "\n";
            break;
    }
}

void GameState::update()
{
    this->printMenu();

    this->updateMenu();
}
