// attackCard.cpp
#include "attackCard.h"
// #include "card.h"

AttackCard::AttackCard(const char* name, const char* desc, int cost, int dmg, int block, StatusEffect* statusEffect) : Card(name, desc, cost, dmg, block), statusEffect(statusEffect) {
    this->cardType = new char[strlen("Attack") + 1];
    strcpy(this->cardType, "Attack");
}

AttackCard::AttackCard(const AttackCard& other) : Card(other) {
    this->cardType = new char[strlen("Attack") + 1];
    strcpy(this->cardType, other.cardType);

    if (other.statusEffect) {
        this->statusEffect = other.statusEffect->clone();
    } else {
        this->statusEffect = nullptr;
    }
}

AttackCard& AttackCard::operator=(const AttackCard& other) {
    // Check self assignment
    if (this != &other) {
        delete[] this->cardType;
        delete this->statusEffect;

        Card::operator=(other);

        this->cardType = new char[strlen("Attack") + 1];
        strcpy(this->cardType, other.cardType);

        if (other.statusEffect) {
            this->statusEffect = other.statusEffect->clone();
        } else {
            this->statusEffect = nullptr;
        }
    }
    return *this;
}

AttackCard::~AttackCard() {
    delete[] this->cardType;
    if (this->statusEffect) {
        delete this->statusEffect;
    }
}

const char* AttackCard::getCardType() const {
    return this->cardType;
}

void AttackCard::applyEffect(Mon* user, Mon* target) const {
    if (this->statusEffect) {
        StatusEffect* effectCopy = statusEffect->clone();
        if (effectCopy->getEffectTarget() == EffectTarget::SELF) {
            effectCopy->apply(user, user);  // Apply effect to the user
        } else {
            effectCopy->apply(user, target);  // Apply effect to the target
        }
    }
}