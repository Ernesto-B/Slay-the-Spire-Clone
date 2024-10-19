// attackCard.h
// SPECIFICALLY FOR CARDS THAT DO DAMAGE, OR DO DAMAGE AND APPLY STATUS EFFECT
#ifndef ATTACKCARD_H
#define ATTACKCARD_H
#include "card.h"
#include "poisonEffect.h"
#include "paralyzeEffect.h"
#include "healingEffect.h"

class AttackCard : public Card {
    private:    
        char* cardType;
        StatusEffect* statusEffect;
        
    public:
        AttackCard(const char* name, const char* desc, int cost, int dmg, int block = 0, StatusEffect* statusEffect = nullptr);
        AttackCard(const AttackCard& other);    // Copy constructor
        AttackCard& operator=(const AttackCard& other);  // Assignment operator
        ~AttackCard();

        const char* getCardType() const;
        void applyEffect(Mon* target) const;
};

#endif