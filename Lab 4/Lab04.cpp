// Program      :   Lab# 4.cpp
// Author       :   Farhad Alemi
// Due Date     :   September 27th, 2018
// Description  :   This program asks the user for information of two items
//                  in a retail store. It stores the information in two objects
//                  one being a pointer and the other a local variable. It then 
//                  displays the information for the object and releases the
//                  reserved space in the heap.

#include <iostream>

using namespace std;

class Inventory
{
private:
    int    itemNumber,                  // item number
           quantity;                    // item quantity
    double cost;                        // item cost

public:
    void setItemNumber(int itemNumber);
    bool setQuantity(int quantity);
    bool setCost(double cost);
    int getItemNumber();
    int getQuantity();
    double getCost();
    double getTotalCost();
    void print();
    Inventory();
    Inventory(int itemNumber, int quantity, double cost);
    ~Inventory();
};


// this function sets the value of the class variable itemNumber
// to the function paramter
void Inventory::setItemNumber(int itemNumber)
{
    this->itemNumber = itemNumber;
}

// this function sets the value of the class variable quantity
// to the function paramter and returns true if the parameter
// is non-negative. Otherwise it sets the class variable to 0
// and returns false
bool Inventory::setQuantity(int quantity)
{
    if (quantity < 0)
    {
        this->quantity = 0;
        return false;
    }
    else
    {
        this->quantity = quantity;
        return true;
    }
}

// this function sets the value of the class variable cost
// to the function paramter and returns true if the parameter
// is non-negative. Otherwise it sets the class variable to 0
// and returns false
bool Inventory::setCost(double cost)
{
    if (cost < 0)
    {
        this->cost = 0;
        return false;
    }
    else
    {
        this->cost = cost;
        return true;
    }
}

// returns itemNumber
int Inventory::getItemNumber()
{
    return itemNumber;
}

// returns quantity
int Inventory::getQuantity()
{
    return quantity;
}

// returns cost
double Inventory::getCost()
{
    return cost;
}

// returns total cost
double Inventory::getTotalCost()
{
    return (quantity * cost);
}

// this function displays the information for the class object
void Inventory::print()
{
    cout << "Item number: " << this->getItemNumber() << endl;
    cout << "Quantity: " << this->getQuantity() << endl;
    cout << "Cost: " << this->getCost() << endl;
    cout << "Total cost: " << this->getTotalCost() << endl;
}

// the constructor with no parameter which assigns the private variables
// to zero
Inventory::Inventory()
{
    itemNumber = 0;
    quantity = 0;
    cost = 0;
}

// the constructor which assigns the class variables to the 
// respective parameters by calling the setter functions
Inventory::Inventory(int itemNumber, int quantity, double cost)
{
    setItemNumber(itemNumber);
    setQuantity(quantity);
    setCost(cost);
}

// the destructor that prints that the object is being destroyed
Inventory::~Inventory()
{
    cout << "Inventory item being destroyed." << endl;
}

//prototype
void printMyInventoryObjects(Inventory &firstObject, Inventory &secondObject);


int main()
{
    int    itemNumber,                  // temp. variable for storing item number
           itemQuantity;                // temp. variable for storing item quantity
    double itemCost;                    // temp. variable for storing item cost
    bool   valid;                       // this variable is useful in input 
                                        // validation for loop iteration

    // object 1 input
    cout << "Enter item number for first inventory item: ";
    cin >> itemNumber;
    cout << endl;
    cout << "Enter quantity for first inventory item: ";
    cin >> itemQuantity;
    cout << endl;
    cout << "Enter cost for first inventory item: ";
    cin >> itemCost;

    // first object uses Inventory type pointer
    Inventory* item1 = new Inventory(itemNumber, itemQuantity, itemCost);

    // second object is a local variable of type Inventory
    Inventory item2 = Inventory();      // call to the constructor with no parameter

    // object 2 input
    cout << "Enter item number for second inventory item: ";
    cin >> itemNumber;
    item2.setItemNumber(itemNumber);    // sets the object variable
    cout << endl;
    
    do                                  // the variable quantity is validated
    {
        cout << "Enter quantity for second inventory item: ";
        cin >> itemQuantity;
        valid = item2.setQuantity(itemQuantity);    // receives the validation flag
        if (!valid)
        {
            cout << "Invalid negative input.  Try again." << endl;
        }
        cout << endl;
    }
    while (!valid);

    do                                  // the variable cost is validated
    {
        cout << "Enter cost for second inventory item: ";
        cin >> itemCost;
        valid = item2.setCost(itemCost);            // receives the validation flag
        if (!valid)
        {
            cout << "Invalid negative input.  Try again." << endl << endl;
        }
    }
    while (!valid);
    
    printMyInventoryObjects(*item1, item2);         // call to output function

    // deallocating the first object
    delete item1;
}

// this function displays the results for the objects being passed by calling
// the member function print() for each object.
void printMyInventoryObjects(Inventory &firstObject, Inventory &secondObject)
{
    cout << "Results for first inventory item: " << endl;
    firstObject.print();                            // call to print() function for first object
    cout << endl;

    cout << "Results for second inventory item: " << endl;
    secondObject.print();                           // call to print() function for second object
}