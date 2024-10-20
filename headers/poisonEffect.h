// poisonEffect.h
#ifndef POISONEFFECT_H
#define POISONEFFECT_H
#include <iostream>
#include "statusEffect.h"

class PoisonEffect : public StatusEffect {
    private:
        int poisonDamage;
        int duration;

    public:
        PoisonEffect(int poisonDamage = 3, int duration = 3);

        void apply(Mon* user, Mon* target) override;
        void endTurn(Mon* target) override;
        bool isExpired() const override;

        StatusEffect* clone() const override;
        void setDuration(int duration) override;

        const char* getName() const;
};

#endif
