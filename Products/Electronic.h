#ifndef ELECTRONIC_H
#define ELECTRONIC_H
#include <sstream>
#include "Product.h"




class Electronic:public Product{

private:
    std::string model;
    int warrantyPeriod;

public:
    Electronic(std::string name,double price,int stock,std::string model,int warrenty);
    std::string getModel() const; //getters
    void setModel(std::string model); //setters
    int getWarrantyPeriod() const;
    void setWarrantyPeriod(int period);//setters

    std::string getMaterial() const; //getters
    void setMaterial(std::string material); //setters
    std::string toString() const override ;
};


#endif
