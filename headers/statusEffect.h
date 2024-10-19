// statusEffect.h
// INTERFACE
#ifndef STATUSEFFECT_H
#define STATUSEFFECT_H
#include "mon.h"

class Mon;

class StatusEffect {
    public:
        virtual ~StatusEffect() {}
        
        virtual void apply(Mon* target) = 0;    // Apply effect logic
        virtual void endTurn(Mon* target) = 0;  // Logic to apply at end of each turn
        virtual bool isExpired() const = 0;     // Check if the effect ended

        virtual StatusEffect* clone() const = 0;    // For cloning
        virtual void setDuration(int duration) = 0;     // Modify the duration
};

#endif
