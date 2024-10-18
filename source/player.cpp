// player.cpp
#include "player.h"

Player::Player(const char* name, int level = 1, int type = 0, int energy = 3) : Mon(name, level, type), energy(energy) {
    
}

Player::~Player() {

}

void Player::endTurn() {

}

void Player::drawCard() {

}

void Player::useCard(Card* card, Mon* target) {

}

int Player::getEnergy() const {

}

void Player::setEnergy() {

}

void Player::gainEnergy() {

}

void Player::loseEnergy() {

}
