#ifndef CALENDAR_H
#define CALENDAR_H
#include "Schedulable.h"
#include <sstream>
#include <vector>



class Calendar {
private:
    std::vector<Schedulable*> events;
public:
    Calendar();
    void addEvent(Schedulable* event);
    std::string getDaysEvents(std::string date);
    virtual ~Calendar()=default;
};


#endif //CALENDAR_H
