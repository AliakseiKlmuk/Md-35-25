#include "Book.h"

void Book::setTitle(const char* title)
{
	if (_title) {
		delete[] _title;
	}

	_title = new char[strlen(title) + 1];
	strcpy_s(_title, strlen(title) + 1, title);
}

void Book::setAuthor(const char* author)
{
	if (_author) {
		delete[] _author;
	}

	_author = new char[strlen(author) + 1];
	strcpy_s(_author, strlen(author) + 1, author);
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

//void Book::setFormatISBN(const char* ISBN)
//{
//	size_t length = strlen(ISBN);
//	size_t new_length = length + 3;
//
//	_ISBN = new char[new_length + 1];
//
//	size_t j = 0;
//	for (size_t i = 0; i < length; ++i) {
//		if (j == 3 || j == 5 || j == 8) {
//			_ISBN[j] = '-';
//			j++;
//		}
//		_ISBN[j] = ISBN[i];
//		j++;
//	}
//
//	_ISBN[j] = '\0';
//}

void Book::printInfo() const
{
	if (_title && _title[0] != '\0') {
		std::cout << "Title:" << '\t' << getTitle() << std::endl;
	}
	else { std::cout << "Title:\tunknown information" << std::endl; }

	if (_author && _author[0] != '\0') {
		std::cout << "Author:" << '\t' << getAuthor() << std::endl;
	} else { std::cout << "Author:\tunknown information" << std::endl; }

	if (_year < 2026 && _year > 0) {
		std::cout << "Year:" << '\t' << getYear() << std::endl;
	} else { std::cout << "Year:\tunknown information" << std::endl; }

	if (_ISBN && _ISBN[0] != '\0') {
		std::cout << "ISBN:" << '\t' << getISBN() << std::endl;
	} else { std::cout << "ISBN:\tunknown information" << std::endl; }

	std::cout << std::endl;
}

