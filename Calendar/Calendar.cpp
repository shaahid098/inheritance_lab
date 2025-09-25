#include "Calendar.h"
Calendar::Calendar() {}
void Calendar::addEvent(Schedulable *event) {
    events.push_back(event);
}

std::string Calendar::getDaysEvents(std::string date) {
    std::string result = "Events on " + date + ":\n";
    for (const auto& event : events) {
        if (event->getDate() == date) {
            result += event->toString() + "\n";
        }
    }
    return result;
}
