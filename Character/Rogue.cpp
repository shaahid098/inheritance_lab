#include "Rogue.h"


//Stealth damage and defence
Rogue::Rogue(std::string name, int startingExperiencePoints, int startingHitPoints)
    : Character(name, startingExperiencePoints, startingHitPoints), hidden(false) {}

void Rogue::hide() {
    hidden = true;
}

bool Rogue::isHidden() const {
    return hidden;
}

int Rogue::attack() {
    if (hidden) {
        hidden = false; // if not hidden
        return 15 * getLevel();
    }
    return 5 * getLevel();
}

void Rogue::damage(int points) {
    if (hidden) {
        Character::damage(points / 2);
    } else {
        Character::damage(points);
    }
}
