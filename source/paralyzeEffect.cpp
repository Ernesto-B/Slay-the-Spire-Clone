// paralyzeEffect.cpp
#include <iostream>
#include "paralyzeEffect.h"

ParalyzeEffect::ParalyzeEffect(int duration) : StatusEffect(EffectTarget::SELF), duration(duration) {}

void ParalyzeEffect::apply(Mon* user, Mon* target) {
    printf("%s is paralyzed for %d turns.\n", target->getName(), this->duration);
}

void ParalyzeEffect::endTurn(Mon* target) {
    if (duration > 0) {
        target->changeBlock(this->duration);
        this->duration--;
        printf("%s's block is zero due to being paralyzed. %d turns remaining.\n", target->getName(), this->duration);
    }
}

bool ParalyzeEffect::isExpired() const {
    return duration <= 0;
}


StatusEffect* ParalyzeEffect::clone() const {
    return new ParalyzeEffect(duration);
}

void ParalyzeEffect::setDuration(int duration) {
    this->duration = duration;
}

const char* ParalyzeEffect::getName() const {
    return "Paralyze";
}