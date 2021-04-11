//
// Created by Vadik on 06.04.2021.
//

#include "MainMenuState.h"

MainMenuState::MainMenuState(
        std::vector<Character*>* characterList,
        unsigned& activeCharacter,
        std::stack<State*>* states)
        : State(), activeCharacter(activeCharacter)
{
    this->characterList = characterList;
    this->states = states;
}

MainMenuState::~MainMenuState()
{

}

//FUnctions


void MainMenuState::printMenu()
{

    std::cout << "---Main Menu---" << "\n" << "\n";

    if (!this->characterList->empty())
        std::cout << this->characterList->at(this->activeCharacter)->getMenuBar()<< "\n";
    else
        std::cout <<"No character selected."<< "\n";

    std::cout << "(-1) Quit" << "\n"
              << "(1) Start Game" << "\n"
              << "(2) Create character" << "\n"
              << "(3) Select character" << "\n" << "\n";
}


void MainMenuState::updateMenu()
{
    switch (this->getChoice())
    {
        case -1:
            this->setQuit(true);
            break;
        case 1:
            if (!this->characterList->empty())
                this->states->push(new GameState(this->characterList->at(this->activeCharacter), this->states));
            else
                std::cout << "Create a Character first" << "\n";
            break;
        case 2:
            this->states->push(new CharacterCreatorState(this->characterList, this->activeCharacter, this->states));
            break;
        case 3:
            this->states->push(new CharacterSelectorState(this->characterList, this->activeCharacter, this->states));
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