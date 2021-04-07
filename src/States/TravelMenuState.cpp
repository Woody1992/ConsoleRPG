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
        int location = rand() % nrOfLocations;

        switch (location)
        {
            case FARM:
                this->locationString = "You are in a farm.";
            case EMPTY:
                this->locationString = "You are on a empty plane.";
                break;
            case CITY:
                this->locationString = "You are in a city.";
                break;
            case SHOP:
                this->locationString = "You find a shop.";
                break;
            case CHEST:
                this->locationString = "You found a chest!.";
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
            << this->character->toStringPosition() << "\n"
            << "Location: " << this->locationString << "\n"
            << "Minimap: " << "\n" << this->minimapString << "\n";

    std::cout
            << "(-1) Back to menu" << "\n"
            << "(1) UP" << "\n"
            << "(2) DOWN" << "\n"
            << "(3) LEFT" << "\n"
            << "(4) RIGHT" << "\n" << "\n";
}

void TravelMenuState::updateMinimap()
{
    int startX = this->character->getX() - 2;
    if (startX < 0)
        startX = 0;

    int startY = this->character->getY() - 2;
    if (startY < 0)
        startY = 0;

    int endX = this->character->getX() + 2;
    int endY = this->character->getY() + 2;

    std::stringstream ss;

    for (size_t y = startY; y <= endY; y++)
    {
        for (size_t x = startX; x <= endX; x++)
        {
            srand(x + y);
            int location = rand() % this->nrOfLocations;

            if (x == this->character->getX() && y == this->character->getY())
                ss << "(P) ";
            else
            {
                switch (location)
                {
                    case FARM:
                        ss << "Fa ";
                        break;
                    case EMPTY:
                        ss << "Em ";
                        break;
                    case CITY:
                        ss << "Ci ";
                        break;
                    case SHOP:
                        ss << "Sh ";
                        break;
                    case CHEST:
                        ss << "Ch ";
                        break;
                }
            }
        }

        ss << "\n";
    }

    this->minimapString = ss.str();
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
    this->updateMinimap();
    this->printMenu();
    this->updateMenu();
    this->updateEncounterMenu();

}
