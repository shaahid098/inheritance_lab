#include "../Character/Wizard.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

TEST_CASE("Should be able to create a Wizard") {
    Wizard arthur = Wizard("Sir Arthur", 167, 100, 100);
}

TEST_CASE("Should be able to get Wizard's name") {
    Wizard elara =  Wizard("Lady Elara", 436, 550, 100);
    std::string name = elara.getName();
    REQUIRE_THAT("Lady Elara", Catch::Matchers::Equals(name));
}

TEST_CASE("Should be able to get the level") {
    Wizard *cedric = new Wizard("Sir Cedric", 343, 277, 100);
    int level = cedric->getLevel();
    REQUIRE(3 == level);
}

TEST_CASE("Should be able to get the Max hit points") {
    Wizard gwendolyn = Wizard("Lady Gwendolyn", 273, 200, 100);
    int max = gwendolyn.getMaxHitPoints();
    CHECK(300 == max);

    Wizard arthur = Wizard("Sir Arthur", 146, 100, 100);
    max = arthur.getMaxHitPoints();
    CHECK(150 == max);
}

TEST_CASE("Should be able to get health as a percentage") {
    Wizard gwendolyn = Wizard("Lady Gwendolyn", 263, 200, 100);
    double health = gwendolyn.health();
    CHECK_THAT(health, Catch::Matchers::WithinAbs(66, 1));

    Wizard arthur = Wizard("Sir Arthur", 134, 32, 100);
    health = arthur.health();
    CHECK_THAT(health, Catch::Matchers::WithinAbs(21, 1));
}

TEST_CASE("Gaining Experience should cause the Wizard to level up") {
    Wizard gwendolyn = Wizard("Lady Gwendolyn", 262, 200, 100);
    gwendolyn.gainExperience(120);
    int level = gwendolyn.getLevel();
    CHECK(3 == level);

    Wizard arthur = Wizard("Sir Arthur", 159, 32, 100);
    arthur.gainExperience(20);
    arthur.gainExperience(89);
    level = arthur.getLevel();
    CHECK(2 == level);
}

TEST_CASE("Attack should return 20 times the Wizard's level") {
    Wizard *cedric = new Wizard("Sir Cedric", 736, 277, 100);
    int damage = cedric->attack();
    CHECK(140 == damage);

    Wizard elara =  Wizard("Lady Elara", 438, 550, 100);
    damage = elara.attack();
    CHECK(80 == damage);
}


TEST_CASE("Attack should return 10 When the Wizard runs out of mana") {
    Wizard *cedric = new Wizard("Sir Cedric", 763, 277, 30);
    int damage = cedric->attack();
    CHECK(140 == damage);
    damage = cedric->attack();
    CHECK(10 == damage);

    Wizard elara =  Wizard("Lady Elara", 458, 550, 100);
    damage = elara.attack();
    CHECK(80 == damage);
    damage = elara.attack();
    CHECK(80 == damage);
    damage = elara.attack();
    CHECK(80 == damage);
    damage = elara.attack();
    CHECK(80 == damage);
    damage = elara.attack();
    CHECK(10 == damage);
}




TEST_CASE("Should be able to heal a Wizard") {
    Wizard gwendolyn = Wizard("Lady Gwendolyn", 259, 200, 100);
    gwendolyn.heal(100);
    double health = gwendolyn.health();
    CHECK_THAT(health, Catch::Matchers::WithinAbs(100, 1));

    Wizard arthur = Wizard("Sir Arthur", 137, 32, 100);
    arthur.heal(45);
    health = arthur.health();
    CHECK_THAT(health, Catch::Matchers::WithinAbs(51, 1));
}

TEST_CASE("Should take damage when damaged") {
    Wizard gwendolyn = Wizard("Lady Gwendolyn", 246, 200, 100);
    gwendolyn.damage(99);
    double health = gwendolyn.health();
    CHECK_THAT(health, Catch::Matchers::WithinAbs(34, 1));

    Wizard arthur = Wizard("Sir Arthur", 139, 32, 100);
    arthur.damage(13);
    health = arthur.health();
    CHECK_THAT(health, Catch::Matchers::WithinAbs(13, 1));
}

TEST_CASE("Should not be able to heal a  Wizard more than 100%") {
    Wizard gwendolyn = Wizard("Lady Gwendolyn", 245, 200, 100);
    gwendolyn.heal(1000);
    double health = gwendolyn.health();
    CHECK_THAT(health, Catch::Matchers::WithinAbs(100, 1));
}

TEST_CASE("Dead Wizards should return 0% health") {
    Wizard arthur = Wizard("Sir Arthur", 154, 32, 100);
    arthur.damage(45);
    int health = arthur.health();
    CHECK_THAT(health, Catch::Matchers::WithinAbs(0, 1));
}

TEST_CASE("Should not be able to heal a  Wizard that is dead") {
    Wizard gwendolyn = Wizard("Lady Gwendolyn", 253, 200, 100);
    gwendolyn.damage(1000);
    gwendolyn.heal(100);
    double health = gwendolyn.health();
    CHECK_THAT(health, Catch::Matchers::WithinAbs(0, 1));
}


TEST_CASE("Should be dead when health is 0") {
    Wizard *cedric = new Wizard("Sir Cedric", 749, 277, 100);
    cedric->damage(300);
    bool isDead = cedric->isDead();
    CHECK(isDead);

    Wizard elara =  Wizard("Lady Elara", 435, 550, 100);
    elara.damage(500);
    elara.damage(350);
    isDead = elara.isDead();
    CHECK(isDead);
}

TEST_CASE("Wizards can not return from the dead") {
    Wizard *cedric = new Wizard("Sir Cedric", 733, 277, 100);
    cedric->damage(300);
    cedric->heal(20);
    bool isDead = cedric->isDead();
    CHECK(isDead);


    Wizard elara =  Wizard("Lady Elara", 448, 550, 100);
    elara.damage(500);
    elara.damage(350);
    elara.heal(1000000);
    isDead = elara.isDead();
    CHECK(isDead);
}
