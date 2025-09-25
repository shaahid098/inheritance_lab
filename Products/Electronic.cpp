#include "Electronic.h"


Electronic::Electronic(std::string name, double price, int stock, std::string model, int warranty)
    : Product(name, price, stock) {
    this->model = model;
    this->warrantyPeriod=warranty;
}
std::string Electronic::getModel() const {
    return model;
}
void Electronic::setModel(std::string model) {
    this->model = model;
}
int Electronic::getWarrantyPeriod() const {
    return warrantyPeriod;
}
void Electronic::setWarrantyPeriod(int period) {
    this->warrantyPeriod=period;
}

std::string  Electronic::toString() const  {
    return "Electronic Name: "+getName()+"| Model: "+model+"\n";
}