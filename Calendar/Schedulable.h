#ifndef SCHEDULABLE_H
#define SCHEDULABLE_H
#include <string>

//It is an abstract class
class Schedulable {
public:
    //declaring a pure virtual function
    virtual std::string getDate()const=0;
    virtual std::string toString() const =0;
    virtual ~Schedulable()=default ;// Distractor has been called
};


#endif //SCHEDULABLE_H
