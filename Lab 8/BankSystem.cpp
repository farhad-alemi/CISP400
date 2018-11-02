#include "BankSystem.h"

int main()
{
    double debtAmount;                      // initial debt amount
    int    menuOption;                      // validated menu option

    // shared pointer which points to the object holding info
    // for the last card payment
    shared_ptr<CreditCardPayment> cardPayment = nullptr;

    // shared pointer which points to the object holding info
    // for the last check payment
    shared_ptr<CheckPayment> checkPayment = nullptr;

    cout << "Enter starting debt:" << endl;
    cin >> debtAmount;

    // unique pointer which points to the object holding the info related
    // to current debt
    unique_ptr<Account> debtAccount(new Account(debtAmount));

    do
    {
        menuOption = displayMenu();                 // call to displayMenu() function

        switch(menuOption)
        {
        case 1:
            // catching the shared pointer from the function
            cardPayment = cardPaymentCreation();

            // feeding the shared pointer into payment application
            // function
            applyCardPayment(debtAccount, cardPayment);

            break;

        case 2:
            // catching the shared pointer from the function
            checkPayment = checkPaymentCreation();

            // feeding the shared pointer into payment application
            // function
            applyCheckPayment(debtAccount, checkPayment);
            break;

        case 3:
            // displaying current status
            cout << *debtAccount;
            break;
        }
    }
    while (menuOption != EXIT_OPTION && debtAccount->stillInDebt());
    
    // Final Report
    cout << endl << endl << "FINAL REPORT:" << endl << endl;
    cout << *debtAccount << endl;
}

// this function displays the menu content and returns
// a validated user input.
int displayMenu()
{
    int menuOption;                     // user's menu choice
    bool valid;                         // temp variable used in input validation

    do
    {
        valid = true;
        cout << "1...Enter card payment" << endl;
        cout << "2...Enter check payment" << endl;
        cout << "3...View Current Account Status" << endl;
        cout << "4...Exit Program" << endl;
        cout << "Enter choice:" << endl;
        cin >> menuOption;

        if (menuOption != 1 && menuOption != 2 && menuOption != 3 && menuOption != 4)
        {
            valid = false;
            cout << "Invalid Input" << endl << endl;
        }
    }
    while (!valid);

    return menuOption;
}

// this function queries the user about every value in the CheckPayment object.
// The object of type CheckPayment is constructed using a shared_ptr,
// and then returned.
shared_ptr<CheckPayment> checkPaymentCreation()
{
    string payerName,                   // name of payer
           coSignerName;                // name of cosigner
    double amount;                      // current repayment amount

    cout << "Enter name of payer:" << endl;
    cin >> payerName;
    cout << "Enter amount of cash:" << endl;
    cin >> amount;
    cout << "Enter name of cosigner:" << endl;
    cin >> coSignerName;

    shared_ptr<CheckPayment> checkPayment(new CheckPayment(payerName, coSignerName,
        amount));

    return checkPayment;
}

// this function queries the user about every value in the CreditCardPayment object.
// The object of type CreditCardPayment is constructed using a shared_ptr,
// and then returned.
shared_ptr<CreditCardPayment> cardPaymentCreation()
{
    string payerName;                   // name of payer
    int    cardNumber;                  // payment card number
    double amount;                      // current repayment amount

    cout << "Enter name of payer:" << endl;
    cin >> payerName;
    cout << "Enter amount of cash (NOTE - there will be a deduction!):" << endl;
    cin >> amount;
    cout << "Enter credit card number:" << endl;
    cin >> cardNumber;

    shared_ptr<CreditCardPayment> cardPayment(new CreditCardPayment(payerName, 
        cardNumber, amount));

    return cardPayment;
}

// friend of the Account class, it uses the overloaded -= operator with Account
// and CheckPayment to reduce the debt by the appropriate amount, and then assigns
// the shared pointer parameter to the checkPayment member variable of the Account
// object.
void applyCheckPayment(unique_ptr<Account> &debtAccount, shared_ptr<CheckPayment>
    checkPayment)
{
    *debtAccount -= *checkPayment;
    debtAccount->checkPayment = checkPayment;
}

// friend of the Account class, it uses the overloaded -= operator with Account
// and CreditCardPayment to reduce the debt by the appropriate amount, and then
// assigns the shared pointer parameter to the CreditCardPayment member variable
//  of the Account object.
void applyCardPayment(unique_ptr<Account> &debtAccount, shared_ptr<CreditCardPayment>
    cardPayment)
{
    *debtAccount -= *cardPayment;
    debtAccount->creditCardPayment = cardPayment;
}