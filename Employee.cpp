#include <string>
#include <cstdlib>
using namespace std;
#include "Employee.h"

//Employee class constructor initialized
Employee::Employee (string theName, double theWage, double theHours)
{
    name = theName;
    wage = theWage;
    hours = theHours;
}

//return the pay of an employee
double Employee::calcPay() const
{
    double pay = wage * hours;
    return pay;
}

//return the name of the emplo
string Employee::getName () const
{
    return name;
}