#include "BOOK.h"

Book::Book()
{
	_title = "";
	_author = "";
	_ISBN = 0;
	_availability = true;
}

Book::Book(std::string title, std::string author, int isbn)
{
	_title = title;
	_author = author;
	_ISBN = isbn;
	_availability = true; //stays true until borrowed later

}

void Book::setTitle(std::string title)
{
	_title = title;
}

void Book::setAuthor(std::string author)
{
	_author = author;
}

void Book::setISBN(int isbn)
{
	_ISBN = isbn;
}

void Book::setAvailability(bool availability)
{
	_availability = availability;
}

std::string Book::getTitle()
{
	return _title;
}

std::string Book::getAuthor()
{
	return _author;
}

int Book::getISBN()
{
	return _ISBN;
}

bool Book::getAvailability()
{
	return _availability;
}
