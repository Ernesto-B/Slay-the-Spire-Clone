// blockCard.h
#ifndef BLOCKCARD_H
#define BLOCKCARD_H
#include "card.h"

class BlockCard : public Card {
    private:    
        char* cardType;
    public:
        BlockCard();
};

#endif