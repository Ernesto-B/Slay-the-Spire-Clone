// deckFactory.h
#ifndef DECKFACTORY_H
#define DECKFACTORY_H
#include "deck.h"
#include "attackCard.h"
#include "blockCard.h"
#include "statusCard.h"

class DeckFactory {
    public:
        static Deck* createDefaultDeck();
        static Deck* createAggressiveDeck();
        static Deck* createStatusDeck();
        // static Deck* createCustomDeck()  // Not MVP. Maybe in future update
};

#endif