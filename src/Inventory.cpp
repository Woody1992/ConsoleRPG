//
// Created by Vadik on 11.04.2021.
//

#include "Inventory.h"

void Inventory::initialize(const unsigned from)
{
    for (size_t i = from; i < this->cap; i++)
    {
        this->items[i] = nullptr; // setting the pointer to a value to not crash on delete
    }
}

void Inventory::expand()
{
    this->cap *= 2;

    Item** temp = new Item*[this->cap];

    for (size_t i = 0; i < this->nrOfItems; i++)
    {
        temp[i] = this->items[i];
    }

    delete[] this->items;

    this->items = temp;

    this->initialize(this->nrOfItems);
}

// Constructors & Destructors
Inventory::Inventory(unsigned cap)
{
    this->cap = cap;
    this->nrOfItems = 0;
    this->items = new Item*[cap];

    this->initialize();
}

Inventory::Inventory(const Inventory& other)
{
    this->cap = other.cap;
    this->nrOfItems = other.nrOfItems;

    this->items = new Item*[this->cap];

    this->initialize();

    for (size_t i = 0; i < this->nrOfItems; i++)
    {
        this->items[i] = other.items[i]->clone();
    }
}

Inventory::~Inventory()
{
    for (size_t i = 0; i < this->nrOfItems; i++)//Deleting pointer-pointers (items)
    {
        delete this->items[i];
    }

    delete [] this->items; //Delete the Array itself
}

//Operators
void Inventory::operator=(const Inventory& other)
{
    if (this != &other)
    {
        for (size_t i = 0; i < this->nrOfItems; i++)
        {
            delete this->items[i];
        }
        delete[] this->items;

        this->cap = other.cap;
        this->nrOfItems = other.nrOfItems;

        this->items = new Item*[this->cap];

        this->initialize();

        for (size_t i = 0; i < this->nrOfItems; i++)
        {
            this->items[i] = other.items[i]->clone();
        }
    }
}

Item& Inventory::operator[](const unsigned index)
{
    if (index < 0 || index >= this->nrOfItems)
    {
        throw("OUT OF BOUNDS!");
    }

    return *this->items[index];
}

//Accessors
const unsigned & Inventory::size() const
{
    return this->nrOfItems;
}

const unsigned & Inventory::capacity() const
{
    return this->cap;
}

Item & Inventory::at(const unsigned index)
{
    if (index < 0 || index >= this->nrOfItems)
    {
        throw("OUT OF BOUNDS!");
    }

    return *this->items[index];
}
//Functions
void Inventory::add(const Item & item)
{
    if (this->nrOfItems >= this->cap)
        this->expand();

    this->items[this->nrOfItems++] = item.clone();
}

void Inventory::remove(const unsigned index)
{

}

std::string Inventory::toString() const
{
    std::stringstream ss;

    ss << ("Inventory Menu");
    for (size_t i = 0; i < this->nrOfItems; i++)
    {
        ss << "(" << i << ")" << " " << "\n";
    }

    return ss.str();
}
