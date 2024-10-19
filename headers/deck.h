// deck.h
#ifndef DECK_H
#define DECK_H
#include "card.h"
#include <vector>
#include <random>
#include <algorithm>    // for std::shuffle()

class Deck {
    private:
        char* deckName;
        vector<Card*> cards;

    public:
        Deck(char* deckName);
        ~Deck();

        void addCard(Card* card);
        Card* drawCard();
        void shuffleDeck();
        void resetDeck();
        int getSize() const;
        char* getName() const;
};

#endif