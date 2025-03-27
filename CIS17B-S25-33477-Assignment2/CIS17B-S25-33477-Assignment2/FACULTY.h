#ifndef FACULTY_H
#define FACULTY_H

//including header files
#include "USER.h"

//derived from User class
class Faculty : public User
{
private:
	bool _isFaculty; //bool to check if account is faculty
public:
	Faculty(); //constructor
	Faculty(std::string userName, int userID); //constructor
	bool getIsFaculty(); //returns if user is faculty
	void setIsFaculty(bool isFaculty); //sets user as faculty
};

#endif