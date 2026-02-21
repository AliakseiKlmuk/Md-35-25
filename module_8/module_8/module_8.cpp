
#include <iostream>
#include "Book.h"
#include <string>

int main()
{
    std::cout << "Hello World!\n";

    Book book ("Sherlock Holmes", "Sir Arthur Conan Doyle", 2020, "9781839641756");
    Book book2 = book;

    book.printInfo();
    book2.printInfo();
   

    book.setTitle("Hobbit");
    book.setAuthor("J R. R. Tolkien");
    book.setYear(1986);
    book.setISBN("9780345339683");
    book.printInfo();

}
