#pragma once
#include <cstring>
#include <iostream>

class Book
{
public: // constructors

	Book() : _title(nullptr), _author(nullptr), _year(0), _ISBN(nullptr)
	{
		std::cout << "default constructor" << std::endl;
	}

	Book(const char* title, const char* author, unsigned int year, const char* ISBN) : _year(year)

	{
		setTitle(title);
		setAuthor(author);
		setISBN(ISBN);
		
		std::cout << "user constructor" << std::endl;
	}

	Book(const Book& other) : _year(other._year)
	{
		setTitle(other._title);
		setAuthor(other._author);
		setISBN(other._ISBN);

		std::cout << "copy constructor" << std::endl;
	}

public: // getters
	char* getTitle() const { return _title; }
	char* getAuthor() const { return _author; }
	unsigned int getYear() const { return _year; }
	char* getISBN() const { return _ISBN; }


public: // setters
	void setTitle(const char* title);
	void setAuthor(const char* author);
	void setYear(unsigned int year);
	void setISBN(const char* ISBN);

	//void setFormatISBN(const char* ISBN);

public: // print information
	void printInfo() const;

public: // distructor
	~Book()
	{
		delete[] _title;
		delete[] _author;
		delete[] _ISBN;

		std::cout << "destructor" << std::endl;
	}

private:
	char* _title;
	char* _author;
	unsigned int _year;
	char* _ISBN;

};

