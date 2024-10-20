// deckFactory.cpp
#include "deckFactory.h"

// Status effects initialized with specific values
StatusEffect* poison = new PoisonEffect(3, 2);  // 3 damage, 2 turns duration.
StatusEffect* paralyze = new ParalyzeEffect(2); // 2 turns duration.
StatusEffect* healing = new HealingEffect(2, 3); // Heals 2 for 3 turns.

Deck* DeckFactory::createDefaultDeck() {
    Deck* deck = new Deck("Default Deck");

    // Normal cards here (makes *4 of them).
    for (int i = 0; i < 2; ++i) {
        deck->addCard(new AttackCard("Strike", "Deal 4 damage.", 1, 4, 0));
        deck->addCard(new BlockCard("Defend", "Gain 3 block.", 1, 0, 3));
    }

    // Strong cards here (makes *3 of them).
    for (int i = 0; i < 2; ++i) {
        // Pass only the effect as the `StatusCard` will use the `duration` from the status effect itself.
        deck->addCard(new StatusCard("Burp", "Poison the opponent for 2 turns.", 2, 0, 0, poison));
        deck->addCard(new StatusCard("Heal", "Heal 2 for 3 turns.", 2, 0, 0, healing));
    }

    // Super rare cards here (makes *1 of them).
    deck->addCard(new AttackCard("Critical Strike", "Deal 7 damage and heal 2 for 3 turns.", 3, 7, 0, healing));

    deck->shuffleDeck();
    return deck;
}
