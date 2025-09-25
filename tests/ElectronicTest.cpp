#include "../Products/Electronic.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>

TEST_CASE("Should be able to Create a Electronic") {
    Electronic * myElectronic = new Electronic("Samsung Galaxy S22", 799.99, 25, "SM-S901U", 2);
    REQUIRE_FALSE(nullptr == myElectronic);
}

TEST_CASE("Should be able to get all the Electronic properties") {
    Electronic * myElectronic = new Electronic("Google Pixel 6", 599.00, 40, "GG1-7000", 2);
    REQUIRE_FALSE(nullptr == myElectronic);

    REQUIRE(myElectronic->getName() == "Google Pixel 6");
    REQUIRE(myElectronic->getPrice() == 599.00);
    REQUIRE(myElectronic->getStock() == 40);
    REQUIRE(myElectronic->getModel() == "GG1-7000");
    REQUIRE(myElectronic->getWarrantyPeriod() == 2);
}

TEST_CASE("Should be able to set Name") {
    Electronic * myElectronic = new Electronic("Dell XPS 13", 999.00, 15, "XPS13-9301", 1);
    REQUIRE_FALSE(nullptr == myElectronic);

    myElectronic->setName("Crime and Punishment");
    REQUIRE(myElectronic->getName() == "Crime and Punishment");
}
TEST_CASE("Should be able to set Price") {
    Electronic * myElectronic = new Electronic("MacBook Air", 999.00, 20, "A2337", 1);
    REQUIRE_FALSE(nullptr == myElectronic);

    myElectronic->setPrice(18.99);
    REQUIRE(myElectronic->getPrice() == 18.99);
}
TEST_CASE("Should be able to set stock") {
    Electronic * myElectronic = new Electronic("Apple Watch Series 7", 399.00, 50, "A2473", 1);
    REQUIRE_FALSE(nullptr == myElectronic);

    myElectronic->setStock(70);
    REQUIRE(myElectronic->getStock() == 70);
}
TEST_CASE("Should be able to set Model") {
    Electronic * myElectronic = new Electronic("Fitbit Versa 3", 229.95, 70, "FB511", 1);
    REQUIRE_FALSE(nullptr == myElectronic);

    myElectronic->setModel("CHDHX-101");
    REQUIRE(myElectronic->getModel() == "CHDHX-101");
}
TEST_CASE("Should be able to set Warranty Period") {
    Electronic * myElectronic = new Electronic("Canon EOS R6", 2399.00, 10, "3454C001", 1);
    REQUIRE_FALSE(nullptr == myElectronic);

    myElectronic->setWarrantyPeriod(7);
    REQUIRE(myElectronic->getWarrantyPeriod() == 7);
}

TEST_CASE("toString should include Electronic name") {
    Electronic *myElectronic = new Electronic("Sony A7 IV", 2499.99, 8, "ILCE-7M4", 1);
    REQUIRE_FALSE(nullptr == myElectronic);

    CHECK_THAT(myElectronic->toString(), Catch::Matchers::ContainsSubstring("Sony A7 IV"));
}
