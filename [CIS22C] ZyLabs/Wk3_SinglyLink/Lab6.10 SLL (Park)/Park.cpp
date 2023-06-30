// Implementation file for the Park class
// Written By: Daniel Wong
// Reviewed & Modified by: Daniel Wong
// IDE: Xcode


#include <iostream>
#include <iomanip>
#include <string>

#include "Park.h"

using namespace std;

// **************************************************
// Constructor
// **************************************************
Park::Park()
{
    code = "";
    state = "";
    name = "";
    description = "";
    year = -1;
}

ostream &operator << (ostream &out, const Park &park) {
    out << park.code << " " << park.state << " " << park.year << " " << park.name << " " << endl;
    return out;
}

// **************************************************
// Overloaded Constructor
// **************************************************
Park::Park(string cd, string st, string nm, string dsc, int yr)
{
    code = cd;
    state = st;
    name = nm;
    description = dsc;
    year = yr;
}

// ***********************************************************
// Displays the values of a Park object member variables
// on one line (horizontal display)
// ***********************************************************
/*void Park::hDdisplay() const COMMENT OUT FOR OVERLOAD
{
    cout << code  << " ";
    cout << state << " ";
    cout << year  << " ";
    cout << name << " " << endl;
}*/

// ***********************************************************
// Displays the values of a Park object member variables
// one per line (vertical display)
// ***********************************************************
void Park::vDisplay() const
{
    cout << name << endl;
    cout << "    \"" << description << "\"" << endl;
    cout << year << endl;
    cout << state << endl;
}

