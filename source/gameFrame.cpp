// gameFrame.cpp
#include "gameFrame.h"

GameFrame::GameFrame(Player* player) : player(player), turnNumber(1) {}

GameFrame::~GameFrame() {
    for (Enemy* enemy : enemies) {
        delete enemy;
    }
    enemies.clear();
}

void GameFrame::addEnemy(Enemy* enemy) {
    enemies.push_back(enemy);
}

void GameFrame::playerTurn() {
    printf("\n--- Player's Turn ---\n");
    while (true) {
        // Display the player's hand and enemies.
        displayHand(player);
        displayEnemies(enemies);

        // Prompt for card selection.
        std::string cardInput = promptCardSelection();
        if (cardInput == "q") {
            printMessage("Ending your turn.");
            break;
        }

        // Convert cardInput to an index.
        int cardIndex;
        try {
            cardIndex = std::stoi(cardInput);
        } catch (std::exception& e) {
            printMessage("Invalid input. Please enter a number or 'q'.");
            continue;
        }

        if (cardIndex < 0 || static_cast<size_t>(cardIndex) >= player->getHand().size()) {
            printMessage("Invalid card selection. Try again.");
            continue;
        }

        // Get the selected card.
        Card* chosenCard = player->getHand()[cardIndex];

        // Prompt for target selection.
        int targetIndex = promptTargetSelection(enemies);
        if (targetIndex < 0 || static_cast<size_t>(targetIndex) >= enemies.size()) {
            printMessage("Invalid target selection. Try again.");
            continue;
        }

        // Get the selected target.
        Mon* target = enemies[targetIndex];

        // Use the selected card on the target.
        player->useCard(chosenCard, target);

        // Remove the used card from the player's hand.
        player->removeCardFromHand(cardIndex);
    }
    turnNumber++;
}

void GameFrame::enemyTurn() {
    printf("\n--- Enemies' Turn ---\n");
    for (Enemy* enemy : enemies) {
        if (enemy->getCurrentHealth() > 0) {
            enemy->takeTurn(player);
        }
    }
    printf("\n");
}

void GameFrame::checkWinCondition() {
    bool allEnemiesDefeated = true;
    for (Enemy* enemy : enemies) {
        if (enemy->getCurrentHealth() > 0) {
            allEnemiesDefeated = false;
            break;
        }
    }

    if (allEnemiesDefeated) {
        printMessage("All enemies have been defeated! You win!");
        endGame();
        return;
    }

    if (player->getCurrentHealth() <= 0) {
        printMessage("You have been defeated! Game Over!");
        endGame();
    }
}

void GameFrame::endGame() {
    printMessage("Game has ended. Thank you for playing!");
    exit(0);  // Terminate. Maybe set a flag to exit the game loop
}


void GameFrame::displayHand(const Player* player) const {
    const vector<Card*>& hand = player->getHand();
    printf("\n---- Your Hand ----\n");
    for (size_t i = 0; i < hand.size(); ++i) {
        printf("[%lu] %s (Cost: %d)\t", static_cast<unsigned long>(i), hand[i]->getName(), hand[i]->getCost());
    }
    printf("\n");
    for (size_t i = 0; i < hand.size(); ++i) {
        printf("    %s\n", hand[i]->getDescription());
    }
    printf("\n-------------------\n");
}

void GameFrame::displayEnemies(const vector<Enemy*>& enemies) const {
    printf("\n---- Enemies ----\n");
    for (size_t i = 0; i < enemies.size(); ++i) {
        printf("[%lu] %s (HP: %d/%d)\n", static_cast<unsigned long>(i), enemies[i]->getName(), enemies[i]->getCurrentHealth(), enemies[i]->getHealth());
    }
    printf("-----------------\n");
}



std::string GameFrame::promptCardSelection() const {
    char input[10];
    printf("\nEnter the number of the card you want to use (or 'q' to end turn): ");
    scanf("%9s", input);  // Read input into the buffer, limit to 9 characters
    return std::string(input);
}

int GameFrame::promptTargetSelection(const vector<Enemy*>& enemies) const {
    int index;
    printf("\nSelect an enemy to target (0 - %d): ", enemies.size() - 1);
    if (scanf("%d", &index) == 1) {
        return index;
    } else {
        return -1;  // -1 if input is invalid.
    }
}

void GameFrame::printMessage(const std::string& message) const {
    printf("%s\n", message.c_str());
}