// mon.cpp
# include <iostream>
#include <algorithm>  // for std::remove_if
using namespace std;
# include <cstring>
# include "mon.h"
# include "attack.h"

Mon::Mon(const char* name, int baseHealth = 0, int level = 1, int type = 0) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->health = 10 * level + baseHealth;
    this->currentHealth = this->health;
    this->level = level;
    this->type = type;
    this->block = 0;
}

Mon::~Mon() {
    delete[] name;
}

Mon::Mon(const Mon& other) {
    this->health = other.health;
    this->name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
}

Mon& Mon::operator=(const Mon& other) {
    if (this != &other) {
        delete[] this->name;

        this->health = other.health;
        this->name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
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

void Mon::changeBlock(int amount) {
    if (this->block + amount < 0) {
        this->block = 0;
    } else {
        this->block += amount;
    }
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