// Program      :   Lab# 3.2.cpp
// Author       :   Farhad Alemi
// Due Date     :   September 20th, 2018
// Description  :   This program asks the user to input two floating-point 
//                  numbers, stores the values in a struct, adds the two values
//                  and displays the result.

#include <iostream>
using namespace std;

struct additionStruct       // The struct containing two variables of type double
{
    double first,           // first variable
           second;          // second variable
};

typedef struct additionStruct addition;         // using typedef to make struct easier
                                                // to handle

// Prototype
void getTwoNumbers(addition &var);

int main()
{
    addition calculation;                       // for storing two numbers
    double   result;                            // for storing the additon result

    getTwoNumbers(calculation);
    result = calculation.first + calculation.second;

    cout << "Result: " << result << endl;
}

// The function asks the user to input two numbers and passes the value by
// reference into a struct
void getTwoNumbers(addition &var)
{
    cout << "Please input the first floating-point number: ";
    cin >> var.first;
    cout << "Please input the second floating-point number: ";
    cin >> var.second;
}