#include "Book.h"

std::string Book::getTitle() const
{
	return _title ? *_title : "No title";
}

std::string Book::getAuthor() const
{
	return _author ? *_author : "No author";
}

void Book::setTitle(const std::string& title)
{
	if (_title) {
		delete _title;
	}
	_title = new std::string(title);
}

void Book::setAuthor(const std::string& author)
{
	if (_author) {
		delete _author;
	}
	_author = new std::string(author);
}

void Book::setYear(unsigned int year)
{ 
	_year = year;
}

void Book::setISBN(const char* ISBN)
{
	if (_ISBN) {
		delete[] _ISBN;
	}
	_ISBN = new char[strlen(ISBN) + 1];
	strcpy_s(_ISBN, strlen(ISBN) + 1, ISBN);
}

void Book::printInfo() const
{
	std::cout << "Title: " << getTitle() << "\tAuthor: " << getAuthor()
		<< "\tYear: " << _year << "\tISBN: " << _ISBN;

	std::cout << std::endl;
}

