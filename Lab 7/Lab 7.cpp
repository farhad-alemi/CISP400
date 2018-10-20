// Program      :   Lab# 7.cpp
// Author       :   Farhad Alemi
// Due Date     :   October 18th, 2018
// Description  :   The program asks the user to input a theater ticket or
//                  package info by giving them a menu choice. It does so by
//                  making the Package class a subclass of the Ticket class.
//                  The program also uses overloaded operator to display object 
//                  content.

#include <iostream>
#include <string>

#define EXIT_OPTION 3                        // the main menu exit option

using namespace std;

// The class stores data for movieName and movie runTime
// by utilizing setter and getter methods. It also has a
// friend overloaded operator to display object content.
class Ticket
{
private:
    string movieName;                        // name of the movie in the ticket
    int    runTime;                          // runtime of the movie in the ticket

public:
    // construtor
    Ticket(string movieName, int runTime);

    //getter methods
    string getMovieName();
    int getRunTime();

    // setter methods
    void setMovieName(string movieName);
    void setRunTime(int runTime);

    // friend overloaded operator
    friend ostream &operator <<(ostream &s, Ticket &obj);
};


// This class is a subclass of the Ticket class. In addition
// to the functionality of its parent class, it also stores
// snackName and has a friend overloaded operator.
class Package : public Ticket
{
private:
    string snackName;                        // name of the snack in the package

public:
    // constructor
    Package(string movieName, int runTime, string snackName);

    // getter method
    string getSnackName();

    // setter method
    void setSnackName(string snackName);

    // friend overloaded operator
    friend ostream &operator <<(ostream &s, Package &obj);
};


// stand-alone function prototypes
int displayMenu();
void inputTicketData(string &movieName, int &runTime);
void inputPackageData(string &movieName, int &runTime, string &snackName);


// The constructor for the Ticket class which uses an initializer list
// to assign member variables.
Ticket::Ticket(string movieName, int runTime) : movieName(movieName), runTime(runTime)
{}

// This function returns the value of the movieName variable
string Ticket::getMovieName()
{
    return movieName;
}

// This function returns the value of the runTime variable
int Ticket::getRunTime()
{
    return runTime;
}

// This function assigns the value of the movieName variable
// to the function parameter.
void Ticket::setMovieName(string movieName)
{
    this->movieName = movieName;
}

// This function assigns the value of the runTime variable
// to the function parameter.
void Ticket::setRunTime(int runTime)
{
    this->runTime = runTime;
}

// The friend overloaded operator, <<, which can be used to
// output to cout or other files.
ostream &operator <<(ostream &s, Ticket &obj)
{
    cout << "Movie: " << obj.getMovieName() << endl;
    cout << "Run Time: " << obj.getRunTime() << endl;
    return s;                                // returns stream variable
}


// The constructor for the Package class which uses an initializer list
// to assign member variables besides calling the constructor for the Ticket 
// class.
Package::Package(string movieName, int runTime, string snackName) : 
    Ticket(movieName, runTime), snackName(snackName)
{}
 
// This function returns the value of the snackName variable.
string Package::getSnackName()
{
    return snackName;
}

// This function assigns the value of the snackName variable
// to the function parameter.
void Package::setSnackName(string snackName)
{
    this->snackName = snackName;
}

// The friend overloaded operator, <<, which can be used to
// output to cout or other files.
ostream &operator <<(ostream &s, Package &obj)
{
    cout << "Movie: " << obj.getMovieName() << endl;
    cout << "Run Time: " << obj.getRunTime() << endl;
    cout << "Snack: " << obj.getSnackName() << endl;
    return s;                                // returns stream variable
}


int main()
{
    int    userOption,                       // user's menu choice
           runTime;                          // the run-time for the movie
    string movieName,                        // name of the movie
           snackName;                        // name of the snack 

    do
    {
        userOption = displayMenu();          // call to the menu function which
                                             // returns a validated menu choice
        switch (userOption)                  // the extra curly braces are for limiting
                                             // the scope of variables
        {
            case 1:
            {
                // grabs input data from user
                inputTicketData(movieName, runTime);

                // creates an object of type Ticket using dynamic memory allocation
                Ticket* ticket = new Ticket("N/A", 0);

                // setter functions for updating object members
                ticket->setMovieName(movieName);
                ticket->setRunTime(runTime);

                // using the friend overloaded operator to display object content
                cout << endl << *ticket << endl;

                // deallocating the pointer
                delete ticket;

                break;
            }  
            case 2:
            {
                // grabs input data from user
                inputPackageData(movieName, runTime, snackName); 
                
                // creates an object of type Package using dynamic memory allocation
                Package* package = new Package("N/A PACKAGE", 0, "NONE");
                
                // setter functions for updating object members
                package->setMovieName(movieName);
                package->setRunTime(runTime);
                package->setSnackName(snackName);

                // using the friend overloaded operator to display object content
                cout << endl << *package << endl;
                
                // deallocating the pointer
                delete package;

                break;
            }
        }
    }
    while (userOption != EXIT_OPTION);
}

// The function displays the menu choices and returns a validated menu choice
int displayMenu()
{
    int  userOption;                    // for storing user's menu choice
    bool valid;                         // temp. variable useful in loop validation

    do
    {
        valid = true;                   // giving the user a new chance
        cout << "Main Menu:" << endl;
        cout << "1 - Input Data for Ticket" << endl;
        cout << "2 - Input Data for Package" << endl;
        cout << EXIT_OPTION << " - Exit" << endl;
        cout << "Make Your Choice: ";
        cin >> userOption;

        if (userOption != 1 && userOption != 2 && userOption != EXIT_OPTION)
        {
            cout << "Invalid Selection!" << endl << endl;
            valid = false;              // the user has made an invalid choice.
        }
    }
    while (!valid);

    return userOption;
}

// The function gets input for movieName and runTime variables.
void inputTicketData(string &movieName, int &runTime)
{
    cout << endl;
    cout << "Enter Movie Name: ";
    cin >> movieName;
    cout << "Enter Movie Run-Time: ";
    cin >> runTime;
}

// The function gets input for movieName, runTime, and snackName variables.
void inputPackageData(string &movieName, int &runTime, string &snackName)
{
    // call to inputTicketData function for getting movieName and runTime
    inputTicketData(movieName, runTime);

    cout << "Enter Snack Name: ";
    cin >> snackName;
}