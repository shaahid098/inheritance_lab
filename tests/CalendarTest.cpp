#include "../Calendar/Calendar.h"
#include "../Calendar/Appointment.h"
#include "../Calendar/Reminder.h"
#include "../Calendar/Meeting.h"

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>

TEST_CASE("Should be able to Create a Calendar") {
    Calendar * myCalendar = new Calendar();
    REQUIRE_FALSE(nullptr == myCalendar);
}

TEST_CASE("Should be able to add a Reminder to the Calendar") {
    Calendar * myCalendar = new Calendar();
    Reminder *todo = new Reminder(2023, 2, 19, "Feed the Dog");
    myCalendar->addEvent(todo);
}

TEST_CASE("Should be able to add a Appointment to the Calendar") {
    Calendar * myCalendar = new Calendar();
    Appointment *interview = new Appointment(2025, 10, 19, "Corporate America", "Profits Inc.");
    myCalendar->addEvent(interview);
}

TEST_CASE("Should be able to add a Meeting to the Calendar") {
    Calendar * myCalendar = new Calendar();
    Meeting *dinner = new Meeting(2023, 2, 19, "Dinner with Friends", "Barnes Burgers");
    myCalendar->addEvent(dinner);
}

TEST_CASE("Should be able to list the events for a given day") {
    Calendar * myCalendar = new Calendar();

    Reminder *todo = new Reminder(2023, 2, 19, "Feed the Dog");
    myCalendar->addEvent(todo);

    Appointment *interview = new Appointment(2025, 10, 19, "Corporate America", "Profits Inc.");
    myCalendar->addEvent(interview);

    Meeting *dinner = new Meeting(2023, 2, 19, "Dinner with Friends", "Barnes Burgers");
    myCalendar->addEvent(dinner);

    std::string events = myCalendar->getDaysEvents("02/19/2023");

    CHECK_THAT(events, Catch::Matchers::ContainsSubstring("Dinner with Friends"));
    CHECK_THAT(events, Catch::Matchers::ContainsSubstring("Feed the Dog"));
}


TEST_CASE("Should not see event that are schedule on days other than the requested day") {
    Calendar * myCalendar = new Calendar();

    Reminder *todo = new Reminder(2023, 2, 19, "Feed the Dog");
    myCalendar->addEvent(todo);

    Appointment *interview = new Appointment(2025, 10, 19, "Corporate America", "Profits Inc.");
    myCalendar->addEvent(interview);

    Meeting *dinner = new Meeting(2023, 2, 19, "Dinner with Friends", "Barnes Burgers");
    myCalendar->addEvent(dinner);

    std::string events = myCalendar->getDaysEvents("02/19/2023");
    int pos = events.find("Corporate America");
    REQUIRE(pos == -1);
}
