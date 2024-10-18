// mon.cpp
# include <iostream>
using namespace std;
# include <cstring>
# include "mon.h"
# include "attack.h"

Mon::Mon(const char* name, int baseHealth, int level, int type = 0) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->health = 10 * level + baseHealth;
    this->currentHealth = this->health;
    this->level = level;
    this->type = type;
    this->attack1 = new Attack(0, "N/a", 0);    // Not sure what to do with this
    this->attack2 = new Attack(0, "N/a", 0);    // Not sure what to do with this
}

Mon::~Mon() {
    delete[] name;
    delete this->attack1;
    delete this->attack2;
}

Mon::Mon(const Mon& other) {
    this->health = other.health;
    this->name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
    this->attack1 = new Attack(*other.attack1);
    this->attack2 = new Attack(*other.attack2);
}

Mon& Mon::operator=(const Mon& other) {
    if (this != &other) {
        delete[] this->name;
        delete this->attack1;
        delete this->attack2;

        this->health = other.health;
        this->name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        this->attack1 = new Attack(*other.attack1);
        this->attack2 = new Attack(*other.attack2);
    }
    return *this;
}

char* Mon::getName() const {
    return this->name;
}

int Mon::getHealth() const {
    return this->health;
}

int Mon::getCurrentHealth() const {
    return this->currentHealth;
}


void Mon::printInfo() const {
    printf("\n%s\t %d\n", this->name, this->type);
    printf("Lv. %d\n", this->level);
    printf("HP: %d/%d\n", this->currentHealth, this->health);
}

void Mon::printAttacks() const {
    printf("\nAttacks:\t\n");
    printf("%s\t%d\n", this->attack1->getAtkName(), this->attack1->getDmg());
    printf("%s\t%d\n", this->attack2->getAtkName(), this->attack2->getDmg());
}

// Status effects, to be called at the end of turn
void Mon::applyPoison(int amount) {

}

void Mon::applyWeaken(int amount) {

}

void Mon::applyStrength(int amount) {

}

void Mon::addBlock(int amount) {

}

void Mon::takeDmg(int amount) {

}
