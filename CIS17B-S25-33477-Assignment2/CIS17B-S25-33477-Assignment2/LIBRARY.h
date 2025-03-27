#ifndef LIBRARY_H // Include Guard
#define LIBRARY_H

//including required header files
#include "BOOKLL.h"
#include "USERLL.h"

//creating Library class as a singleton.
class Library
{
private:
	
	static Library s_Library;
	Library();
	BookLL bookList; //linked list of books in the library
	UserLL userList; //linked list of users in the library
public:
	static Library& getLibrary();
	Library(const Library&) = delete; //prevents additional instance of singleton library

	//Library member functions

	//Managing Books
	void addBook(std::string title, std::string author, int ISBN);
	void removeBook(int ISBN);
	void displayBooks();
	//insert search function here

	//Managing Users
	void addUser(std::string userName, int userID, int userType); //add user to librart's user list
	void removeUser(int userID); //remove user from library's user list
	void displayAllUsers(); //displays all users in the library
	
	//Borrowing and Returning Books
	void borrowBook(std::string userName, std::string title);
	void returnBook(std::string userName, std::string title);
	void displayUserBooks(std::string userName); //displays all books borrowed by a user

	//Searching book functions
	void searchBookTitle(std::string title);
	void searchBookAuthor(std::string author);
};

#endif