// Program      :   Lab11.cpp
// Author       :   Farhad Alemi
// Due Date     :   December 20th, 2018
// Description  :   This program provides a brief example of working with 
//                  templates and the C++ Standard Template Library(STL).

#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// class template which has a, private, vector variable of type TD. It uses
// the STL functions to sort, shuffle, and search for contents.
template <typename TD>
class DataList
{
private:
    vector<TD> data;                     // vector for holding program data

public:
    virtual ~DataList();
    void append(TD element);
    void printContents();
    void sortContents();
    void scrambleContents();
    bool isPresent(TD value);
};

// virtual destructor for DataList clas template
template <typename TD>
DataList<TD>::~DataList()
{
}

// adds elements to the data vector
template <typename TD>
void DataList<TD>::append(TD element)
{
    data.push_back(element);
}

// prints contents for the data vector
template <typename TD>
void DataList<TD>::printContents()
{
    // iterator for progressing through vector
    typename vector<TD>::iterator iter;

    for (iter = data.begin(); iter != data.end(); iter++)
    {
        cout << *iter << endl;
    }
}

// sorts the vector elements using the STL sort() function
template <typename TD>
void DataList<TD>::sortContents()
{
    sort(data.begin(), data.end());
}

// shuffles the vector elements using the STL random_shuffle() function
template <typename TD>
void DataList<TD>::scrambleContents()
{
    random_shuffle(data.begin(), data.end());   
}

// returns a bool indicating whether the function parameter has been found
// in the data vector. It uses the STL binary_search() function.
template <typename TD>
bool DataList<TD>::isPresent(TD value)
{
    return (binary_search(data.begin(), data.end(), value));
}

// template function prototype
template <typename T>
void processList(T stop, T findit);

int main()
{
    // seeding for the random number generator
    srand(static_cast<unsigned int>(time(NULL)));

    // string search keyword
    const string SEARCH_VALUE_STR = "banana";

    // string "end" keyword
    const string STOP_VALUE_STR = "END";

    // int search keyword
    const int SEARCH_VALUE_INT = 5;

    // int "end" keyword
    const int STOP_VALUE_INT = -999;

    int  menuChoice;                // user menu-choice
    bool invalid;                   // useful for input validation mechanism

    do
    {
        invalid = false;
        cout << "1... integers" << endl;
        cout << "2... strings" << endl;
        cout << "Enter type to use: ";
        cin >> menuChoice;

        if (menuChoice != 1 && menuChoice != 2)
        {
            invalid = true;
            cout << "INVALID INPUT" << endl << endl;
        }
    }
    while (invalid);

    switch(menuChoice)
    {
    case 1:
        processList(STOP_VALUE_INT, SEARCH_VALUE_INT);
        break;

    case 2:
        processList(STOP_VALUE_STR, SEARCH_VALUE_STR);
        break;
    }
}

// template function which populates object of type DataList with the
// user input and then displays the object content in several orders.
template <typename T>
void processList(T stop, T findit)
{
    DataList<T> obj;                    // object for holding program data
    T           userInput;              // user input
    bool        shouldStop;             // useful for "when-to-stop" mechanism

    do
    {
        shouldStop = true;
        cout << "\nEnter next data element: ";
        cin >> userInput;

        if (userInput != stop)
        {
            obj.append(userInput);
            shouldStop = false;
        }
    }
    while (!shouldStop);

    // prints contents in entry order
    cout << "\nEntry order:\n";
    obj.printContents();

    // scrambles the data-list and prints contents
    cout << "\nScrambled order:\n";
    obj.scrambleContents();
    obj.printContents();

    // sorts the data-list and prints contents
    cout << "\nSorted order:\n";
    obj.sortContents();
    obj.printContents();

    // searches the data-list and reports whether or not
    // the "findit" value was found
    if(obj.isPresent(findit))
    {
        cout << "Requested item was found in the list." << endl;
    }
    else
    {
        cout << "Requested item was NOT found in the list." << endl;
    }
}