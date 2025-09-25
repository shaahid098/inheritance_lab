#ifndef REMINDER_H
#define REMINDER_H
#include <sstream>
#include <iomanip>
#include "Schedulable.h"


class Reminder: public Schedulable {
private:
    std::string task;
    int day;
    int month;
    int year;
public:
    Reminder(int year,int day,int month,std::string task);
    std::string getDate() const override;

    std::string toString() const override;
    virtual ~Reminder()=default;
};


#endif //REMINDER_H


