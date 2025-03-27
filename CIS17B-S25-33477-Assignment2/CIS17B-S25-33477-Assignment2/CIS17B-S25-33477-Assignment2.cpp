// CIS17B-S25-33477-Assignment2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Author: Aaron Zamora

//Including Header files
#include <iostream>
#include <string>
#include "LIBRARY.h"
#include <exception>
using namespace std;

//Start of the program
int main()
{
    //declaring vairables
    int choice;
    int subChoice;
    string userName;
    string bookInput;
    int inputID;
    int userType;

    //This while loop handles the main menu for user interface.
    while (true) {
        cout << "Welcome to the Library!" << endl;
        cout << "1. Manage Users" << endl;
        cout << "2. Add or Remove Books" << endl;
        cout << "3. Search for Books" << endl;
        cout << "4. Borrow or Return Books" << endl;
        cout << "5. Exit" << endl;

        try //error checking for user choice input for menu
        {
            cin >> choice; //user input for main menu choice
            if (cin.fail())
            {
                throw exception(); //thows if not an integer
            }
        }
        catch(exception)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clears the input buffer
        }

        //This switch handles options in the Main Menu
        switch (choice) {

        case 1: //Manage Users
            //Users Sub-Menu
            while (true) {
                cout << "> Manage Users:" << endl;
                cout << "> 1. Add a User" << endl;
                cout << "> 2. Remove a User" << endl;
                cout << "> 3. User Details" << endl;
                cout << "> 4. Go Back" << endl;

                try //error checking for subChoice input for sub-menu
                {
                    cin >> subChoice; //user input for sub-menu
                    if (cin.fail())
                    {
                        throw exception();//throws if not an integer
                    }
                }
                catch (exception)
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clears the input buffer
                }

                //This switch handles options in the Book Sub-Menu
                switch (subChoice) {

                case 1://Add a User

                    //accessing Library class to add a user
                    cout << "Enter first name only: ";
                    cin >> userName;

                    while (true) //error checking input for ID
                    {
                        cout << "Enter your ID for the account: ";
                        cin >> inputID;
                        if (cin.fail())
                        {
                            cout << "Invalid input. Please enter a number." << endl;
                            cout << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clears the input buffer
                        }
                        else
                        {
                            break;
                        }
                    }

                    while (true) //error checking input for user type
                    {
                        cout << "Are you a student or faculty?" << endl;
                        cout << "1 for studnet, 2 for faculty" << endl;
                        cin >> userType;

                        //error checking for user type for user creation
                        if (cin.fail())
                        {
                            cout << "Invalid input. Please enter 1 or 2." << endl;
                            cout << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clears the input buffer
                        }
                        else if (userType < 1)
                        {
                            cout << "Invalid input. Please enter 1 or 2." << endl;
                            cout << endl;
                            cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clears the input buffer
                        }
                        else if (userType > 2)
                        {
                            cout << "Invalid input. Please enter 1 or 2." << endl;
                            cout << endl;
                            cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clears the input buffer
                        }
                        else
                        {
                            break;
                        }
                    }
                    if (userType == 1)
                    {
                        Library::getLibrary().addUser(userName, inputID, userType); //creates user with student class
                        cout << "Student " << userName << " has been added to the Library!" << endl;
                    }
                    else if (userType == 2)
                    {
                        Library::getLibrary().addUser(userName, inputID, userType); //creates user with faculty class
                        cout << "Faculty " << userName << " has been added to the Library!" << endl;
                    }
                    //Library::getLibrary().addUser(userName, inputID); //debugging, only creates user class
                    cout << endl;
                    break;

                case 2://Remove a User

                    //accessing Library class to remove a uesr
                    cout << "Enter the first name of the user you want to remove: ";
                    cin >> userName;

                    while (true) //error checking input for ID
                    {
                        cout << "Enter the ID of the user you want to remove: ";
                        cin >> inputID;
                        if (cin.fail())
                        {
                            cout << "Invalid input. Please enter a number." << endl;
                            cout << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clears the input buffer
                        }
                        else
                        {
                            break;
                        }
                    }

                    while (true) //error checking input for user type
                    {
                        cout << "Are you a student or faculty?" << endl;
                        cout << "1 for studnet, 2 for faculty" << endl;
                        cin >> userType;
                        if (cin.fail() && userType < 0)
                        {
                            cout << "Invalid input. Please enter 1 or 2." << endl;
                            cout << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clears the input buffer
                        }
                        else
                        {
                            break;
                        }
                    }

                    Library::getLibrary().removeUser(inputID);
                    cout << userName << " has been removed from the Library!" << endl;
                    cout << endl;
                    break;

                case 3://displays users

                    //accessing Library class to display users
                    Library::getLibrary().displayAllUsers();
                    cout << endl;
                    break;

                case 4://Back to Library Menu

                    cout << "Returning back Library Menu" << endl;
                    cout << endl;
                    break;

                default://error checking user choice
                    cout << "Invalid choice. Please select from 1-4." << endl;
                    cout << endl;
                    break;
                }
                //if user selects 4, it breaks out of the loop
                if (subChoice == 4) {
                    subChoice = 0;
                    choice = 0;
                    break;
                }
            }
            break;// stops managing users sub-menu loop

        case 2: //Add or Remove Books
            //Add or remove Books sub-menu
            while (true) {
                cout << "> Add or Remove Books" << endl;
                cout << "> 1. Add Books" << endl;
                cout << "> 2. Remove Books" << endl;
                cout << "> 3. Display Books" << endl;
                cout << "> 4. Go Back" << endl;

                try //error checking for subChoice input for sub-menu
                {
                    cin >> subChoice; //user input for sub-menu
                    if (cin.fail())
                    {
                        throw exception();//throws if not an integer
                    }
                }
                catch (exception)
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clears the input buffer
                }

                switch (subChoice) {
                case 1://Add Books

                    //accessing Library class to add a book
                    cout << "Enter Title of the book: ";
                    cin >> userName;
                    cout << "Enter Author of the book: ";
                    cin >> bookInput;

                    while (true) //error checking input for ISBN
                    {
                        cout << "Enter ISBN of the book: ";
                        cin >> inputID;
                        if (cin.fail())
                        {
                            cout << "Invalid input. Please enter a number." << endl;
                            cout << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clears the input buffer
                        }
                        else
                        {
                            break;
                        }
                    }

                    Library::getLibrary().addBook(userName, bookInput, inputID);
                    cout << userName << " has been added to the Library!" << endl;
                    cout << endl;
                    break;

                case 2://Remove Books

                    //accessing Library class to remove a book

                    while (true) //error checking input for ISBN
                    {
                        cout << "Enter the ISBN of the book you want to remove: ";
                        cin >> inputID;
                        if (cin.fail())
                        {
                            cout << "Invalid input. Please enter a number." << endl;
                            cout << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clears the input buffer
                        }
                        else
                        {
                            break;
                        }
                    }

                    Library::getLibrary().removeBook(inputID);
                    cout << userName << " has been removed from the Library!" << endl;
                    cout << endl;
                    break;

                case 3://Display Books

                    Library::getLibrary().displayBooks();
                    cout << endl;
                    break;

                case 4://Back to Library Menu

                    cout << "Returning back to Library Menu" << endl;
                    cout << endl;
                    break;

                default://error checking user choice

                    cout << "Invalid choice. Please select from 1-4." << endl;
                    cout << endl;
                    break;

                }
                if (subChoice == 4) { //breaks out of the loop when user enters 4
                    subChoice = 0;
                    choice = 0;
                    break;
                }
            }
            break; //stops add or remove books sub-menu loop

        case 3: //Search for Books
            while (true) {
                cout << "> Search for Books" << endl;
                cout << "> 1. Search by Tittle" << endl;
                cout << "> 2. Search by Author" << endl;
                cout << "> 3. Go Back" << endl;

                try //error checking for subChoice input for sub-menu
                {
                    cin >> subChoice; //user input for sub-menu
                    if (cin.fail())
                    {
                        throw exception();//throws if not an integer
                    }
                }
                catch (exception)
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clears the input buffer
                }

                switch (subChoice) {

                case 1://Search by Title

                    //accessing library class to search for a book by title
                    cout << "Enter the title of the book you want to search for: ";
                    cin >> userName;
                    Library::getLibrary().searchBookTitle(userName);
                    cout << endl;
                    break;

                case 2://Search by Auhtor

                    //accessing library class to search for book by author
                    cout << "Enter the author of the book you want to search for: ";
                    cin >> userName;
                    Library::getLibrary().searchBookAuthor(userName);
                    cout << endl;
                    break;

                case 3://Back to Library Menu

                    cout << "Returning back to Library Menu" << endl;
                    cout << endl;
                    break;

                default://error checking user choice

                    cout << "Invalid choice. Please select from 1-3." << endl;
                    cout << endl;
                    break;

                }
                if (subChoice == 3) {//breaks out of the loop when user enters 3
                    subChoice = 0;
                    choice = 0;
                    break;
                }
            }
            break;// stops search for books sub-menu loop

        case 4://Borrow or Return Books
            while (true) {
                cout << "> Borrow or Return Books" << endl;
                cout << "> 1. Borrow Books" << endl;
                cout << "> 2. Return Books" << endl;
                cout << "> 3. Display User's Borrowed List" << endl;
                cout << "> 4. Display Book List" << endl;
                cout << "> 5. Go Back" << endl;

                try //error checking for subChoice input for sub-menu
                {
                    cin >> subChoice; //user input for sub-menu
                    if (cin.fail())
                    {
                        throw exception();//throws if not an integer
                    }
                }
                catch (exception)
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clears the input buffer
                }

                switch (subChoice) {
                case 1://Borrow Books

                    //accessing library class to borrow a book
                    cout << "Enter user name (remember it is your first name): ";
                    cin >> userName;
                    cout << "Enter the title of the book you want to borrow: ";
                    cin >> bookInput;
                    Library::getLibrary().borrowBook(userName, bookInput);
                    cout << userName << " has borrowed " << bookInput << "!" << endl;
                    cout << endl;
                    break;

                case 2://Return Books

                    //accessing library class to return a book
                    cout << "Enter user name (remember it is your first name): ";
                    cin >> userName;
                    cout << "Enter the title of the book you want to return: ";
                    cin >> bookInput;
                    Library::getLibrary().returnBook(userName, bookInput);
                    cout << userName << " has returned " << bookInput << "!" << endl;
                    cout << endl;
                    break;

                case 3://display user's borrowed list

                    //accessing library class to display user's borrowed list
                    cout << "Enter user name (remember it is your first name): ";
                    cin >> userName;
                    Library::getLibrary().displayUserBooks(userName);
                    cout << endl;
                    break;

                case 4://display book list

                    //accessing library class to display book list
                    Library::getLibrary().displayBooks();
                    cout << endl;
                    break;

                case 5://Back to Library Menu

                    cout << "Returning back to Library Menu" << endl;
                    cout << endl;
                    break;

                default://error checking user choice

                    cout << "Invalid choice. Please select from 1-5." << endl;
                    cout << endl;
                    break;

                }
                if (subChoice == 5) { //breaks out of the loop when user enters 5
                    subChoice = 0;
                    choice = 0;
                    break;
                }
            }
            break;// stops borrow or return books sub-menu loop

        case 5://Exits the program

            cout << "Thanks for using the Library!" << endl;
            cout << endl;
            break;

        default://error checking with user choie

            cout << "Invalid choice. Please select from 1-5." << endl;
            cout << endl;
            break;

        }
            if (choice == 5) { //breaks out of loop when user enters 4
                break;
        }
    }
    return 0;
}
