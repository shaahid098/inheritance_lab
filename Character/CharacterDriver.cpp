#include <iostream>
#include "Knight.h"
#include "Wizard.h"
#include "Rogue.h"
#include "Monster.h"

int main() {
    std::cout << "=== Character Demo ===\n\n";

    // Create characters
    Knight arthur("Sir Arthur", 200, 150);
    Wizard merlin("Merlin", 100, 250, 100);
    Rogue shadow("Shadow", 120, 120);
    Monster orc("Orc", 50, 100, 80);

    std::cout << "Knight " << arthur.getName() << " attacks for " << arthur.attack() << " damage.\n";
    std::cout << "Wizard " << merlin.getName() << " attacks for " << merlin.attack() << " damage.\n";
    std::cout << "Rogue " << shadow.getName() << " attacks for " << shadow.attack() << " damage.\n";
    std::cout << "Monster " << orc.getName() << " attacks for " << orc.attack() << " damage.\n\n";

    // Rogue hides
    shadow.hide();
    std::cout << "Rogue " << shadow.getName() << " hides...\n";
    std::cout << "Rogue hidden attack: " << shadow.attack() << "\n";
    std::cout << "Rogue normal attack: " << shadow.attack() << "\n\n";

    // Knight hits the monster
    int damage = arthur.attack();
    std::cout << "Knight hits monster for " << damage << "!\n";
    orc.damage(damage);
    std::cout << "Monster health after hit: " << orc.health() << "%\n\n";

    // Monster attacks wizard
    damage = orc.attack();
    std::cout << "Monster hits wizard for " << damage << "!\n";
    merlin.damage(damage);
    std::cout << "Wizard health after hit: " << merlin.health() << "%\n\n";

    // Wizard uses all mana
    std::cout << "Wizard casting spells:\n";
    for (int i = 0; i < 5; ++i) {
        int attackValue = merlin.attack();
        std::cout << " - Attack value: " << attackValue << " (mana used)\n";
    }

    std::cout << "\nWizard health before healing: " << merlin.health() << "%\n";
    merlin.heal(30);
    std::cout << "Wizard health after healing: " << merlin.health() << "%\n\n";

    // Monster is defeated
    if (orc.isDead()) {
        int xp = orc.getExperienceReward();
        std::cout << "Monster defeated! XP reward: " << xp << "\n";
        arthur.gainExperience(xp);
        std::cout << "Knight new level: " << arthur.getLevel() << "\n";
    } else {
        std::cout << "Monster is still alive.\n";
    }

    return 0;
}