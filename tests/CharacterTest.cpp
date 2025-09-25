#include "../Character/Character.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>


class DerivedCharacter: public Character {
public:
    DerivedCharacter(std::string name, int starting_level, int startingHitPoints)
    :Character(name, starting_level, startingHitPoints) {}
};

TEST_CASE("Should be able to create a DerivedCharacter") {
    DerivedCharacter arthur = DerivedCharacter("Sir Arthur", 1, 100);
}

TEST_CASE("Should be able to get DerivedCharacter's name") {
    DerivedCharacter elara =  DerivedCharacter("Lady Elara", 4, 550);
    std::string name = elara.getName();
    REQUIRE_THAT("Lady Elara", Catch::Matchers::Equals(name));
}

TEST_CASE("Should be able to get the level") {
    DerivedCharacter *cedric = new DerivedCharacter("Sir Cedric", 358, 277);
    int level = cedric->getLevel();
    REQUIRE(3 == level);
}

TEST_CASE("Should be able to get the Max hit points") {
    DerivedCharacter gwendolyn = DerivedCharacter("Lady Gwendolyn", 267, 200);
    int max = gwendolyn.getMaxHitPoints();
    CHECK(300 == max);

    DerivedCharacter arthur = DerivedCharacter("Sir Arthur", 123, 100);
    max = arthur.getMaxHitPoints();
    CHECK(150 == max);
}

TEST_CASE("Should be able to get health as a percentage") {
    DerivedCharacter gwendolyn = DerivedCharacter("Lady Gwendolyn", 245, 200);
    double health = gwendolyn.health();
    CHECK_THAT(health, Catch::Matchers::WithinAbs(66, 1));

    DerivedCharacter arthur = DerivedCharacter("Sir Arthur", 178, 32);
    health = arthur.health();
    CHECK_THAT(health, Catch::Matchers::WithinAbs(21, 1));
}

TEST_CASE("Gaining Experience should cause the DerivedCharacter to level up") {
    DerivedCharacter gwendolyn = DerivedCharacter("Lady Gwendolyn", 278, 200);
    gwendolyn.gainExperience(120);
    int level = gwendolyn.getLevel();
    CHECK(3 == level);

    DerivedCharacter arthur = DerivedCharacter("Sir Arthur", 143, 32);
    arthur.gainExperience(20);
    arthur.gainExperience(89);
    level = arthur.getLevel();
    CHECK(2 == level);
}

TEST_CASE("Attack should return 5 times the DerivedCharacter's level") {
    DerivedCharacter *cedric = new DerivedCharacter("Sir Cedric", 700, 277);
    int damage = cedric->attack();
    CHECK(35 == damage);

    DerivedCharacter elara =  DerivedCharacter("Lady Elara", 400, 550);
    damage = elara.attack();
    CHECK(20 == damage);
}

TEST_CASE("Should be able to heal a DerivedCharacter") {
    DerivedCharacter gwendolyn = DerivedCharacter("Lady Gwendolyn", 200, 200);
    gwendolyn.heal(100);
    double health = gwendolyn.health();
    CHECK_THAT(health, Catch::Matchers::WithinAbs(100, 1));

    DerivedCharacter arthur = DerivedCharacter("Sir Arthur", 100, 32);
    arthur.heal(45);
    health = arthur.health();
    CHECK_THAT(health, Catch::Matchers::WithinAbs(51, 1));
}

TEST_CASE("Should take damage when damaged") {
    DerivedCharacter gwendolyn = DerivedCharacter("Lady Gwendolyn", 200, 200);
    gwendolyn.damage(99);
    double health = gwendolyn.health();
    CHECK_THAT(health, Catch::Matchers::WithinAbs(34, 1));

    DerivedCharacter arthur = DerivedCharacter("Sir Arthur", 100, 32);
    arthur.damage(13);
    health = arthur.health();
    CHECK_THAT(health, Catch::Matchers::WithinAbs(13, 1));
}

TEST_CASE("Should not be able to heal a  DerivedCharacter more than 100%") {
    DerivedCharacter gwendolyn = DerivedCharacter("Lady Gwendolyn", 200, 200);
    gwendolyn.heal(1000);
    double health = gwendolyn.health();
    CHECK_THAT(health, Catch::Matchers::WithinAbs(100, 1));
}

TEST_CASE("Dead DerivedCharacters should return 0% health") {
    DerivedCharacter arthur = DerivedCharacter("Sir Arthur", 100, 32);
    arthur.damage(45);
    int health = arthur.health();
    CHECK_THAT(health, Catch::Matchers::WithinAbs(0, 1));
}

TEST_CASE("Should not be able to heal a  DerivedCharacter that is dead") {
    DerivedCharacter gwendolyn = DerivedCharacter("Lady Gwendolyn", 200, 200);
    gwendolyn.damage(1000);
    gwendolyn.heal(100);
    double health = gwendolyn.health();
    CHECK_THAT(health, Catch::Matchers::WithinAbs(0, 1));
}


TEST_CASE("Should be dead when health is 0") {
    DerivedCharacter *cedric = new DerivedCharacter("Sir Cedric", 700, 277);
    cedric->damage(300);
    bool isDead = cedric->isDead();
    CHECK(isDead);

    DerivedCharacter elara =  DerivedCharacter("Lady Elara", 400, 550);
    elara.damage(500);
    elara.damage(350);
    isDead = elara.isDead();
    CHECK(isDead);
}

TEST_CASE("DerivedCharacters can not return from the dead") {
    DerivedCharacter *cedric = new DerivedCharacter("Sir Cedric", 700, 277);
    cedric->damage(300);
    cedric->heal(20);
    bool isDead = cedric->isDead();
    CHECK(isDead);


    DerivedCharacter elara =  DerivedCharacter("Lady Elara", 400, 550);
    elara.damage(500);
    elara.damage(350);
    elara.heal(1000000);
    isDead = elara.isDead();
    CHECK(isDead);
}

