//
// Created by Vadik on 27.03.2021.
//

#include "Game.h"
Game::Game()
{
    quit = false;
    this->currentState = nullptr;

    this->character = new Character("PogSon");
}

Game::~Game()
{
    delete this->character;
}

// Accessors
const bool& Game::getQuit() const
{
    return this->quit;
}

// Modifier

// Functions
void Game::updateMenu()
{
    switch (this->getChoice())
    {
        case 0:
            std::cout << "--- GOODBYE --- " << "\n";
            this->quit = true;
            break;
        case 1:
            std::cout << "--- Character Stats --- " << "\n";
            std::cout << this->character->toString() << "\n" << "\n";
            break;
        case 2:
            std::cout << "--- Inventory --- " << "\n";
            break;
        default:
            std::cout << "--- Wrong Option --- " << "\n";
            break;
    }
}
void Game::update()
{
    this->printMenu();

    this->updateMenu();
}

const int Game::getChoice() const {
    int choice = 0;
    std::cout << "Enter choice: ";
    std::cin >> choice;
    return choice;
}

void Game::printMenu() const {
    std::cout << "--- MAIN MENU ---" << "\n"
              << "(0) Exit game"<< "\n"
              << "(1) Character Stats" << "\n"
              << "(2) Inventory" << "\n"
              << "(3) Shop" << "\n"
              << "(4) Travel" << "\n"
              << "(5) Rest" << "\n";
}


