//
// Created by Vadik on 11.04.2021.
//

#include "CharacterStatMenuState.h"

CharacterStatMenuState::CharacterStatMenuState(
        Character*& character,
        std::stack<State*>* states)
        : character(character), State()

{
    this->states = states;
}


CharacterStatMenuState::~CharacterStatMenuState()
{

}

void CharacterStatMenuState::printMenu()
{
    system("CLS");
    std::cout << "----Statpoint Menu----" << "\n";

    std::cout << this->character->getMenuBar(true);

    std::cout << "(-1) Quit to menu" << "\n" << "\n"
         << "(1) Strength"<< "\n"
         << "(2) Vitality"<< "\n"
         << "(3) Agility"<< "\n"
         << "(4) Dexterity"<< "\n"
         << "(5) Intelligence"<< "\n";
}

void CharacterStatMenuState::updateMenu()
{
    int choice = this->getChoice();

    if (choice == -1)
    {
        this->setQuit(true);
    }
    else if (choice >= 1 && choice <= 5)
    {
        if (!this->character->addStatpoint(choice - 1))
        {
            std::cout << "Not enough statpoints." << "\n";
            system("PAUSE");
        }
    }
    else
    {
        system("CLS");
        std::cout << "Not a valid option.";
        system("PAUSE");
    }
}

//Functions


void CharacterStatMenuState::update()
{
    this->printMenu();
    this->updateMenu();
}