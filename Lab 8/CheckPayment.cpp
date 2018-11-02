#include "BankSystem.h"

// constructor which calls the constructor for parent 
// class in the initialization list besides assigning the
// value of its parameter to the remaining member variable
CheckPayment::CheckPayment(string payerName, string coSignerName, double paymentAmount)
    : Payment(payerName, paymentAmount), coSignerName(coSignerName)
{}

// destructor which announces destruction of the current object.
CheckPayment::~CheckPayment()
{
    cout << "Removing checking payment record..." << endl;
}

// this function calls the parent member function and returns the
// concatenated value of the payerName.
string CheckPayment::getName()
{
    return getNamedPayer() + " (by check)";
}

// overloaded operator which allows CheckPayment objects to 
// be used with ostream operators.
ostream &operator <<(ostream &s, CheckPayment &obj)
{
    s << "Name: " << obj.getName() << endl;
    s << "Amount: " << obj.getAmount() << endl;
    s << "Cosigner: " << obj.coSignerName << endl <<endl;

    return s;
}