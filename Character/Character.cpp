#include "Character.h"
#include <iostream>


//Initialising the constructor
Character::Character(std::string name,int startingExperiencePoints,int startingHitPoints) {
    this->name=name;
    this->experiencePoints=startingExperiencePoints;
    this->hitPoints=startingHitPoints;
};

//Getting the name of the character
std::string Character::getName() const {
    return name;
}

//Getting level from experiencePoints
int Character::getLevel() const {
    return  (experiencePoints/100);
}

//Getting maximum hit points
int Character::getMaxHitPoints() const {
    return getLevel()*150;
}

double Character::health() const {
    if (hitPoints == 0) return 0.0;
    return (static_cast<double>(hitPoints) / getMaxHitPoints()) * 100.0;

}

//increasing the XP
void Character::gainExperience(int points) {
    if (points > 0) {
        experiencePoints += points;
    }
}

//Characters attack method
int Character::attack() {
    return 5*getLevel();
}

//Heal HitPoint
void Character::heal(int points) {
    if (isDead()) {
        std::cout<<"Healing failed:You are Already Dead \n";
        return;
    }

    hitPoints +=points; //increasing hit points
    /**
     *@param making sure that hit points won't exceeds max hit points
     */
    if (hitPoints > getMaxHitPoints()) {
        hitPoints = getMaxHitPoints();
    }
}

//Taking damage
void Character::damage(int points){
    if (points < 0) {
        std::cout << "Failed: Damage cannot be negative \n";
        return;
    }
    std::cout << "Character::damage() - New HP: " << hitPoints << "\n";


    hitPoints -= points;

    // Ensure HP does not drop below zero
    if (hitPoints < 0) {
        hitPoints = 0;
    }
}

//checking weather the characters is dead or not
bool Character::isDead() const {

    return hitPoints <= 0;
}
