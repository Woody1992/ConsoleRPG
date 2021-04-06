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
        case 0:
            this->setQuit(true);
            break;
        case 1:
            std::cout << " --- Character Stats --- " << "\n";
            this->states->push(new CharacterMenuState(this->character, this->states));
            break;
        case 2:

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

    std::cin.ignore();
    std::cin.clear();

    return choice;
}

void GameState::printMenu() const
{


    std::cout
            << "--- GAME MENU ---" << "\n" << "\n"
            << this->character->getMenuBar()<< "\n" << "\n"
            << "(0) Quit to main menu"<< "\n"
            << "(1) Character Menu" << "\n"
            << "(2) Shop menu" << "\n"
            << "(3) Travel menu" << "\n"
            << "(4) Rest menu" << "\n" << "\n";

}


void GameState::update()
{
    this->printMenu();

    this->updateMenu();
}