#ifndef ROGUE_H
#define ROGUE_H

#include "Character.h"

class Rogue : public Character {
private:
    bool hidden;

public:
    Rogue(std::string name, int startingExperiencePoints, int startingHitPoints);
    void hide();
    bool isHidden() const;  // Check if in stealth
    int attack()  override;
    void damage(int points) override;
};

#endif



