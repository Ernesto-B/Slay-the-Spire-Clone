// blockCard.h
// SPECIFICALLY FOR CARDS THAT APPLY BLOCK, OR APPLY BLOCK AND STATUS EFFECT
#ifndef BLOCKCARD_H
#define BLOCKCARD_H
#include "card.h"
#include "statusEffect.h"

class BlockCard : public Card {
    private:    
        char* cardType;
        StatusEffect* statusEffect;

    public:
        BlockCard(const char* name, const char* desc, int cost, int dmg, int block = 0, StatusEffect* statusEffect = nullptr);
        BlockCard(const BlockCard& other);  // Copy constructor
        BlockCard& operator=(const BlockCard& other);   // Assignment operator
        ~BlockCard();

        const char* getCardType() const;
        void applyEffect(Mon* user, Mon* target) const override;       
};

#endif