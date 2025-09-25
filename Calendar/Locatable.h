#ifndef LOCATABLE_H
#define LOCATABLE_H
#include <string>

class Locatable {
public:
    //declaring a pure virtual function
    virtual std::string getLocation() const=0;
    virtual ~Locatable()=default;// Distractor has been called
};


#endif //LOCATABLE_H
