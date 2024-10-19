// player.h
#ifndef PLAYER_H
#define PLAYER_H
#include "mon.h"
#include "card.h"
#include "deck.h"
#include "deckFactory.h"
using namespace std;


class Player : public Mon {
    private:
        int energy;
        int currentEnergy;
        Deck deck;
        vector<Card*> hand;
        vector<Card*> discardPile;

    public:
        Player(const char* name, int baseHealth = 0, int level = 1, int type = 0, int energy = 3, Deck* initialDeck);
        ~Player();

        void takeTurn();
        void endTurn();
        void drawCard();
        void useCard(Card* card, Mon* target);

        int getEnergy() const;
        void setMaxEnergy(int energy);
        void changeEnergy(int amount);
        void resetEnergy();  // Helper func for endTurn() 
        void loseEnergy(int amount);  // Helper func for useCard()
};

#endif