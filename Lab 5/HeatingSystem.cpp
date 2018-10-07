#include "Thermostat.h"                             // the main header file for the project

// This constructor announces the creation of the object
// besides initializing the system status to inactive mode
HeatingSystem::HeatingSystem()
{
    cout << "HEATING SYSTEM: Data object created. Setting to inactive mode." << endl;
    status = Inactive;                              // initializes the system mode
}

// The function outputs the private member variable
// status (its string equivalent) to the screen.
void HeatingSystem::getStatus()
{
    cout << "HEATING SYSTEM STATUS: - ";
    if (status == 0)
    {
        cout << "Inactive" << endl;
    }
    else if (status == 1)
    {
        cout << "Active" << endl;
    }
}

// The functions updates the system's operation mode
// and announces the operation on the screen.
void HeatingSystem::setStatus(HeatingStatus status)
{
    cout <<"HEATING SYSTEM: ";
    if (status == 0)
    {
        cout << "Shutting down" << endl;
    }
    else if (status == 1)
    {
        cout << "Activating!" << endl;
    }
    this->status = status;
}

// This destructor annouces the destruction of the
// object being destroyed.
HeatingSystem::~HeatingSystem()
{
    cout << "HEATING SYSTEM: Data object destroyed." << endl;
}