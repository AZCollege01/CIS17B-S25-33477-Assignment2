#include "FACULTY.h"

Faculty::Faculty() {
	addName(" ");
	addUserID(0);
	_isFaculty = false;
	setEmpty(true);
}

Faculty::Faculty(std::string userName, int userID)
{
	addName(userName);
	addUserID(userID);
	_isFaculty = true;
	setEmpty(false);
}

bool Faculty::getIsFaculty() {
	return _isFaculty;
}

void Faculty::setIsFaculty(bool isFaculty) {
	_isFaculty = isFaculty;
}