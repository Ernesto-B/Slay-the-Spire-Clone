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
    printf("\n--- PLAYER'S TURN ---\n");

    if (turnNumber == 1) {
        player->drawCard();
        player->drawCard();
        player->drawCard();
        player->drawCard();
    }

    player->drawCard();

    while (true) {
        // Display the player's hand and enemies.
        displayPlayer(player);
        displayHand(player);
        displayEnemies(enemies);

        // Prompt for card selection.
        std::string cardInput = promptCardSelection();
        if (cardInput == "q") {
            printMessage("Ending your turn.");
            break;
        }

        if (cardInput == "end") {
            printMessage("Ending game.");
            exit(0);
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
        if (chosenCard->getCost() > player->getCurrentEnergy()) {
            printf("Not enough energy to use this card.\n");
            continue;
        }

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
    player->endTurn();
}

void GameFrame::enemyTurn() {
    printf("\n--- ENEMIES' TURN ---\n");
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

void GameFrame::displayPlayer(const Player* player) const {
    printf("\n---- Player Status ----\n");
    printf("%s (HP: %d+%d/%d)\tLv: %d\tEnergy: %d/%d\t", player->getName(), player->getBlock(), player->getCurrentHealth(), player->getHealth(), player->getLv(), player->getCurrentEnergy(), player->getEnergy());

    // Get the player's active status effects.
    const vector<StatusEffect*>& effects = player->getActiveEffects();
    std::ostringstream effectsStream;
    if (effects.empty()) {
        effectsStream << "None";
    } else {
        for (size_t i = 0; i < effects.size(); ++i) {
            effectsStream << effects[i]->getName();
            if (i < effects.size() - 1) {
                effectsStream << ", ";
            }
        }
    }
    
    // Print all status effects in one line.
    printf("Status Effects: %s\n", effectsStream.str().c_str());
}

void GameFrame::displayHand(const Player* player) const {
    const vector<Card*>& hand = player->getHand();
    printf("\n---- Your Hand ----\n");
    for (size_t i = 0; i < hand.size(); ++i) {
        printf("[%lu] %s (Cost: %d) \t", static_cast<unsigned long>(i), hand[i]->getName(), hand[i]->getCost());
        printf("%s\n", hand[i]->getDescription());
    }
    printf("\n-------------------\n");
}

void GameFrame::displayEnemies(const vector<Enemy*>& enemies) const {
    printf("\n---- Enemies ----\n");
    for (size_t i = 0; i < enemies.size(); ++i) {
        printf("[%lu] %s (HP: %d/%d)\tStatus Effects: ", 
               static_cast<unsigned long>(i), 
               enemies[i]->getName(), 
               enemies[i]->getCurrentHealth(), 
               enemies[i]->getHealth());

        // Get the enemy's active status effects.
        const vector<StatusEffect*>& effects = enemies[i]->getActiveEffects();
        if (effects.empty()) {
            printf("None");
        } else {
            std::ostringstream effectsStream;
            for (size_t j = 0; j < effects.size(); ++j) {
                effectsStream << effects[j]->getName();
                if (j < effects.size() - 1) {
                    effectsStream << ", ";
                }
            }
            printf("%s", effectsStream.str().c_str());
        }
        printf("\n");
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