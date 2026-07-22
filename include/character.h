#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character {
public:
    std::string name;
    int hp;
    int maxHp;
    int attack;
    int defense;
    int potions;

    Character(std::string name, int hp, int attack, int defense);

    void takeDamage(int amount);
    bool isAlive() const;
    void printStatus() const;
};

#endif
