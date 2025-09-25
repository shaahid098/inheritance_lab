#ifndef WIZARD_H
#define WIZARD_H
#include "Character.h"

//uses mana for fireball attacks
class Wizard:public Character {
private:
    int mana ; //store mana points

public:
    Wizard(std::string name, int startingManaPoints, int startingExperiencePoints, int startingHitPoints);

    void addMana(int points); //adding mana points
    int attack() override; //inherits from attack method
    void damage(int points) override; //inherits from damage method






};


#endif //WIZARD_H
