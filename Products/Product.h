#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>



class  Product {
private:
    std::string name;
    double price ;
    int stock;

public:
    Product(std::string name, double price,int stock );
    std::string getName() const;//getters
    void setName(std::string name);//setters
    double getPrice() const;//getters
    void setPrice(double price);//setters
    int getStock() const;//getters
    void setStock(int stock);//setters
    virtual std::string toString() const;
};

#endif  // PRODUCT_H
