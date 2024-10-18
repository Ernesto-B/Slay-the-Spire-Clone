// mon.h
#ifndef MON_H
#define MON_H

#include <iostream>
#include <cstring>
#include "attack.h"

class Mon {
    private:
        char* name;
        int health;
        int currentHealth;
        int level;  // influences health
        int type;   // type weakness or resistance?
        Attack* attack1;    // Not sure if used for enemy class
        Attack* attack2;    // Not sure if used for enemy class

        // Status effects
        int poison;
        int weaken;
        int strength;
        int block;

    public:
        Mon(const char* name, int baseHealth, int level, int type = 0);
        ~Mon();
        
        Mon(const Mon& other);  // copy constructor
        Mon& operator=(const Mon& other);   // assignment constructor

        char* getName() const;
        int getHealth() const;
        int getCurrentHealth() const;
        void printInfo() const;
        void printAttacks() const;

        void applyPoison(int amount);
        void applyWeaken(int amount);
        void applyStrength(int amount);
        void addBlock(int amount);
        void takeDmg(int amount);
};

#endif
