//
// Created by Vadik on 06.04.2021.
//

#include "CharacterCreatorState.h"

CharacterCreatorState::CharacterCreatorState(
        std::vector<Character*>* characterList,
        unsigned& activeCharacter,std::stack<State*>*states)
        :State(), activeCharacter(activeCharacter), maxCharacters(5)
{
    this->characterList = characterList;
    this->states = states;
}
CharacterCreatorState::~CharacterCreatorState()
{

}

//Functions
void CharacterCreatorState::createCharacter()
{
    if (this->characterList->size() < this->maxCharacters)
    {
        std::string name = "";


        std::cout << "Name: ";
        getline(std::cin, name);


        this->characterList->push_back(new Character(name));

        std::cout << "Character " << name << " created." << "\n" << "\n";
        system("pause");
    }
    else
    {
        std::cout << "Max number of characters reached!" << "\n";
        system("pause");
    }

}

void CharacterCreatorState::printMenu()
{
    std::cout << "--- Character Creator ---" << "\n" << "\n"
         << "Characters: " << std::to_string(this->characterList->size()) << " / " << std::to_string(this->maxCharacters) << "\n" << "\n"
         << "(-1) Back to menu" << "\n"
         << "(1) New Character" << "\n" << "\n";
}


void CharacterCreatorState::updateMenu()
{
    switch (this->getChoice())
    {
        case -1:
            this->setQuit(true);
            break;
        case 1:
            this->createCharacter();
            break;
        default:
            std::cout <<"Not valid option"<< "\n";
            break;
    }
}


void CharacterCreatorState::update()
{
    this->printMenu();
    this->updateMenu();
}


