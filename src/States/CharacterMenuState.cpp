//
// Created by Vadik on 06.04.2021.
//

#include "CharacterMenuState.h"

CharacterMenuState::CharacterMenuState(Character*& character, std::stack<State*>* states)
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
            << "(0) Back to menu" << "\n"
            << "(1) Main info" << "\n"
            << "(2) Stats " << "\n"
            << "(3) Level Up" << "\n"
            << "(4) Assign skill points" << "\n" << "\n";
}

const int CharacterMenuState::getChoice() const {
    int choice = 0;
    std::cout << "Enter choice:";
    std::cin >> choice;

    std::cin.ignore();
    std::cin.clear();

    return choice;
}

void CharacterMenuState::updateMenu()
{
    switch (this->getChoice())
    {
        case 0:
            this->setQuit(true);
            break;
        case 1:
            std::cout << this->character->toStringMain() << "\n";
            break;
        case 2:
            std::cout << this->character->toStringStats() << "\n";
            break;
        case 3:
            if (this->character->canLevelUp())
            {
                std::cout << "LEVEL UP" << "\n";
            } else
                std::cout << "Need more EXP" << "\n";
            break;
        case 4:

            break;
        default:
            std::cout << "Not valid option"<< "\n";
            break;
    }
}

void CharacterMenuState::update()
{
    this->printMenu();
    this->updateMenu();
}