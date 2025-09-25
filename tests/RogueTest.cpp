#include "../Character/Rogue.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
TEST_CASE("Should be able to create a Rogue") {
Rogue arthur = Rogue("Sir Arthur", 100, 100);
}
TEST_CASE("Should be able to get Rogue's name") {
Rogue elara = Rogue("Lady Elara", 400, 550);
std::string name = elara.getName();
REQUIRE_THAT("Lady Elara", Catch::Matchers::Equals(name));
}
TEST_CASE("Should be able to get the level") {
Rogue *cedric = new Rogue("Sir Cedric", 300, 277);
int level = cedric->getLevel();
REQUIRE(3 == level);
}
TEST_CASE("Should be able to get the Max hit points") {
Rogue gwendolyn = Rogue("Lady Gwendolyn", 200, 200);
int max = gwendolyn.getMaxHitPoints();
CHECK(300 == max);
Rogue arthur = Rogue("Sir Arthur", 100, 100);
max = arthur.getMaxHitPoints();
CHECK(150 == max);
}
TEST_CASE("Should be able to get health as a percentage") {
Rogue gwendolyn = Rogue("Lady Gwendolyn", 200, 200);
double health = gwendolyn.health();
CHECK_THAT(health, Catch::Matchers::WithinAbs(66, 1));
Rogue arthur = Rogue("Sir Arthur", 100, 32);
health = arthur.health();
CHECK_THAT(health, Catch::Matchers::WithinAbs(21, 1));
}
TEST_CASE("Gaining Experience should cause the Rogue to level up") {
Rogue gwendolyn = Rogue("Lady Gwendolyn", 200, 200);
gwendolyn.gainExperience(120);
int level = gwendolyn.getLevel();
CHECK(3 == level);
Rogue arthur = Rogue("Sir Arthur", 100, 32);
arthur.gainExperience(20);
arthur.gainExperience(89);
level = arthur.getLevel();
CHECK(2 == level);
}
TEST_CASE("Attack should return 5 times the Rogue's level") {
Rogue *cedric = new Rogue("Sir Cedric", 700, 277);
int damage = cedric->attack();
CHECK(35 == damage);
Rogue elara = Rogue("Lady Elara", 400, 550);
damage = elara.attack();
CHECK(20 == damage);
}
TEST_CASE("Rogue should be able to hide") {
Rogue *slick = new Rogue("Slick", 500, 200);
slick->hide();
CHECK(slick->isHidden());
}
TEST_CASE("Rogues should not be hidden by default") {
Rogue *slick = new Rogue("Slick", 500, 200);
REQUIRE_FALSE(slick->isHidden());
}
TEST_CASE("Attack should return 15 times the Rogue's level if they are hidden") {
Rogue *cedric = new Rogue("Sir Cedric", 700, 277);
cedric->hide();
int damage = cedric->attack();
CHECK(105 == damage);
Rogue elara = Rogue("Lady Elara", 400, 550);
elara.hide();
damage = elara.attack();
CHECK(60 == damage);
}
TEST_CASE("Attacking should expose the Rogue") {
Rogue *slick = new Rogue("Slick", 500, 200);
slick->hide();
slick->attack();
REQUIRE_FALSE(slick->isHidden());
}
TEST_CASE("Should be able to heal a Rogue") {
Rogue gwendolyn = Rogue("Lady Gwendolyn", 200, 200);
gwendolyn.heal(100);
double health = gwendolyn.health();
CHECK_THAT(health, Catch::Matchers::WithinAbs(100, 1));
Rogue arthur = Rogue("Sir Arthur", 100, 32);
arthur.heal(45);
health = arthur.health();
CHECK_THAT(health, Catch::Matchers::WithinAbs(51, 1));
}
TEST_CASE("Should take damage when damaged") {
Rogue gwendolyn = Rogue("Lady Gwendolyn", 200, 200);
gwendolyn.damage(99);
double health = gwendolyn.health();
CHECK_THAT(health, Catch::Matchers::WithinAbs(34, 1));
Rogue arthur = Rogue("Sir Arthur", 100, 32);
arthur.damage(13);
health = arthur.health();
CHECK_THAT(health, Catch::Matchers::WithinAbs(13, 1));
}
TEST_CASE("Should take %50 damage when hidden") {
Rogue gwendolyn = Rogue("Lady Gwendolyn", 200, 200);
gwendolyn.hide();
gwendolyn.damage(99);
double health = gwendolyn.health();
CHECK_THAT(health, Catch::Matchers::WithinAbs(50, 1));
Rogue arthur = Rogue("Sir Arthur", 100, 32);
arthur.hide();
arthur.damage(13);
health = arthur.health();
CHECK_THAT(health, Catch::Matchers::WithinAbs(17, 1));
}
TEST_CASE("Should not be able to heal a Rogue more than 100%") {
Rogue gwendolyn = Rogue("Lady Gwendolyn", 200, 200);
gwendolyn.heal(1000);
double health = gwendolyn.health();
CHECK_THAT(health, Catch::Matchers::WithinAbs(100, 1));
}
TEST_CASE("Dead Rogues should return 0% health") {
Rogue arthur = Rogue("Sir Arthur", 100, 32);
arthur.damage(45);
int health = arthur.health();
CHECK_THAT(health, Catch::Matchers::WithinAbs(0, 1));
}
TEST_CASE("Should not be able to heal a Rogue that is dead") {
Rogue gwendolyn = Rogue("Lady Gwendolyn", 200, 200);
gwendolyn.damage(1000);
gwendolyn.heal(100);
double health = gwendolyn.health();
CHECK_THAT(health, Catch::Matchers::WithinAbs(0, 1));
}
TEST_CASE("Should be dead when health is 0") {
Rogue *cedric = new Rogue("Sir Cedric", 700, 277);
cedric->damage(300);
bool isDead = cedric->isDead();
CHECK(isDead);
Rogue elara = Rogue("Lady Elara", 400, 550);
elara.damage(500);
elara.damage(350);
isDead = elara.isDead();
CHECK(isDead);
}
TEST_CASE("Rogues can not return from the dead") {
Rogue *cedric = new Rogue("Sir Cedric", 700, 277);
cedric->damage(300);
cedric->heal(20);
bool isDead = cedric->isDead();
CHECK(isDead);
Rogue elara = Rogue("Lady Elara", 400, 550);
elara.damage(500);
elara.damage(350);
elara.heal(1000000);
isDead = elara.isDead();
CHECK(isDead);
}