//
// Created by Vadik on 27.03.2021.
//

#include "Game.h"
Game::Game()
{
    quit = false;

    this->activeCharacter = 0;
    this->states.push(new MainMenuState(&this->characterList, this->activeCharacter, &this->states));
}

Game::~Game()
{


    while (!this->states.empty())
    {
        delete this->states.top();
        this->states.pop();
    }
    for (size_t i = 0; i < this->characterList.size(); i++)
    {
        delete this->characterList[i];
    }
}

// Accessors
const bool& Game::getQuit() const
{
    return this->quit;
}

// Functions
void Game::update()
{
    system("CLS");

    this->states.top()->update();
    if (this->states.top()->getQuit())
    {
        delete this->states.top();
        this->states.pop();
    }


    if(this->states.empty())
        this->quit = true;
}
