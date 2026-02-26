
#include <iostream>
#include "Book.h"
#include <string>

int main()
{

	Book book1;
	book1.setTitle("Hobbit");
	book1.setAuthor("J R. R. Tolkien");
	book1.setYear(1986);
	book1.setISBN("9780345339683");
	book1.printInfo();

	Book book2("Hobbit", "J R. R. Tolkien", 1986, "9780345339683");
	book2.printInfo();

	Book book3 = book1;
	book3.printInfo();


}
