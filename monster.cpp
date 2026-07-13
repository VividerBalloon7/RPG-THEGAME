#include "monster.h"
#include <cstdlib>

Character makeRandomMonster() {
    std::string names[3] = {"Goblin", "Skeleton", "Orc"};
    int hps[3]  = {15, 18, 22};
    int atks[3] = {5, 6, 7};
    int defs[3] = {1, 2, 3};

    int pick = rand() % 3;

    return Character(names[pick], atks[pick], hps[pick], defs[pick]);
}
