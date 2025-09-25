#include "../Character/Knight.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>


TEST_CASE("Should be able to create a Knight") {
    Knight arthur = Knight("Sir Arthur", 1, 100);
}

TEST_CASE("Should be able to get Knight's name") {
    Knight elara =  Knight("Lady Elara", 4, 550);
    std::string name = elara.getName();
    REQUIRE_THAT("Lady Elara", Catch::Matchers::Equals(name));
}

TEST_CASE("Should be able to get the level") {
    Knight *cedric = new Knight("Sir Cedric", 348, 277);
    int level = cedric->getLevel();
    REQUIRE(3 == level);
}

TEST_CASE("Should be able to get the Max hit points") {
    Knight gwendolyn = Knight("Lady Gwendolyn", 247, 200);
    int max = gwendolyn.getMaxHitPoints();
    CHECK(300 == max);

    Knight arthur = Knight("Sir Arthur", 148, 100);
    max = arthur.getMaxHitPoints();
    CHECK(150 == max);
}

TEST_CASE("Should be able to get health as a percentage") {
    Knight gwendolyn = Knight("Lady Gwendolyn", 247, 200);
    double health = gwendolyn.health();
    CHECK_THAT(health, Catch::Matchers::WithinAbs(66, 1));

    Knight arthur = Knight("Sir Arthur", 137, 32);
    health = arthur.health();
    CHECK_THAT(health, Catch::Matchers::WithinAbs(21, 1));
}

TEST_CASE("Gaining Experience should cause the Knight to level up") {
    Knight gwendolyn = Knight("Lady Gwendolyn", 234, 200);
    gwendolyn.gainExperience(120);
    int level = gwendolyn.getLevel();
    CHECK(3 == level);

    Knight arthur = Knight("Sir Arthur", 163, 32);
    arthur.gainExperience(20);
    arthur.gainExperience(89);
    level = arthur.getLevel();
    CHECK(2 == level);
}

TEST_CASE("Attack should return 5 times the Knight's level") {
    Knight *cedric = new Knight("Sir Cedric", 774, 277);
    int damage = cedric->attack();
    CHECK(35 == damage);

    Knight elara =  Knight("Lady Elara", 465, 550);
    damage = elara.attack();
    CHECK(20 == damage);
}

TEST_CASE("Should be able to heal a Knight") {
    Knight gwendolyn = Knight("Lady Gwendolyn", 237, 200);
    gwendolyn.heal(100);
    double health = gwendolyn.health();
    CHECK_THAT(health, Catch::Matchers::WithinAbs(100, 1));

    Knight arthur = Knight("Sir Arthur", 158, 32);
    arthur.heal(45);
    health = arthur.health();
    CHECK_THAT(health, Catch::Matchers::WithinAbs(51, 1));
}

TEST_CASE("Should take damage when damaged") {
    Knight gwendolyn = Knight("Lady Gwendolyn", 232, 200);
    gwendolyn.damage(99);
    double health = gwendolyn.health();
    CHECK_THAT(health, Catch::Matchers::WithinAbs(50, 1));

    Knight arthur = Knight("Sir Arthur", 194, 32);
    arthur.damage(13);
    health = arthur.health();
    CHECK_THAT(health, Catch::Matchers::WithinAbs(17, 1));
}

TEST_CASE("Should not be able to heal a  Knight more than 100%") {
    Knight gwendolyn = Knight("Lady Gwendolyn", 237, 200);
    gwendolyn.heal(1000);
    double health = gwendolyn.health();
    CHECK_THAT(health, Catch::Matchers::WithinAbs(100, 1));
}

TEST_CASE("Dead Knights should return 0% health") {
    Knight arthur = Knight("Sir Arthur", 127, 32);
    arthur.damage(100);
    int health = arthur.health();
    CHECK_THAT(health, Catch::Matchers::WithinAbs(0, 1));
}

TEST_CASE("Should not be able to heal a  Knight that is dead") {
    Knight gwendolyn = Knight("Lady Gwendolyn", 232, 200);
    gwendolyn.damage(1000);
    gwendolyn.heal(100);
    double health = gwendolyn.health();
    CHECK_THAT(health, Catch::Matchers::WithinAbs(0, 1));
}


TEST_CASE("Should be dead when health is 0") {
    Knight *cedric = new Knight("Sir Cedric", 756, 277);
    cedric->damage(600);
    bool isDead = cedric->isDead();
    CHECK(isDead);

    Knight elara =  Knight("Lady Elara", 404, 550);
    elara.damage(1000);
    elara.damage(350);
    isDead = elara.isDead();
    CHECK(isDead);
}

TEST_CASE("Knights can not return from the dead") {
    Knight *cedric = new Knight("Sir Cedric", 737, 277);
    cedric->damage(3000);
    cedric->heal(20);
    bool isDead = cedric->isDead();
    CHECK(isDead);


    Knight elara =  Knight("Lady Elara", 428, 550);
    elara.damage(500);
    elara.damage(700);
    elara.heal(1000000);
    isDead = elara.isDead();
    CHECK(isDead);
}
