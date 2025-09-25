#include "Wizard.h"


Wizard::Wizard(std::string name, int startingManaPoints, int startingExperiencePoints, int startingHitPoints)
        : Character(name, startingExperiencePoints, startingHitPoints), mana(startingManaPoints) {}

void Wizard::addMana(int points) {
        if (points > 0) {
                mana += points;
        }
}

int Wizard::attack() {
        if (mana >= 25) {
                mana -= 25;
                return 20 * getLevel();
        }
        else {
                return 10;
        }
}

void Wizard::damage(int points) {
        Character::damage(points);
}