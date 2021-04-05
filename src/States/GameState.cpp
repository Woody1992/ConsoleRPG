//
// Created by Vadik on 05.04.2021.
//

#include "GameState.h"

GameState::GameState(Character* character, std::stack<State*>*states)
{
    this->character = character;
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
        case 0:
            std::cout << " --- GOODBYE --- " << "\n";
            this->setQuit(true);
            break;
        case 1:
            std::cout << " --- Character Stats --- " << "\n";
            std::cout << this->character->toString() << "\n" << "\n";
            break;
        case 2:
            std::cout << " --- Inventory --- " << "\n";
            if (this->character->canLevelUp())
            {
                std::cout << "LEVEL UP!" << "\n";
            }
            break;
        default:
            std::cout << " --- Wrong Option --- " << "\n";
            break;
    }
}

const int GameState::getChoice() const {
    int choice = 0;
    std::cout << "Enter choice:";
    std::cin >> choice;
    return choice;
}

void GameState::printMenu() const
{


    std::cout
            << "--- MAIN MENU ---" << "\n" << "\n"
            << this->character->getMenuBar()<< "\n" << "\n"
            << "(0) Exit game"<< "\n"
            << "(1) Character Stats" << "\n"
            << "(2) Inventory" << "\n"
            << "(3) Shop" << "\n"
            << "(4) Travel" << "\n"
            << "(5) Rest" << "\n" << "\n";

}


void GameState::update()
{
    this->printMenu();

    this->updateMenu();
}