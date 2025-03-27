#include "STUDENT.h"

Student::Student() {
	addName(" ");
	addUserID(0);
	_isStudent = false;
	setEmpty(true);
}

Student::Student(std::string userName, int userID)
{
	addName(userName);
	addUserID(userID);
	_isStudent = true;
	setEmpty(false);
}

bool Student::getIsStudent() {
	return _isStudent;
}

void Student::setIsStudent(bool isStudent) {
	_isStudent = isStudent;
}