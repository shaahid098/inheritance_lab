#include "Clothing.h"

//Costructor
Clothing::Clothing(std::string name, double price, int stock, std::string size, std::string material)
    :Product(name, price,stock){
    this->size = size;
    this->material = material;
}

std::string Clothing::getSize() const {
    return size;
}

void Clothing::setSize(std::string size) {
    this->size = size;
}
std::string Clothing::getMaterial() const {
    return material;
}
void Clothing::setMaterial(std::string material) {
    this->material = material;
}

std::string Clothing::toString() const {
    return "Clothing:" +getName()+ "|Size: "+ size + "|Material: " + material+"\n";
}
