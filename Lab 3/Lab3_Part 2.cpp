// Program      :   Lab# 3-1.cpp
// Author       :   Farhad Alemi
// Due Date     :   September 20th, 2018
// Description  :   This program accepts information about purchased real estate.
//                  It will take the input from the user and then repeat that 
//                  information to the user.

#include <iostream>
#include <string>

using namespace std;

// constants
const int EXIT_OPTION = 5;              // the exit option
const int MAX_NAME_LENGTH = 20;         // maximum number of characters for
                                        // owner member variable

// enumerator for various property types
enum Property {Lakeside, Downtown, Suburb, Country, Parkside};

// struct for storing property information;
struct OwnedPropertyStruct
{
    int      transactionNumber;         // for storing the transaction number
    string   owner;                     // for storing the owner's name
    Property which;                     // for stroing the property type
};

// for better struct name handling
typedef struct OwnedPropertyStruct OwnedProperty;

// prototypes
string TranslateProperty(Property translationData);
int userMenu();
void printOwnedProperty(OwnedProperty *printableData);
void handlePropertyData(int userOption);


int main()
{
    int userOption;                     // for storing user's menu choice

    do
    {
        userOption = userMenu();
        if (userOption != EXIT_OPTION)
        {
            handlePropertyData(userOption);
        }
    }
    while (userOption != EXIT_OPTION);
}


// This function returns a descriptive string for each enumerator in
// Property and returns a string that says Error if the variable does
// not match any enumerator in Property.
string TranslateProperty(Property translationData)
{
    if (translationData == 0)
    {
        return "Lakeside";
    }
    else if (translationData == 1)
    {
        return "Downtown";
    }
    else if (translationData == 2)
    {
        return "Suburb";
    }
    else if (translationData == 3)
    {
        return "Country";
    }
    else if (translationData == 4)
    {
        return "Parkside";
    }
    else
    {
        return "Error";
    }
}


// This function presents a user a choice of several numbers, one each for the
// enumerators in Property. The options shown match the int value of the
// enumerator.
int userMenu()
{
    int  userOption;                    // for storing user's menu choice
    bool valid;                         // temp. variable useful in loop validation

    do
    {
        valid = true;                   // giving the user a new chance
        cout << "0 - Lakeside" << endl;
        cout << "1 - Downtown" << endl;
        cout << "2 - Suburb" << endl;
        cout << "3 - Country" << endl;
        cout << "4 - Parkside" << endl;
        cout << EXIT_OPTION << " - Exit" << endl;
        cout << "Make your choice:";
        cin >> userOption;

        if (userOption != 0 && userOption != 1 && userOption != 2 && userOption != 3 && userOption
            != 4 && userOption != EXIT_OPTION)
        {
            cout << "Invalid selection." << endl;
            valid = false;              // the user has made an invalid choice.
        }
    }
    while (!valid);

    return userOption;
}


// This function prints out the contents of the instance of OwnedProperty that
// the pointer is pointing to, and labels each field appropriately.
void printOwnedProperty(OwnedProperty *printableData)
{
    cout << "Transaction #: " << printableData->transactionNumber << endl;
    cout << "Owner: " << printableData->owner << endl;
    cout << "Type: " << TranslateProperty(printableData->which) << endl;
}


// This function takes the user'choice as an int and then casts it into a
// variable of type Property. The function also instantiates a pointer of type
// OwnedProperty in the heap and then passes it to another function after rece-
// iving input from the user. A the end, the pointer is removed to prevent memory
// leak.
void handlePropertyData(int userOption)
{
    // casts the int variable into a variable of type Property
    Property purchasedProperty = static_cast<Property>(userOption);

    // creates a pointer to data of type OwnedProperty
    OwnedProperty* purchaseData = new OwnedProperty;

    // assigns the cast variable to a (de-referenced) struct pointer
    // member variable
    purchaseData->which = purchasedProperty;
    
    cout << "Enter transaction number:";
    cin >> purchaseData->transactionNumber;

    do                                  // validates the owner name length
    {
        cout << "Enter owner name:";
        cin >> purchaseData->owner;

        // The if statement compares the length of member variable owner
        // with const. MAX_NAME_LENGTH  by using .length() function.
        if ((purchaseData->owner).length() > MAX_NAME_LENGTH)
        {
            cout << "Invalid name, try again." << endl;
        }
    }
    while ((purchaseData->owner).length() > MAX_NAME_LENGTH);

    printOwnedProperty(purchaseData);
    delete purchaseData;            // the pointer is removed to prevent memory
                                    // leak.
}