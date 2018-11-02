#include "BankSystem.h"

// constructor which assigns the value for the member variables
Account::Account(double currentDebt)
{
    checkPayment = nullptr;
    creditCardPayment = nullptr;
    this->currentDebt = currentDebt;
}

// destructor which announces destruction of the current object.
// However, it displays different message based on whether the 
// debt is completely settled at the time the object is destroyed.
Account::~Account()
{
    if (stillInDebt())
    {
        cout << "Debt still unsettled on deallocation." << endl;
    }
    else
    {
        cout << "Debt satisfied prior to deallocation." << endl;
    }
}

// returns false if debt is completely settled; otherwise 
// returns true
bool Account::stillInDebt()
{
    if (currentDebt > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// returns the value for currentDebt
double Account::getCurrentDebt()
{
    return currentDebt;
}

// returns the shared_ptr object which owns object
// of type CheckPayment
shared_ptr<CheckPayment> Account::getLastCheck()
{
    return checkPayment;
}

// returns the shared_ptr object which owns object
// of type CreditCardPayment
shared_ptr<CreditCardPayment> Account::getLastCard()
{
    return creditCardPayment;
}

// This function overloads the << operator and allows
// objects of type Account to be used with ostream operators.
ostream &operator <<(ostream &s, Account &obj)
{
    s << "---Current Account Status---" << endl;
    s << "current debt: " << obj.getCurrentDebt() << endl;
    s << "------------------------------" << endl;

    // checks whether there is a recent card payment
    if (obj.getLastCard() == nullptr)
    {
        s << "NO CREDIT CARD PAYMENT ENTERED." << endl;
    }
    else
    {
        s << *(obj.getLastCard());
    }

    s << "------------------------------" << endl;

    // checks whether there is a recent check payment
    if (obj.getLastCheck() == nullptr)
    {
        s << "NO CHECK PAYMENT ENTERED." << endl;
    }
    else
    {
        s << *(obj.getLastCheck());
    }
    s << "------------------------------" << endl;
    return s;
}

// protected member overloaded operator function for -=. It takes a Payment
// parameter and subtracts the amount in the payment from the current debt.
Account& Account::operator-=(const Payment &amount)
{
    currentDebt -= amount.getAmount();
    return *this;                       // returning an object of type Account
}

// protected member overloaded operator function for -=. It takes a CreditCardPayment
// parameter and subtracts the amount in the payment from the current debt.
Account& Account::operator-=(const CreditCardPayment &amount)
{
    currentDebt -= amount.getAmount();
    return *this;                       // returning an object of type Account
}