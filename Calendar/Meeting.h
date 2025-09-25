#ifndef MEETING_H
#define MEETING_H
#include <sstream>
#include <iomanip>
#include <vector>

#include "Schedulable.h"
#include "Locatable.h"



class Meeting:public Schedulable,public Locatable{
private:
    int year, month, day;
    std::string location;
    std::string title;
    std::vector<std::string> attendances;
public:
    Meeting(int year, int month, int day, std::string title,std::string location);
    void addAttendee(std::string name);
    std::string toString() const override;
    std::string getLocation() const override;
    std::string getDate() const override;
    virtual ~Meeting()=default;


};


#endif //MEETING_H
