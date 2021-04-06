//
// Created by Vadik on 06.04.2021.
//

#include "TravelMenuState.h"

TravelMenuState::TravelMenuState(
        Character*& character,
        std::stack<State*>* states)
        : character(character), State()
{
    this->states = states;
    this->locationString = "NONE";
    this->nrOfLocations = 5;
}

TravelMenuState::~TravelMenuState()
{

}

//Functions
void TravelMenuState::travel()
{
    //Move character

    //Get randomly generated location

    //Change player variables
}

void TravelMenuState::updateEncounterMenu()
{
    if (!this->getQuit())
    {
        srand(this->character->getSeed());
        int location = rand() % 3;

        switch (location)
        {
            case EMPTY:
                std::cout << "you are fucked" << "\n";
            case FARM:
                std::cout <<"You are on a farm." << "\n";
                break;
            case CITY:
                std::cout << "You are in a city." << "\n";
                break;
            case SHOP:
                std::cout <<  "You find a shop." << "\n";
                break;
            case CHEST:
                std::cout << "You found a chest!." << "\n";
                break;
            default:
                std::cout << "ERROR NO SUCH LOCATION!" << "\n";
                system("pause");
                break;
        }
    }
}

void TravelMenuState::printMenu()
{

    std::cout << "---Travel Menu---" << "\n";

    std::cout
            << this->character->getMenuBar();

    std::cout
            << "\n"
            << this->character->toStringPosition()
            << "\n";

    std::cout
            << "(-1) Back to menu" << "\n"
            << "(1) UP" << "\n"
            << "(2) DOWN" << "\n"
            << "(3) LEFT" << "\n"
            << "(4) RIGHT" << "\n" << "\n";
}

void TravelMenuState::updateMenu()
{
    switch (this->getChoice())
    {
        case -1:
            this->setQuit(true);
            break;
        case 1:
            this->character->move(0, -1);
            break;
        case 2:
            this->character->move(0, 1);
            break;
        case 3:
            this->character->move(-1, 0);
            break;
        case 4:
            this->character->move(1, 0);
            break;
        default:
            std::cout << "Not a valid option! " << "\n";
            system("PAUSE");
            break;
    }
}

void TravelMenuState::update()
{

    this->printMenu();
    this->updateMenu();
    this->updateEncounterMenu();

}
