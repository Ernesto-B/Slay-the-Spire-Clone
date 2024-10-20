// healingEffect.cpp
#include <iostream>
#include "healingEffect.h"

HealingEffect::HealingEffect(int healingAmount, int duration) : StatusEffect(EffectTarget::SELF), healingAmount(healingAmount), duration(duration) {

}

void HealingEffect::apply(Mon* user, Mon* target) {
    printf("%s is healing for %d turns.\n", user->getName(), this->duration);
}

void HealingEffect::endTurn(Mon* target) {
    if (duration > 0) {
        target->heal(this->healingAmount);
        duration--;
        printf("%s heals %d health. %d turns remaining.\n", target->getName(), this->healingAmount, this->duration);
    }
}

bool HealingEffect::isExpired() const {
    return duration <= 0;
}

StatusEffect* HealingEffect::clone() const {
    return new HealingEffect(healingAmount, duration);
}

void HealingEffect::setDuration(int duration) {
    this->duration = duration;
}

const char* HealingEffect::getName() const {
    return "Healing";
}