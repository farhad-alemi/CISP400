#include "BankSystem.h"

// constructor which assigns the value of its parameters
// to member variables in the initialization list.
Payment::Payment(string payerName, double paymentAmount) : payerName(payerName),
paymentAmount(paymentAmount)
{}

// destructor which announces destruction of the current object.
Payment::~Payment()
{
    cout << "Payment deallocated." << endl;
}

// returns the value of payerName
string Payment::getNamedPayer()
{
    return payerName;
}

// returns the value of paymentAmount
double Payment::getAmount() const
{
    return paymentAmount;
}