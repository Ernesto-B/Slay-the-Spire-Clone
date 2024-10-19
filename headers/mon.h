// mon.h
#ifndef MON_H
#define MON_H

#include <iostream>
#include <algorithm>  // for std::remove_if
#include <cstring>
#include <vector>
using namespace std;
#include "statusEffect.h"

class StatusEffect;

class Mon {
    private:
        char* name;
        int health;
        int currentHealth;
        int level;  // influences health
        int type;   // type weakness or resistance?
        int block;
        vector<StatusEffect*> activeEffects;    // Maybe limit the size of this?

    public:
        Mon(const char* name, int baseHealth = 0, int level = 1, int type = 0);
        ~Mon();
        
        Mon(const Mon& other);  // copy constructor
        Mon& operator=(const Mon& other);   // assignment constructor

        char* getName() const;
        int getHealth() const;
        int getCurrentHealth() const;
        void printInfo() const;

        void changeBlock(int amount);

        void addStatusEffect(StatusEffect* effect);
        void processEndTurnEffects();
        void cleanupExpiredEffects();

        void takeDmg(int amount);
        void heal(int amount);
};

#endif
