#include "Monster.h"

Monster::Monster(std::string name, int startingExperiencePoints, int startingHitPoints, int experiencePointsValue)
    : Character(name, startingExperiencePoints, startingHitPoints), experiencePointsValue(experiencePointsValue) {}

int Monster::getExperienceReward() const {
    return experiencePointsValue;
}

int Monster::attack() {
    return 5 * getLevel();
}
