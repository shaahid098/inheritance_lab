#include "Product.h"
#include<iostream>



//constructor
Product::Product(std::string name, double price, int stock) {

    this->name = name;
    this->stock = stock;
    this->price = price;
}

std::string Product::getName() const {
    return name;
}
void Product::setName(std::string name) {
    this->name = name;
}

double Product::getPrice() const {
    return price;
}

void Product::setPrice(double price) {
    this->price = price;
}

int Product::getStock() const {
    return stock;
}

void Product::setStock(int stock) {
    this->stock = stock;
}

std::string Product::toString() const {
    return "Product: "+ name + "| Price: $"+ std::to_string(price) +"\n";

}