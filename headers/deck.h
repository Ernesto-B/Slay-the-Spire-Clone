// deck.h
#ifndef DECK_H
#define DECK_H
#include "card.h"
#include <vector>
#include <random>
#include <algorithm>    // for std::shuffle()
#include <cstring>

class Deck {
    private:
        char* deckName;
        vector<Card*> cards;

    public:
        Deck(const char* deckName);
        ~Deck();

        void addCard(Card* card);
        Card* drawCard();
        void shuffleDeck();
        void resetDeck(vector<Card*>& discardPile);
        int getSize() const;
        char* getName() const;
};

#endif