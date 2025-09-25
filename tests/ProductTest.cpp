#include "../Products/Product.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>


class DerivedProduct: public Product {
public:
    DerivedProduct(std::string name, double price, int stock): Product(name, price, stock) {};
};

TEST_CASE("Should be able to Create a DerivedProduct") {
    DerivedProduct * myDerivedProduct = new DerivedProduct("Generic Product", 14.99, 120);
    REQUIRE_FALSE(nullptr == myDerivedProduct);
}

TEST_CASE("Should be able to get all the DerivedProduct properties") {
    DerivedProduct * myDerivedProduct = new DerivedProduct("Generic Product", 19.99, 65);
    REQUIRE_FALSE(nullptr == myDerivedProduct);

    REQUIRE(myDerivedProduct->getName() == "Generic Product");
    REQUIRE(myDerivedProduct->getPrice() == 19.99);
    REQUIRE(myDerivedProduct->getStock() == 65);
}

TEST_CASE("Should be able to set Name") {
    DerivedProduct * myDerivedProduct = new DerivedProduct("Generic Product", 9.99, 85);
    REQUIRE_FALSE(nullptr == myDerivedProduct);

    myDerivedProduct->setName("Crime and Punishment");
    REQUIRE(myDerivedProduct->getName() == "Crime and Punishment");
}
TEST_CASE("Should be able to set Price") {
    DerivedProduct * myDerivedProduct = new DerivedProduct("Generic Product", 9.99, 85);
    REQUIRE_FALSE(nullptr == myDerivedProduct);

    myDerivedProduct->setPrice(18.99);
    REQUIRE(myDerivedProduct->getPrice() == 18.99);

}
TEST_CASE("Should be able to set stock") {
    DerivedProduct * myDerivedProduct = new DerivedProduct("Generic Product", 9.99, 85);
    REQUIRE_FALSE(nullptr == myDerivedProduct);

    myDerivedProduct->setStock(70);
    REQUIRE(myDerivedProduct->getStock() == 70);
}

TEST_CASE("toString should include DerivedProduct name") {
    DerivedProduct *myDerivedProduct = new DerivedProduct("Generic Product", 18.99, 70);
    REQUIRE_FALSE(nullptr == myDerivedProduct);

    CHECK_THAT(myDerivedProduct->toString(), Catch::Matchers::ContainsSubstring("Generic Product"));
}
