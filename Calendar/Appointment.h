#ifndef APPOINTMENT_H
#define APPOINTMENT_H
#include "Schedulable.h"
#include "Locatable.h"
#include <string>
#include <sstream>
#include <iomanip>



class Appointment: public Schedulable, public Locatable{
private:
    int day;
    int year;
    std::string title;
    std::string location;
    int month;
public:
    //Constructor
    Appointment(int year,int month,int day,std::string title,std::string location);
    std::string getDate() const override;
    std::string toString() const override;
    std::string getLocation() const override;
    virtual ~Appointment()=default;
};


#endif //APPOINTMENT_H
