#include "USER.h"

User::User()
{
	_name = "";
	_userID = 0;
	_empty = true;
}

User::User(std::string name, int userID)
{
	_name = name;
	_userID = userID;
	_empty = false;
}

void User::addName(std::string name)
{
	_name = name;
}

void User::addUserID(int userID)
{
	_userID = userID;
}

void User::borrowBook(Book book)
{
	borrowedList.addToRear(book);
}

void User::returnBook(Book book)
{
	borrowedList.removeBook(book.getISBN());
}

void User::setEmpty(bool empty)
{
	_empty = empty;
}

std::string User::getName()
{
	return _name;
}

int User::getUserID()
{
	return _userID;
}

void User::displayBorrowedBooks()
{
	borrowedList.displayBooks();
}

bool User::getEmpty()
{
	return _empty;
}
