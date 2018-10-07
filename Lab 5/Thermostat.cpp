#include "Thermostat.h"                             // the main header file for the project

// This default constructor announces the creation of the object.
// It also assigns a pointer to an object of type HeatingSystem.
Thermostat::Thermostat(int desiredTemp, int currentTemp)
{
    cout << "THERMOSTAT: Object Initializing..." << endl;
    systemStatus = new HeatingSystem();             // assigning a pointer to an
                                                    // object of type HeatingSystem
    setDesiredTemp(desiredTemp);                    // updates the desired temperature
    setCurrentTemp(currentTemp);                    // updates the current temperature
    cout << "THERMOSTAT: Current temperature is " << getCurrentTemp() << endl;
    setMode();                                      // updates the heating system activation mode
    cout << endl << endl << endl;
    cout << "THERMOSTAT: Initial setup and temperature status complete, system online." << endl;
}

// The function returns the current temperature
// member variable.
int Thermostat::getCurrentTemp()
{
    return currentTemp;
}

// The function returns the desired temperature
// member variable.
int Thermostat::getDesiredTemp()
{
    return desiredTemp;
}

// The function updates the desired temperature
// member variable.
void Thermostat::setDesiredTemp(int desiredTemp)
{
    this->desiredTemp = desiredTemp;
    cout << "THERMOSTAT: User has provided a new desired temperature of " << desiredTemp << endl;
}

// The function updates the current temperature
// member variable.
void Thermostat::setCurrentTemp(int currentTemp)
{
    this->currentTemp = currentTemp;
}

// The function updates the heating system's operation
// status based on desired and current temperatures.
void Thermostat::setMode()
{
    cout << "THERMOSTAT: The current temperature is too ";
    if (currentTemp < desiredTemp)
    {
        cout << "cool, activating heating." << endl;
        systemStatus->setStatus(Active);
    }
    else if (currentTemp > desiredTemp)
    {
        cout << "hot, disabling heating." << endl;
        systemStatus->setStatus(Inactive);
    }
}

// The function returns a pointer to an object of 
// type HeatingSystem.
HeatingSystem* Thermostat::getHeatingSystem()
{
    return systemStatus;
}

// The destructor announces the destruction of the object
// being destroyed. It also deletes the pointer to the object of
// type HeatingSystem.
Thermostat::~Thermostat()
{
    cout << "THERMOSTAT: Shutting down data object." << endl;
    delete systemStatus;                            // deletes object of type HeatingSystem
    cout << "THERMOSTAT: Data object destroyed." << endl;
}