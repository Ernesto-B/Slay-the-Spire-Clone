// attack.cpp
# include <iostream>
using namespace std;
# include <cstring>
# include "attack.h"

Attack::Attack(const char* attackName, int type, int dmg, StatusEffect* statusEffect = nullptr, int effectDuration = 0) : dmg(dmg), type(type), effectDuration(effectDuration) {
    this->attackName = new char[strlen(attackName) + 1];
    strcpy(this->attackName, attackName);
}

Attack::~Attack() {
    delete[] attackName;
    if (this->statusEffect) {
        delete this->statusEffect;
    }
}

int Attack::getDmg() {
    return this->dmg;
}

const char* Attack::getAtkName() {
    return this->attackName;
}

void Attack::applyEffect(Mon* target) const {
    if (this->statusEffect) {
        StatusEffect* effectCopy = this->statusEffect->clone();
        effectCopy->setDuration(this->effectDuration);
        target->addStatusEffect(effectCopy);
    }
}
