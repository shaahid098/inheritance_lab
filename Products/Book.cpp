#include "Book.h"

//Constructor
Book::Book(std::string name, double price, int stock, std::string author, std::string publisher)
    :Product(name,price,stock){
    this->author = author;
    this->publisher = publisher;
}

std::string Book::getAuthor() const{
    return author;
}
void Book::setAuthor(std::string author) {
    this->author = author;
}

std::string Book::getPublisher() const {
    return publisher;
}
void Book::setPublisher(std::string publisher) {
    this->publisher = publisher;
}
std::string Book::toString() const {
    return "Book: "+getName()+"Author: "+author+"\n";
}

