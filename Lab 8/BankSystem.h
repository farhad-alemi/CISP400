#ifndef BankSystem
#define BankSystem

#include <iostream>
#include <string>
#include <memory>

#define EXIT_OPTION 4                       // menu exit option
#define PERCENT_FEES 10                     // credit card percent transaction fee

using namespace std;

// This class track payments, accepting the name of the payer,
// and the amount that they are for. It has two child classes.
class Payment
{
private:
    string payerName;                       // debt payer name
    double paymentAmount;                   // debt repayment amount

protected:
    string getNamedPayer();

public:
    Payment(string payerName, double paymentAmount);
    ~Payment();
    double getAmount() const;
};

// This is a child class of Payment. In addition to the default 
// data tracked by Payment objects, this will also carry data
// on the credit card number.
class CreditCardPayment : public Payment
{
private:
    int cardNumber;                         // credit card number

public:
    CreditCardPayment(string payerName, int cardNumber, double paymentAmount);
    ~CreditCardPayment();
    string getName();
    int getCardNumber();
    double getAmount() const;

    // friend overloaded operator
    friend ostream &operator <<(ostream &s, CreditCardPayment &obj);
};

// This is a child class of Payment. CheckPayment objects hold one
// additional piece of information - i.e., name of a co-signer.
class CheckPayment : public Payment
{
private:
    string coSignerName;                    // name of the cosigner

public:
    CheckPayment(string payerName, string coSignerName, double paymentAmount);
    ~CheckPayment();
    string getName();
    
    // friend overloaded operator
    friend ostream &operator <<(ostream &s, CheckPayment &obj);
};

//
class Account
{
private:
    double currentDebt;                              // current remaining debt amount
    shared_ptr<CheckPayment> checkPayment;           // shared pointer object 
                                                     // owning the CheckPayment object
    shared_ptr<CreditCardPayment> creditCardPayment; // shared pointer object owning the
                                                     // CreditCardPayment Object

public:
    Account(double currentDebt);
    ~Account();
    bool stillInDebt();

    // getter methods
    double getCurrentDebt();
    shared_ptr<CheckPayment> getLastCheck();
    shared_ptr<CreditCardPayment> getLastCard();

    // friend overloaded operator
    friend ostream &operator <<(ostream &s, Account &obj);

    // external friend functions
    friend void applyCheckPayment(unique_ptr<Account> &debtAccount,
        shared_ptr<CheckPayment> checkPayment);
    friend void applyCardPayment(unique_ptr<Account> &debtAccount,
        shared_ptr<CreditCardPayment> cardPayment);

protected:
    // overloaded operators
    Account& operator-=(const Payment &amount);
    Account& operator-=(const CreditCardPayment &amount);
};

// function prototypes
int displayMenu();
shared_ptr<CheckPayment> checkPaymentCreation();
shared_ptr<CreditCardPayment> cardPaymentCreation();
void applyCheckPayment(unique_ptr<Account> &debtAccount, 
    shared_ptr<CheckPayment> checkPayment);
void applyCardPayment(unique_ptr<Account> &debtAccount, 
    shared_ptr<CreditCardPayment> cardPayment);

#endif