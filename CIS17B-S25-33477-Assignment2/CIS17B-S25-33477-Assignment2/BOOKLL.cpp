#include "BOOKLL.h"

#include <iostream>
#include <exception>

BookLL::BookLL()
{
	head = nullptr;
}

BookLL::~BookLL()
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

int BookLL::size()
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

void BookLL::addToFront(Book book)
{
	Node* tempN;
	tempN = new Node;
	tempN->_book = book;

	tempN->next = head;
	head = tempN;
}

void BookLL::addToRear(Book book)
{
	if (head == nullptr) //checks if list is empty
	{
		addToFront(book);
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
		tempN->_book = book;
		tempP->next = tempN;

		tempN->next = nullptr;
	}
}

void BookLL::removeBook(int ISBN)
{
	//check if list is empty
	if (head == nullptr)
	{
		std::cout << "no books in the library!" << std::endl;
		return;
	}

	//check if book is found in head pointer
	if (head->_book.getISBN() == ISBN) //ISBN is easier to use here
	{
		Node* destroy = head;
		head = destroy->next;
		delete destroy;
		return;
	}

	//traversing the list until we find the book
	Node* tempN = head;
	while (tempN != nullptr)
	{
		if (tempN->next != nullptr && tempN->next->_book.getISBN() == ISBN)
		{
			break;
		}
		tempN = tempN->next;
	}

	//When the book is found, delete the node
	if (tempN != nullptr)
	{
		Node* destroy = tempN->next;
		tempN->next = destroy->next; //sets next pointer to node after if there is one
		delete destroy;
	}
	if (tempN == nullptr)
	{
		std::cout << "book not found!" << std::endl;
	}
}

void BookLL::displayBooks()
{
	if (head == nullptr)
	{
		std::cout << "no books!" << std::endl;
	}
	Node* tempN;
	tempN = head; //points to first node
	while (tempN != nullptr) //prints out books until end of list
	{
		std::cout << "Title: " << tempN->_book.getTitle() << std::endl;
		std::cout << "Author: " << tempN->_book.getAuthor() << std::endl;
		std::cout << "ISBN: " << tempN->_book.getISBN() << std::endl;
		std::cout << "Availabilty: " << tempN->_book.getAvailability() << std::endl;
		std::cout << "--------------------" << std::endl;
		tempN = tempN->next;
	}
}

void BookLL::displayBookTitle(std::string title) //search by title
{
	bool found = false; //flag to check if book is found in loop
	if (head == nullptr)
	{
		std::cout << "no books in the library" << std::endl;
	}
	if (head->_book.getTitle() == title)
	{
		std::cout << "Title: " << head->_book.getTitle() << std::endl;
		std::cout << "Author: " << head->_book.getAuthor() << std::endl;
		std::cout << "ISBN: " << head->_book.getISBN() << std::endl;
		std::cout << "Availabilty: " << head->_book.getAvailability() << std::endl;
		std::cout << "--------------------" << std::endl;
		found = true;
	}

	Node* tempN;
	tempN = head;
	while (tempN != nullptr)
	{
		if (tempN->next != nullptr && tempN->next->_book.getTitle() == title)
		{
			break;
		}
		tempN = tempN->next;
	}
	if (tempN != nullptr)
	{
		std::cout << "Title: " << tempN->_book.getTitle() << std::endl;
		std::cout << "Author: " << tempN->_book.getAuthor() << std::endl;
		std::cout << "ISBN: " << tempN->_book.getISBN() << std::endl;
		std::cout << "Availabilty: " << tempN->_book.getAvailability() << std::endl;
		std::cout << "--------------------" << std::endl;
		found = true;
	}
	if (!found)
	{
		std::cout << "book not found!" << std::endl;
	}

}

void BookLL::displayBookAuthor(std::string author)
{
	bool found = false; //flag to check if book is found in loop
	if (head == nullptr)
	{
		std::cout << "no books in the library" << std::endl;
	}
	if (head->_book.getAuthor() == author)
	{
		std::cout << "Title: " << head->_book.getTitle() << std::endl;
		std::cout << "Author: " << head->_book.getAuthor() << std::endl;
		std::cout << "ISBN: " << head->_book.getISBN() << std::endl;
		std::cout << "Availabilty: " << head->_book.getAvailability() << std::endl;
		std::cout << "--------------------" << std::endl;
		found = true;
	}

	Node* tempN;
	tempN = head;
	while (tempN != nullptr)
	{
		if (tempN->next != nullptr && tempN->next->_book.getAuthor() == author)
		{
			break;
		}
		tempN = tempN->next;
	}
	if (tempN != nullptr)
	{
		std::cout << "Title: " << tempN->_book.getTitle() << std::endl;
		std::cout << "Author: " << tempN->_book.getAuthor() << std::endl;
		std::cout << "ISBN: " << tempN->_book.getISBN() << std::endl;
		std::cout << "Availabilty: " << tempN->_book.getAvailability() << std::endl;
		std::cout << "--------------------" << std::endl;
		found = true;
	}
	if (!found)
	{
		std::cout << "book not found!" << std::endl;
	}

}

Book BookLL::getBook(std::string title)
{
	if (head == nullptr)
	{
		std::cout << "no books in the library" << std::endl;
		throw std::exception("no books in the library");
	}
	Node* tempN;
	tempN = head;
	if (tempN->_book.getTitle() == title)
	{
		return tempN->_book;
	}
	while (tempN != nullptr)
	{
		if (tempN->next != nullptr && tempN->next->_book.getTitle() == title)
		{
			break;
		}
		tempN = tempN->next;
	}
	if (tempN != nullptr)
	{
		return tempN->_book;
	}
	if (tempN == nullptr)
	{
		std::cout << "book not found!" << std::endl;
		throw std::exception("book not found");
	}
}

void BookLL::setBoolfalse(Book book)
{
	bool found = false; // flag to check if book is found in loop
	//check if list is empty
	if (head == nullptr)
	{
		std::cout << "no books in the library!" << std::endl;
		return;
	}

	//check if book is found in head pointer
	if (head->_book.getISBN() == book.getISBN()) //ISBN is easier to use here
	{
		head->_book.setAvailability(false);
		found = true;
		return;
	}

	//traversing the list until we find the book
	Node* tempN = head;
	while (tempN != nullptr)
	{
		if (tempN->next != nullptr && tempN->next->_book.getISBN() == book.getISBN())
		{
			break;
		}
		tempN = tempN->next;
	}

	//When the book is found, delete the node
	if (tempN != nullptr)
	{
		tempN->_book.setAvailability(false);
		found = true;
	}

	if (!found) //if book not found
	{
		std::cout << "book not found!" << std::endl;
	}
}

void BookLL::setBooltrue(Book book)
{
	bool found = false; // flag to check if book is found in loop
	//check if list is empty
	if (head == nullptr)
	{
		std::cout << "no books in the library!" << std::endl;
		return;
	}

	//check if book is found in head pointer
	if (head->_book.getISBN() == book.getISBN()) //ISBN is easier to use here
	{
		head->_book.setAvailability(true);
		found = true;
		return;
	}

	//traversing the list until we find the book
	Node* tempN = head;
	while (tempN != nullptr)
	{
		if (tempN->next != nullptr && tempN->next->_book.getISBN() == book.getISBN())
		{
			break;
		}
		tempN = tempN->next;
	}

	//When the book is found, delete the node
	if (tempN != nullptr)
	{
		tempN->_book.setAvailability(true);
		found = true;
	}

	if (!found) //if book not found
	{
		std::cout << "book not found!" << std::endl;
	}
}
