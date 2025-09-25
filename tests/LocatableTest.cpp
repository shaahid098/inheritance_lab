#include "../Calendar/Locatable.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>


class DerivedEvent: public Locatable {
public:
    DerivedEvent() {};
    std::string getLocation() const override {return "Tuttletown, Ca";}

};

TEST_CASE("Should be able to Create a DerivedEvent") {
    DerivedEvent * myDerivedEvent = new DerivedEvent();
    REQUIRE_FALSE(nullptr == myDerivedEvent);
}

TEST_CASE("Should be able to getLocation") {
    DerivedEvent * myDerivedEvent = new DerivedEvent();
    REQUIRE_FALSE(nullptr == myDerivedEvent);

    REQUIRE(myDerivedEvent->getLocation() == "Tuttletown, Ca");
}