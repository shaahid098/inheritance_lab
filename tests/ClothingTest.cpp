#include "../Products/Clothing.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>

TEST_CASE("Should be able to Create a Clothing") {
    Clothing * myClothing = new Clothing("T-Shirt", 19.99, 100, "M", "Cotton");
    REQUIRE_FALSE(nullptr == myClothing);
}

TEST_CASE("Should be able to get all the Clothing properties") {
    Clothing * myClothing = new Clothing("Jeans", 49.99, 50, "L", "Denim");
    REQUIRE_FALSE(nullptr == myClothing);

    REQUIRE(myClothing->getName() == "Jeans");
    REQUIRE(myClothing->getPrice() == 49.99);
    REQUIRE(myClothing->getStock() == 50);
    REQUIRE(myClothing->getSize() == "L");
    REQUIRE(myClothing->getMaterial() == "Denim");
}

TEST_CASE("Should be able to set Name") {
    Clothing * myClothing = new Clothing("Jacket", 99.99, 20, "XL", "Leather");
    REQUIRE_FALSE(nullptr == myClothing);

    myClothing->setName("Scarf");
    REQUIRE(myClothing->getName() == "Scarf");
}
TEST_CASE("Should be able to set Price") {
    Clothing * myClothing = new Clothing("Sweater", 39.99, 30, "S", "Wool");
    REQUIRE_FALSE(nullptr == myClothing);

    myClothing->setPrice(24.99);
    REQUIRE(myClothing->getPrice() == 24.99);
}
TEST_CASE("Should be able to set stock") {
    Clothing * myClothing = new Clothing("Coat", 149.99, 15, "M", "Polyester");
    REQUIRE_FALSE(nullptr == myClothing);

    myClothing->setStock(35);
    REQUIRE(myClothing->getStock() == 35);
}
TEST_CASE("Should be able to set Size") {
    Clothing * myClothing = new Clothing("Shorts", 29.99, 60, "L", "Cotton");
    REQUIRE_FALSE(nullptr == myClothing);

    myClothing->setSize("One Size");
    REQUIRE(myClothing->getSize() == "One Size");
}
TEST_CASE("Should be able to set material") {
    Clothing * myClothing = new Clothing("Hoodie", 59.99, 40, "XL", "Cotton");
    REQUIRE_FALSE(nullptr == myClothing);

    myClothing->setMaterial("Wool");
    REQUIRE(myClothing->getMaterial() == "Wool");
}

TEST_CASE("toString should include Clothing name") {
    Clothing *myClothing = new Clothing("Tank Top", 14.99, 80, "S", "Cotton");
    REQUIRE_FALSE(nullptr == myClothing);

    CHECK_THAT(myClothing->toString(), Catch::Matchers::ContainsSubstring("Cotton"));
}

TEST_CASE("toString should include Clothing size") {
    Clothing *myClothing = new Clothing("Socks", 7.99, 200, "M", "Cotton");
    REQUIRE_FALSE(nullptr == myClothing);

    CHECK_THAT(myClothing->toString(), Catch::Matchers::ContainsSubstring("M"));
}

