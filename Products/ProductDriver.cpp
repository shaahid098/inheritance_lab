#include <iostream>
#include <iomanip>
#include "Product.h"
#include "Book.h"
#include "Electronic.h"
#include "Clothing.h"

//creating a vector to store the inventory dynamically
 void addingProducts(std::vector<Product*>& inventory) {
     /**
      *@param Pushing the values for Electronic class
      *Electronic(name,price,stock,model,warrenty)
      */
     inventory.push_back(new Electronic("MacBook Air", 999.00, 20, "A2337", 2));
     inventory.push_back(new Electronic("Samsung Galaxy S22", 799.99, 25, "SM-S901U", 1));
     inventory.push_back(new Electronic("Apple iPhone 13", 699.00, 30, "A2489", 2));
     inventory.push_back(new Electronic("GoPro HERO10", 499.99, 35, "CHDHX-101", 1));
     inventory.push_back(new Electronic("Canon EOS R6", 2399.00, 10, "3454C001", 3));
     inventory.push_back(new Electronic("Sony A7 IV", 2499.99, 8, "ILCE-7M4", 2));
     inventory.push_back(new Electronic("Fitbit Versa 3", 229.95, 70, "FB511", 1));
     inventory.push_back(new Electronic("Google Pixel 6", 599.00, 40, "GGI-7000", 2));
     inventory.push_back(new Electronic("Apple Watch Series 7", 399.00, 50, "A2473", 1));
     inventory.push_back(new Electronic("Dell XPS 13", 999.00, 15, "XPS13-9301", 2));

     /**
      *@param Pushing the value for the Clothing Class
      *Cloathing(name,price,stock,size,material)
      */
     inventory.push_back(new Clothing("Jeans", 49.99, 50, "L", "Denim"));
     inventory.push_back(new Clothing("Sweater", 39.99, 30, "M", "Wool"));
     inventory.push_back(new Clothing("Jacket", 99.99, 20, "XL", "Leather"));
     inventory.push_back(new Clothing("T-Shirt", 19.99, 100, "M", "Cotton"));
     inventory.push_back(new Clothing("Hoodie", 59.99, 40, "XL", "Cotton"));
     inventory.push_back(new Clothing("Scarf", 24.99, 35, "One Size", "Wool"));
     inventory.push_back(new Clothing("Shorts", 29.99, 60, "L", "Cotton"));
     inventory.push_back(new Clothing("Tank Top", 14.99, 80, "S", "Cotton"));
     inventory.push_back(new Clothing("Socks", 7.99, 200, "M", "Cotton"));
     inventory.push_back(new Clothing("Coat", 149.99, 15, "M", "Polyester"));

     /**
      *@param pushing the values for Books class
      *Book(name,price,stock,author,publisher)
      */
     inventory.push_back(new Book("To Kill a Mockingbird", 7.99, 100, "Harper Lee", "J.B. Lippincott & Co."));
     inventory.push_back(new Book("1984", 9.99, 85, "George Orwell", "Secker & Warburg"));
     inventory.push_back(new Book("Pride and Prejudice", 11.99, 100, "Jane Austen", "T. Egerton"));
     inventory.push_back(new Book("Crime and Punishment", 18.99, 70, "Fyodor Dostoevsky", "The Russian Messenger"));
     inventory.push_back(new Book("Moby Dick", 12.99, 75, "Herman Melville", "Harper & Brothers"));
     inventory.push_back(new Book("The Catcher in the Rye", 8.99, 110, "J.D. Salinger", "Little, Brown and Company"));
     inventory.push_back(new Book("War and Peace", 15.99, 65, "Leo Tolstoy", "The Russian Messenger"));
     inventory.push_back(new Book("The Odyssey", 10.99, 200, "Homer", "Ancient Greece"));
     inventory.push_back(new Book("Ulysses", 16.99, 80, "James Joyce", "Shakespeare and Company"));
     inventory.push_back(new Book("The Great Gatsby", 14.99, 120, "F. Scott Fitzgerald", "Charles Scribner's Sons"));
    }
    //Now Printing the inventory report
    void InventoryReport(const std::vector<Product*>& inventory) {

     double totalValue = 0.0;

     std::cout<<std::left<< std::setw(15) << "Name"
              <<std::left<<std::setw(15)<<"Price"
              <<std::left<<std::setw(15)<<"Stock" << std::endl;
     std::cout << "__________________________________________" << std::endl;

     for (const Product* product : inventory) {
         double value = product->getPrice() * product->getStock();
         totalValue += value;

         std::cout << std::left << std::setw(30) << product->toString()  //setw() Its a keyword to set width to value next to it
                   << std::setw(10) << product->getPrice()
                   << std::setw(10) << product->getStock()
                   << std::setw(10) << value << "\n";
     }

     std::cout << "--------------------------------------------------------------\n";
     std::cout << "Total Inventory Value: $" << totalValue << "\n";
     }



//Creating the cleanup function;
void cleanUp(std::vector<Product*>& inventory) {
     for (Product* product : inventory) {
         delete product;
     }
     inventory.clear();
 }

int main() {

     std::vector<Product*>inventory;
     addingProducts(inventory);
     InventoryReport(inventory);
     cleanUp(inventory);

     return 0;
}
