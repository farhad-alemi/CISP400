#include "BankSystem.h"

// constructor which calls the constructor for parent 
// class in the initialization list besides assigning the
// value of its parameter to the remaining member variable 
CreditCardPayment::CreditCardPayment(string payerName, int cardNumber, double paymentAmount)
    : Payment(payerName, paymentAmount), cardNumber(cardNumber)
{}

// destructor which announces destruction of the current object.
CreditCardPayment::~CreditCardPayment()
{
    cout << "Removing credit card payment record..." << endl;
}

// this function calls the parent member function and returns the
// concatenated value of the payerName.
string CreditCardPayment::getName()
{
    return getNamedPayer() + " (on credit)";
}

// returns the credit card number
int CreditCardPayment::getCardNumber()
{
    return cardNumber;
}

// This function returns a "processed" recent payment amount
// since it also has to account for the transactions fees that
// the credit card companies charge.
double CreditCardPayment::getAmount() const
{
    return ((1 - PERCENT_FEES / 100.0) * Payment::getAmount());
}

// overloaded operator which allows CreditCardPayment objects to 
// be used with ostream operators.
ostream &operator <<(ostream &s, CreditCardPayment &obj)
{
    s << "Name: " << obj.getName() << endl;
    s << "Amount: " << obj.getAmount() << endl;
    s << "Card number: " << obj.getCardNumber() << endl << endl;
    return s;
}