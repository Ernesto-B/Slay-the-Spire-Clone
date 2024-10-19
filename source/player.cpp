// player.cpp
#include "player.h"

Player::Player(const char* name, int baseHealth = 0, int level = 1, int type = 0, int energy = 3, Deck* initialDeck) : Mon(name, baseHealth = 0, level = 1, type = 0), energy(energy), currentEnergy(energy), deck(*initialDeck) {

}

Player::~Player() {
    for (Card* card : hand) {
        delete card;
    }
    for (Card* card : discardPile) {
        delete card;
    }
    hand.clear();
    discardPile.clear();
}

void Player::takeTurn() {

}

void Player::endTurn() {
    // Maybe set a flag to be used in the gameFrame file?

    this->resetEnergy();
}

void Player::drawCard() {
    Card* drawnCard = deck.drawCard();
    if (drawnCard) {
        hand.push_back(drawnCard);
    } else {
        deck.resetDeck();   // to be implemented
    }
}

void Player::useCard(Card* card, Mon* target) {
    // Check if the player has enough energy.
    if (card->getCost() > currentEnergy) {
        printf("Not enough energy to use %s\n", card->getName());
        return;
    }

    loseEnergy(card->getCost());

    // Apply effects based on the card type using dynamic_cast.
    if (AttackCard* attackCard = dynamic_cast<AttackCard*>(card)) {
        target->takeDmg(attackCard->getDmg());
        attackCard->applyEffect(target);  // Apply status effect if any.
        printf("%s uses %s, dealing %d damage!\n", this->getName(), card->getName(), attackCard->getDmg());
    } else if (BlockCard* blockCard = dynamic_cast<BlockCard*>(card)) {
        this->changeBlock(blockCard->getBlock());
        blockCard->applyEffect(this);  // Apply status effect if any.
        printf("%s uses %s, gaining %d block!\n", this->getName(), card->getName(), blockCard->getBlock());
    } else if (StatusCard* statusCard = dynamic_cast<StatusCard*>(card)) {
        statusCard->applyEffect(target);
        printf("%s uses %s, applying a status effect.\n", this->getName(), card->getName());
    } else {
        printf("%s uses an unknown card!\n", this->getName());
    }

    // Move the card to the discard pile.
    discardPile.push_back(card);
}


int Player::getEnergy() const {
    return this->energy;
}

void Player::setMaxEnergy(int energy) {
    this->energy = energy;
}

void Player::changeEnergy(int amount) {
    if (this->currentEnergy + amount < 0) {
        this->currentEnergy = 0;
    } else {
        this->currentEnergy += amount;
    }
}

// to be used as helper func to endTurn()
void Player::resetEnergy() {
    this->currentEnergy = this->energy; 
}

// to be used as helper func to useCard()
void Player::loseEnergy(int amount) {
    if (this->currentEnergy - amount < 0) {
        this->currentEnergy = 0;
    } else {
        this->currentEnergy -= amount;
    }
}
