//
// Created by Vadik on 06.04.2021.
//

#include "CharacterMenuState.h"

CharacterMenuState::CharacterMenuState(
        Character*& character,
        std::stack<State*>* states)
        : character(character), State()
{
    this->states = states;
}

CharacterMenuState::~CharacterMenuState()
{

}

//Functions
void CharacterMenuState::printMenu()
{
    std::cout << "---Character Menu---" << "\n" << "\n"
            << this->character->getMenuBar() << "\n"
            << "(-1) Back to menu" << "\n"
            << "(1) Main info" << "\n"
            << "(2) Stats " << "\n"
            << "(3) Assign skill points" << "\n"
            << "(4) Inventory" << "\n" << "\n";
}

void CharacterMenuState::updateMenu()
{
    switch (this->getChoice())
    {
        case -1:
            this->setQuit(true);
            break;
        case 1:
            system("CLS");
            std::cout << this->character->toStringMain() << "\n";
            system("pause");
            break;
        case 2:
            system("CLS");
            std::cout << this->character->toStringStats() << "\n";
            system("pause");
            break;
        case 3:

            break;
        case 4:

            break;
        default:
            system("CLS");
            std::cout <<"Not valid option"<< "\n";
            system("pause");
            break;
    }
}

void CharacterMenuState::update()
{
    this->printMenu();
    this->updateMenu();
}