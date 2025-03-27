#include "USERLL.h"
#include <iostream>
#include <exception>
#include "BOOK.h"

UserLL::UserLL()
{
	head = nullptr;
}

UserLL::~UserLL()
{
	Node* tempP;
	tempP = head;
	while (tempP != nullptr)
	{
		Node* tempN = tempP->next;
		delete tempP;
		tempP = tempN;
	}
}

int UserLL::size()
{
	int count = 0;
	Node* tempN;
	tempN = head; //points to the first node
	while (tempN != nullptr)
	{
		count++;
		tempN = tempN->next;
	}
	return count;
}

void UserLL::addToFront(User user)
{
	Node* tempN;
	tempN = new Node;
	tempN->_user = user;

	tempN->next = head;
	head = tempN;
}

void UserLL::addToRear(User user)
{
	if (head == nullptr) //checks if list is empty
	{
		addToFront(user);
	}
	else
	{
		Node* tempP;
		tempP = head;
		while (tempP->next != nullptr)
		{
			tempP = tempP->next;
		}
		Node* tempN = new Node;
		tempN->_user = user;
		tempP->next = tempN;

		tempN->next = nullptr;
	}
}

void UserLL::addToFront(Student student)
{
	Node* tempN;
	tempN = new Node;
	tempN->_student = student;

	tempN->next = head;
	head = tempN;
}

void UserLL::addToRear(Student student)
{
	if (head == nullptr) //checks if list is empty
	{
		addToFront(student);
	}
	else
	{
		Node* tempP;
		tempP = head;
		while (tempP->next != nullptr)
		{
			tempP = tempP->next;
		}
		Node* tempN = new Node;
		tempN->_student = student;
		tempP->next = tempN;

		tempN->next = nullptr;
	}
}

void UserLL::addToFront(Faculty faculty)
{
	Node* tempN;
	tempN = new Node;
	tempN->_faculty = faculty;

	tempN->next = head;
	head = tempN;
}

void UserLL::addToRear(Faculty faculty)
{
	if (head == nullptr) //checks if list is empty
	{
		addToFront(faculty);
	}
	else
	{
		Node* tempP;
		tempP = head;
		while (tempP->next != nullptr)
		{
			tempP = tempP->next;
		}
		Node* tempN = new Node;
		tempN->_faculty = faculty;
		tempP->next = tempN;

		tempN->next = nullptr;
	}
}

void UserLL::removeUser(int userID)
{
	//check if list is empty
	if (head == nullptr)
	{
		std::cout << "no users in the library!" << std::endl;
		return;
	}

	//check if user, student, or faculty is found in head pointer
	if (head->_user.getUserID() == userID) //UserID is easier to use here
	{
		Node* destroy = head;
		head = destroy->next;
		delete destroy;
		return;
	}
	else if (head->_student.getUserID() == userID)
	{
		Node* destroy = head;
		head = destroy->next;
		delete destroy;
		return;
	}
	else if (head->_faculty.getUserID() == userID)
	{
		Node* destroy = head;
		head = destroy->next;
		delete destroy;
		return;
	}

	//traversing the list until we find the user, student, or faculty
	Node* tempN = head;
	while (tempN != nullptr)
	{
		if (tempN->next != nullptr && tempN->next->_user.getUserID() == userID)
		{
			break;
		}
		else if (tempN->next != nullptr && tempN->next->_student.getUserID() == userID)
		{
			break;
		}
		else if (tempN->next != nullptr && tempN->next->_faculty.getUserID() == userID)
		{
			break;
		}
		tempN = tempN->next;
	}

	//When the User, sudent, or faculty is found, delete the node
	if (tempN != nullptr)
	{
		Node* destroy = tempN->next;
		tempN->next = destroy->next; //sets next pointer to node after if there is one
		delete destroy;
	}

	if (tempN == nullptr)
	{
		std::cout << "User not found!" << std::endl;
	}
}

