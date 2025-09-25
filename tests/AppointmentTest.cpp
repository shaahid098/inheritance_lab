#include "../Calendar/Appointment.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>

TEST_CASE("Should be able to Create a Appointment") {
    Appointment * myAppointment = new Appointment(2023, 1, 9, "Register Car", "The Red Tape line");
    REQUIRE_FALSE(nullptr == myAppointment);
}

TEST_CASE("Should be able to getDate") {
    Appointment * myAppointment = new Appointment(2023, 1, 9, "Register Car", "The Red Tape line");
    REQUIRE_FALSE(nullptr == myAppointment);

    REQUIRE(myAppointment->getDate() == "01/09/2023");
}

TEST_CASE("Should be able call toString ") {
    Appointment * myAppointment = new Appointment(2023, 1, 9, "Register Car", "The Red Tape line");
    REQUIRE_FALSE(nullptr == myAppointment);

    REQUIRE(myAppointment->toString().size() > 0);
}

TEST_CASE("Should be able get location ") {
    Appointment * myAppointment = new Appointment(2023, 1, 9, "Register Car", "The Red Tape line");
    REQUIRE_FALSE(nullptr == myAppointment);

    REQUIRE(myAppointment->getLocation() == "The Red Tape line");
}
