#include "character.h"
#include <iostream>

Character::Character(std::string name, int hp, int attack, int defense) {
    this->name = name;
    this->hp = hp;
    this->maxHp = hp;
    this->attack = attack;
    this->defense = defense;
    this->potions = 3;
}

void Character::takeDamage(int amount) {
    int reduced = amount - defense;
    if (reduced < 1) {
        reduced = 1;
    }
    hp -= reduced;
}

bool Character::isAlive() const {
    return hp > 0;
}

void Character::printStatus() const {
    std::cout << "  [" << name << "]  HP: " << hp << "/" << maxHp
              << "  ATK: " << attack
              << "  DEF: " << defense
              << "  Potions: " << potions << "\n";
}
