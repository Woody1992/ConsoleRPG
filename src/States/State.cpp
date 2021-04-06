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