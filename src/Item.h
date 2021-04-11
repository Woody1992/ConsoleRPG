//
// Created by Vadik on 11.04.2021.
//

#ifndef RPG_ITEM_H
#define RPG_ITEM_H


#include<string>
#include<sstream>

enum item_types {WEAPON = 0, ARMOR};
enum item_rarities {COMMON = 0, UNCOMMON, RARE, EPIC, LEGENDARY, MYTHIC};

class Item
{
private:
    std::string name;
    unsigned type;
    unsigned rarity;
    unsigned value;

    void generate();

public:
    Item(std::string name,
         unsigned type,
         unsigned rarity,
         unsigned value);
    virtual ~Item();

    //Accessors
    const std::string& getName() const;
    const unsigned& getType() const;
    const std::string getTypeAsString() const;
    const unsigned& getRarity() const;
    const std::string getRarityAsString() const;
    const unsigned& getValue() const;

    //Functions
    virtual Item* clone() const = 0;
    virtual const std::string toString() const = 0;
};

#endif //RPG_ITEM_H
