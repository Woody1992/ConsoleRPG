//
// Created by Vadik on 06.04.2021.
//

#include "CharacterSelectorState.h"

CharacterSelectorState::CharacterSelectorState(
        std::vector<Character*>* characterList,
        unsigned& activeCharacter,
        std::stack<State*>* states)
        : State(),
          characterList(characterList),
          activeCharacter(activeCharacter),
          states(states)
{

}

CharacterSelectorState::~CharacterSelectorState()
{

}

//Functions
void CharacterSelectorState::printMenu()
{

    std::cout << "--- Character Selector ---" << "\n" << "\n";

    std::cout << "(-1) Back to menu" << "\n";

    if (!this->characterList->empty())
    {
        std::cout <<"Available characters:" << "\n";
        for (size_t i = 0; i < this->characterList->size(); i++)
        {
            std::cout << "(" << i << ")" << this->characterList->at(i)->getMenuBar() << "\n";
        }
        std::cout << "\n";
    }
}

void CharacterSelectorState::updateMenu()
{
    if (!this->characterList->empty())
    {
        int choice = this->getChoice();

        if (choice < 0)
        {
            this->setQuit(true);
        }
        else if (choice >= 0 && choice < this->characterList->size())
        {
            this->activeCharacter = choice;
            this->setQuit(true);
            std::cout <<"Character " << choice << " selected." << "\n" << "\n";
            system("pause");
        }
        else
        {
            std::cout <<"Error: Choice out of bounds! " << "\n" << "\n";
            system("pause");
        }
    }
    else
    {
        this->setQuit(true);
        std::cout <<"No characters created!" << "\n" << "\n";
        system("pause");
    }
}

void CharacterSelectorState::update()
{
    this->printMenu();
    this->updateMenu();
}
