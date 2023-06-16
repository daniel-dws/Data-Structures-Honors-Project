/* *~*~*
Implementation file for the Customer class
Written By: A. Student
Changed by: Daniel Wong
IDE: xCode
*~**/

#include <iostream>
#include <string>
#include "Customer.h"

using namespace std;

/* Write your code here */

//CONSTRUCTOR
Customer::Customer()
{
    year = -1;
    mileage = -1;
    seq = -1;
    name = "";
}

//OVERLOADED Constructor
Customer::Customer(int yr, int ml, int sq, string nm)
{
    year = yr;
    mileage = ml;
    seq = sq;
    name = nm;
}

//FRIEND FUNCTIONS
int calcSerial(const Customer& customer)
{
    //Calc Priority
    int priority = (customer.mileage / 1000) + customer.year - customer.seq;
    
    //Calc Serial Num
    int serial_num = (priority * 100) + (100 - customer.seq);
    
    return serial_num;
}

int compareSerial(const Customer &left, const Customer &right)
{
    if (calcSerial(left) == calcSerial(right))
    {
        return 0;
    }
    
    else if (calcSerial(left) > calcSerial(right))
    {
        return -1;
    }
    
    else {
        return 1;
    }
}
 


