// attack.h
#ifndef ATTACK_H
#define ATTACK_H

#include <iostream>
#include <cstring>
#include "statusEffect.h"

class Attack {
    private:
        char* attackName;
        int type;
        int dmg;
        StatusEffect* statusEffect;
        int effectDuration;

    public:
        Attack(const char* attackName, int type, int dmg, StatusEffect* statusEffect = nullptr, int effectDuration = 0);
        ~Attack();
        
        int getDmg();
        const char* getAtkName();
        void applyEffect(Mon* target) const;
};

#endif
