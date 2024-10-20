// enemy.h
#ifndef ENEMY_H
#define ENEMY_H
#include "mon.h"
#include "attack.h"
#include "player.h"     // To target the player??

class Player;

class Enemy: public Mon {
    private:
        vector<Attack*> attacks;

    public:
        Enemy(const char* name, int baseHealth = 0, int level = 1, int type = 0);
        ~Enemy();

        void attack(Player* player, Attack* chosenAttack);
        void takeTurn(Player* Player);    // algo for decision making or something
        void endTurn();
        void processEndTurnEffects();
        void addAttack(Attack* attack);
};

#endif