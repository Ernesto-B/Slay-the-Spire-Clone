// poisonEffect.cpp
#include <iostream>
#include "poisonEffect.h"

PoisonEffect::PoisonEffect(int poisonDamage = 3, int duration = 3) 
    : poisonDamage(poisonDamage), duration(duration) {}

void PoisonEffect::apply(Mon* target) {
    printf("%s is poisoned for %d turns.\n", target->getName(), this->duration);
}

void PoisonEffect::endTurn(Mon* target) {
    if (duration > 0) {
        target->takeDmg(this->poisonDamage);
        duration--;
        printf("%s takes %d poison damage. %d turns remaining.\n", target->getName(), this->poisonDamage, this->duration);
    }
}

bool PoisonEffect::isExpired() const {
    return duration <= 0;
}
