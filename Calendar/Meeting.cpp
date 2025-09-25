#include "Meeting.h"
Meeting::Meeting(int year, int month, int day, std::string title, std::string location) {
    this->year=year;
    this->month=month;
    this->day=day;
    this->location=location;
    this->title=title;

}
std::string Meeting::getLocation()const {
    return location;
}
std::string Meeting::getDate()const {
    std::ostringstream oss; //"ostringstream" Stores temporary list of string
    oss << std::setw(2) << std::setfill('0') << month << "/"; //if the output character is less the 2 adda 0 on front
    oss << std::setw(2) << std::setfill('0') << day << "/"; //if the output character is less the 2 adda 0 on front
    oss << year;
    return oss.str();
}
std::string Meeting::toString() const {
    std::ostringstream oss;
    oss << "Meeting: " << title << " at " << location << " on " << getDate();

    if (!attendances.empty()) {
        oss << " Attendees: ";
        for (size_t i = 0; i < attendances.size(); i++) {
            oss << attendances[i];
            if (i < attendances.size() - 1) {
                oss << ", ";
            }
        }
    }

    return oss.str();
}

void Meeting::addAttendee(std::string name) {
    attendances.push_back(name);
}

