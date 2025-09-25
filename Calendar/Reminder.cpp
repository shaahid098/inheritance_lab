#include "Reminder.h"

Reminder::Reminder(int year,int day,int month,std::string task){
    this->task = task;
    this->day = day;
    this->month = month;
    this->year = year;
}
std::string Reminder::getDate() const {
    std::ostringstream oss; //"ostringstream" Stores temporary list of string
    oss << std::setw(2) << std::setfill('0') << day << "/";//if the output character is less the 2 adda 0 on front
    oss << std::setw(2) << std::setfill('0') << month << "/";//if the output character is less the 2 adda 0 on front
    oss << year;
        return oss.str();
}

std::string Reminder::toString()const {
    return "Reminder:"+ task+" On "+ getDate();
}
