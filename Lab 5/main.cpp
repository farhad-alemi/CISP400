// Program      :   Lab# 5.cpp
// Author       :   Farhad Alemi
// Due Date     :   October 5th, 2018
// Description  :   This project simulates the operation of a simple heating system.
//                  It uses two classes Thermostat and HeatingSystem and provides
//                  the user with a list of choices based on which the system operates.

#include "Thermostat.h"             // the main header file for the project

int main()
{
    int currentTemp,                // current temperature of the system
        desiredTemp,                // desired temperature of the system
        userOption;                 // user's menu option

    cout << "Enter initial temperature:" << endl;
    cin >> currentTemp;
    cout << "Enter initial desired temperature:" << endl;
    cin >> desiredTemp;
    cout << endl << endl << endl;

    // creation of a pointer to an object of type Thermostat
    Thermostat* mainSystem = new Thermostat(desiredTemp, currentTemp);

    do
    {
        cout << endl;
        userOption = displayMenu();             // call to the menu function

        switch (userOption)
        {
            case 1:
                // displaying current temperature
                cout << "THERMOSTAT REPORT: Current temperature: " 
                    << mainSystem->getCurrentTemp() << endl;

                // displaying desired temperature
                cout << "THERMOSTAT REPORT: Desired temperature: "
                    << mainSystem->getDesiredTemp() << endl;

                // displaying heating system status
                mainSystem->getHeatingSystem()->getStatus();
                break;
            case 2:
                // displaying current temperature
                cout << "Current temperature is: " << mainSystem->getCurrentTemp()
                    << endl;

                // displaying current temperature
                cout << "Current desired temperature is: " << mainSystem->getDesiredTemp()
                    << endl;

                // input for a new desired temperature
                cout << "Enter new desired temperature:" << endl;
                cin >> desiredTemp;
                
                // updating desired temperature
                mainSystem->setDesiredTemp(desiredTemp);
                cout << "Current temperature is " << mainSystem->getCurrentTemp()
                    << endl;

                // updating heating system's operation mode
                mainSystem->setMode();
                break;
            case 3:
                cout << "THERMOSTAT: Simulating time passing... setting current" 
                    << " temperature to desired temperature.";

                // assigning the value of the desired temperature
                // to that of the current temperature
                mainSystem->setCurrentTemp(desiredTemp);
                break;
        }
    }
    while (userOption != EXIT_OPTION);

    // deleting the pointer to the object of type Thermostat
    delete mainSystem;
}

// The function displays the menu choices on the screen and
// returns the validated menu option.
int displayMenu()
{
    int userOption;             // user's menu option
    do
    {
        cout << "MAIN MENU:" << endl;
        cout << "1 - See system status" << endl;
        cout << "2 - Set temperature goal" << endl;
        cout << "3 - Simulate time passing" << endl;
        cout << "4 - Exit program" << endl;
        cout << "Input choice:" << endl;
        cin >> userOption;
    }
    while (userOption != 1 && userOption != 2 && userOption != 3 && userOption != 4);
    
    return userOption;
}