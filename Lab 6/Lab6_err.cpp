// Program      :   Lab# 6.cpp
// Author       :   Farhad Alemi
// Due Date     :   October 12th, 2018
// Description  :   This program is an exercise intended to allow the programmer
//                  to work with many of the object interaction programming
//                  techniques.
//                  This program keeps track of the number of hours a worker 
//                  has worked.

#include <iostream>
#include <string>

using namespace std;

// constants
const int JANE_HOURS = 30, JIM_HOURS = 20, SETTER_HOURS = 40;
const double SETTER_DAYS = 3.0, HOURS_PER_DAY = 24.0;

// This versatile class makes use of multiple constructors
// and operators' overloading to perform various operations.
// It also assigns an external function as a friend to itself.
class WorkerHours
{
private:
    int hoursWorked;            // number of hours worked
    double daysWorked;          // number of days worked
    int copies;                 // number of copies of a specific object

public:
    // constructors
    WorkerHours();
    WorkerHours(int hours);
    WorkerHours(const WorkerHours &object);

    // overloaded function
    void setData(int hoursWorked);
    void setData(double daysWorked);
    
    // operator overloading
    friend WorkerHours operator+(WorkerHours a, WorkerHours b);
    friend WorkerHours& operator+=(WorkerHours &a);

    // type conversion operators
    operator double() const;
    operator int() const;

    // a stand-alone external function which is friend to the current class
    friend void showInternalData(string label, const WorkerHours &worker);
};


// The default constructor which sets the member
// variables hoursWorked and copies to 0.
WorkerHours::WorkerHours()
{
    hoursWorked = 0;
    copies = 0;
}

// Convert constructor which takes a parameter of type
// int and updates the member variables hoursWorked and
// daysWorked besides setting copies to 0.
WorkerHours::WorkerHours(int hours)
{
    hoursWorked = hours;                            // updating the member variable
    daysWorked = static_cast<double>(hours) / 24;   // converting hours to days
    copies = 0;
}

// The copy constructor which assigns the member variable
// copies to the current object's value of the instance
// variable + 1.
WorkerHours::WorkerHours(const WorkerHours &object)
{
    copies = object.copies + 1;                     // updates the copies variable

    hoursWorked = object.hoursWorked;               // copies the number of hours
                                                    // worked to the new object
}

// This overloaded function assigns the variable
// hoursWorked to the local variable.
void WorkerHours::setData(int hoursWorked)
{
    this->hoursWorked = hoursWorked;
}

// This overloaded function converts the parameter
// of type double to int and calls the setData(int hoursWorked)
// function.
void WorkerHours::setData(double daysWorked)
{
    setData(static_cast<int>(daysWorked * 24));     // multiplication by 24 
                                                    // converts days to hours
}

// defining the (+) overloaded operator
WorkerHours operator+(WorkerHours a, WorkerHours b)
{
    return WorkerHours(a.hoursWorked + b.hoursWorked);
}

// defining the (+=) overloaded operator
WorkerHours& operator+=(const WorkerHours &a)   // note that a is passed by reference
{
    a.hoursWorked = a.hoursWorked + a.hoursWorked;                 // updates a.hoursWorked
    return *this;
}

// type conversion operator for type double
WorkerHours::operator double() const
{
    return daysWorked;
}

// type conversion operator for type int
WorkerHours::operator int() const
{
    return hoursWorked;
}


// This is the prototype of the showInternalData function.
// It must access INTERNAL STRUCTURES in the worker object.
// Do NOT use member functions to get the data for that object.

void showInternalData(string label, const WorkerHours &worker);

int main()
{
	// Conversion constructor
	WorkerHours jane = JANE_HOURS, jim = JIM_HOURS;
	// Copy constructor
	WorkerHours janeCopy = jane;
	// + operator and copy constructor
	WorkerHours combined = jane + jim;
	// Default constructor
	WorkerHours testSetters;

	// Variables set aside for calculations
	double daysWorked;
	int hoursWorked;

	// You can use static_cast here, but it shouldn't be required.
	// static_cast<double>(combined);

	// Type conversion operator - int
	daysWorked = combined;
	cout << "TEST DAYS WORKED : " << daysWorked << endl;

	// You can use static_cast here, but it shouldn't be required.
	// static_cast<int>(combined);

	// Type conversion operator - double
	hoursWorked = combined; 
	cout << "TEST HOURS WORKED: " << hoursWorked << endl;

	// Now we start using the internal function
	showInternalData("Jane", jane);
	showInternalData("JaneCopy", janeCopy);
	showInternalData("Jim", jim);
	showInternalData("Combined", combined);

	// += operators

	jane += janeCopy;
	showInternalData("Jane + JaneCopy", jane);

	// Now we test the overloaded setters
	testSetters.setData(SETTER_HOURS);
	showInternalData("Testing int setter", testSetters);
	testSetters.setData(SETTER_DAYS);
	showInternalData("Testing double setter", testSetters);

	return 0;
}

// The function displays the content of the object being passed
// by using the friend relationship. It does so by directly accessing
// the private variables of the object.
void showInternalData(string label, const WorkerHours &worker)
{
    cout << "Data: " << label << ", Hours worked: " << worker.hoursWorked 
        << ", Copy generation: " << worker.copies << endl;
}