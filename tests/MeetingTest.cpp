#include "../Calendar/Meeting.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>

TEST_CASE("Should be able to Create a Meeting") {
    Meeting * myMeeting = new Meeting(2023, 2, 19, "Dinner with Friends", "Barnes Burgers");
    REQUIRE_FALSE(nullptr == myMeeting);
}

TEST_CASE("Should be able to getDate") {
    Meeting * myMeeting = new Meeting(2023, 2, 19, "Dinner with Friends", "Barnes Burgers");
    REQUIRE_FALSE(nullptr == myMeeting);

    REQUIRE(myMeeting->getDate() == "02/19/2023");
}

TEST_CASE("Should be able call toString ") {
    Meeting * myMeeting = new Meeting(2023, 2, 19, "Dinner with Friends", "Barnes Burgers");
    REQUIRE_FALSE(nullptr == myMeeting);

    REQUIRE(myMeeting->toString().size() > 0);
}

TEST_CASE("Should be able get location ") {
    Meeting * myMeeting = new Meeting(2023, 2, 19, "Dinner with Friends", "Barnes Burgers");
    REQUIRE_FALSE(nullptr == myMeeting);

    REQUIRE(myMeeting->getLocation() == "Barnes Burgers");
}

TEST_CASE("Should be able to add an attendee") {
    Meeting * dinner = new Meeting(2023, 2, 19, "Dinner with Friends", "Barnes Burgers");
    dinner->addAttendee("Bob");

    CHECK_THAT(dinner->toString(), Catch::Matchers::ContainsSubstring("Bob"));
}

TEST_CASE("Should be able to add multiple attendees") {
    Meeting * dinner = new Meeting(2023, 2, 19, "Dinner with Friends", "Barnes Burgers");
    dinner->addAttendee("Bob");
    dinner->addAttendee("Ann");

    CHECK_THAT(dinner->toString(), Catch::Matchers::ContainsSubstring("Bob"));
    CHECK_THAT(dinner->toString(), Catch::Matchers::ContainsSubstring("Ann"));
}