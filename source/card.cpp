#include <iostream>
using namespace std;
#include <cstring>
#include "card.h"

Card::Card(char* name, char* desc, int cost, int dmg, int block) : cost(cost), dmg(dmg), block(block) {
    this->name = new char[50];
    strcpy(this->name, name);
    this->desc = new char[200];
    strcpy(this->desc, desc);
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

void Card::getCardInfo() const {
    printf("\n%s\t%d\n", this->name, this->cost);
    printf("%s\n", this->desc);
    printf("%d\t%d\n", this->dmg, this->block);
}
