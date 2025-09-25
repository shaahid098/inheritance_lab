#include "../Character/Monster.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
TEST_CASE("Should be able to create a Monster") {
Monster arthur = Monster("Sir Arthur", 100, 100, 388);
}
TEST_CASE("Should be able to get Monster's name") {
Monster elara = Monster("Lady Elara", 400, 550, 388);
std::string name = elara.getName();
REQUIRE_THAT("Lady Elara", Catch::Matchers::Equals(name));
}
TEST_CASE("Should be able to get the level") {
Monster *cedric = new Monster("Sir Cedric", 300, 277, 388);
int level = cedric->getLevel();
REQUIRE(3 == level);
}
TEST_CASE("Should be able to get the Max hit points") {
Monster gwendolyn = Monster("Lady Gwendolyn", 200, 200, 388);
int max = gwendolyn.getMaxHitPoints();
CHECK(300 == max);
Monster arthur = Monster("Sir Arthur", 100, 100, 388);
max = arthur.getMaxHitPoints();
CHECK(150 == max);
}
TEST_CASE("Should be able to get health as a percentage") {
Monster gwendolyn = Monster("Lady Gwendolyn", 200, 200, 388);
double health = gwendolyn.health();
CHECK_THAT(health, Catch::Matchers::WithinAbs(66, 1));
Monster arthur = Monster("Sir Arthur", 100, 32, 388);
health = arthur.health();
CHECK_THAT(health, Catch::Matchers::WithinAbs(21, 1));
}
TEST_CASE("Gaining Experience should cause the Monster to level up") {
Monster gwendolyn = Monster("Lady Gwendolyn", 200, 200, 388);
gwendolyn.gainExperience(120);
int level = gwendolyn.getLevel();
CHECK(3 == level);
Monster arthur = Monster("Sir Arthur", 100, 32, 388);
arthur.gainExperience(20);
arthur.gainExperience(89);
level = arthur.getLevel();
CHECK(2 == level);
}
TEST_CASE("Attack should return 5 times the Monster's level") {
Monster *cedric = new Monster("Sir Cedric", 756, 277, 388);
int damage = cedric->attack();
CHECK(35 == damage);
Monster elara = Monster("Lady Elara", 490, 550, 388);
damage = elara.attack();
CHECK(20 == damage);
}
TEST_CASE("Should be able to heal a Monster") {
Monster gwendolyn = Monster("Lady Gwendolyn", 200, 200, 388);
gwendolyn.heal(100);
double health = gwendolyn.health();
CHECK_THAT(health, Catch::Matchers::WithinAbs(100, 1));
Monster arthur = Monster("Sir Arthur", 112, 32, 388);
arthur.heal(45);
health = arthur.health();
CHECK_THAT(health, Catch::Matchers::WithinAbs(51, 1));
}
TEST_CASE("Should take damage when damaged") {
Monster gwendolyn = Monster("Lady Gwendolyn", 207, 200, 388);
gwendolyn.damage(99);
double health = gwendolyn.health();
CHECK_THAT(health, Catch::Matchers::WithinAbs(34, 1));
Monster arthur = Monster("Sir Arthur", 187, 32, 388);
arthur.damage(13);
health = arthur.health();
CHECK_THAT(health, Catch::Matchers::WithinAbs(13, 1));
}
TEST_CASE("Should not be able to heal a Monster more than 100%") {
Monster gwendolyn = Monster("Lady Gwendolyn", 296, 200, 388);
gwendolyn.heal(1000);
double health = gwendolyn.health();
CHECK_THAT(health, Catch::Matchers::WithinAbs(100, 1));
}
TEST_CASE("Dead Monsters should return 0% health") {
Monster arthur = Monster("Sir Arthur", 186, 32, 388);
arthur.damage(45);
int health = arthur.health();
CHECK_THAT(health, Catch::Matchers::WithinAbs(0, 1));
}
TEST_CASE("Should not be able to heal a Monster that is dead") {
Monster gwendolyn = Monster("Lady Gwendolyn", 297, 200, 388);
gwendolyn.damage(1000);
gwendolyn.heal(100);
double health = gwendolyn.health();
CHECK_THAT(health, Catch::Matchers::WithinAbs(0, 1));
}
TEST_CASE("Should be dead when health is 0") {
Monster *cedric = new Monster("Sir Cedric", 785, 277, 388);
cedric->damage(300);
bool isDead = cedric->isDead();
CHECK(isDead);
Monster elara = Monster("Lady Elara", 445, 550, 388);
elara.damage(500);
elara.damage(350);
isDead = elara.isDead();
CHECK(isDead);
}
TEST_CASE("Monsters can not return from the dead") {
Monster *cedric = new Monster("Sir Cedric", 786, 277, 388);
cedric->damage(300);
cedric->heal(20);
bool isDead = cedric->isDead();
CHECK(isDead);
Monster elara = Monster("Lady Elara", 456, 550, 388);
elara.damage(500);
elara.damage(350);
elara.heal(1000000);
isDead = elara.isDead();
CHECK(isDead);
}
TEST_CASE("Monsters should return a Experience points value") {
    Monster *cedric = new Monster("Sir Cedric", 767, 277, 388);
    REQUIRE(cedric->getExperienceReward() == 388);
}