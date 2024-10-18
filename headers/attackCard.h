// attackCard.h
#ifndef ATTACKCARD_H
#define ATTACKCARD_H
#include "card.h"

class AttackCard : public Card {
    private:    
        char* cardType;
    public:
        AttackCard(Card* card);
};

#endif