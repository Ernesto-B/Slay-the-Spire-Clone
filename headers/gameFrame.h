// gameFrame.h
#ifndef GAMEFRAME_H
#define GAMEFRAME_H
#include <limits>   // for input validation with std::cin
#include "player.h"
#include "enemy.h"

class GameFrame {
    private:
        Player* player;
        vector<Enemy*> enemies;
        int turnNumber;

    public:
        GameFrame(Player* player);
        ~GameFrame();

        void addEnemy(Enemy* enemy);
        void playerTurn();
        void enemyTurn();
        void checkWinCondition();
        void endGame();

        void displayHand(const Player* player) const;
        void displayEnemies(const vector<Enemy*>& enemies) const;
        std::string promptCardSelection() const;
        int promptTargetSelection(const vector<Enemy*>& enemies) const;
        void printMessage(const string& message) const;
};

#endif