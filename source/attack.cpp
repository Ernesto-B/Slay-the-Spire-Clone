// attack.cpp
# include <iostream>
using namespace std;
# include <cstring>
# include "attack.h"

Attack::Attack(int dmg, const char* attackName, int type) {
    this->dmg = dmg;
    this->attackName = new char[strlen(attackName) + 1];
    strcpy(this->attackName, attackName);
    this->type = type;
}

Attack::~Attack() {
    delete[] attackName;  // Free the dynamically allocated memory for attackName
}

int Attack::getDmg() {
    return this->dmg;
}

const char* Attack::getAtkName() {
    return this->attackName;
}
