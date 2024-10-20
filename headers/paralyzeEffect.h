// paralyzeEffect.h
#ifndef PARALYZEEFFECT_H
#define PARALYZEEFFECT_H
#include <iostream>
#include "statusEffect.h"


// Unable to block for duration
class ParalyzeEffect : public StatusEffect {
    private:
        int duration;
    
    public:
        ParalyzeEffect(int duration);

        void apply(Mon* user, Mon* target) override;
        void endTurn(Mon* target) override;
        bool isExpired() const override;
        
        StatusEffect* clone() const override;
        void setDuration(int duration) override;

        const char* getName() const;
};

#endif