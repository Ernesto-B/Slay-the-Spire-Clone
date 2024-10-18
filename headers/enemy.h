// enemy.h
#ifndef ENEMY_H
#define ENEMY_H
#include "mon.h"
#include "player.h"

class Enemy: public Mon {
    private:
    public:
        Enemy(const char* name, int level = 1, int type = 0);
        void attack(Player* player);
        void takeTurn();    // algo for decision making or something
};

#endif