#ifndef STUDENT_H //Include Guard
#define STUDENT_H

//including header files
#include "USER.h"

//derived from User class
class Student : public User
{
private:
	bool _isStudent; //bool to check if account is a student
public:
	Student(); //constructor
	Student(std::string userName, int userID); //constructor
	bool getIsStudent(); //returns if user is a student
	void setIsStudent(bool isStudent); //sets user as student
};

#endif