#ifndef MONSTER_H
#define MONSTER_H

#include "Character.h"

// basic enemy with XP reward
class Monster : public Character {
private:
    int experiencePointsValue;

public:
    Monster(std::string name, int startingExperiencePoints, int startingHitPoints, int experiencePointsValue);
    int getExperienceReward() const; //// reward given when defeated
    int attack() override;
};

#endif
