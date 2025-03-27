//including header files
#include "LIBRARY.h"
#include "USER.h"
#include "BOOK.h"
#include "BOOKLL.h"
#include "USERLL.h"
#include <iostream>

//initialize the static member
Library Library::s_Library;

Library::Library(){
}

//get the singleton instance of library
Library& Library::getLibrary() {
	return s_Library;
}

void Library::addBook(std::string title, std::string author, int ISBN)
{
	Book book(title, author, ISBN);
	bookList.addToRear(book);
}

void Library::removeBook(int ISBN)
{
	//removing a book via ISBN number
	bookList.removeBook(ISBN);
}

void Library::displayBooks()
{
	bookList.displayBooks();
}

void Library::addUser(std::string userName, int userID, int userType)
{
	if (userType == 0) //debug purpose
	{
		User user(userName, userID);
		userList.addToRear(user);
	}
	else if(userType == 1)//adds student to user linked list
	{
		Student student(userName, userID);
		userList.addToRear(student);
	}
	else if (userType == 2)//adds faculty to user linked list
	{
		Faculty faculty(userName, userID);
		userList.addToRear(faculty);
	}
}

void Library::removeUser(int userID)
{
	userList.removeUser(userID);
}

void Library::displayAllUsers()
{
	userList.displayUsers();
}

void Library::borrowBook(std::string userName, std::string title) //adds book to user's borrowed list and sets book's availability to false.
{
	//gets copy of book to give to userList
	Book book = bookList.getBook(title);

	userList.borrowBook(userName, book);
	//Due to how deep the list is burried. I have to call userList first to find the user.
	//This is due that the bookList and borrowBook function is in the user's class.
	//A better way would to move the borrowed list to the library class.
	//or make the borrowed list static in the user class. I'm sure theres alternatives.

	//lastly sets the book to false in the book list in the library
	bookList.setBoolfalse(book);
}

void Library::returnBook(std::string userName, std::string title)
{
	//removes book from user's borrowed list and sets book's availability to true.
	Book book = bookList.getBook(title);
	bookList.setBooltrue(book);

	userList.returnBook(userName, book);
	//just like borrow book. i have to call the userlist first then the booklist.
}

void Library::displayUserBooks(std::string userName)
{
	//going into the user list to find the user then call the display function in the user class
	userList.displayUserBooks(userName);
	//thoughts here comment.
	//Due to encapsulation, I had an error where it crashed when i called the display function outside of userList.
	//If i remember the code was Userlist.getUser(userName).displayBorrowedBooks();
	//Was fun to learn about how encapsulation affected the program.
}

void Library::searchBookTitle(std::string title)
{
	bookList.displayBookTitle(title);
}

void Library::searchBookAuthor(std::string author)
{
	bookList.displayBookAuthor(author);
}
