/**~*~*~*
CIS 22C
Project: Stack ADT

Written by: Student
IDE:
*~*/

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>

#include "StackADT.h"

using namespace std;

void printInfo();
void processNumbers(string, Stack<int> &);
void printStack(Stack<int> &);

int main()
{
    printInfo();
   
    cout << "Enter input file name: " << endl;
    string filename;
    getline(cin, filename); // assume valid
    
    // declare stack here
        
    // call processNumbers()
   
    // call printStack()
    

    return 0;
}


/**~*~*~*~*~
This function displays the project's title
*~*/
void printInfo()
{
    cout << " ~*~ Project: Stack ADT ~*~ " << endl;
}

    // define processNumbers(), a function to process the input file
   
    // define printStack(), a function to print the stack