void UserLL::displayUsers()
{
	if (head == nullptr)
	{
		std::cout << "no users in the library!" << std::endl;
	}
	Node* tempN;
	tempN = head;

	//when the node contains an object that isn't empty, display the user, student, or faculty
	while (tempN != nullptr)
	{
		if (tempN->_user.getEmpty() == false)
		{
			std::cout << "User: " << tempN->_user.getName() << std::endl;
			std::cout << "User ID: " << tempN->_user.getUserID() << std::endl;
		}
		else if (tempN->_student.getEmpty() == false)
		{
			std::cout << "Student: " << tempN->_student.getName() << std::endl;
			std::cout << "Student ID: " << tempN->_student.getUserID() << std::endl;
		}
		else if (tempN->_faculty.getEmpty() == false)
		{
			std::cout << "Faculty: " << tempN->_faculty.getName() << std::endl;
			std::cout << "Faculty ID: " << tempN->_faculty.getUserID() << std::endl;
		}

		std::cout << "--------------------" << std::endl;
		tempN = tempN->next;
	}
}

User UserLL::getUser(std::string userName)
{
	if (head == nullptr)
	{
		std::cout << "no users in the library!" << std::endl;
		throw std::exception("no users in the library!");
	}
	Node* tempN;
	tempN = head;
	if (tempN->_user.getName() == userName)
	{
		return tempN->_user;
	}
	while (tempN != nullptr)
	{
		if (tempN->next != nullptr && tempN->next->_user.getName() == userName)
		{
			break;
		}
		tempN = tempN->next;
	}
	if (tempN != nullptr)
	{
		return tempN->_user;
	}
	if (tempN == nullptr)
	{
		std::cout << "User not found!" << std::endl;
		throw std::exception("User not found!");
	}
}

void UserLL::borrowBook(std::string userName, Book book)
{
	bool found = false;
	if (head == nullptr)
	{
		std::cout << "no users!" << std::endl;
		return;
	}

	//checking if user, student, or faculty
	if (head->_user.getName() == userName)
	{
		head->_user.borrowBook(book); //calls member function with the Book Linked list in the User class
		found = true;
		return;
	}
	else if (head->_student.getName() == userName)
	{
		head->_student.borrowBook(book); //calls member function with the book Linked list in the student class
		found = true;
		return;
	}
	else if (head->_faculty.getName() == userName)
	{
		head->_faculty.borrowBook(book); //calls member function with the book Linked list in the faculty class
		found = true;
		return;
	}

	//traversing the list until we find the user, student, or faculty
	Node* tempN;
	tempN = head;
	while (tempN != nullptr)
	{
		//checking user, student, or faculty
		if (tempN->next != nullptr && tempN->next->_user.getName() == userName)
		{
			break;
		}
		else if (tempN->next != nullptr && tempN->next->_student.getName() == userName)
		{
			break;
		}
		else if (tempN->next != nullptr && tempN->next->_faculty.getName() == userName)
		{
			break;
		}
		tempN = tempN->next;
	}

	//when the user, student, or faculty is found, borrow the book
	if (tempN != nullptr && tempN->_user.getName() == userName) //debug user
	{
		tempN->_user.borrowBook(book); //calls the member function with the book Linked list in the User class
		found = true;
		return;
	}
	else if (tempN != nullptr && tempN->_student.getName() == userName) //when is student.
	{
		tempN->_student.borrowBook(book); //calls the member function with the book Linked list in the student class
		found = true;
		return;
	}
	else if (tempN != nullptr && tempN->_faculty.getName() == userName) //when is faculty
	{
		tempN->_faculty.borrowBook(book); //calls the member function with the book Linked list in the faculty class
		found = true;
		return;
	}

	if (!found)
	{
		std::cout << "User not Found!" << std::endl;
	}
}

