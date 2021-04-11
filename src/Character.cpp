//
// Created by Vadik on 27.03.2021.
//

#include "Character.h"

void Character::updateSkills()
{
    this->hpMax = this->vitality * 10;
    this->hp = this->hpMax;
    this->staminaMax=this->agility*2;
    this->stamina=this->staminaMax;
    this->manaMax=this->intelligence * 10;
    this->mana=this->manaMax;


    this->damageMin = this->strength * 2 + 3;
    this->damageMax = this->strength / 2 + this->strength * 2 + 5;

    this->defence= this->agility*2;
    this->hitRating=this->dexterity * 5;
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
    this->exp = 0;
    this->expNext =46;
    this->skillPoints = 5;
    this->location = -1;

    this->strength = 1;
    this->vitality = 1;
    this->agility = 1;
    this->dexterity = 1;
    this->intelligence = 1;

    this->gold = 100;

    this->updateSkills();
    this->resetHP();
}

Character::~Character()
{

}

//Accessors
const int Character::getDamageMin() const
{
    return this->damageMin;
}

const int Character::getDamageMax() const
{
    return this->damageMax;
}

const int Character::getTotalDamage() const
{
    return rand() % (this->damageMax - this->damageMin + 1) + this->damageMin;
}

// Functions
void Character::setPosition(const unsigned x, const unsigned y)
{
    this->x = x;
    this->y = y;
}

void Character::setLocation(const int location)
{
    this->location = location;
}

void Character::move(const int x, const int y) // MOVE
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

const std::string Character::flee() // Run from battle
{
    std::stringstream ss;
    int lostExp = rand() % (this->level * 5) + 1;
    int lostGold = rand() % (this->level * 5) + 1;
    ss << " Exp lost: " << lostExp << " | " << " Gold lost: " << lostGold;

    this->exp -= lostExp;;

    if (this->exp < 0)
        this->exp = 0;

    this->gold -= lostGold;

    if (this->gold < 0)
        this->gold = 0;

    return ss.str();
}

void Character::resetHP() // REset HP
{
    this->hp = this->hpMax;
}

void Character::reset() //Reset all STATS
{
    this->hp = this->hpMax;
    this->stamina = this->staminaMax;
    this->mana = this->manaMax;
}

void Character::takeDamage(const int damage) //Take DMG
{
    this->hp -= damage;

    if (this->hp <= 0)
        this->setDead();
}

void Character::setDead() // Player Death
{
    this->hp = 0;

    this->exp -= rand()% (this->level * 10) + 1; // EXP lost if died

    if (this->exp < 0)
        this->exp = 0;

    this->gold -= rand() % (this->level * 10) + 1; //GOLD lost if died

    if (this->gold < 0)
        this->gold = 0;
}

bool Character::addExp(const unsigned exp) // EXP
{
    bool levelup = false;

    this->exp += exp;

    while (this->exp >= this->expNext)
    {
        this->level++;
        this->exp -= this->expNext;
        this->expNext = (50 / 3) * (pow(this->level, 3) - 6 * pow(this->level, 2) + (this->level * 17) - 12);
        this->skillPoints++;

        this->strength += this->level % 2;
        this->vitality += this->level % 2;
        this->agility += this->level % 2;
        this->dexterity += this->level % 2;
        this->intelligence += this->level % 2;

        levelup = true;

        this->updateSkills();
        this->resetHP();
    }

    return levelup;
}

void Character::addGold(const unsigned gold) // GOLD
{
    this->gold += gold;
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

const std::string Character::getMenuBar() //Player minibar
{
    std::stringstream ss;

    ss
        << "Name: " << this->name << " |"
        << "Level: " << this->level << " |"
        << "Exp: " << this->exp << "/"<< this->expNext << " |"
        << "Health: " << this->hp << "/" << this->hpMax << " |"
        << "Stamina: " << this->stamina << "/" << this->staminaMax << "\n"
        << "Skill points available: " << this->skillPoints << "\n";

    return ss.str();
}

const std::string Character::toStringPosition() // Player position on the map
{
    std::stringstream ss;

    ss << "x: " << this->x << " y: " << this->y << "\n";

    return ss.str();
}

const std::string Character::toStringStats() // Character Stats
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


       << "Damage: " << this->damageMin << "-" << this->damageMax << "\n"
       << "Defence: " << this->defence << "\n"
       << "Hit rating: " << this->hitRating << "\n"
       << "Crit chance: " << this->critChance << "\n"
       << "Magic Find: " << this->magicFind << "\n";

    return ss.str();
}

const std::string Character::toStringMain() // Character main info
{
    std::stringstream ss;

    ss << "Name: " << this->name << "\n"
       << "Level: " << this->level << "\n"
       << "Exp: " << this->exp << "/" << this->expNext << "\n"
       << "Gold: " << this->gold << "\n";
    return ss.str();
}
