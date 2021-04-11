//
// Created by Vadik on 11.04.2021.
//

#include "Item.h"

//Private functions
void Item::generate()
{

}

//Constructors / Destructors
Item::Item(
        std::string name,
        unsigned type,
        unsigned rarity,
        unsigned value
)
{
    this->name = name;
    this->type = type;
    this->rarity = rarity;
    this->value = value;
}

Item::~Item()
{

}

//Accessors
const std::string & Item::getName() const
{
    return this->name;
}

const unsigned & Item::getType() const
{
    return this->type;
}

const std::string Item::getTypeAsString() const
{
    std::string typestr = "ERROR";

    switch (this->type)
    {
        case WEAPON:
            typestr = "Weapon";
            break;

        case ARMOR:
            typestr = "Armor";
            break;

        default:
            break;
    }

    return typestr;
}

const unsigned & Item::getRarity() const
{
    return this->rarity;
}

const std::string Item::getRarityAsString() const
{
    std::string raritystr = "ERROR";

    switch (this->type)
    {
        case COMMON:
            raritystr = "Common";
            break;

        case UNCOMMON:
            raritystr = "Uncommon";
            break;

        case RARE:
            raritystr = "Rare";
            break;

        case EPIC:
            raritystr = "Epic";
            break;

        case LEGENDARY:
            raritystr = "Legendary";
            break;

        case MYTHIC:
            raritystr = "Mythic";
            break;

        default:
            break;
    }

    return raritystr;
}

const unsigned & Item::getValue() const
{
    return this->value;
}
