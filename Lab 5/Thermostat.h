#ifndef _THERMOSTAT_SYSTEM_H
#define _THERMOSTAT_SYSTEM_H

#define EXIT_OPTION 4                   // main menu exit option

#include <iostream>
using namespace std;

// The enumerator structure containing the possible status
// options for the heating system
enum HeatingStatus {Inactive, Active};

// This class simulates the functions of a heating system.
// It uses the enum structure to configure the system status.
class HeatingSystem
{
public:
    HeatingSystem();
    void getStatus();
    void setStatus(HeatingStatus status);
    ~HeatingSystem();

private:
    HeatingStatus status;               // the status of the heating system (on / off)
};

// This class simulates the functions of a thermostat.
// It accesses the HeatingSystem class through a pointer
// to an object of that class. Its member variables also
// store the current and desired temperatures.
class Thermostat
{
public:
    Thermostat(int desiredTemp, int currentTemp);
    int getCurrentTemp();
    int getDesiredTemp();
    void setDesiredTemp(int desiredTemp);
    void setCurrentTemp(int currentTemp);
    void setMode();
    HeatingSystem* getHeatingSystem();
    ~Thermostat();

private:
    int            currentTemp,         // current temperature of the system
                   desiredTemp;         // desired temperature of the system
    HeatingSystem* systemStatus;        // status of the heating system
};

// function prototype(s)
int displayMenu();

#endif