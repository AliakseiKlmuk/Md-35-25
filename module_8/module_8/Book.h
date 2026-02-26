#pragma once
#include <cstring>
#include <iostream>

#include <string>

class Book
{
public: // constructors

	Book() : _title(nullptr), _author(nullptr), _year(0), _ISBN(nullptr)
	{
		//std::cout << "default constructor" << std::endl;
	}

	Book(const std::string& title, const std::string& author, unsigned int year, const char* ISBN) : _year(year)
	{
		setTitle(title);
		setAuthor(author);
		setISBN(ISBN);
		
		//std::cout << "user constructor" << std::endl;
	}

	Book(const Book& other) : _year(other._year)
	{
		if (other._title) {
			_title = new std::string(*other._title);
		}
		else {
			_title = nullptr;
		}

		if (other._author) {
			_author = new std::string(*other._author);
		}
		else {
			_author = nullptr;
		}

		if (other._ISBN) {
			_ISBN = new char[strlen(other._ISBN) + 1];
			strcpy_s(_ISBN, strlen(other._ISBN) + 1, other._ISBN);
		}
		else {
			_ISBN = nullptr;
		}
		//std::cout << "copy constructor" << std::endl;
	}

public: // getters
	std::string getTitle() const;
	std::string getAuthor() const;
	unsigned int getYear() const { return _year; }
	char* getISBN() const { return _ISBN; }


public: // setters
	void setTitle(const std::string& title);
	void setAuthor(const std::string& author);
	void setYear(unsigned int year);
	void setISBN(const char* ISBN);

public: // print information
	void printInfo() const;

public: // distructor
	~Book()
	{
		delete _title;
		delete _author;
		delete[] _ISBN;

		//std::cout << "destructor" << std::endl;
	}

private:
	std::string* _title;
	std::string* _author;
	unsigned int _year;
	char* _ISBN;

};

