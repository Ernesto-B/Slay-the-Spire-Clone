// player.cpp
#include "player.h"

Player::Player(const char* name, int baseHealth, int level, int type, int energy, Deck* initialDeck) : Mon(name, baseHealth, level, type), energy(energy), currentEnergy(energy), deck(*initialDeck) {

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

void Player::takeTurn(GameFrame* gameFrame, vector<Mon*>& enemies) {

}

void Player::endTurn() {
    printf("%s ends their turn.\n", getName());
    processEndTurnEffects();    // trouble
    this->resetEnergy();
}

void Player::drawCard() {
    if (hand.size() >= 5) {
        printf("Cannot draw more cards. Hand size limit reached.\n");
        return;
    }
    
    Card* drawnCard = deck.drawCard();
    if (drawnCard) {
        hand.push_back(drawnCard);
    } else {
        deck.resetDeck(discardPile); // Pass discardPile to reset the deck.
        // Try drawing a card again after resetting.
        drawnCard = deck.drawCard();
        if (drawnCard) {
            hand.push_back(drawnCard);
        }
    }
}


void Player::useCard(Card* card, Mon* target) {
    loseEnergy(card->getCost());

    // Apply effects based on the card type using dynamic_cast.
    if (AttackCard* attackCard = dynamic_cast<AttackCard*>(card)) {
        target->takeDmg(attackCard->getDmg());
        attackCard->applyEffect(this, target);  // Apply status effect if any.
        printf("%s uses %s, dealing %d damage!\n", this->getName(), card->getName(), attackCard->getDmg());
    } else if (BlockCard* blockCard = dynamic_cast<BlockCard*>(card)) {
        this->changeBlock(blockCard->getBlock());
        blockCard->applyEffect(this, this);  // Apply status effect to self, if any.
        printf("%s uses %s, gaining %d block!\n", this->getName(), card->getName(), blockCard->getBlock());
    } else if (StatusCard* statusCard = dynamic_cast<StatusCard*>(card)) {
        // Check if the effect should target the user or the target
        if (statusCard->getEffectTarget() == EffectTarget::SELF) {
            statusCard->applyEffect(this, this);  // Apply status effect to self
        } else {
            statusCard->applyEffect(this, target);  // Apply status effect to target
        }
    } else {
        printf("%s uses an unknown card!\n", this->getName());
    }

    // Move the card to the discard pile.
    discardPile.push_back(card);
}

void Player::removeCardFromHand(int index) {
    if (index >= 0 && static_cast<size_t>(index) < hand.size()) {
        discardPile.push_back(hand[index]);  // move to discard pile
        hand.erase(hand.begin() + index);    // remove card from hand
    }
}


int Player::getEnergy() const {
    return this->energy;
}

int Player::getCurrentEnergy() const {
    return this->currentEnergy;
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

const vector<Card*>& Player::getHand() const {
    return hand;
}

const Deck& Player::getDeck() const {
    return deck;
}