//
// Created by Vadik on 27.03.2021.
//

#include "Character.h"


Character::Character(std::string name)
{
    this->name = name;
    this->level = 1;
    this->exp = 0;
    this->expNext = 100;

    this->hp = 100;
    this->hpMax = 100;
    this->mana=100;
    this->manaMax=100;
    this->stamina=10;
    this->staminaMax=10;

    this->defence=1;
    this->dodgeChance=1.f;
    this->hitChance=1.f;
    this->critChance=1.f;
    this->magicFind=1.f;

    this->gold = 0;

    this->strength = 1;
    this->vitality = 1;
    this->agility = 1;
    this->dexterity = 1;
    this->intelligence = 1.f;


    // Init attr and stats

}

Character::~Character()
{

}


// Functions
const std::string Character::toString() // set variables in strings
{
    std::stringstream ss;

    ss << "Name: " << this->name << "\n"
       << "Level: " << this->level << "\n"
       << "Exp: " << this->exp << "/" << this->expNext << "\n"

       << "Strength: " << this->strength << "\n"
       << "Vitality: " << this->vitality << "\n"
       << "Agility: " << this->agility << "\n"
       << "Dexterity: " << this->dexterity << "\n"
       << "Intelligence: " << this->intelligence << "\n"

       << "Health: " << this->hp << "/" << this->hpMax << "\n"
       << "Mana: " << this->mana << "/" << this->manaMax << "\n"
       << "Stamina: " << this->stamina << "/" << this->staminaMax << "\n"

       << "Defence: " << this->defence << "\n"
       << "Dodge chance: " << this->dodgeChance << "\n"
       << "Hit chance: " << this->hitChance << "\n"
       << "Crit chance: " << this->critChance << "\n"
       << "Magic Find: " << this->magicFind << "\n"
       << "Gold: " << this->gold << "\n"
       << "\n";
    return ss.str();
}