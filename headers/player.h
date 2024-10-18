// player.h
#ifndef PLAYER_H
#define PLAYER_H
#include "mon.h"
#include "card.h"
#include <vector>
using namespace std;


class Player : public Mon {
    private:
        int energy;
        vector<Card*> hand;
        vector<Card*> deck;
        vector<Card*> discardPile;

    public:
        Player(const char* name, int level = 1, int type = 0, int energy = 3);
        ~Player();

        void endTurn();
        void drawCard();
        void useCard(Card* card, Mon* target);

        int getEnergy() const;
        void setEnergy();
        void gainEnergy();
        void loseEnergy();
};

#endif