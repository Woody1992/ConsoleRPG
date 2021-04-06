//
// Created by Vadik on 06.04.2021.
//

#include "MainMenuState.h"

MainMenuState::MainMenuState(Character*& character, std::stack<State*>*states)
                : character(character), State()
{

    this->states = states;
}

MainMenuState::~MainMenuState()
{

}

//FUnctions


void MainMenuState::printMenu()
{

    std::cout << "---Main Menu---" << "\n" << "\n"
              << "(0) Quit" << "\n"
              << "(1) Start Game" << "\n"
              << "(2) Create character" << "\n" << "\n";
}

const int MainMenuState::getChoice() const {
    int choice = 0;
    std::cout << "Enter choice:";
    std::cin >> choice;

    std::cin.ignore();
    std::cin.clear();
    return choice;
}

void MainMenuState::updateMenu()
{
    switch (this->getChoice())
    {
        case 0:
            this->setQuit(true);
            break;
        case 1:
            if(this->character != nullptr)
                this->states->push(new GameState(this->character, this->states));
            else
                std::cout << "Create a Character first" << "\n";
            break;
        case 2:
            this->states->push(new CharacterCreatorState(this->character, this->states));
            break;
        default:
            std::cout << "Not valid option"<< "\n";
            break;
    }
}

void MainMenuState::update()
{
    this->printMenu();

    this->updateMenu();
}