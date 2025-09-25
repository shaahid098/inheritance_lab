#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>


class Character {
private:
    std::string name;  //store characters name
    int experiencePoints;  //Used to determine the level
    int hitPoints;  //Shows the characters current health

public:
    //declaring constructor
    Character(std::string name,int startingExperiencePoint,int startingHitPoints);



    //Getters
    std::string getName()const;
    int getLevel() const;   //Getting level from experiencePoints
    int getMaxHitPoints() const; //Getting maximum hit points
    double health() const;

    void gainExperience(int points);  //increasing the XP
    int virtual  attack() ;  //Characters attack method
    void heal(int points);  //Heal HitPoint
    virtual void damage(int points);  //Taking damage
    bool isDead() const; //checking weather the characters is dead or not
};
#endif