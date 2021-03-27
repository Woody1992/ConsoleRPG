//
// Created by Vadik on 27.03.2021.
//

#include "Game.h"
Game::Game()
{
    quit = false;
}

Game::~Game()
{

}

// Accessors
bool Game::getQuit()
{
    return this->quit;
}

// Modifier

// Functions
void Game::update()
{
    this->printMenu();

    switch (this->getChoice())
    {
        case 0:
            std::cout << "--- GOODBYE --- " << "\n";
            this->quit = true;
            break;
        case 1:
            std::cout << "--- Character Stats --- " << "\n";
            break;
        case 2:
            std::cout << "--- Inventory --- " << "\n";
            break;
        default:
            std::cout << "--- Wrong Option --- " << "\n";
            break;
    }
}

int Game::getChoice() {
    int choice = 0;
    std::cout << "Enter choice: ";
    std::cin >> choice;
    return choice;
}

void Game::printMenu() {
    std::cout << "--- MAIN MENU ---" << "\n"
              << "(0) Exit game"<< "\n"
              << "(1) Character Stats" << "\n"
              << "(2) Inventory" << "\n"
              << "(3) Shop" << "\n"
              << "(4) Travel" << "\n"
              << "(5) Rest" << "\n";
}


