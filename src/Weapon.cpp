//
// Created by Vadik on 11.04.2021.
//

#include "Weapon.h"

Weapon::Weapon(
        int damageMin,
        int damageMax,
        std::string name,
        unsigned type,
        unsigned rarity,
        unsigned value)
        : Item(name, type, rarity, value)
{
    this->damageMax = damageMax;
    this->damageMin = damageMin;
}

Weapon::~Weapon()
{

}

Weapon * Weapon::clone() const
{
    return new Weapon(*this);
}

const std::string Weapon::toString() const
{
    std::stringstream ss;

    ss << "Name: " << this->getName()
       << "Type: " << this->getTypeAsString()
       << "Damage: " << this->damageMin << "-" << this->damageMax
       << "Rarity: " << this->getRarityAsString()
       << "Value: " << this->getValue();

    return ss.str();
}

