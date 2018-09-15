// Author       :   Farhad Alemi
// Instructor   :   Professor Michael Pope
// Project      :   Lab# 2
// Due Date     :   September 13th, 2018

#include <iostream>         // needed for basic I/O
#include <iomanip>          // needed for formatting functions like setw()
using namespace std;

// Function prototypes
void subtractNumbers();
double calculateSubtraction(double firstNumber, double secondNumber);
void countingArray();
void multiplicationTable();
void castToShort();
void runCountdown();
void arrayCountdown(int *outputArray, int elements);

int main()
{
    int  userOption;                // the variable used to store menu choice
    bool valid;                     // indicates whether the user has entered a
                                    // valid input

    do                              // the main loop for program reiteration
    {
        do                          // user input validation loop
        {
            valid = true;           // resets input condition

            cout << "1) Subtract Numbers" << endl;
            cout << "2) Counting Array" << endl;
            cout << "3) Multiplication Table" << endl;
            cout << "4) Cast Double to Short" << endl;
            cout << "5) Count Down Array" << endl;
            cout << "6) Quit" << endl;
            cin >> userOption;

            if (userOption != 1 && userOption != 2 && userOption != 3 && userOption
            != 4 && userOption != 5 && userOption != 6)
            {
                valid = false;
                cout << "Please enter a valid input." << endl << endl;
            }
        }
        while (!valid);

        switch (userOption)         // switch structure for menu choices
        {
        case 1:
            subtractNumbers();
            break;
        case 2:
            countingArray();
            break;
        case 3:
            multiplicationTable();
            break;
        case 4:
            castToShort();
            break;
        case 5:
            runCountdown();
            break;
        }
    }
    while(userOption != 6);
}

//
// The function asks the user for input and then passes this input
// to other function, and then displays the result.
//
void subtractNumbers()
{
    double firstNumber,             // first number input by the user
           secondNumber,            // second number input by the user
           subtractionResult;       // subtraction result

    cout << "Please input the first floating point number: ";
    cin >> firstNumber;
    cout << "Please input the second floating point number: ";
    cin >> secondNumber;

    subtractionResult = calculateSubtraction(firstNumber, secondNumber);
    cout << firstNumber << " - " << secondNumber << " = " 
        << subtractionResult << endl << endl;
}

//
// The function calculates the subtraction result and returns the final value
//
double calculateSubtraction(double firstNumber, double secondNumber)
{
    return (firstNumber - secondNumber);
}

//
// The function asks the user to input numbers, and then it stores those numbers
// in an int array. It keeps asking the user to input numbers until the user inputs
// 'N' or 'n' or 10 numbers are input. Then, it displays the total count and total sum.
//
void countingArray()
{
    int  numArray[10],              // array fro storing the numbers
         counter = 0,               // number of entries
         totalSum = 0;              // total sum of the entries
    char userOption;                // the user option variable for whether to 
                                    // continue with asking for new numbers or to
                                    // end the loop

    // array initialization
    for(int i = 0; i < 10; i++)
    {
        numArray[i] = -1;
    }

    do                              // function reiteration loop
    {
        do                          // input validation loop
        {
            cout << "Do you want to enter a variable? (Y/N): ";
            cin >> userOption;

            if (userOption == 'y')
            {
                userOption = 'Y';
            }
            else if (userOption == 'n')
            {
                userOption = 'N';
            }

            if (userOption != 'Y' && userOption != 'N')
            {
                cout << "Please enter a valid input (Y/N)." << endl;
            }
        }
        while (userOption != 'Y' && userOption != 'N');
        
        if (userOption == 'Y')
        {
            cout << "Please input an integer: ";
            cin >> numArray[counter];
            counter++;
        }
    }
    while (userOption != 'N' && counter < 10);

    for (int i = 0; i < counter; i++)   // calculating sum
    {
        totalSum += numArray[i];
    }
    cout << endl << "Total Sum: " << totalSum << endl;
    cout << "Total Count: " << counter << endl;
}

//
// The function for generating a multiplication table of the its row and
// column positions
//
void multiplicationTable()
{
    int intArray [10][10];

    for (int i = 0; i < 10; i++)    // multiplication with nested loop indices
    {
        for (int j = 0; j < 10; j++)
        {
            intArray[i][j] = (i * j);
        }
    }

    for (int i = 0; i < 10; i++)    // output loops
    {
        for (int j = 0; j < 10; j++)
        {
            cout << setw(2) << intArray[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

//
// The function casts a DOUBLE number to the type SHORT and then 
// displays the result
//
void castToShort()
{
    double numberToCast;            // number to cast to the type SHORT
    short  castNumber;              // cast number

    cout << "Please input a floating point number to cast: ";
    cin >> numberToCast;

    castNumber = static_cast<short>(numberToCast);

    cout << "Cast Number: " << castNumber << endl << endl;
}

//
// The function displays a countdown of numbers using an array after 
// calling other function for array data entry
//
void runCountdown()
{
    const int COUNTDOWN_ELEMENTS = 20;      // number of elements in the array
    int numArray[COUNTDOWN_ELEMENTS];       // the countdown array
    
    arrayCountdown(numArray, COUNTDOWN_ELEMENTS);

    // output the array in reverse
    for (int i = (COUNTDOWN_ELEMENTS - 1); i >= 0; i--)     
    {
        cout << endl << setw(2) << numArray[i];
    }
    cout << endl << endl;
}

//
// The function assigns values to array using pointer notation
//
void arrayCountdown(int *outputArray, int elements)
{
    for (int i = 0; i < elements; i++)
    {
        *(outputArray + i) = i + 1;
    }
}