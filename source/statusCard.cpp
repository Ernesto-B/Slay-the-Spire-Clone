// statusCard.cpp
#include "statusCard.h"

StatusCard::StatusCard(const char* name, const char* desc, int cost, int dmg, int block = 0, StatusEffect* statusEffect = nullptr) : Card(name, desc, cost, dmg, block), statusEffect(statusEffect) {
    this->cardType = new char[strlen("Status") + 1];
    strcpy(this->cardType, "Status");
}

StatusCard::StatusCard(const StatusCard& other) : Card(other) {
    this->cardType = new char[strlen("Status") + 1];
    strcpy(this->cardType, other.cardType);

    if (other.statusEffect) {
        this->statusEffect = other.statusEffect->clone();
    } else {
        this->statusEffect = nullptr;
    }
}

StatusCard& StatusCard::operator=(const StatusCard& other) {
    // Check self assignment
    if (this != &other) {
        delete[] this->cardType;
        delete this->statusEffect;

        Card::operator=(other);

        this->cardType = new char[strlen("Status") + 1];
        strcpy(this->cardType, other.cardType);

        if (other.statusEffect) {
            this->statusEffect = other.statusEffect->clone();
        } else {
            this->statusEffect = nullptr;
        }
    }   
    return *this;
}

StatusCard::~StatusCard() {
    delete[] this->cardType;
    if (this->statusEffect) {
        delete this->statusEffect;
    }
}

const char* StatusCard::getCardType() const {
    return this->cardType;
}

void StatusCard::applyEffect(Mon* target) const {
    if (this->statusEffect) {
        StatusEffect* effectCopy = statusEffect->clone();
        target->addStatusEffect(effectCopy);
    }    
}
