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
        Card(const char* name, const char* desc, int cost, int dmg, int block);
        Card(const Card& other);    // Copy constructor
        Card& operator=(const Card& other);    // Assginment constructor
        ~Card();
        
        int getCost() const;
        int getDmg() const;
        int getBlock() const;
        void printCardInfo() const;
};

#endif
