// blockCard.cpp
#include "blockCard.h"

BlockCard::BlockCard(const char* name, const char* desc, int cost, int dmg, int block = 0, StatusEffect* statusEffect = nullptr, int effectDuration = 0) : Card(name, desc, cost, dmg, block), statusEffect(statusEffect), effectDuration(effectDuration) {
    this->cardType = new char[strlen("Block") + 1];
    strcpy(this->cardType, "Block");
}

BlockCard::BlockCard(const BlockCard& other) : Card(other), effectDuration(other.effectDuration) {
    this->cardType = new char[strlen("Block") + 1];
    strcpy(this->cardType, other.cardType);

    if (other.statusEffect) {
        this->statusEffect = other.statusEffect->clone();
    } else {
        this->statusEffect = nullptr;
    }
}

BlockCard& BlockCard::operator=(const BlockCard& other) {
    // Check self assignment
    if (this != &other) {
        delete[] this->cardType;
        delete this->statusEffect;

        Card::operator=(other);

        this->cardType = new char[strlen("Block") + 1];
        strcpy(this->cardType, other.cardType);

        if (other.statusEffect) {
            this->statusEffect = other.statusEffect->clone();
        } else {
            this->statusEffect = nullptr;
        }
        this->effectDuration = other.effectDuration;
    }   
    return *this;
}

BlockCard::~BlockCard() {
    delete[] this->cardType;
    if (this->statusEffect) {
        delete this->statusEffect;
    }
}

const char* BlockCard::getCardType() const {
    return this->cardType;
}

void BlockCard::applyEffect(Mon* target) const {
    if (this->statusEffect) {
        StatusEffect* effectCopy = statusEffect->clone();
        effectCopy->setDuration(effectDuration);

        target->addStatusEffect(effectCopy);
    }    
}
