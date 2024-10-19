// main.cpp
#include "gameFrame.h"
#include "deckFactory.h"

class GameFrame;
class DeckFactory;

int main() {
    // Create a deck using the DeckFactory.
    Deck* playerDeck = DeckFactory::createDefaultDeck();

    // Create a player with the initial deck.
    Player* player = new Player("Hero", 10, 1, 0, 3, playerDeck);

    // Create a GameFrame with the player.
    GameFrame gameFrame(player);

    // Create some enemies.
    Enemy* goblin = new Enemy("Goblin", 5, 1);
    Enemy* orc = new Enemy("Orc", 8, 2);
    Enemy* dragon = new Enemy("Dragon", 20, 5);

    // Add some attacks to the enemies.
    goblin->addAttack(new Attack("Bite", 0, 2));
    orc->addAttack(new Attack("Smash", 0, 4));
    dragon->addAttack(new Attack("Fire Breath", 0, 7));
    dragon->addAttack(new Attack("Claw Swipe", 0, 5));

    // Add enemies to the game.
    gameFrame.addEnemy(goblin);
    gameFrame.addEnemy(orc);
    gameFrame.addEnemy(dragon);

    // Start the game loop.
    while (true) {
        gameFrame.playerTurn();
        gameFrame.enemyTurn();
        gameFrame.checkWinCondition();
    }

    return 0;
}
