/*
    # Author: Peize LI
    # BannerID: 001393721
    # Course: CS 181
    # Assignment: PA4
    # Date Assigned: Monday, March 18, 2024
    # Date/Time Due: Saturday, March 30, 2024 -- 11:55 pm
    # Description: This program will exercise ObjectOriented concepts with C++.
    # Certification of Authenticity: I certify that this assignment is 
                                            entirely my own work.
 */
 
#include <iostream>
#include <iomanip>
#include "Employee.h" //includes the header file
using namespace std;

// Manager class inherits Employee class publicly
class Manager : public Employee {
    private:
    double bonus;
    public:
    //Manager class constructor
    Manager(string name, double wage, double hours, double bonus);
    double calcPay() const;
};

// Constructor for Manager class which also inherits the employee class 
//constructor
Manager::Manager(string name, double wage, double hours, double bonus)
    : Employee(name, wage, hours), bonus(bonus){}

//function to calculate pay for Manager
double Manager::calcPay() const {
    double totalPay = Employee::calcPay() + bonus;
    return totalPay;
}

int main() {
    int numManagers;
    string name;
    double wage, bonus;
    double hoursWorked;
    const int MAX_MANAGERS = 100;
    
    //input validation to enter the number of managers
    //loop continues until the number of managers is either negative or zero.
    do
    {
        cout << "Enter number of managers: ";
        cin >> numManagers;
        if (numManagers <= 0){
            cout << "Enter the number of manager greater than 0." << endl;
        }
    }while(numManagers <= 0);
    
    // array of pointers to Manager objects that can store maximum of 100
    //managers
    Manager* managers[MAX_MANAGERS];

    // for loop to enter the information of managers according to the number of
    //managers user input
    for (int i = 0; i < numManagers; ++i) {
        cout << "\nEnter manager " << i << " name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter manager " << i << " hourly wage: ";
        cin >> wage;
        cout << "Enter manager " << i << " hours worked: ";
        cin >> hoursWorked;
        cout << "Enter manager " << i << " bonus: ";
        cin >> bonus;

        //dynamic allocation of Manager object
        managers[i] = new Manager(name, wage, hoursWorked, bonus);
    }

    //initialize the highest pay and total pay
    double maxPay = 0.0;
    double totalPay = 0.0;
    string maxPaidManager;

    //for loop to calculate the highest paid manager
    for (int i = 0; i < numManagers; i++) {
        double payAmount = managers[i]->calcPay();
        totalPay += payAmount;

        if (payAmount > maxPay) {
            maxPay = payAmount;
            maxPaidManager = managers[i]->getName();
        }
    }

    double averagePay = totalPay / numManagers;

    // display the highest paid manager and the average pay
    cout << fixed << setprecision(2) << "\nHighest paid manager is " 
         << maxPaidManager << " who is paid $" << maxPay << "." << endl;
    cout << "Average pay is $" << averagePay << "." << endl;

    // delete the dynamically allocated memory
    for (int i = 0; i < numManagers; i++) {
        delete managers[i];
    }
    return 0;
}

