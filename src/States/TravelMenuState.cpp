//
// Created by Vadik on 06.04.2021.
//

#include "TravelMenuState.h"
#include <conio.h>

TravelMenuState::TravelMenuState(
        Character*& character,
        std::stack<State*>* states)
        : character(character), State()
{
    this->states = states;
    this->locationString = "NONE";
    this->nrOfLocations = 5; // Number of locations
}

TravelMenuState::~TravelMenuState()
{

}

//Functions
void TravelMenuState::updateEncounterMenu()
{
    if (!this->getQuit())
    {
        srand(this->character->getSeed());
        int location = rand() % this->nrOfLocations;
        this->character->setLocation(location);

        switch (location)
        {
            case EMPTY:
            {
                this->locationString = "You are in an empty plane.";

                srand(time(NULL));
                int randomnr = rand() % 2;

                if (randomnr)
                {
                    system("cls");
                    std::cout << "ENEMY ENCOUTERED!" << "\n";
                    system("pause");

                    this->states->push(new CombatState(this->character, this->states));
                }
                break;
            }
            case FARM:
                this->locationString = "You are on a farm.";
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
            << "(Q) << BACK TO MENU" << "\n"
            << "                       +------------------+" << "\n"
            << "                       |   (W) MOVE UP    |" << "\n"
            << "                       +---------+--------+" << "\n"
            << " +-------------------+           |           +-------------------+" << "\n"
            << " |  (A) MOVE LEFT    |-----------+-----------|  (D) MOVE RIGHT   |" << "\n"
            << " +-------------------+           |           +-------------------+" << "\n"
            << "                       +---------+--------+" << "\n"
            << "                       |  (S) MOVE DOWN   |" << "\n"
            << "                       +------------------+" << "\n";
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
                    case EMPTY:
                        ss << "Em ";
                        break;
                    case FARM:
                        ss << "Fa ";
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
    
    switch (_getch())
    {
        case 'Q':
        case 'q':
            this->setQuit(true);
            break;
        case 'W':
        case 'w':
            this->character->move(0, -1);
            break;
        case 'S':
        case 's':
            this->character->move(0, 1);
            break;
        case 'A':
        case 'a':
            this->character->move(-1, 0);
            break;
        case 'D':
        case 'd':
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
