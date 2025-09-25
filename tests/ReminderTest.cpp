#include "../Calendar/Reminder.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>

TEST_CASE("Should be able to Create a Reminder") {
    Reminder * myReminder = new Reminder(2024, 04, 19, "Drop this class");
    REQUIRE_FALSE(nullptr == myReminder);
}

TEST_CASE("Should be able to getDate") {
    Reminder * myReminder = new Reminder(1989, 06, 05, "start anew");
    REQUIRE_FALSE(nullptr == myReminder);

    REQUIRE(myReminder->getDate() == "06/05/1989");
}

TEST_CASE("Should be able call toString ") {
    Reminder * myReminder = new Reminder(1989, 06, 05, "start anew");
    REQUIRE_FALSE(nullptr == myReminder);

    REQUIRE(myReminder->toString().size() > 0);
}
