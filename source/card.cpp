// card.cpp
#include <iostream>
using namespace std;
#include <cstring>
#include "card.h"

Card::Card(const char* name, const char* desc, int cost, int dmg, int block) : cost(cost), dmg(dmg), block(block) {
    this->name = new char[50];
    strcpy(this->name, name);
    this->desc = new char[200];
    strcpy(this->desc, desc);
}

Card::Card(const Card& other) : cost(other.cost), dmg(other.dmg), block(other.block) {
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);
    this->desc = new char[strlen(other.desc) + 1];
    strcpy(this->desc, other.desc);

}

Card& Card::operator=(const Card& other) {
    // Check self assign
    if (this != &other) {
        delete[] this->name;
        delete[] this->desc;

        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
        this->desc = new char[strlen(other.desc) + 1];
        strcpy(this->desc, other.desc);

        this->cost = other.cost;
        this->dmg = other.dmg;
        this->block = other.block;
    }
    return *this;
}

Card::~Card() {
    delete[] this->name;
    delete[] this->desc;
}

int Card::getCost() const {
    return this->cost;
}

int Card::getDmg() const {
    return this->dmg;
}

int Card::getBlock() const {
    return this->block;
}

void Card::printCardInfo() const {
    printf("\n%s\t%d\n", this->name, this->cost);
    printf("%s\n", this->desc);
    printf("%d\t%d\n", this->dmg, this->block);
}
