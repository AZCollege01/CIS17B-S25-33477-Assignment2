#ifndef USERLL_H //include guard
#define USERLL_H

//including header files
#include "USER.h"
#include "BOOK.h"
#include "STUDENT.h"
#include "FACULTY.h"

//User Linked List
class UserLL : public User
{
private:
	struct Node
	{
		User _user;
		Student _student;
		Faculty _faculty;
		Node* next;
	};
	Node* head;

public:
	UserLL(); //constructor
	~UserLL(); //destructor
	int size(); //returns size of user list

	//add specific nodes to the list
	void addToFront(User user); //adds a user to the front of the list
	void addToRear(User user); //adds a user to the rear of the list
	void addToFront(Student student); //adds a student to the front of the list
	void addToRear(Student student); //adds a student to the rear of the list
	void addToFront(Faculty faculty); //adds a faculty to the front of the list
	void addToRear(Faculty faculty); //adds a faculty to the rear of the list

	//removes a user, student, or faculty from the list
	void removeUser(int userID);

	void displayUsers(); //displays all users in the list
	User getUser(std::string userName); //returns a user by name
	void borrowBook(std::string userName, Book book); //adds a book to a user's borrowed list
	void returnBook(std::string userName, Book book); //removes a book from a user's borrowed list
	void displayUserBooks(std::string userName); //display users borrow books.
};

#endif