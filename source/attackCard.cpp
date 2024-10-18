// attackCard.cpp
#include "attackCard.h"
#include "card.h"

AttackCard::AttackCard(const char* name, const char* desc, int cost, int dmg, int block) : Card(name, desc, cost, dmg, block) {
    this->cardType = new char[strlen("Attack") + 1];
    strcpy(this->cardType, "Attack");
}

AttackCard::~AttackCard() {
    delete[] this->cardType;
}

const char* AttackCard::getCardType() const {
    return this->cardType;
}