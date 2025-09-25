#ifndef BOOK_H
#define BOOK_H
#include <string>

#include "Product.h"


class Book: public Product {
private:
    std::string author;
    std::string publisher;
public:
    Book(std::string name,double price,int stock,std::string author,std::string publisher);
    std::string getAuthor() const; //Getters
    void setAuthor(std::string author); //Setters
    std::string getPublisher() const; //Getters
    void setPublisher(std::string publisher); //Setters
    std::string toString() const override;
};


#endif //BOOK_H