void UserLL::returnBook(std::string userName, Book book)
{
	bool found = false;
	if (head == nullptr)
	{
		std::cout << "no users!" << std::endl;
		return;
	}

	//checking if user, student, or faculty
	if (head->_user.getName() == userName)
	{
		head->_user.returnBook(book); //calls member function with the Book Linked list in the User class
		found = true;
		return;
	}
	else if (head->_student.getName() == userName)
	{
		head->_student.returnBook(book); //calls member function with the book Linked list in the student class
		found = true;
		return;
	}
	else if (head->_faculty.getName() == userName)
	{
		head->_faculty.returnBook(book); //calls member function with the book Linked list in the faculty class
		found = true;
		return;
	}

	Node* tempN;
	tempN = head;

	//traversing the list until we find the user, student, or faculty
	while (tempN != nullptr)
	{
		if (tempN->next != nullptr && tempN->next->_user.getName() == userName)
		{
			break;
		}
		else if (tempN->next != nullptr && tempN->next->_student.getName() == userName)
		{
			break;
		}
		else if (tempN->next != nullptr && tempN->next->_faculty.getName() == userName)
		{
			break;
		}
		tempN = tempN->next;
	}

	//when the user, student, or faculty is found, return the book
	if (tempN != nullptr && tempN->_user.getName() == userName)
	{
		tempN->_user.returnBook(book); //calls member function with the book Linked list in the User class
		found = true;
		return;
	}
	else if (tempN != nullptr && tempN->_student.getName() == userName)
	{
		tempN->_student.returnBook(book); //calls member function with the book Linked list in the student class
		found = true;
		return;
	}
	else if (tempN != nullptr && tempN->_faculty.getName() == userName)
	{
		tempN->_faculty.returnBook(book); //calls member function with the book Linked list in the faculty class
		found = true;
		return;
	}

	if (!found)
	{
		std::cout << "User not Found!" << std::endl;
	}
}

void UserLL::displayUserBooks(std::string userName)
{
	bool found = false;
	if (head == nullptr)
	{
		std::cout << "no users!" << std::endl;
		return;
	}

	//checking if user, student, or faculty is in the head pointer
	if (head->_user.getName() == userName)
	{
		head->_user.displayBorrowedBooks(); //calls member function with the Book Linked list in the User class
		found = true;
		return;
	}
	else if (head->_student.getName() == userName)
	{
		head->_student.displayBorrowedBooks(); //calls member function with the book Linked list in the student class
		found = true;
		return;
	}
	else if (head->_faculty.getName() == userName)
	{
		head->_faculty.displayBorrowedBooks(); //calls member function with the book Linked list in the faculty class
		found = true;
		return;
	}

	Node* tempN;
	tempN = head;

	//traversing the list until we find the user, student, or faculty
	while (tempN != nullptr)
	{
		if (tempN->next != nullptr && tempN->next->_user.getName() == userName)
		{
			break;
		}
		else if (tempN->next != nullptr && tempN->next->_student.getName() == userName)
		{
			break;
		}
		else if (tempN->next != nullptr && tempN->next->_faculty.getName() == userName)
		{
			break;
		}
		tempN = tempN->next;
	}

	//when the user, student, or faculty is found, display the borrowed books
	if (tempN != nullptr && tempN->_user.getName() == userName)
	{
		tempN->_user.displayBorrowedBooks(); //calls the member function with the book Linked list in the User class
		found = true;
		return;
	}
	else if (tempN != nullptr && tempN->_student.getName() == userName)
	{
		tempN->_student.displayBorrowedBooks(); //calls the member function with the book Linked list in the student class
		found = true;
		return;
	}
	else if (tempN != nullptr && tempN->_faculty.getName() == userName)
	{
		tempN->_faculty.displayBorrowedBooks(); //calls the member function with the book Linked list in the faculty class
		found = true;
		return;
	}

	if (!found)
	{
		std::cout << "User not Found!" << std::endl;
	}
}
