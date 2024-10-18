// gameFrame.h
#ifndef GAMEFRAME_H
#define GAMEFRAME_H
#include "player.h"
#include "enemy.h"

class GameFrame {
    private:
        Player* player;
        vector<Enemy*> enemies;
        int roundNumber;
    public:
        GameFrame(Player* player);

        void addEnemy(Enemy* enemy);
        void startBattle();
        void playerTurn();
        void enemyTurn();
        void checkWinCondition();
        void endGame();
};

#endif