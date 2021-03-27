//
// Created by Vadik on 27.03.2021.
//

#ifndef RPG_CHARACTER_H
#define RPG_CHARACTER_H
#include <string>
#include <iostream>
#include <vector>
#include <sstream>

class Character
{
private:
    // Core stats
    std::string name;
    int level;
    int exp;
    int expNext;

    int hp;
    int hpMax;
    int mana;
    int manaMax;
    int stamina;
    int staminaMax;

    int defence;
    float dodgeChance;
    float hitChance;
    float critChance;
    float magicFind;

    int gold;

    // Attributes
    int strength;
    int vitality;
    int agility;
    int dexterity; // ловкость
    int intelligence;



public:
    Character(std::string name);
    virtual ~Character();

    const std::string toString(); // set variables in strings
};


#endif //RPG_CHARACTER_H
