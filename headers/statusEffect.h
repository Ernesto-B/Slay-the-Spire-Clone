// statusEffect.h
// INTERFACE
#ifndef STATUSEFFECT_H
#define STATUSEFFECT_H
#include "mon.h"

class Mon;

enum class EffectTarget {
    SELF,  // Effect targets the user of the card (e.g. heal)
    TARGET // Effect targets the target of the card (e.g. poison)
};

class StatusEffect {
    protected:
        EffectTarget effectTarget;
    public:
        StatusEffect(EffectTarget target) : effectTarget(target) {}
        virtual ~StatusEffect() {}
        
        virtual void apply(Mon* user, Mon* target) = 0;    // Apply effect logic
        virtual void endTurn(Mon* target) = 0;  // Logic to apply at end of each turn
        virtual bool isExpired() const = 0;     // Check if the effect ended

        virtual StatusEffect* clone() const = 0;    // For cloning
        virtual void setDuration(int duration) = 0;     // Modify the duration

        EffectTarget getEffectTarget() const {return effectTarget;}
        virtual const char* getName() const = 0;    // Get the name of the effect
};

#endif
