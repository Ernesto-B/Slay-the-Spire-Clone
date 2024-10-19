// statusCard.h
// SPECIFICALLY FOR CARDS THAT ONLY APPLY STATUS EFFECT
#ifndef STATUSCARD_H
#define STATUSCARD_H
#include "card.h"
#include "statusEffect.h"

class StatusCard : public Card {
    private:    
        char* cardType;
        StatusEffect* statusEffect;

    public:
        StatusCard(const char* name, const char* desc, int cost, int dmg, int block = 0, StatusEffect* statusEffect = nullptr);
        StatusCard(const StatusCard& other);  // Copy constructor
        StatusCard& operator=(const StatusCard& other);   // Assignment operator
        ~StatusCard();

        const char* getCardType() const;
        void applyEffect(Mon* target) const;       
};

#endif