// enemy.cpp
#include "enemy.h"

// baseHealth is added to the health calculation to make more tanky mons
Enemy::Enemy(const char* name, int baseHealth = 0, int level = 1, int type = 0) : Mon(name, baseHealth, level, type) {}

Enemy::~Enemy() {
    for (auto attack : attacks) {
        delete attack;
    }
    attacks.clear();
}

void Enemy::attack(Player* player, Attack* chosenAttack) {    // helper function
    printf("%s uses %s!\n", this->getName(), chosenAttack->getAtkName());
    this->takeDmg(chosenAttack->getDmg());
    chosenAttack->applyEffect(player);
}

void Enemy::takeTurn(Player* player) {
    // Check to make sure there is an attack in the array
    if (this->attacks.empty()) return;

    // Algorightm for deciding an attack here. WIP
    int attackIndex = rand() % attacks.size();
    Attack* chosenAttack = attacks[attackIndex];

    // Attack the player
    attack(player, chosenAttack);
}

void Enemy::addAttack(Attack* attack) {
    this->attacks.push_back(attack);
}