#include "Appointment.h"

Appointment::Appointment(int year, int month, int day, std::string title, std::string location) {
    this->year = year;
    this->month = month;
    this->day = day;
    this->title = title;
    this->location = location;
}

std::string Appointment::getDate() const {
    std::ostringstream oss; //"ostringstream" Stores temporary list of string
    oss << std::setw(2) << std::setfill('0') << month << "/"; //if the output character is less the 2 adda 0 on front
    oss << std::setw(2) << std::setfill('0') << day << "/"; //if the output character is less the 2 adda 0 on front
    oss << year;
    return oss.str();
}
std::string Appointment::toString() const {
    return "Appopinment: "+title+" at "+location+" on "+getDate();
}

std::string Appointment::getLocation() const {
    return location;
}

