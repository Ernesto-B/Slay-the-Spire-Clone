// healingEffect.h
#ifndef HEALINGEFFECT_H
#define HEALINGEFFECT_H
#include "statusEffect.h"

class HealingEffect : public StatusEffect {
    private:
        int healingAmount;
        int duration;

    public:
        HealingEffect(int healingAmount = 2, int duration = 3);

        void apply(Mon* user, Mon* target) override;
        void endTurn(Mon* target) override;
        bool isExpired() const override; 

        StatusEffect* clone() const override;
        void setDuration(int duration) override;

        const char* getName() const;
};

#endif
