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
    int location;


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

    int damageMin;
    int damageMax;
    int defence;
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
    inline const unsigned getSeed() const { return this->x + this->y; }
    inline const unsigned getX() const { return this->x; }
    inline const unsigned getY() const { return this->y; }
    inline const int getLevel() const { return this->level; }
    inline const bool isDead() const { return this->hp <= 0; }
    inline const int getHP() const { return this->hp; }
    inline const int getHPMax() const { return this->hpMax; }
    inline const int getStamina() const { return this->stamina; }
    const int getDamageMin() const;
    const int getDamageMax() const;
    const int getTotalDamage() const;
    inline const int getDefence() const { return this->defence; }
    inline const int getHitRating() const { return this->hitRating; }
    inline const int getLocation() const { return this->location; }

    //Modifiers
    void setLocation(const int location);
    void setPosition(const unsigned x, const unsigned y);
    void move(const int x, const int y);

    //Functions

    const std::string flee();
    void reset();
    void resetHP();
    void takeDamage(const int damage);
    void setDead();
    void addExp(const unsigned exp);
    bool canLevelUp();
    const std::string getMenuBar();
    const std::string toStringPosition();
    const std::string toStringStats();
    const std::string toStringMain();
};


#endif //RPG_CHARACTER_H
