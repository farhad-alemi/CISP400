// Program      :   Lab# 9.cpp
// Author       :   Farhad Alemi
// Due Date     :   November 9th, 2018
// Description  :   This program uses inheritance, virtual functions, overriding,
//                  and dynamic casting and works with three classes. One returns
//                  the concatenated version of two strings, the other the smaller
//                  of the two and third class the bigger of the two by implementing
//                  their member functions besides returning the length of the 
//                  returned string. 

#include <iostream>
#include <memory>
#include <string>

using namespace std;

// This class is the base class for BiggerString and SmallerString. It stores
// two strings and, by implementing its member functions, returns the concatenated
// version of the two strings besides returning the length for the concatenated version.
class HoldsString
{
protected:
    string stringOne,                   // first string
           stringTwo;                   // second string

public:
    HoldsString(string str1, string str2);
    virtual ~HoldsString();
    virtual string getString();
    int getLength();
};

// This class is the child class of HoldsString. By implementing its member functions,
// it returns the bigger of the two strings besides returning the length for the returned
//  string.
class BiggerString : public HoldsString
{
public:
    BiggerString(string str1, string str2);
    string getString();
    string announceBigger();
};

// This class is the child class of HoldsString. By implementing its member functions,
// it returns the smaller of the two strings besides returning the length for the returned
//  string.
class SmallerString : public HoldsString
{
public:
    SmallerString(string str1, string str2);
    string getString();
    string announceSmaller();
};

// Function prototypes
void outputContents(shared_ptr<HoldsString> &str);
void printSeparator();

///////////////////////////////////////////////////////////////////////////////

// Constructor which assigns the parameters to class members using the initializer
// list.
HoldsString::HoldsString(string str1, string str2) : stringOne(str1), 
    stringTwo(str2)
{}

// Virtual destructor which takes care of the compiler issues caused by deleting
// an instance of a derived class by a pointer to a base class.
HoldsString::~HoldsString()
{}

// returns the concatenated version of the two strings
string HoldsString::getString()
{
    return (stringOne + stringTwo);
}

// returns the length for the returned string
int HoldsString::getLength()
{
    return static_cast<int>(this->getString().length());
}

///////////////////////////////////////////////////////////////////////////////

// Constructor which assigns the parameters to class members by calling the parent
// constructor in the initializer list.
BiggerString::BiggerString(string str1, string str2) : HoldsString (str1, str2)
{}

// returns the bigger of the two strings
string BiggerString::getString()
{
    string biggerString;                    // bigger string

    if (stringOne > stringTwo)
    {
        biggerString = stringOne;
    }
    else
    {
        biggerString = stringTwo;
    }

    return biggerString;
}

// returns the word "Bigger"
string BiggerString::announceBigger()
{
    return "Bigger";
}

///////////////////////////////////////////////////////////////////////////////

// Constructor which assigns the parameters to class members by calling the parent
// constructor in the initializer list.
SmallerString::SmallerString(string str1, string str2) : HoldsString (str1, str2)
{}

// returns the smaller of the two strings
string SmallerString::getString()
{
    string smallerString;                   // smaller string

    if (stringOne < stringTwo)
    {
        smallerString = stringOne;
    }
    else
    {
        smallerString = stringTwo;
    }

    return smallerString;
}

// returns the word "Smaller"
string SmallerString::announceSmaller()
{
    return "Smaller";
}

///////////////////////////////////////////////////////////////////////////////

// Global constants
const string BIGGER_STR_1 = "Cat", BIGGER_STR_2 = "Dog";
const string SMALLER_STR_1 = "House", SMALLER_STR_2 = "Violet";
const string HOLDER_STR_1 = "Length", HOLDER_STR_2 = "Width";

int main()
{
    // decalaring shared pointers of type HoldsString
    shared_ptr<HoldsString> bigger, smaller, holder;

    // constructing the objects of types HoldsString, BiggerString, and SmallerString 
    bigger = make_shared<BiggerString>(BIGGER_STR_1, BIGGER_STR_2);
    smaller = make_shared<SmallerString>(SMALLER_STR_1, SMALLER_STR_2);
    holder = make_shared<HoldsString>(HOLDER_STR_1, HOLDER_STR_2);

    // calls to outputContents() and printSeparator() functions
    outputContents(bigger);
    printSeparator();
    outputContents(smaller);
    printSeparator();
    outputContents(holder);

    return 0;
}

// 
void outputContents(shared_ptr<HoldsString> &str)
{
    string announceString;                  // string to be output on the screen
    
    // using dynamic_pointer_cast to determine the correct object type and then
    // to use the respective member function of the object
    if (dynamic_pointer_cast<BiggerString>(str) != nullptr)
    {
        // assigning the local shared pointer to the cast version of the function parameter
        shared_ptr<BiggerString> castPtr (dynamic_pointer_cast<BiggerString>(str));

        // assinging the announceString
        announceString = castPtr->announceBigger();
    }
    else if (dynamic_pointer_cast<SmallerString>(str) != nullptr)
    {
        // assigning the local shared pointer to the cast version of the function parameter
        shared_ptr<SmallerString> castPtr (dynamic_pointer_cast<SmallerString>(str));

        // assinging the announceString
        announceString = castPtr->announceSmaller();
    }
    else
    {
        // assinging the announceString
        announceString = "Concatenate";
    }

    // output section
    cout << "Type: " << announceString << endl;
    cout << "Result: " << str->getString() << endl;
    cout << "Length: " << str->getLength() << endl;
}

// prints the line separator to the screen
void printSeparator()
{
    cout << "**********************" << endl;
}