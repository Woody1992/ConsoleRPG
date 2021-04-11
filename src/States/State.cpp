//
// Created by Vadik on 27.03.2021.
//


#include "State.h"

State::State()
{
    this ->quit = false;
}

State::~State()
{

}

const bool &State::getQuit() const {
    return this->quit;
}

void State::setQuit(const bool quit)
{
    this->quit = quit;
}

int State::getChoice() const
{
    int choice = 0;
    std::cout << "Enter choice:";
    std::cin >> std::setw(1) >> choice;

    while(!std::cin.good())
    {
        std::cout << "enter a correct value" << "\n";
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');


        std::cout << "Enter choice:";
        std::cin >> std::setw(1) >> choice; //reading only first character in line
    }

    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');

    return choice;
}
