// attack.h
#ifndef ATTACK_H
#define ATTACK_H

#include <iostream>
#include <cstring>

class Attack {
    private:
        int dmg;
        char* attackName;
        int type;

    public:
        Attack(int dmg, const char* attackName, int type);
        ~Attack();
        
        int getDmg();
        const char* getAtkName();
};

#endif
