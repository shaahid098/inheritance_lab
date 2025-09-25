#ifndef CLOTHING_H
#define CLOTHING_H
#include <sstream>
#include "Product.h"

class Clothing: public Product {
private:
    std::string size;
    std::string material;

public:
    Clothing(std::string name,double price,int stock,std::string size,std::string material);
    std::string getSize() const ;//Getters
    void setSize(std::string size); //Setters
    std::string getMaterial() const; //Getters
    void setMaterial(std::string material); //Setters
    std::string toString() const override ;

};


#endif //CLOTHING_H
