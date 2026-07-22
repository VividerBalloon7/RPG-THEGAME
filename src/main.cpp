
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "character.h"
#include "monster.h"

void drinkPotion(Character& hero) {
    if (hero.potions <= 0) {
        std::cout << hero.name << " is out of potions!\n";
        return;
    }

    hero.hp += 10;

    // Prevent HP from exceeding maximum.
    if (hero.hp > hero.maxHp) {
        hero.hp = hero.maxHp;
    }

    hero.potions--;

    std::cout << "\n"
              << hero.name
              << " drinks a potion! Health increased by 10!\n";
}

int main() {
    srand(time(0));

    std::cout << "=== Welcome to DUNGEON DEBUGGER ===\n";
    std::cout << "Enter your hero's name: ";

    std::string heroName;
    std::getline(std::cin, heroName);

    Character hero(heroName, 30, 7, 2);
    int wins = 0;

    // Three battles.
    for (int i = 0; i < 3; i++) {
        Character monster = makeRandomMonster();

        std::cout << "\n--- Battle " << (i + 1)
                  << ": a wild " << monster.name
                  << " appears! ---\n";

        // Battle continues only while BOTH are alive.
        while (hero.isAlive() && monster.isAlive()) {
            std::cout << "\n";
            hero.printStatus();
            monster.printStatus();

            std::cout << "Choose an action: (1) Attack  (2) Potion: ";

            int choice;
            std::cin >> choice;

            if (choice == 1) {
                int dmg = hero.attack + rand() % 3;
                monster.takeDamage(dmg);
                std::cout << hero.name << " hits the "
                          << monster.name << "!\n";
            }
            else if (choice == 2) {
                drinkPotion(hero);
            }
            else {
                std::cout << "Invalid choice!\n";
                continue;
            }

            if (monster.isAlive()) {
                int dmg = monster.attack + rand() % 3;
                hero.takeDamage(dmg);
                std::cout << "The " << monster.name
                          << " strikes back!\n";
            }
        }

        if (hero.isAlive()) {
            std::cout << ">>> You defeated the "
                      << monster.name << "! <<<\n";
            wins++;
        }
        else {
            std::cout << ">>> " << hero.name
                      << " has fallen... <<<\n";
            break;
        }
    }

    std::cout << "\n=== GAME OVER — monsters defeated: "
              << wins << " ===\n";

    return 0;
}
