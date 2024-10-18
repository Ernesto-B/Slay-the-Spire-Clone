// card.h
#ifndef CARD_H
#define CARD_H

#include <iostream>
using namespace std;
#include <cstring>

class Card {
    private:
        char* name;
        char* desc;
        int cost;
        int dmg;
        int block;
    public:
        Card(char* name, char* desc, int cost, int dmg, int block);
        ~Card();
        
        int getCost() const;
        int getDmg() const;
        int getBlock() const;
        void printCardInfo() const;
};

#endif
