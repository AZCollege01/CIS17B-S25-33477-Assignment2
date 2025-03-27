#ifndef BOOK_H // Include Guard
#define BOOK_H

//Including Header Files
#include <string>

//Book class
class Book {
private:
	std::string _title;
	std::string _author;
	int _ISBN;
	bool _availability;

public:
	//constructors
	Book();
	Book(std::string title, std::string author, int isbn);

	//member functions
	void setTitle(std::string title);
	void setAuthor(std::string author);
	void setISBN(int isbn);
	void setAvailability(bool availability);

	//get functions
	std::string getTitle();
	std::string getAuthor();
	int getISBN();
	bool getAvailability();
};

#endif