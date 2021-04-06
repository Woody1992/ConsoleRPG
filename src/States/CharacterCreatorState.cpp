//
// Created by Vadik on 06.04.2021.
//

#include "CharacterCreatorState.h"

CharacterCreatorState::CharacterCreatorState(Character*& character, std::stack<State*>*states)
                                        : character(character), State()
{

    this->states = states;
}
CharacterCreatorState::~CharacterCreatorState()
{

}

//Functions
void CharacterCreatorState::createCharacter()
{
    std::string name = "";

    std::cout << "Name:";
    std::getline(std::cin, name);

    delete this->character;
    this->character = new Character(name);

    std::cout << "Character " << name << " created" <<"\n";

}

void CharacterCreatorState::printMenu()
{
    std::cout << "---Character Creater---" << "\n" << "\n"
              << "(0) Back to menu" << "\n"
              << "(1) New Character" << "\n" << "\n";
}

const int CharacterCreatorState::getChoice() const {
    int choice = 0;
    std::cout << "Enter choice:";
    std::cin >> choice;

    std::cin.ignore();
    std::cin.clear();

    return choice;
}

void CharacterCreatorState::updateMenu()
{
    switch (this->getChoice())
    {
        case 0:
            this->setQuit(true);
            break;
        case 1:
            this->createCharacter();
            break;
        default:
            std::cout << "Not valid option"<< "\n";
            break;
    }
}


void CharacterCreatorState::update()
{
    this->printMenu();

    this->updateMenu();
}


