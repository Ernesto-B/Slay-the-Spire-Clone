// mon.cpp
# include <iostream>
#include <algorithm>  // for std::remove_if
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
    this->block = 0;
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

void Mon::addBlock(int amount) {
    this->block += amount;
}

void Mon::addStatusEffect(StatusEffect* effect) {
    this->activeEffects.push_back(effect);
    effect->apply(this);
}

void Mon::processEndTurnEffects() {
    for (auto effect : activeEffects) {
        effect->endTurn(this);
    }
    cleanupExpiredEffects();
}

void Mon::cleanupExpiredEffects() {
    activeEffects.erase(
        remove_if(activeEffects.begin(), activeEffects.end(), [](StatusEffect* effect) {
            if (effect->isExpired()) {
                delete effect; // Clean up expired effects
                return true;  // Remove this effect from the list
            }
            return false;  // Keep this effect in the list
        }),
        activeEffects.end());
}

void Mon::takeDmg(int amount) {
    if (this->block >= amount) {
        this->block -= amount;
    } else {
        int remainingDmg = amount - this->block;
        this->block = 0;
        this->health -= remainingDmg;

        if (this->currentHealth < 0) {
            this->currentHealth = 0;    // to prevent it from going negative
        }
    }
}

void Mon::heal(int amount) {
    if (this->currentHealth == this->health) {
        return;
    } else {
        if (this->currentHealth + amount > this->health) {
            this->currentHealth = this->health;
        } else {
            this->currentHealth += amount;
        }
    }
}