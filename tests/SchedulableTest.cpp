#include "../Calendar/Schedulable.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>


class DerivedEvent: public Schedulable {
public:
    DerivedEvent() {};
    std::string getDate() const override {return "17/06/2011";};
    std::string toString() const override {return "Some Event";};

};

TEST_CASE("Should be able to Create a DerivedEvent") {
    DerivedEvent * myDerivedEvent = new DerivedEvent();
    REQUIRE_FALSE(nullptr == myDerivedEvent);
}


TEST_CASE("Should be able to getDate") {
    DerivedEvent * myDerivedEvent = new DerivedEvent();
    REQUIRE_FALSE(nullptr == myDerivedEvent);

    REQUIRE(myDerivedEvent->getDate() == "17/06/2011");
}
TEST_CASE("Should be able to call toString") {
    DerivedEvent * myDerivedEvent = new DerivedEvent();
    REQUIRE_FALSE(nullptr == myDerivedEvent);

    REQUIRE(myDerivedEvent->toString() == "Some Event");
}