// deck.cpp
#include "deck.h"
#include <ctime>    // Used for creating the random seed for shuffling the deck

Deck::Deck(const char* deckName) {
    this->deckName = new char[strlen(deckName) + 1];
    strcpy(this->deckName, deckName);
}

Deck::~Deck() {
    delete[] this->deckName;
    for (Card* card : cards) {
        delete card;    // deleting the mem allocation
    }
    cards.clear();  // deleting elements from the array
}

void Deck::addCard(Card* card) {
    this->cards.push_back(card);
}

Card* Deck::drawCard() {
    if (this->cards.empty()) return nullptr;

    Card* drawnCard = cards.back();
    cards.pop_back();
    return drawnCard;
}

void Deck::shuffleDeck() {
    unsigned seed = static_cast<unsigned>(std::time(0)) + (rand() % 100);
    mt19937 g(seed);
    shuffle(cards.begin(), cards.end(), g);

    printf("Deck shuffled!\n");
}

void Deck::resetDeck(vector<Card*>& discardPile) {
    printf("Reshuffling discard pile into deck...\n");
    this->cards.insert(cards.end(), discardPile.begin(), discardPile.end());
    discardPile.clear();
    shuffleDeck();
}

int Deck::getSize() const {
    return cards.size();
}

char* Deck::getName() const {
    return this->deckName;
}