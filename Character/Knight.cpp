#include "Knight.h"
//takes half damage and has strong attack
Knight:: Knight(std::string name,int startingExperiencePoint,int startingHitPoints)
    :Character(name,startingExperiencePoint,startingHitPoints){}

//Knight attach level*5

int Knight::attack() {
    return 5 * getLevel(); //adding the stronger attack

}

//takes only 50% of damage
void Knight::damage(int points) {
    Character::damage(points/2);
}
