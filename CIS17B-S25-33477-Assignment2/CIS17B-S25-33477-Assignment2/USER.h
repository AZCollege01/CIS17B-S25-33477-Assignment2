#ifndef USER_H //Include guard
#define USER_H

//Including Header Files
#include <string>
#include "BOOK.h"
#include "BOOKLL.h"

//User class
class User {
private:
	std::string _name; //name of user account
	int _userID; //ID of user account
	BookLL borrowedList;//Linked List of books that user has borrowed
	bool _empty; //bool to check if user data is empty upon initialization

public:
	//constructors
	User();
	User(std::string name, int userID);

	//member functions
	void addName(std::string name); //sets name
	void addUserID(int userID); //sets user ID
	void borrowBook(Book book); //uses the book linked list class to add a book to user's borrowed list
	void returnBook(Book book); //uses the book linked list class to remove a book from user's borrowed list
	void setEmpty(bool empty);

	//get functions
	std::string getName(); //returns name
	int getUserID(); //returns user ID
	void displayBorrowedBooks(); //displays a list of books borrowed by user
	bool getEmpty(); //returns bool status of user's data
};

#endif