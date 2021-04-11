//
// Created by Vadik on 11.04.2021.
//

#ifndef RPG_INVENTORY_H
#define RPG_INVENTORY_H

#include<sstream>
#include<string>
#include "Weapon.h"


class Inventory {
private:
    Item **items; //pointer-pointer to an item inside an array
    unsigned cap; //Capacity of the array
    unsigned nrOfItems; // Number of actual items in the array

    void initialize(const unsigned from = 0);
    void expand();
public:
    Inventory(unsigned cap = 10); //Size of an array when created
    Inventory(const Inventory& other); // creating an inventory from another inventory
    virtual ~Inventory();

    //Operators
    void operator = (const Inventory& other);
    Item& operator [] (const unsigned index); //return an item

    //Accessors
    const unsigned& size() const; // Numbr of items
    const unsigned& capacity() const; //Capacity
    Item& at(const unsigned index);

    //Functions
    void add(const Item& item);
    void remove(const unsigned index);
    Item* replace(const unsigned index, Item* item);
    std::string toString() const;
};


#endif //RPG_INVENTORY_H
