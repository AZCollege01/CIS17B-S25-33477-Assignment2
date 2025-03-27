#ifndef BOOKLL_H //include guard
#define BOOKLL_H

//including header files
#include "BOOK.h"

//Linked List of Books
class BookLL : public Book
{
private:
	struct Node
	{
		Book _book;
		Node* next;
	};
	Node* head;
public:
	BookLL(); //constructor
	~BookLL(); //destructor
	int size(); //returns size of book list
	void addToFront(Book book); //adds a book to the front of the list
	void addToRear(Book book); //adds a book to the rear of the list
	void removeBook(int ISBN); //removes a book by ISBN
	void displayBooks(); //displays all books in the list
	void displayBookTitle(std::string title); //displays a specific book by title
	void displayBookAuthor(std::string author); //displays a specific book by author
	Book getBook(std::string title); //returns a book by title
	void setBoolfalse(Book book); //sets the availabilty of a book in the list to false
	void setBooltrue(Book book); //sets the availabilty of a book in the list to true
};

#endif