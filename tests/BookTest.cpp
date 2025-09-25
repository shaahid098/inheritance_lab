#include "../Products/Book.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>

TEST_CASE("Should be able to Create a Book") {
    Book * myBook = new Book("The Great Gatsby", 14.99, 120, "F. Scott Fitzgerald", "Charles Scribner's Sons");
    REQUIRE_FALSE(nullptr == myBook);
}

TEST_CASE("Should be able to get all the Book properties") {
    Book * myBook = new Book("War and Peace", 19.99, 65, "Leo Tolstoy", "The Russian Messenger");
    REQUIRE_FALSE(nullptr == myBook);

    REQUIRE(myBook->getName() == "War and Peace");
    REQUIRE(myBook->getPrice() == 19.99);
    REQUIRE(myBook->getStock() == 65);
    REQUIRE(myBook->getAuthor() == "Leo Tolstoy");
    REQUIRE(myBook->getPublisher() == "The Russian Messenger");
}

TEST_CASE("Should be able to set Name") {
    Book * myBook = new Book("1984", 9.99, 85, "George Orwell", "Secker & Warburg");
    REQUIRE_FALSE(nullptr == myBook);

    myBook->setName("Crime and Punishment");
    REQUIRE(myBook->getName() == "Crime and Punishment");
}
TEST_CASE("Should be able to set Price") {
    Book * myBook = new Book("1984", 9.99, 85, "George Orwell", "Secker & Warburg");
    REQUIRE_FALSE(nullptr == myBook);

    myBook->setPrice(18.99);
    REQUIRE(myBook->getPrice() == 18.99);
}
TEST_CASE("Should be able to set stock") {
    Book * myBook = new Book("1984", 9.99, 85, "George Orwell", "Secker & Warburg");
    REQUIRE_FALSE(nullptr == myBook);

    myBook->setStock(70);
    REQUIRE(myBook->getStock() == 70);
}
TEST_CASE("Should be able to set Author") {
    Book * myBook = new Book("1984", 9.99, 85, "George Orwell", "Secker & Warburg");
    REQUIRE_FALSE(nullptr == myBook);

    myBook->setAuthor("Fyodor Dostoevsky");
    REQUIRE(myBook->getAuthor() == "Fyodor Dostoevsky");
}
TEST_CASE("Should be able to set publisher") {
    Book * myBook = new Book("1984", 9.99, 85, "George Orwell", "Secker & Warburg");
    REQUIRE_FALSE(nullptr == myBook);

    myBook->setPublisher("The Russian Messenger");
    REQUIRE(myBook->getPublisher() == "The Russian Messenger");
}

TEST_CASE("toString should include Book name") {
    Book *myBook = new Book("Crime and Punishment", 18.99, 70, "Fyodor Dostoevsky", "The Russian Messenger");
    REQUIRE_FALSE(nullptr == myBook);

    CHECK_THAT(myBook->toString(), Catch::Matchers::ContainsSubstring("Crime and Punishment"));
}

TEST_CASE("toString should include Book author") {
    Book *myBook = new Book("Crime and Punishment", 18.99, 70, "Fyodor Dostoevsky", "The Russian Messenger");
    REQUIRE_FALSE(nullptr == myBook);

    CHECK_THAT(myBook->toString(), Catch::Matchers::ContainsSubstring("Fyodor Dostoevsky"));
}