// attackCard.h
#ifndef ATTACKCARD_H
#define ATTACKCARD_H
#include "card.h"

class AttackCard : public Card {
    private:    
        char* cardType;
    public:
        AttackCard(const char* name, const char* desc, int cost, int dmg, int block);
        ~AttackCard();
        
        const char* getCardType() const;
};

#endif