//
// Created by Vadik on 27.03.2021.
//

#include "Character.h"


// Private Functions
void Character::updateSkills()
{

    this->hpMax = this->vitality * 10;
    this->hp = this->hpMax;
    this->staminaMax=this->agility*2;
    this->stamina=this->staminaMax;
    this->manaMax=this->intelligence * 10;
    this->mana=this->manaMax;



    this->defence= this->agility;
    this->dodgeChance= static_cast<float>(this->agility)/50;
    this->hitRating=this->dexterity * 2;
    this->critChance=static_cast<float>(this->dexterity)/60;
    this->magicFind=static_cast<float>(this->intelligence)/70;




}

// Constructors and Destructors
Character::Character(std::string name)
{
    this->x = 0;
    this->y = 0;

    this->name = name;
    this->level = 1;
    this->exp = 1000;
    this->expNext =46;
    this->skillPoints = 0;

    this->strength = 1;
    this->vitality = 1;
    this->agility = 1;
    this->dexterity = 1;
    this->intelligence = 1;

    this->gold = 0;

    this->updateSkills();
}

Character::~Character()
{

}


// Functions

void Character::setPosition(const unsigned x, const unsigned y)
{
    this->x = x;
    this->y = y;
}

void Character::move(const int x, const int y)
{
    if (static_cast<int>(this->x) + x < 0)
        this->x = 0;
    else
        this->x += x;

    if (static_cast<int>(this->y) + y < 0)
        this->y = 0;
    else
        this->y += y;
}

void Character::addExp(const unsigned exp)
{
    this->exp += exp;
}

bool Character::canLevelUp()
{
    if (this->exp >= this->expNext)
    {
        this->level++;
        this->exp -= this->expNext;
        this->expNext = (50 / 3) * (pow(this->level, 3) - 6 * pow(this->level, 2) + (this->level * 17) - 12);
        this->skillPoints++;

        return true;
    }

    return false;
}

const std::string Character::getMenuBar()
{
    std::stringstream ss;

    ss
        << "Name: " << this->name << " |"
        << " Level: " << this->level << " |"
        << " Exp: " << this->exp << "/"<< this->expNext << " |"
        << " Health: " << this->hp << "/" << this->hpMax << " |"
        << " Stamina: " << this->stamina << "/" << this->staminaMax << "\n"
        << "Skill points available: " << this->skillPoints;

    return ss.str();

}

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
       << "Hit rating: " << this->hitRating << "\n"
       << "Crit chance: " << this->critChance << "\n"
       << "Magic Find: " << this->magicFind << "\n"

       << "Gold: " << this->gold << "\n";
    return ss.str();
}

const std::string Character::toStringPosition()
{
    std::stringstream ss;

    ss << "x: " << this->x << " y: " << this->y << "\n";

    return ss.str();
}

const std::string Character::toStringStats()
{
    std::stringstream ss;

    ss << "Strength: " << this->strength << "\n"
       << "Vitality: " << this->vitality << "\n"
       << "Agility: " << this->agility << "\n"
       << "Dexterity: " << this->dexterity << "\n"
       << "Intelligence: " << this->intelligence << "\n"

       << "Health: " << this->hp << "/" << this->hpMax << "\n"
       << "Mana: " << this->mana << "/" << this->manaMax << "\n"
       << "Stamina: " << this->stamina << "/" << this->staminaMax << "\n"

       << "Defence: " << this->defence << "\n"
       << "Dodge chance: " << this->dodgeChance << "\n"
       << "Hit rating: " << this->hitRating << "\n"
       << "Crit chance: " << this->critChance << "\n"
       << "Magic Find: " << this->magicFind << "\n";


    return ss.str();
}

const std::string Character::toStringMain() {
    std::stringstream ss;

    ss << "Name: " << this->name << "\n"
       << "Level: " << this->level << "\n"
       << "Exp: " << this->exp << "/" << this->expNext << "\n"
       << "Gold: " << this->gold << "\n";
    return ss.str();

}
