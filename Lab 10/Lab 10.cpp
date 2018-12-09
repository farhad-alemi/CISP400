// Program      :   Lab10.cpp
// Author       :   Farhad Alemi
// Due Date     :   December 8th, 2018
// Description  :   This is a demonstration program of how to write try-catch
//                   blocks and the basic use of the throw keyword in concert
//                   with simple programming structures.

#include <iostream>
#include <string>
#include <memory>

using namespace std;

// a very simple class which anounces the creation and deletion of
// an object
class AnnounceDestroyed
{
public:
    AnnounceDestroyed();
    ~AnnounceDestroyed();
};

// an abstract class which has a pure virtual member function. It also
// has a virtual destructor.
class ExceptionThrower
{
public:
    virtual void launchException() const = 0;
    virtual ~ExceptionThrower();
};

// subclass of ExceptionThrower which throws an exception of type
// int through launchException member function.
class IntThrower : public ExceptionThrower
{
private:
    int intVar;             // int exception value

public:
    IntThrower(int intVar);
    virtual void launchException() const;
};

// subclass of ExceptionThrower which throws an exception of type
// string through launchException member function.
class MsgThrower : public ExceptionThrower
{
private:
    string stringVar;       // string exception value

public:
    MsgThrower(string stringVar);
    virtual void launchException() const;
};

// subclass of ExceptionThrower which throws an exception of type
// CustomException through launchException member function.
class CustomThrower : public ExceptionThrower
{
private:
    string stringVar;       // string exception value
    int    intVar;          // int exception value

public:
    CustomThrower(string stringVar, int intVar);
    virtual void launchException() const;
};

// this class stores string and int exception values. It also has a 
// method for displaying the contents of the member variables.
class CustomException
{
private:
    string stringVar;       // string exception value
    int    intVar;          // int exception value

public:
    CustomException(string stringVar, int intVar);
    void printContents();
};

// helper function prototype
void activateException(const ExceptionThrower &currentThrower);

///////////////////////////////////////////////////////////////////////////////

// constructor which announces the creation of object
AnnounceDestroyed::AnnounceDestroyed()
{
    cout << "Object created." << endl;
}

// destructor which announces the deletion of object
AnnounceDestroyed::~AnnounceDestroyed()
{
    cout << "Object destroyed." << endl;
}

///////////////////////////////////////////////////////////////////////////////

// virtual destructor for ExceptionThrower class
ExceptionThrower::~ExceptionThrower()
{
}

///////////////////////////////////////////////////////////////////////////////

// constructor which assigns to the function parameter the
// private member variable.
IntThrower::IntThrower(int intVar)
{
    this->intVar = intVar;
}

// the function throws an exception of type int.
void IntThrower::launchException() const
{
    throw int(intVar);
}

///////////////////////////////////////////////////////////////////////////////

// constructor which assigns to the function parameter the
// private member variable.
MsgThrower::MsgThrower(string stringVar)
{
    this->stringVar = stringVar;
}

// the function throws an exception of type string.
void MsgThrower::launchException() const
{
    throw string(stringVar);
}

///////////////////////////////////////////////////////////////////////////////

// constructor which assigns to the function parameters the
// private member variables.
CustomThrower::CustomThrower(string stringVar, int intVar)
{
    this->stringVar = stringVar;
    this->intVar = intVar;
}

// the function throws an exception of type CustomException.
void CustomThrower::launchException() const
{
    CustomException obj(stringVar, intVar);
    throw obj;                               // throwing CustomException object
}

///////////////////////////////////////////////////////////////////////////////

// constructor which assigns to the function parameters the
// private member variables.
CustomException::CustomException(string stringVar, int intVar)
{
    this->stringVar = stringVar;
    this->intVar = intVar;
}

// display function for outputting the private member variables
void CustomException::printContents()
{
    cout << "Exception number: " << stringVar << ", Message: " << intVar << endl;
}


int main()
{
    const int    INT_THROWER_CODE = -1,                  // int exception value
                 CUSTOM_THROWER_CODE = -99;              // int exception value (for CustomException)
    const string MSG_THROWER_STRING = "Error!",          // string exception value
                 CUSTOM_THROWER_STRING = "Major error!"; // string exception value (for CustomException)
    int          exceptionCounter = 0;                   // number of occured exceptions

    // object which throws exception of type int
    IntThrower LauncherInt(INT_THROWER_CODE);

    // object which throws exception of type string
    MsgThrower LauncherMsg(MSG_THROWER_STRING);

    // object which throws exception of type CustomException
    CustomThrower LauncherCustom(CUSTOM_THROWER_STRING, CUSTOM_THROWER_CODE);

    // try-catch block for handling exception of type int
    try
    {
        cout << "Now attempting: integer exception" << endl;
        activateException(LauncherInt);

        // the following statement should never run!
        cout << "An exception did not take place" << endl; 
    }
    catch (int &intException)
    {
        cout << "Exception caught: " << intException << endl;
        exceptionCounter++;
    }

    // try-catch block for handling exception of type string
    try
    {
        cout << "Now attempting: string exception" << endl;
        activateException(LauncherMsg);

        // the following statement should never run!
        cout << "An exception did not take place" << endl;
    }
    catch (string &stringException)
    {
        cout << "Exception caught: " << stringException << endl;
        exceptionCounter++;
    }

    // try-catch block for handling exception of type CustomException
    try
    {
        cout << "Now attempting: custom exception" << endl;
        activateException(LauncherCustom);

        // the following statement should never run!
        cout << "An exception did not take place" << endl;
    }
    catch (CustomException &obj)
    {
        obj.printContents();
        exceptionCounter++;
    }

    cout << "Total exceptions caught: " << exceptionCounter << endl;
}

// helper function which calls the launchException() function in order for
// it to throw an exception.
void activateException(const ExceptionThrower &currentThrower)
{
    shared_ptr<AnnounceDestroyed> obj(new AnnounceDestroyed()); 

    currentThrower.launchException();

    // the following statement should never execute
    cout << "WARNING! \nAN EXCEPTION WAS ATTEMPTED BUT DID NOT OCCUR!" << endl;
}