#ifndef KNIGHT_H
#define KNIGHT_H
#include "Character.h"

class Knight: public Character {
    private:
    std::string name;
    int hitPoints;
    int experiencePoint;


    public:
    Knight(std::string name,int startingExperiencePoint,int startingHitPoints);
    int attack() override; //Inherits the attack method
    void damage(int points) override; //Inherits the damage method


};


#endif //KNIGHT_H
