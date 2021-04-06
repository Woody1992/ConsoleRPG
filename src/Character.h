//
// Created by Vadik on 27.03.2021.
//

#ifndef RPG_CHARACTER_H
#define RPG_CHARACTER_H
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>

class Character
{
private:
    //location
    unsigned x;
    unsigned y;

    // Core stats
    std::string name;
    int level;
    int exp;
    int expNext;
    int skillPoints;


    //Stars
    int hp;
    int hpMax;
    int mana;
    int manaMax;
    int stamina;
    int staminaMax;

    // Attributes
    int strength;
    int vitality;
    int agility;
    int dexterity; // ловкость
    int intelligence;

    int defence;
    float dodgeChance;
    float hitRating;
    float critChance;
    float magicFind;

    int gold;



    //Functions
    void updateSkills();

public:
    Character(std::string name);
    virtual ~Character();

    //Accessors
    inline const unsigned getSeed() const { return this->x + this->y; };

    //Modifiers
    void setLocation(const int location);
    void setPosition(const unsigned x, const unsigned y);
    void move(const int x, const int y);

    //Functions
    void addExp(const unsigned exp);
    bool canLevelUp();
    const std::string getMenuBar();
    const std::string toString(); // set variables in strings
    const std::string toStringPosition();
    const std::string toStringStats();
    const std::string toStringMain();
};


#endif //RPG_CHARACTER_H
